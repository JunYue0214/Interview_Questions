// QueueWithTwoStacks.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include <stack>
#include <exception>
using namespace std;
class Solution
{
public:
	void push(int node) {
		stack1.push(node);

	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int a = stack1.top();
				stack1.pop();
				stack2.push(a);

			}
		}
		int b = stack2.top();
		stack2.pop();
		return b;

	}
			

	

private:
	stack<int> stack1;
	stack<int> stack2;
};
void main()
{



}