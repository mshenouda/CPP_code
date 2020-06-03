#include "pch.h"
#include "MinStack.h"
#include <algorithm>

MinStack::MinStack() {
}

void MinStack::push(int x) {

	if (v.empty())
		v.push_back(x);

	if (x < v.front())
		vector<int>::iterator it = v.insert(v.begin(), x);
	else
	{	if (x <= v.front())
			minimum = x;
		v.push_back(x);
	}
}

void MinStack::pop() {
	

	vector<int>::iterator it = find(v.begin(), v.end(), minimum);
	if (it == v.begin())
		it = v.erase(v.begin());
	else if (it == v.end()-1)
	{	int min = v.back();
		vector<int>::iterator it = v.erase(v.end() - 1);
		v.insert(v.begin(), min);
	} else if (it != v.end()) // minimum in between
		it = v.erase(v.end() - 1);

	it = find(v.begin(), v.end(), minimum);
	if (it == v.end())
		minimum = v.front();
}

int MinStack::top() {
	return v.back();
}

int MinStack::getMin() {
	return (v.front() <v.back()? v.front(): v.back());
}

MinStack::~MinStack()
{
}
