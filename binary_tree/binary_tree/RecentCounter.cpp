#include "pch.h"
#include "RecentCounter.h"

RecentCounter::RecentCounter()
{

}

int RecentCounter::ping(int t) {

	if ((t - recent.front() < 3000) && (t > 3000))
		recent.push(t);
	return recent.size();
}

RecentCounter::~RecentCounter()
{
}
