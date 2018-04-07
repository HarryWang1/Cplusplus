#include <stdio.h>
#include <string.h>

struct tbl_entry {
	char src;
	char dst;
} trans_tbl[] = {
	{ 1, 187 },{ 2, 155 },{ 3, 196 },{ 4, 108 },{ 5, 74 },{ 6, 46 },
	{ 7, 34 },{ 8, 69 },{ 9, 51 },{ 10, 184 },{ 11, 213 },{ 12, 6 },
	{ 13, 10 },{ 14, 188 },{ 15, 250 },{ 16, 121 },{ 17, 36 },{ 18, 225 },
	{ 19, 178 },{ 20, 191 },{ 21, 44 },{ 22, 173 },{ 23, 134 },{ 24, 96 },
	{ 25, 164 },{ 26, 182 },{ 27, 216 },{ 28, 89 },{ 29, 135 },{ 30, 65 },
	{ 31, 148 },{ 32, 119 },{ 33, 240 },{ 34, 79 },{ 35, 203 },{ 36, 97 },
	{ 37, 37 },{ 38, 192 },{ 39, 151 },{ 40, 42 },{ 41, 92 },{ 42, 8 },
	{ 43, 201 },{ 44, 159 },{ 45, 67 },{ 46, 78 },{ 47, 207 },{ 48, 249 },
	{ 49, 62 },{ 50, 111 },{ 51, 101 },{ 52, 231 },{ 53, 197 },{ 54, 57 },
	{ 55, 183 },{ 56, 239 },{ 57, 208 },{ 58, 200 },{ 59, 47 },{ 60, 170 },
	{ 61, 199 },{ 62, 71 },{ 63, 60 },{ 64, 129 },{ 65, 50 },{ 66, 73 },
	{ 67, 211 },{ 68, 166 },{ 69, 150 },{ 70, 43 },{ 71, 88 },{ 72, 64 },
	{ 73, 241 },{ 74, 156 },{ 75, 238 },{ 76, 26 },{ 77, 91 },{ 78, 198 },
	{ 79, 214 },{ 80, 128 },{ 81, 45 },{ 82, 109 },{ 83, 154 },{ 84, 61 },
	{ 85, 167 },{ 86, 147 },{ 87, 132 },{ 88, 224 },{ 89, 18 },{ 90, 59 },
	{ 91, 185 },{ 92, 9 },{ 93, 105 },{ 94, 186 },{ 95, 153 },{ 96, 72 },
	{ 97, 115 },{ 98, 177 },{ 99, 124 },{ 100, 130 },{ 101, 190 },{ 102, 39 },
	{ 103, 157 },{ 104, 251 },{ 105, 103 },{ 106, 126 },{ 107, 244 },{ 108, 179 },
	{ 109, 5 },{ 110, 194 },{ 111, 95 },{ 112, 27 },{ 113, 84 },{ 114, 35 },
	{ 115, 113 },{ 116, 17 },{ 117, 48 },{ 118, 210 },{ 119, 165 },{ 120, 104 },
	{ 121, 158 },{ 122, 63 },{ 123, 245 },{ 124, 122 },{ 125, 206 },{ 126, 11 },
	{ 127, 12 },{ 128, 133 },{ 129, 222 },{ 130, 99 },{ 131, 94 },{ 132, 142 },
	{ 133, 189 },{ 134, 254 },{ 135, 106 },{ 136, 218 },{ 137, 38 },{ 138, 136 },
	{ 139, 232 },{ 140, 172 },{ 141, 3 },{ 142, 98 },{ 143, 168 },{ 144, 246 },
	{ 145, 247 },{ 146, 117 },{ 147, 107 },{ 148, 195 },{ 149, 70 },{ 150, 81 },
	{ 151, 230 },{ 152, 143 },{ 153, 40 },{ 154, 118 },{ 155, 90 },{ 156, 145 },
	{ 157, 236 },{ 158, 31 },{ 159, 68 },{ 160, 82 },{ 161, 1 },{ 162, 252 },
	{ 163, 139 },{ 164, 58 },{ 165, 161 },{ 166, 163 },{ 167, 22 },{ 168, 16 },
	{ 169, 20 },{ 170, 80 },{ 171, 202 },{ 172, 149 },{ 173, 146 },{ 174, 75 },
	{ 175, 53 },{ 176, 14 },{ 177, 181 },{ 178, 32 },{ 179, 29 },{ 180, 93 },
	{ 181, 193 },{ 182, 226 },{ 183, 110 },{ 184, 15 },{ 185, 237 },{ 186, 144 },
	{ 187, 212 },{ 188, 217 },{ 189, 66 },{ 190, 221 },{ 191, 152 },{ 192, 87 },
	{ 193, 55 },{ 194, 25 },{ 195, 120 },{ 196, 86 },{ 197, 175 },{ 198, 116 },
	{ 199, 209 },{ 200, 4 },{ 201, 41 },{ 202, 85 },{ 203, 229 },{ 204, 76 },
	{ 205, 160 },{ 206, 242 },{ 207, 137 },{ 208, 219 },{ 209, 228 },{ 210, 56 },
	{ 211, 131 },{ 212, 234 },{ 213, 23 },{ 214, 7 },{ 215, 220 },{ 216, 140 },
	{ 217, 138 },{ 218, 180 },{ 219, 123 },{ 220, 233 },{ 221, 255 },{ 222, 235 },
	{ 223, 21 },{ 224, 13 },{ 225, 2 },{ 226, 162 },{ 227, 243 },{ 228, 52 },
	{ 229, 204 },{ 230, 24 },{ 231, 248 },{ 232, 19 },{ 233, 141 },{ 234, 127 },
	{ 235, 174 },{ 236, 33 },{ 237, 227 },{ 238, 205 },{ 239, 77 },{ 240, 112 },
	{ 241, 83 },{ 242, 253 },{ 243, 171 },{ 244, 114 },{ 245, 100 },{ 246, 28 },
	{ 247, 102 },{ 248, 169 },{ 249, 176 },{ 250, 30 },{ 251, 215 },{ 252, 223 },
	{ 253, 54 },{ 254, 125 },{ 255, 49 },
};

