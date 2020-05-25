#include<iostream>
#include<string>
using namespace std;


/*************************最基本的二分查找*********************************/

int BinarySearchUp(int * nums,int numslen,int key){//针对升序数组,非递归实现
	int high, low, mid;
	high = numslen - 1;
	low = 0;
	while (low <= high){
		mid = high - (high - low) / 2;//更新mid的位置
		if (key == nums[mid]){//找到了
			return mid;
		}
		else if (key < nums[mid]){//key在左半边
			high = mid - 1;
		}
		else{//key在右半边
			low = mid + 1;
		}
	}
	return -1;
}

int BinarySearchDown(int * nums, int numslen, int key){//针对降序数组，非递归实现
	int high, low, mid;
	high = numslen - 1;
	low = 0;
	while (low <= high){
		mid = high - (high - low) / 2;//更新mid的位置
		if (key == nums[mid]){//找到了
			return mid;
		}
		else if (key < nums[mid]){//key在右半边
			low = mid + 1;
		}
		else{//key在左半边
			high = mid - 1; 
		}
	}
	return -1;
}

int BinarySearchUpRecursive(int * nums, int low, int high, int key){//针对升序数组，采用递归实现
	//边界条件判断
	if (low > high){
		return -1;
	}

	int mid = low + (high - low) / 2;//计算mid的位置
	if (key == nums[mid]){//找到了
		return mid;
	}
	else if (key > nums[mid]){//key在右半边
		return BinarySearchUpRecursive(nums, mid + 1, high, key);
	}
	else{//key在左半边
		return BinarySearchUpRecursive(nums, low, mid - 1, key);
	}
}


/*************************查找目标值区域的左边界*******************************************/
/*************************查找与目标值相等的第一个元素位置*********************************/
/*************************查找第一个不小于目标值的元素位置*********************************/


int BinarySearchLowerBound(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key <= nums[mid]){//不在右半边
			high = mid - 1;
		}
		else{//在右半边
			low = mid + 1;
		}
	}
	if (nums[low] == key){//low < numslen && 
		return low;
	}
	else{
		return -1;
	}
}

/*************************查找目标值区域的右边界*******************************************/
/*************************查找与目标值相等的最后一个元素位置*********************************/
/*************************查找第一个不大于目标值的元素位置*********************************/

int BinarySearchUpperBound(int * nums,int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key >= nums[mid]){//不在左侧
			low = mid + 1;
		}
		else{//在左侧
			high = mid - 1;
		}
	}
	if (key == nums[high]){ //high >= 0 &&
		return high;
	}
	else{
		return -1;
	}
}

/*************************查找第一个大于目标值的数*******************************************/
/*************************查找比目标值大但是最接近目标值的数*********************************/
/*
我们已经找到了最后一个不大于目标值的数，那么再往后进一位，
返回high + 1，就是第一个大于目标值的数。*/
int BinarySearchBiggerOne(int * nums,int numslen,int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key >= nums[mid]){//不在左边
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	if (high+1 < numslen && key == nums[high]){
		return high + 1;
	}
	else{
		return -1;
	}
}
/*************************查找最后一个小于目标值的数*******************************************/
/*************************查找比目标值小但是最接近目标值的数*********************************/
int BinarySearchLessOne(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key <= nums[mid]){//不在右边
			high = mid - 1;
		}
		else{//在右边
			low = mid + 1;
		}
	}
	if (low - 1 >= 0 && key == nums[low]){
		return low - 1;
	}
	else{
		return -1;
	}
}

/*************************查找旋转数组的最小值元素下标（假设不存在重复数字）*********************************/
int BinarySearchRotateMinUnique(int * nums, int numslen){
	int low = 0, high = numslen - 1, mid;
	while (low < high){
		mid = low + (high - low) / 2;
		if (nums[mid] > nums[high]){//说明最小值在右半边
			low = mid + 1;
		}
		else{//说明最小值不在右半边
			high = mid;
		}
	}
	return high;//此时low=high,写return high;一样的
}

/*************************查找旋转数组的最小值元素下标（假设存在重复数字）*********************************/
int BinarySearchRotateMinRepeated(int * nums, int numslen){
	int low = 0, high = numslen - 1, mid;
	while (low < high){
		mid = low + (high - low) / 2;
		if (nums[mid] > nums[high]){//最小值在右半边
			low = mid + 1;
		}
		else if (nums[mid] < nums[high]){//最小值不在右半边
			high = mid;
		}
		else{//最小值可能为当前值，也可能在左半边，也可能在右半边
			high--;//小步前进
		}
	}
	return low;
}

/*************************在旋转排序数组中搜索（假设不存在重复数字）*********************************/
int BinarySearchKeyInRotateUnique(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key == nums[mid]){
			return mid;
		}
		else if (nums[low] <= nums[mid]){//左半边是有序的
			if (key >= nums[low] && key < nums[mid]){//key在左半边
				high = mid - 1;
			}
			else{//key在右半边
				low = mid + 1;
			}
		}
		else if (nums[mid] <= nums[high]){//右半边是有序的
			if (key>nums[mid] && key <= nums[high]){//key在右半边
				low = mid + 1;
			}
			else{//key在左半边
				high = mid - 1;
			}
		}
	}
	return -1;
}
/*************************在旋转排序数组中搜索（假设存在重复数字）*********************************/
bool BinarySearchKeyInRotateRepeat(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key == nums[mid]){
			return true;
		}
		else if (nums[low] < nums[mid]){//左半边有序
			if (key >= nums[low] && key < nums[mid]){//key在左半边
				high = mid;
			}
			else{//key在右半边
				low = mid + 1;
			}
		}
		else if (nums[mid] < nums[high]){//右半边有序
			if (key > nums[mid] && key <= nums[high]){//key在右半边
				low = mid + 1;
			}
			else{//key在左半边
				high = mid;
			}
		}
		else {
			high--;
		}
	}
	return false;
}

int main(){
	int data[] = { 6, 5, 4, 3, 2, 1 };
	int data2[] = { 1, 2, 3, 4, 5, 6 };
	int data3[] = { 1, 3, 7, 7, 7, 14, 14, 14 };
	int data4[] = { 4, 5, 6, 7, 8, 1, 2, 3 };
	int data5[] = { 5, 5, 5, 6, 7,7,7, 8,8, 2, 2, 2, 3 };

	
	bool num = BinarySearchKeyInRotateRepeat(data5, 13, 2);//此种情况显示的是有或无
	
	cout << "Index of the number is " << num <<"."<<endl;
	system("pause");
	return 0;
}