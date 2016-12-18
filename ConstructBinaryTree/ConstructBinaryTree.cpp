// ConstructBinaryTree.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include <vector>
using namespace std;


 struct TreeNode {

     int val;

     TreeNode *left;

    TreeNode *right;

     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 };



class Solution {

public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int inlen = vin.size();
		int prelen = pre.size();
		if (inlen == 0)
			return NULL;
		if (prelen != inlen)
			return NULL;
		vector<int> left_pre, right_pre, left_in, right_in;
		//创建根节点，根节点肯定是前序遍历的第一个数
		TreeNode* head = new TreeNode(pre[0]);
		//找到中序遍历根节点所在位置,存放于变量gen中
		int gen = 0;
		for (int i = 0; i<inlen; i++)
		{
			if (vin[i] == pre[0])
			{
				gen = i;
				break;
			}
		}
		//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
		//利用上述这点，对二叉树节点进行归并
		for (int i = 0; i<gen; i++)
		{
			left_in.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);//前序第一个为根节点
		}
		for (int i = gen + 1; i<inlen; i++)
		{
			right_in.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}
		//和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
	//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
		head->left = reConstructBinaryTree(left_pre, left_in);
		head->right = reConstructBinaryTree(right_pre, right_in);
		return head;
	}

};
void main()
{
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	TreeNode* node;
	Solution so;
	node = so.reConstructBinaryTree(pre, vin);
}