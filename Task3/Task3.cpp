#include <iostream>
#include <vector>
#include <string>
#include "header.h"

int main() {
	std::string input;
	std::cin >> input;
	std::vector<int> numbers;
	std::string toInt;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
			if (std::stoi(toInt) < 0) {
				exit(-1);
			}
			numbers.push_back(std::stoi(toInt));
			toInt.clear();
		}
		else {
			toInt += input[i];
		}
	}
	numbers.push_back(std::stoi(toInt));
	std::cout << toStraight(numbers);
	return 0;
}