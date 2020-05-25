#include<iostream>
#include<vector>

using namespace std;

//基本实现
void insertSort(vector<int>& a) {
    for (int i = 1;i < a.size();++i) {
        int j = i - 1;//j初始化为有序区最后一个数，也是无序区的前一个数
        int val = a[i];//要插入到前面有序区的数，备份
        while (j >= 0 && a[j] > val) {//有插入必要
            a[j + 1] = a[j];//有序区数字后移，给新数腾位置
            --j;
        }
        a[j + 1] = val;//腾出的合适的位置就是j+1对应的位置
    }
}

//算法优化-使用二分法找到最优插入点
void insertSort1(vector<int> &a) {
    int len = a.size();
    for (int i = 1; i < len; ++i) {
        int key = a[i];

        int left = 0, right = i - 1;
        while (left <= right) {//在区间内查找位置
            int middle = (left + right) / 2;
            if (a[middle] > key)
                right = middle - 1;
            else left = middle + 1;
        }
        for (int j = i - 1; j >= left; --j) {
            a[j + 1] = a[j];
        }

        a[left] = key;//left为新元素要插入的位置
    }
}


//打印数组
void printVector(const vector<int>& a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    vector<int> a{ 5,6,4,2,3 };
    insertSort1(a);
    printVector(a);
    return 0;
}


