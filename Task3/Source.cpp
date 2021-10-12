#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>


void minimum(std::vector<int> chain, int& indx, int& min) {
	min = chain[0];
	int indxCount = 0;
	indx = 0;
	for (auto& i : chain) {
		if (min > i) {
			min = i;
			indx = indxCount;
		}
		indxCount++;
	}
}

void maximum(std::vector<int> chain, int& indx, int& max) {
	max = chain[0];
	int indxCount = 0;
	indx = 0;
	for (auto& i : chain) {
		if (max < i) {
			max = i;
			indx = indxCount;
		}
		indxCount++;
	}
}

int toStraight(std::vector<int> chain) {
	int indxCount = 0;
	int min;
	int indx = 0; 
	minimum(chain, indx, min);
	if (min == 0) {
		chain.erase(chain.begin() + indx);
		if (chain.size() != 0) {//If was one element
			indx = 0;
			minimum(chain, indx, min);
		}
	}
	else if (min >= chain.size()) {
		return chain.size() - 1;
	}
	else if (min == chain.size() - 2 || min == chain.size() - 1) {
		return min;
	}
	else {
		int max, indxMax;
		chain.erase(chain.begin() + indx);
		auto sum_max = 0;
		if (chain.size() != 0) {
		for (int i = 0; i < min; i++) {  //min = size of vector - 1 because we can`t move to this line if it more
			maximum(chain, indxMax, max);
			sum_max += max;
			chain.erase(chain.begin() + indxMax);
		}
		chain.push_back(sum_max); // merge
		}
		return min + toStraight(chain);
	}
	return 0;
}
