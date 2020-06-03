#include "pch.h"
#include "linkList.h"

//template<typename T1, typename T2, typename T3>
linkList::linkList()
{
	head = prev = curr = NULL;
}

ListNode* linkList::buildList(std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (!head)
		{	head = new ListNode(nums[i]);
			prev = head;
			continue;
		}

		curr = new ListNode(nums[i]);
		prev->next = curr;
		prev = curr;
	}
	return head;
}

void linkList::printList()
{
	curr = head;
	while (curr!=NULL)
	{	cout << curr->val << " ";
		curr = curr->next;
	};
	cout << endl << endl;
}

//template<typename T1, typename T2, typename T3>
linkList::~linkList()
{
}

