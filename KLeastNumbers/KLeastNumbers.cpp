// KLeastNumbers.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <set>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len) return vector<int>();

		//�º����е�greater<T>ģ�壬�Ӵ�С����
		multiset<int, greater<int> > leastNums;
		vector<int>::iterator vec_it = input.begin();
		for (; vec_it != input.end(); vec_it++)
		{
			//��ǰk��Ԫ�ز��뼯��
			if (leastNums.size()<k)
				leastNums.insert(*vec_it);
			else
			{
				//��һ��Ԫ�������ֵ
				multiset<int, greater<int> >::iterator greatest_it = leastNums.begin();
				//�������Ԫ��<��һ��Ԫ�أ�ɾ����һ�������뵱ǰԪ��
				if (*vec_it<*(leastNums.begin()))
				{
					leastNums.erase(greatest_it);
					leastNums.insert(*vec_it);
				}
			}
		}

		return vector<int>(leastNums.begin(), leastNums.end());
	}
};
void main()
{
	vector<int> input = { 4,5,1,6,2,7,3,8 };
	Solution aaa;
	vector<int> aa = aaa.GetLeastNumbers_Solution(input, 4);
}