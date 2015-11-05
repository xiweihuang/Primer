/**********

【根据前序中序，计算后序】
已知某二叉树的遍历结果如下，求它的后序遍历序列
前序遍历：GDAFEMHZ
中序遍历：ADEFGHMZ

**********/

void PreInToPost(const vector<int>& preVec, int from1, int to1, const vector<int>& inVec, int from2, int to2)
{
	int root = preVec[from1];

	int pos = from2;
	for (int i = from2; i <= to2; ++i) {
		if (inVec[i] == root) {
			pos = i;
			break;
		}
	}

	int len = i - from2;

	PreInToPost(preVec, from1 + 1, from1 + len, inVec, from2, i);
	PreInToPost(preVec, )
}

