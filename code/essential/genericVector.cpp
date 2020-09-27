/**
* Copyright(c)
* All rights reserved.
* Author : Andrew Q.
* Date : 2020-09-12-11.19.19
* Description : �Բ�ͬ�ķ�ʽʵ�֣���һ��vector����array�в���ĳ��ֵ
*/
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

// �����ǻ�����ʵ�ַ�ʽ
// �Ժ���ģ��ֱ�ʵ�ֶ�vector��array�Ĳ���
// ������ʵ�֣�ÿ������ֻ�����vector����array
template <typename T>
const T* myFind(const vector<T> &vec, int len, const T &num)
{
    if(vec.empty())
        return 0;
    for(int i=0; i<len; i++){
        if(vec[i] == num)
            return &vec[i];
    }
    return 0;
}
// �����صķ�ʽ����array�Ĳ��Һ���
template <typename T>
const T* myFind(const T arr[], int len, const T &num)
{
    if(!arr)
        return 0;
    for(int i=0; i<len; i++){
        if(arr[i] == num)
            return &arr[i];
    }
    return 0;
}

// �����ڶԵ�һ���������г���
// ��ָ��ȡ��������Ԫ�أ��ڽ��в���
template <typename T>
const T* myFindGeneric(const T* start, const T* over, const T &num)
{
    if(!start || !over)
        return 0;
    for(; start!=over; start++){
        if((*start) == num)
            return start;
    }
    return 0;
}
// ��Ϊvector�����ǿյģ�����vectorһ����������������һ��ʹ��
template <typename T>
inline const T* myBegin(const vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[0];
}
template <typename T>
inline const T* myEnd(const vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[vec.size()];
}

// ʹ�÷���ָ���ٴ�ʵ��find����
// ʵ�ֶ��������������͵ĸ���
template <typename iteratorType, typename elemType>
iteratorType findIterator(iteratorType first, iteratorType last, elemType &num)
{
    for(; first!=last; first++){
        if(*first == num)
            return first;
    }
    return last;
}


int main(){
    int myArr[] = {1, 2, 3, 4};
    vector<int> myVec(myArr, myArr+4);

    int searchVal = 3;

    const int *ptr1 = myFind(myArr, sizeof(myArr)/sizeof(myArr[0]), searchVal);
    cout << *ptr1 << endl;
    // ʹ�����غ������в���
    const int *ptr2 = myFind(myVec, myVec.size(), searchVal);
    cout << *ptr2 << endl;

    // ---------------------------------------------
    // ���Է��ͺ���
    const int *ptr3 = myFindGeneric(myBegin(myVec), myEnd(myVec), searchVal);
    cout << *ptr3 << endl;

    const int *ptr4 = myFindGeneric(&myArr[0], &myArr[4], searchVal);
    cout << *ptr4 << endl;

    // ---------------------------------------------
    // ����iterator����ķ��ͺ���
    vector<int>::iterator ans;
    ans = findIterator(myVec.begin(), myVec.end(), searchVal);
    cout << "use the iterator fun to find vector : " << *ans << endl;

    list<int> myLs(myArr, myArr+4);
    list<int>::iterator ans2;
    ans2 = findIterator(myLs.begin(), myLs.end(), searchVal);
    cout << "use the iterator fun to find list : " << *ans2 << endl;

    return 0;
}
