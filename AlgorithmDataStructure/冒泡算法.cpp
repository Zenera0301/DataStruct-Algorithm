#include<iostream>
#include<vector>

using namespace std;

//冒泡算法原始
void bubbleSort(vector<int> & a) {
    int n = a.size();

    for (int i = 0;i < n - 1;++i) { 
        for (int j = 0;j < n - i - 1;++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }    
}

//冒泡算法改进1-增加flag，减少不必要的循环
void bubbleSort1(vector<int>& a) {
    int n = a.size();
    for (int i = 0;i < n - 1;++i) {
        bool sorted = true;//可以放到循环体外面，只要检测到一次sorted为true，说明整趟走下来，没有发生交换
        for (int j = 0;j < n - i - 1;++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sorted = false;//如果发生数据交换，说明数组无序
            }
        }
        if (sorted) {//数组有序
            break;
        }
    }
}
//冒泡算法改进2-采用双向冒泡，正向冒泡冒出最大值，反向冒泡冒出最小值
void bubbleSort2(vector<int> &a) {
    int n = a.size();
    int low = 0, high = n - 1;
    while (low < high) {//排序区间[low,high]
        int flag = 0;//标志点
        for (int i = low; i < high; ++i) {//第1次,正向冒泡
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = i;
            }
        }
        high = flag;//表示标志点之后的元素已经排好，区间右值缩小
        for (int i = high; i > low; --i) {//第2次,反向冒泡
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                flag = i;
            }
        }
        low = flag;//表示断点之前的元素已经排好，区间左值缩小 
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
    bubbleSort(a);
    printVector(a);

    system("pause");
    return 0;
}


//当需要记录一个字符串作为数字的标记的时候
//struct student {
//    string name;
//    int score;
//};
//
//int main() {
//    vector<student> vs{ {"zhang1",23},{"zhang4",5},{"zhang3",7},{"zhang5",2},{"zhang2",9} };//5个学生信息
//    int n = vs.size();
//    for (int i = 0;i < n - 1;++i) {
//        for (int j = 0;j < n - i - 1;++j) {
//            if (vs[j].score < vs[j + 1].score) {
//                swap(vs[j], vs[j + 1]);
//            }
//        }
//    }
//    for (auto i : vs) {
//        cout << i.name<< endl;
//    }
//    return 0;
//}