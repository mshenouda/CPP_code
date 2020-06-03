#include "pch.h"
#include "Tree.h"
#include <time.h>

TreeNode* Tree::buildBinaryTree(vector<int>& nums)
{
	if (nums.empty())
		return NULL;

	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
		{	root = new TreeNode(nums[i]);
			treeBuffer.push_back(root);
			++treeLevel;
		}
		else
			addNode(nums, i);	

		++numNodes;
		computeLevel(i);
	}
	return root;
}


//Add Nodes
void Tree::addNode(vector<int>& nums, int index)
{
	if (treeBuffer.empty())
		return;

	TreeNode* dummy = treeBuffer.front();
	if (dummy == NULL)
		return;
	else if (index % 2 == 1)
	{	dummy->left = new TreeNode(nums[index]);
		treeBuffer.push_back(dummy->left);
		return;
	}
	else if (index % 2 == 0)
	{	dummy->right = new TreeNode(nums[index]);
		treeBuffer.push_back(dummy->right);
		treeBuffer.pop_front();
	}
}

void Tree::printNodes()
{
	if(this == NULL)	
	{ 	cerr << "Empty Tree, can't print " << endl; 
		return;
	}
	
	cout << " Printing the tree " << endl;
	if (treeLevel == 0)
	{	cout << root->val << " ";
		return;
	}

	
	treeBuffer.clear();
	treeBuffer.push_back(root);
	TreeNode* curr;
	do 
	{	
		curr = treeBuffer.front();
		cout << curr->val << " ";
		if (curr->left)
			treeBuffer.push_back(curr->left);

		if (curr->right)
			treeBuffer.push_back(curr->right);
		
		treeBuffer.pop_front();
	}
	while (!treeBuffer.empty());
}

void Tree::computeLevel(int index)
{
	int lowerBound = (int)pow(2, treeLevel) - 1; 
	int upperBound = (int)pow(2, treeLevel + 1) - 1;
	if (lowerBound<= index && index < upperBound)
		++treeLevel;
}

void Tree::printLevel()
{
	cout << " Tree Depth = " << treeLevel<<endl;
}

Tree::Tree()
{
	root = NULL;
	treeLevel = 0;
	numNodes = 0;
}


Tree::~Tree()
{
}

void Tree::computeNodes()
{
	cout << " Num of nodes = " << numNodes <<" treeLevel = "<<treeLevel<<endl;
	return;
}

bool Tree::isSymmetric(TreeNode* myRoot) {

	if (myRoot == nullptr)
		return false;
	
	//only one root



	if ((!myRoot->left) && (!myRoot->right))
		return true;
	
	deque<TreeNode*> tmpBuffer;
	tmpBuffer.clear();

	stack<int> myValues;
	tmpBuffer.push_back(myRoot);
	do 
	{
		TreeNode* curr = tmpBuffer.front();	
		if (curr)
		{	if (myValues.empty())
				myValues.push(curr->val);
			else if (curr->val == myValues.top())
				myValues.pop();
			else
				myValues.push(curr->val);
		}
		
		if (curr->left)
			tmpBuffer.push_back(curr->left);
		else if (curr->right)
			myValues.push(1000);

		if (curr->right)
			tmpBuffer.push_back(curr->right);
		else if (curr->left)
			myValues.push(1000);
			
		//pop buffer
		tmpBuffer.pop_front();
	} while(!tmpBuffer.empty());
	
	cout << myValues.size() << endl;
	return (myValues.size() == 1);
}

