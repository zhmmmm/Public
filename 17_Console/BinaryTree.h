#pragma once
#include <iostream>
#include <list>
using namespace std;
//==================二叉树
typedef struct stBinaryTreeNode
{
	char data;
	stBinaryTreeNode* father;
	stBinaryTreeNode* left;
	stBinaryTreeNode* right;
}BINTREENODE, *LPBINTREENODE;

template<typename Data>
class BinaryTree
{
public:
	LPBINTREENODE createTreeNode(Data data)
	{
		LPBINTREENODE node = new BINTREENODE;
		node->data = data;
		node->father = node->left = node->right = NULL;
		return node;
	}


	LPBINTREENODE cutTree(LPBINTREENODE node)
	{
		//做安全的判断
		if (node == NULL)
		{
			return NULL;
		}
		if (node->father != NULL)
		{
			//如果是左孩子
			if (node->father->left == node)
			{
				node->father->left = NULL;
			}
			else
			{
				node->father->right = NULL;
			}
			node->father = NULL;
		}
		return node;
	}


	LPBINTREENODE insertTree(LPBINTREENODE root, LPBINTREENODE node, bool insertleft = true)
	{
		if (root == NULL || node == NULL)
			return NULL;

		//将要插入的位置砍树操作

		LPBINTREENODE beCutTreeNode = NULL;
		if (insertleft)
		{
			beCutTreeNode = cutTree(root->left);
			root->left = node;
		}
		else
		{
			beCutTreeNode = cutTree(root->right);
			root->right = node;
		}
		node->father = root;
		return beCutTreeNode;
	}

	void rootFirstPrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;
		cout << node->data << " ";
		rootFirstPrint(node->left);
		rootFirstPrint(node->right);
	}
	void rootAfterPrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;
		rootAfterPrint(node->left);
		rootAfterPrint(node->right);
		cout << node->data << " ";
	}
	void rootMiddlePrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;
		rootMiddlePrint(node->left);
		cout << node->data << " ";
		rootMiddlePrint(node->right);
	}
	void layerViewPrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;

		list<LPBINTREENODE> NodeDeque;
		NodeDeque.push_back(node);

		while (!NodeDeque.empty())
		{
			LPBINTREENODE tempNode = NodeDeque.front();
			cout << tempNode->data << " ";
			if (tempNode->left)
			{
				NodeDeque.push_back(tempNode->left);
			}
			if (tempNode->right)
			{
				NodeDeque.push_back(tempNode->right);
			}
			NodeDeque.pop_front();
		}
	}

	void DeleteTree(LPBINTREENODE& root)
	{
		if (root == NULL)
			return;

		root = cutTree(root);

		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
		root = NULL;
	}

	LPBINTREENODE CopyTree(LPBINTREENODE root)
	{
		if (root == NULL)
			return NULL;

		LPBINTREENODE node = createTreeNode(root->data);

		node->left = CopyTree(root->left);
		if (node->left)
		{
			node->left->father = node;
		}
		node->right = CopyTree(root->right);
		if (node->right)
		{
			node->right->father = node;
		}
		return node;
	}
};

//二叉树的大小

//二叉树的深度
