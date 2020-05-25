#include<iostream>
#include<vector>
#include<random>
using namespace std;

void swap(vector<int>& nums, int m, int n);
int randRange(int low, int high);
int partition(vector<int>& nums, int low, int high);
int partition1(vector<int>& nums, int low, int high);

//快速排序主体
void quicksort(vector<int>& nums, int low, int high) {
	if (low >= high) return;//如果只剩下一个元素，返回
	int p = partition1(nums, low, high);//找到分割点，左半部分都不比它大，右半部分都比它大
	quicksort(nums, low, p - 1);//递归
	quicksort(nums, p + 1, high);
}

//针对数组，将指定的两个坐标对应的数交换
inline void swap(vector<int> &nums, int m, int n) {
	std::swap(nums[m], nums[n]);
}
//从指定的范围，随机选取一个整数
inline int randRange(int low, int high) {
	uniform_int_distribution<int> u(low, high);
	default_random_engine e;//生成无符号随机整数
	return u(e);
}
//使得被选出的基准值，都是当前子数组中的中间数
inline int partition(vector<int> &nums, int low, int high) {
	swap(nums, randRange(low, high), high);//避免最糟糕的情况出现，随机选值放到最右端
	int i=0, j=0;
	for (i = low, j = low;j < high;++j) {
		if (nums[j] <= nums[high]) {
			swap(nums, i++, j);
		}
	}
	swap(nums, i, j);
	return i;
}

/*不大靠谱*/
//集成版的partion
int partition1(vector<int>& nums, int low, int high) {
	
	uniform_int_distribution<int> u(low, high);
	default_random_engine e;//生成无符号随机整数
	std::swap(nums[u(e)], nums[high]);//避免最糟糕的情况出现，随机选值放到最右端
	int i = 0, j = 0;
	for (i = low, j = low;j < high;++j) {//从头到尾遍历每个数，但不遍历最后的基准值
		if (nums[j] <= nums[high]) {//如果发现当前数不大于基准值
			std::swap(nums[i++], nums[j]);//把这个不大于基准值的数与i位置上的数交换，同时i++
		}
	}//结束后，i之前的所有的数都不大于基准值，i之后所有的数都大于基准值；退出的时候j=high
	std::swap(nums[i], nums[j]);//把j位置的数（基准值）换到i位置上来
	return i;
}



/*靠谱的方法*/
void quicksort1(vector<int>& nums, int left, int right) {

	int i = left, j = right;

	if (left > right) return;//左已经跑到右了

	int target = nums[left];//以最左边的数为基准
	while (i < j) {
		while (nums[j] >= target && i < j) {//为了找到小于基准的数，就要略过不小于基准的数们
			j--;
		}

		while (nums[i] <= target && i < j) {//为了找到大于基准的数，就要略过不大于基准的数们
			i++;
		}

		if (i < j) {
			swap(nums[i], nums[j]);//一次交换两个数
		}
	}
	nums[left] = nums[i];
	nums[i] = target;

	quicksort1(nums, left, i - 1);
	quicksort1(nums, i + 1, right);
	return;
}

//打印数组
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
