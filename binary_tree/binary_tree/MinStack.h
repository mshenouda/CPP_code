#include "pch.h"
#pragma once
class MinStack
{
	std::vector<int> v;
	int minimum;

public:
	MinStack();
	void push(int x);
	void pop();
	int top();
	int getMin();
	~MinStack();
};

