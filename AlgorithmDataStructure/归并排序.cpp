#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high);//声明

void sort(vector<int>& a, int low, int high) {
	if (low >= high) return;//看是否只剩最后一个元素了
	int mid = low + (high - low) / 2;//把数组分成左右两半
	sort(a, low, mid);//与下一句一起，递归地把数组左右两半排好序
	sort(a, mid + 1, high);
	merge(a, low, mid, high);//把排好序的数组合并起来
}

void merge(vector<int> &nums, int low, int mid, int high) {
	vector<int> copy(nums);//后面会修改原数组
	int k = low, i = low, j = mid + 1;//k表示从什么位置开始修改原来的数组，i表示左半边的起始位置，j表示右半边的起始位置

	while (k <= high) {
		if (i > mid) {//左半边的数都处理完毕了，只剩右半边的数。只需把右边的数逐个拷贝上去就行了
			nums[k++] = copy[j++];
		}
		else if (j > high) {//右半边的数都处理完毕了，只剩左半边的数。只需把左边的数逐个拷贝上去就行了
			nums[k++] = copy[i++];
		}
		else if (copy[j] < copy[i]) {//右边的数小于左边的数，将右边的数拷贝上去一个
			nums[k++] = copy[j++];
		}
		else {//左边的数小于右边的数，将左边的数拷贝上去一个
			nums[k++] = copy[i++];
		}
	}
}



//打印数组
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