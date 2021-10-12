#include "pch.h"
#include "../Task3/header.h"
#include <vector>
TEST(Chain, LastMin) {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(32);
	vec.push_back(45);
	vec.push_back(4);
	EXPECT_EQ(toStraight(vec), 3);
}

TEST(Chain, OneElement) {
	std::vector<int> vec;
	vec.push_back(0);
	EXPECT_EQ(toStraight(vec), 0);
}

TEST(Chain, PreLast) {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(32);
	vec.push_back(3);
	vec.push_back(45);
	EXPECT_EQ(toStraight(vec), 3);
}

TEST(Chain, SameElements) {
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	EXPECT_EQ(toStraight(vec), 3);
}

