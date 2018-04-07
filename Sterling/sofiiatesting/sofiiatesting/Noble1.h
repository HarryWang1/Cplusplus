#pragma once
#ifndef Noble1_h
#define Noble1_h
#include <string>
#include <vector>

namespace WarriorCraft {
	class Noble {
	public:
		void display();
	private:
		std::string name;
		int power;
		bool alive;
	};
}

#endif