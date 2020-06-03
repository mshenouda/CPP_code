#include "pch.h"
#include <vector>
#include <queue>
#pragma once

using namespace std;

//creating templates for the data types in the linkList typename
//template<typename T1, typename T2, typename T3>


//Single list linkLists
struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};



class linkList
{	
	private:
		ListNode* head; 
		ListNode* prev;
		ListNode* curr;

	public:	
		linkList();
		//Linked List
		ListNode* buildList(std::vector<int>&);
		void printList();
		~linkList();
};

