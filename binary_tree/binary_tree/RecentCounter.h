#pragma once
class RecentCounter
{
	queue<int> recent;

public:
	RecentCounter();
	int ping(int t);
	~RecentCounter();
};

