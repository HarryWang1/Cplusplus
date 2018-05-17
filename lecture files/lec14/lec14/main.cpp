/*
concurrency / threads:
https://www.youtube.com/watch?v=wXBcwHwIt_I

Divide tasks using threads. 

Multithreading is running one instance of a program: 
But within the process is a division with multiple things happening concurrently. 

All the threads of activity is happening within the same memory layout. Same code. 


How to split:
int main(){

//======Stuff==========
//=====================

thread tid(spin); //Initialize a thread and pass in the function "spin" (or whatever function you want)
tid.detach(); //Detach the thread. So now there are two threads, the thread that would be let's say running main... and then a thread running spin.
//Thread is just saying that the thread won't talk to main. So that when main for example hits the end, the thread for spin won't just terminate
with main ending. 

}

Multithreading is where activities are running off the same memory image; they are all running the same program. Just different callstacks. 
Meaning they all have access to the entire memory. They are sharing memory - good and bad. 
- Good b/c easy to communicate (Global variables)


How: 
- Create the thread
- Tell it what code to run
- How do you get a answer back? 

API's:
C++ Thread API. 

t.join();  //By placing this ex. in a main function. it will wait for the thread t to finish, sync up, then continue the rest of the main function. 

int main(){
thread t1(threadFunc);
thread t2(threadFunc);

t1.join(); //Will wait till finishes. 
t2.join(); //WIll wait till finishes
cout << "Glob = " << glob << endl;

}

Pretend you were to run the function above, with a loop that increments glob 10,000 times. But this will fail, and you will get
an output that is inconsistent and won't get 20,000 like expected. 

This is b/c they have a race condition. 

If one thread will modify shared dat while others will also modify or even just access it, the code that touches that data is referred
to as a critical region. 

Two threads should not both be in their critical regions for a shared item at the sam etime. 

If they are we have a race condition. 

ENsuring that only one process/thread will be in its critical region at a time is reffered to as mutual exclusion. 

Ex. In this case the thing that happen is.. 
1) To increment glob
2) it needs to access global
3) Increment it in some register
4) Send the value back to glob.

HOWEVER When you have two threads touching it at the same time, they might be touching the glob in between all those steps. 
And what happens is that it will mess up the other condition by modifying glob in between while another thread might be working
on it. 

*/

/*
The main thing is locking and unlocking in order to fix. It ensures mutual exclusivity so that two threads
won't touch it at once. 

#include <mutex>
mutex myMutex;
void increment(){
	for(int i = 0; i < 10000000; ++i)
	{
		myMutex.lock();
		++x;
		myMutex.unlock;
	}
}

What happens when there is a lock() but no unlock(). 
1) Java -> Would say that you can keep having it lock. It increments the # of locks that you have. 
2) In C++ lock, it would just say that it is locked.... It is locked... that's it. <- A lot of threading api are implemented this way. 

bool try_lock()
- similar to lock() but i the mutex was lunlocked then it is now locked by you and returned true. 
- Can look at further documentation if necessary. 

Issues:
- Programmer neglects to acquire lock when entering critical region
- programmer neglects to release lock when leaving the critical region
- code throws an unhandled exception resulting in it leaving tthe critical region before unlocking the lock. 

The first problem is handled by encapsulating the shared resource in a class that handles the lock acquisition / realease. 
This is commonly refferred to as a monitor. 

We can address the second and third problem with a lock_guard. 

void threadFunc(){
	for (int j = 0; j < loops; j++){
		lock_guard<mutex> myLock(myMutex);
		++glob;
	}
} //myMutex is unlocked when it goes out of scope. 

On destruction, the guard is unlocked. 
*/

/*
BARRIER
Syncrhonization abstraction allowing multiple threads to block until they have completed their task(s) and then continue. 
https://en.wikipedia.org/wiki/Barrier_(computer_science)

int main(){
	Barrier bar(10);
	vector<thread> threads;
	for (int i = 0; i < 10; ++i)[
		threads.push_back(threads[&bar, i] {
		cerr << "Thread " << i << "Working . waiting ";
		bar.arrive();
		cerr << "Thread << i << " leaving ";
		}));
	//^The above is a lambda expression.
	for(threads& t : threads ) t.join();
}

*/