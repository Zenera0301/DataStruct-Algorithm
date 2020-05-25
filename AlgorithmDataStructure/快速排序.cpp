#include<iostream>
#include<vector>
#include<random>
using namespace std;

void swap(vector<int>& nums, int m, int n);
int randRange(int low, int high);
int partition(vector<int>& nums, int low, int high);
int partition1(vector<int>& nums, int low, int high);

//������������
void quicksort(vector<int>& nums, int low, int high) {
	if (low >= high) return;//���ֻʣ��һ��Ԫ�أ�����
	int p = partition1(nums, low, high);//�ҵ��ָ�㣬��벿�ֶ����������Ұ벿�ֶ�������
	quicksort(nums, low, p - 1);//�ݹ�
	quicksort(nums, p + 1, high);
}

//������飬��ָ�������������Ӧ��������
inline void swap(vector<int> &nums, int m, int n) {
	std::swap(nums[m], nums[n]);
}
//��ָ���ķ�Χ�����ѡȡһ������
inline int randRange(int low, int high) {
	uniform_int_distribution<int> u(low, high);
	default_random_engine e;//�����޷����������
	return u(e);
}
//ʹ�ñ�ѡ���Ļ�׼ֵ�����ǵ�ǰ�������е��м���
inline int partition(vector<int> &nums, int low, int high) {
	swap(nums, randRange(low, high), high);//����������������֣����ѡֵ�ŵ����Ҷ�
	int i=0, j=0;
	for (i = low, j = low;j < high;++j) {
		if (nums[j] <= nums[high]) {
			swap(nums, i++, j);
		}
	}
	swap(nums, i, j);
	return i;
}

/*������*/
//���ɰ��partion
int partition1(vector<int>& nums, int low, int high) {
	
	uniform_int_distribution<int> u(low, high);
	default_random_engine e;//�����޷����������
	std::swap(nums[u(e)], nums[high]);//����������������֣����ѡֵ�ŵ����Ҷ�
	int i = 0, j = 0;
	for (i = low, j = low;j < high;++j) {//��ͷ��β����ÿ�����������������Ļ�׼ֵ
		if (nums[j] <= nums[high]) {//������ֵ�ǰ�������ڻ�׼ֵ
			std::swap(nums[i++], nums[j]);//����������ڻ�׼ֵ������iλ���ϵ���������ͬʱi++
		}
	}//������i֮ǰ�����е����������ڻ�׼ֵ��i֮�����е��������ڻ�׼ֵ���˳���ʱ��j=high
	std::swap(nums[i], nums[j]);//��jλ�õ�������׼ֵ������iλ������
	return i;
}



/*���׵ķ���*/
void quicksort1(vector<int>& nums, int left, int right) {

	int i = left, j = right;

	if (left > right) return;//���Ѿ��ܵ�����

	int target = nums[left];//������ߵ���Ϊ��׼
	while (i < j) {
		while (nums[j] >= target && i < j) {//Ϊ���ҵ�С�ڻ�׼��������Ҫ�Թ���С�ڻ�׼������
			j--;
		}

		while (nums[i] <= target && i < j) {//Ϊ���ҵ����ڻ�׼��������Ҫ�Թ������ڻ�׼������
			i++;
		}

		if (i < j) {
			swap(nums[i], nums[j]);//һ�ν���������
		}
	}
	nums[left] = nums[i];
	nums[i] = target;

	quicksort1(nums, left, i - 1);
	quicksort1(nums, i + 1, right);
	return;
}

//��ӡ����
void printVector(const vector<int>& a) {
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	vector<int> a{ 4,2,5,3,1 };
	quicksort1(a, 0, a.size() - 1);
	printVector(a);
	return 0;
}
