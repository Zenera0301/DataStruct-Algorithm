#include<iostream>
#include<vector>

using namespace std;

//ð���㷨ԭʼ
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

//ð���㷨�Ľ�1-����flag�����ٲ���Ҫ��ѭ��
void bubbleSort1(vector<int>& a) {
    int n = a.size();
    for (int i = 0;i < n - 1;++i) {
        bool sorted = true;//���Էŵ�ѭ�������棬ֻҪ��⵽һ��sortedΪtrue��˵��������������û�з�������
        for (int j = 0;j < n - i - 1;++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sorted = false;//����������ݽ�����˵����������
            }
        }
        if (sorted) {//��������
            break;
        }
    }
}
//ð���㷨�Ľ�2-����˫��ð�ݣ�����ð��ð�����ֵ������ð��ð����Сֵ
void bubbleSort2(vector<int> &a) {
    int n = a.size();
    int low = 0, high = n - 1;
    while (low < high) {//��������[low,high]
        int flag = 0;//��־��
        for (int i = low; i < high; ++i) {//��1��,����ð��
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = i;
            }
        }
        high = flag;//��ʾ��־��֮���Ԫ���Ѿ��źã�������ֵ��С
        for (int i = high; i > low; --i) {//��2��,����ð��
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                flag = i;
            }
        }
        low = flag;//��ʾ�ϵ�֮ǰ��Ԫ���Ѿ��źã�������ֵ��С 
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
    bubbleSort(a);
    printVector(a);

    system("pause");
    return 0;
}


//����Ҫ��¼һ���ַ�����Ϊ���ֵı�ǵ�ʱ��
//struct student {
//    string name;
//    int score;
//};
//
//int main() {
//    vector<student> vs{ {"zhang1",23},{"zhang4",5},{"zhang3",7},{"zhang5",2},{"zhang2",9} };//5��ѧ����Ϣ
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