#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n=5, m=3;//n行，每行m个数字
	cin >> n >> m;

	vector<vector<int>> nums;
	for (int i = 0;i < n; ++i) {//n行
		for (int j = 0;j < m;++j) {//m列
			cin >> nums[i][j];
		}
	}

	//nums = {
	//	{2,11,21},
	//	{19,10,1},
	//	{20,11,1},
	//	{6,15,24},
	//	{18,27,36}
	//};

	int total = 0;
	
	for (int i = 0;i < n-1; ++i) {//n行共需比较n-1次
		vector<int> numsi = nums[i];//每次都取出第i行，与剩下的行进行比较
		for (int k = i+1;k < n;++k) {
			vector<int> numsk = nums[k];
			int j = 1;
			int sum = numsi[0] + numsk[0];//应该都为sum才对
			for (j = 1;j < m;++j) {//共m列，遍历剩下的列，看和是否等于sum
				if (numsi[j] + numsk[j] != sum) {
					break;//该行不再考虑
				}
			}
			if (j == m) {
				++total;//产生一行
			}
		}
	}
	cout << total << endl;
	return 0;
}