/**********

【子集和数问题N-Sum--递归】
已知数组A[0...N-1]，给定某数值sum，找出数组中的若干个数，使得这些数的和为sum。

**********/


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(vector<int>& v, int s) : vc(v), sum(s) {}

	// 输出
	void Print(vector<bool>& x)
	{
		for (int i = 0; i < x.size(); ++i) {
			if (x[i]) {
				cout << vc[i] << ' ';
			}
		}
		cout << endl;
	}

	void NSum()
	{
		vector<bool> xx;
		int residue = 0;
		for (int i = 0; i < vc.size(); ++i) {
			xx.push_back(false);
			residue += vc[i];
		}
		FindNumBySum(xx, 0, 0, residue);
	}

	void FindNumBySum(vector<bool>& x, int curIdx, int curSum, int residue)
	{
		if (curIdx >= vc.size()) {
			return;
		}

		if (curSum + vc[curIdx] == sum) {
			x[curIdx] = true;
			Print(x);
			x[curIdx] = false;
		} else if (curSum + residue >= sum && curSum + vc[curIdx] <= sum) {
			// 假设curIdx为true，做一下递归
			x[curIdx] = true;
			FindNumBySum(x, curIdx + 1, curSum + vc[curIdx], residue - vc[curIdx]);
		}

		if (curSum + residue - vc[curIdx] >= sum) {
			// 假设curIdx为false，做一下递归
			x[curIdx] = false;
			FindNumBySum(x, curIdx + 1, curSum, residue - vc[curIdx]);
		}
	}

private:
	int sum;
	const vector<int>& vc;
};


int main()
{
	vector<int> v = {1, 2, 3, 4, 5};
	Solution s(v, 10);
	s.NSum();
	return 0;
}


