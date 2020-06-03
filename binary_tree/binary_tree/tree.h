#pragma once
#include "pch.h"
#include <stdlib.h>
#include <vector>
#include <deque>
#include <iostream>

//ListNodes with left and right pointers
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

//template <typename T1, typename T2, typename T3>
class Tree 
{
	private:
		TreeNode* root;	
		int numNodes;
		int treeLevel;
		deque<TreeNode*> treeBuffer;

	public:
		Tree();

		//Binary Tree
		TreeNode* buildBinaryTree(std::vector<int>&);
		void addNode(vector<int>&, int);
		void printNodes();
		void printLevel();
		void computeLevel(int);
		void computeNodes();
		bool isSymmetric(TreeNode* root);
		virtual ~Tree();
};


