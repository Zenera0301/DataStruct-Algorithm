#include<iostream>
#include<vector>

using namespace std;

//int main() {
//	vector<int> vi(11, 0);//11��Ͱ����Ӧ��Ͱ��ų��ִ�����Ϊ0
//
//	vector<int> v{5,3,5,2,8};
//	for (auto i : v) {//v�г��ֵ�ÿ�������ӽ�vi��Ͱ��
//		++vi[i];
//	}
//
//	for (int i = 10;i >= 0;--i) {//��10-0����
//		for (int j = 0;j < vi[i];++j) {//���ּ��δ�ӡ���Σ�û���־Ͳ���ӡ
//			cout << i << endl;
//		}
//	}
//
//	return 0;
//}

//Ͱ������ȥ��---������Ĺ���
int main() {
	vector<int> vi(1000,0);//1000��0
	int n;
	for (int i = 0;i < 10;++i) {
		cin >> n;
		vi[n] = 1;
	}
	for (int i = 0;i < 1000;++i) {

		if (vi[i] == 1) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}