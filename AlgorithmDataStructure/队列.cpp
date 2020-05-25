#include<iostream>
#include<vector>

using namespace std;


//打印数组
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
		//打印队首元素，并将其出队
		cout << *head << " ";
		head++;

		//把队首元素移到队尾，并将其出队
		if (head < tail) {
			vi.push_back(*head);//这里有可能head为空
			tail = vi.end();
			head++;
		}
			
	}
	cout << endl;
	return 0;
}