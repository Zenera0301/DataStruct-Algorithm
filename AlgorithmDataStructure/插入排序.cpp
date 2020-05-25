#include<iostream>
#include<vector>

using namespace std;

//����ʵ��
void insertSort(vector<int>& a) {
    for (int i = 1;i < a.size();++i) {
        int j = i - 1;//j��ʼ��Ϊ���������һ������Ҳ����������ǰһ����
        int val = a[i];//Ҫ���뵽ǰ������������������
        while (j >= 0 && a[j] > val) {//�в����Ҫ
            a[j + 1] = a[j];//���������ֺ��ƣ���������λ��
            --j;
        }
        a[j + 1] = val;//�ڳ��ĺ��ʵ�λ�þ���j+1��Ӧ��λ��
    }
}

//�㷨�Ż�-ʹ�ö��ַ��ҵ����Ų����
void insertSort1(vector<int> &a) {
    int len = a.size();
    for (int i = 1; i < len; ++i) {
        int key = a[i];

        int left = 0, right = i - 1;
        while (left <= right) {//�������ڲ���λ��
            int middle = (left + right) / 2;
            if (a[middle] > key)
                right = middle - 1;
            else left = middle + 1;
        }
        for (int j = i - 1; j >= left; --j) {
            a[j + 1] = a[j];
        }

        a[left] = key;//leftΪ��Ԫ��Ҫ�����λ��
    }
}


//��ӡ����
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


