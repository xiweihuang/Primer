/**********

【拓扑排序】


**********/


#include <iostream>

using namespace std;


// 结点数为n，用邻接矩阵gragh[n][n]存储边权
// 用indegree[n]存储每个结点的入度
void topologic(int* toposort)
{
	int cnt = 0;  // 当前拓扑排序列表中有多少结点
	queue<int> q;  // 保存入度为0的结点：还可以用栈甚至随机取
	for (int i = 0; i < n; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();  // 当前入度为0的结点
		q.pop();
		toposort[cnt++] = cur;
		for (int i = 0; i < n; ++i) {
			if (gragh[cur][i] != 0) {
				indegree[i]--;
				if (indegree[i] == 0)
					q.push(i);
			}
		}
	}
}

int main()
{

	return 0;
}


