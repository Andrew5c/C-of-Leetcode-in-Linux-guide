/**
* Copyright(c)
* All rights reserved.
* Author : Andrew Q.
* Date : 2020-09-12-08.17.20
* Description : ����ָ��ʹ����ϵ
*/
#include<iostream>
#include<vector>
using namespace std;

/*
* ���涨������������еĺ���
* ���ǵķ���ֵ�Ͳ����б���ͬ
* �����������ú���ָ��ȷ��ʹ���ĸ�����
*/
const vector<int>* fibo(int num)
{
    const int MAX_SIZE = 1024;
    static vector<int> elem;

    if(num<0 || num > MAX_SIZE){
        cout << "error..." << endl;
        return 0;
    }
    for(int i=elem.size(); i<num; i++){
        if(i==0 || i==1)
            elem.push_back(1);
        else
            elem.push_back(elem[i-1]+elem[i-2]);
    }
    return &elem;
}

const vector<int>* square(int num)
{
    const int MAX_SIZE = 1024;
    static vector<int> elem;

    if(num<0 || num > MAX_SIZE){
        cout << "The num is too big or negative..." << endl;
        return 0;
    }
    for(int i=elem.size(); i<num; i++){
        elem.push_back(i*i);
    }
    return &elem;
}

/*
* ����ĳ��������ָ��λ�õ��Ǹ���
* ���ú���ָ��ȷ��ʹ���ĸ�����
*/
bool seqElem(int pos, int &num, const vector<int>* (*ptr)(int)=NULL)
{
    if(ptr == NULL){
        num = 0;
        cout << "The function point to NULL...";
        return false;
    }
    const vector<int> *seq = ptr(pos);
    if(seq == NULL){
        num = 0;
        return false;
    }
    num = (*seq)[pos-1];
    return true;
}

int main(){
    // ���ȶ���һ������ָ�����飬����������õ��ĺ����ĵ�ַ����������
    // ע�������������ͨ���鶨�������
    const vector<int>* (*funList[])(int) = {fibo, square};
    string nameList[] = {"Fibonicca", "Square"};
    enum funIndex{
        nsFibo, nsSquare
    };
    int myVal;
    const int myPos = 3;
    // ���������ѡ���Լ���Ҫʹ�õ�����
    funIndex myIndex = nsSquare;

    if(!seqElem(myPos, myVal, funList[myIndex]))
       return 0;
    cout << "The " << nameList[myIndex] << " list in position " << myPos << " is: " \
        << myVal << endl;
    return 0;
}