char get_tbl_entry(char c) {
	for (size_t i = 0; i < sizeof(trans_tbl) / sizeof(struct tbl_entry); i++) {
		if (trans_tbl[i].src == c)
			return trans_tbl[i].dst;
	}
	// wuttt
	return 0;
}

char get_tbl_back(char c) {
	for (size_t i = 0; i < sizeof(trans_tbl) / sizeof(struct tbl_entry); i++) {
		if (trans_tbl[i].dst == c)
			return trans_tbl[i].src;
	}
	// wuttt
	return 0;
}

int main() {
	char buf[128];
	size_t len;
	char ans[] = "\x27\xb3\x73\x9d\xf5\x7c\x99\x67\x3f\x99\x65\x3f\x99\xe7\xc2"
		"\x82\x99\x27\x30\xc2\xce";
	for (size_t i = 0; i < strlen(ans); i++) {
		ans[i] = get_tbl_back(ans[i]);
	}
	printf("%s", ans);
	printf("Please enter the flag:\n");
	//fgets(buf, sizeof(buf), stdin);
	buf[strlen(buf) - 1] = '\0';
	len = strlen(buf);
	for (size_t i = 0; i < len; i++) {
		buf[i] = get_tbl_entry(buf[i]);
	}
	if (len != sizeof(ans) - 1) {
		printf("WRONG\n");
		return 1;
	}
	if (strncmp(buf, ans, sizeof(ans)) == 0) {
		printf("CORRECT <3\n");
		return 0;
	}
	printf("WRONG\n");
	return 1;
}

///*
//Justin Lin
//NYU ID: jwl488
//N#: 19699912
//Name File: rec12_Inheritance
//Purpose:
//*/
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//
///*
//Classes and Structs
//*/
//class Pet {
//public:
//	virtual void eat() { cout << "Pet Eating" << endl; }
//private:
//};
//
//class Cat : public Pet {
//public:
//	void eat() { cout << "Cat Eating: " << endl;
//	pet:eat();
//	}
//
//private:
//};
//
//class Slug : public Pet {
//public:
//	void eat() override { cout << "Slug Eating" << endl; } //By writing override it tells the compiler to tell compiler
//	//that you think that you are overriding something and make sure that you are overriding. 
//private:
//};
//
//class Roach : public Pet {
//public:
//private:
//};
///*
//Prototype Main Function
//*/
//void someFunc(Pet aPet) { //bases in directly and causes slicing problem
//	aPet.eat();
//}
//
//void someFuncRec(Pet& aPet) {//Reference will prevent a slicing problem
//	cout << "someFunc: ";
//	aPet.eat();
//}
//
///*
//Main Function
//*/
//int main() {
//	Pet peeve;
//	peeve.eat();
//
//	Cat felix;
//	felix.eat();
//	someFunc(felix); //Can pass in a derived type. 
//
//	Slug sluggo;
//	sluggo.eat();
//	someFunc(sluggo);
//	someFuncRec(sluggo);
//
//	Roach archie;
//
//	vector<Pet*>menagerie;
//	menagerie.push_back(&peeve);
//	menagerie.push_back(&felix);
//	menagerie.push_back(&sluggo);
//	menagerie.push_back(&archie);
//
//	for (size_t i = 0; i < menagerie.size(); ++i) {
//		menagerie[i]->eat();	
//	}
//
//	felix.eat();
//	felix.Pet::eat();
//}
//
///*/
//Functions
//*/
