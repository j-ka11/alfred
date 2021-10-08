// Alfred.cpp

#include <iostream>
#include <string>
#include "Database.h"
#include "PrimitiveContainer.h"

int main() {
    std::cout << "Hello! My name is Alfred:)\n";
	Alfred::PrimitiveContainer* numberContainer = new Alfred::PrimitiveContainer(6);
	Alfred::PrimitiveContainer* stringContainer = new Alfred::PrimitiveContainer(std::string("test string"));
	int testNumber;
	std::string testString;
	numberContainer->getData(testNumber);
	stringContainer->getData(testString);
	std::cout << testNumber << std::endl;
	std::cout << testString << std::endl;
}
