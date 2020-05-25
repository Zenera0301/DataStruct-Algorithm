#include<iostream>
#include<vector>

using namespace std;

//int main() {
//	vector<int> vi(11, 0);//11个桶，相应的桶编号出现次数均为0
//
//	vector<int> v{5,3,5,2,8};
//	for (auto i : v) {//v中出现的每个数，扔进vi的桶里
//		++vi[i];
//	}
//
//	for (int i = 10;i >= 0;--i) {//从10-0遍历
//		for (int j = 0;j < vi[i];++j) {//出现几次打印几次，没出现就不打印
//			cout << i << endl;
//		}
//	}
//
//	return 0;
//}

//桶排序解决去重---》排序的功能
int main() {
	vector<int> vi(1000,0);//1000个0
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