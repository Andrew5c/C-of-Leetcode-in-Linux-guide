/**
* Copyright(c)
* All rights reserved.
* Author : Andrew Q.
* Date : 2020-09-13-09.19.31
* Description : ʹ�÷����㷨�����fibonicca����������ĳ��ֵ
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

// ����vec��ǰ�Ĺ�ģ������num��ֵ�ķ�������
bool growVec(vector<int> &vec, int num)
{
    int i = vec.size();
    while(i<2){
        vec.push_back(1);
        i++;
    }
    while(vec[i-1] < num){
        vec.push_back(vec[i-1]+vec[i-2]);
        i++;
    }
    return vec[i-1]==num ? true : false;
}

bool isElem(vector<int> &vec, int num)
{
    vector<int>::iterator maxVal = max_element(vec.begin(), vec.end());
    if(*maxVal < num)
        return growVec(vec, num);

    // ��������Ҫ�������ö���Ҫ�Ǿ��������
    // ������ø��Ƶķ�ʽ���Ƚ��������鸴��һ�ݣ��ڽ�������
    vector<int> vecSorted(vec.size());
    copy(vec.begin(), vec.end(), vecSorted.begin());
    sort(vecSorted.begin(), vecSorted.end());
    return binary_search(vec.begin(), vec.end(), num);
}

int main(){
    int arr[] = {1,1};
    vector<int> fibo(arr, arr+2);
    if(isElem(fibo, 8)){
        cout << "Find it..." << endl;
        return 0;
    }
    cout << "No..." << endl;
    return 0;
}
