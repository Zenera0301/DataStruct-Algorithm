#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high);//����

void sort(vector<int>& a, int low, int high) {
	if (low >= high) return;//���Ƿ�ֻʣ���һ��Ԫ����
	int mid = low + (high - low) / 2;//������ֳ���������
	sort(a, low, mid);//����һ��һ�𣬵ݹ�ذ��������������ź���
	sort(a, mid + 1, high);
	merge(a, low, mid, high);//���ź��������ϲ�����
}

void merge(vector<int> &nums, int low, int mid, int high) {
	vector<int> copy(nums);//������޸�ԭ����
	int k = low, i = low, j = mid + 1;//k��ʾ��ʲôλ�ÿ�ʼ�޸�ԭ�������飬i��ʾ���ߵ���ʼλ�ã�j��ʾ�Ұ�ߵ���ʼλ��

	while (k <= high) {
		if (i > mid) {//���ߵ�������������ˣ�ֻʣ�Ұ�ߵ�����ֻ����ұߵ������������ȥ������
			nums[k++] = copy[j++];
		}
		else if (j > high) {//�Ұ�ߵ�������������ˣ�ֻʣ���ߵ�����ֻ�����ߵ������������ȥ������
			nums[k++] = copy[i++];
		}
		else if (copy[j] < copy[i]) {//�ұߵ���С����ߵ��������ұߵ���������ȥһ��
			nums[k++] = copy[j++];
		}
		else {//��ߵ���С���ұߵ���������ߵ���������ȥһ��
			nums[k++] = copy[i++];
		}
	}
}



//��ӡ����
void printVector(const vector<int>& a) {
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	vector<int> a{ 5,6,4,2,3 };
	sort(a,0,a.size()-1);
	printVector(a);

	return 0;
}