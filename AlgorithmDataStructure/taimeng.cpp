#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n=5, m=3;//n�У�ÿ��m������
	cin >> n >> m;

	vector<vector<int>> nums;
	for (int i = 0;i < n; ++i) {//n��
		for (int j = 0;j < m;++j) {//m��
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
	
	for (int i = 0;i < n-1; ++i) {//n�й���Ƚ�n-1��
		vector<int> numsi = nums[i];//ÿ�ζ�ȡ����i�У���ʣ�µ��н��бȽ�
		for (int k = i+1;k < n;++k) {
			vector<int> numsk = nums[k];
			int j = 1;
			int sum = numsi[0] + numsk[0];//Ӧ�ö�Ϊsum�Ŷ�
			for (j = 1;j < m;++j) {//��m�У�����ʣ�µ��У������Ƿ����sum
				if (numsi[j] + numsk[j] != sum) {
					break;//���в��ٿ���
				}
			}
			if (j == m) {
				++total;//����һ��
			}
		}
	}
	cout << total << endl;
	return 0;
}