#include<iostream>
#include<vector>

using namespace std;


//��ӡ����
void printVector(const vector<int>& a) {
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vi(100);
	vi={ 6, 3, 1, 7, 5, 8, 9, 2, 4 };

	auto head = vi.begin(), tail = vi.end();
	while (head < tail) {
		//��ӡ����Ԫ�أ����������
		cout << *head << " ";
		head++;

		//�Ѷ���Ԫ���Ƶ���β�����������
		if (head < tail) {
			vi.push_back(*head);//�����п���headΪ��
			tail = vi.end();
			head++;
		}
			
	}
	cout << endl;
	return 0;
}