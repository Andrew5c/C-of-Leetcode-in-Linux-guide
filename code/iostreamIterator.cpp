/**
* Copyright(c)
* All rights reserved.
* Author : Andrew Q.
* Date : 2020-09-14-07.56.23
* Description : ��������������ĵ�����
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void iostreamIterator_v1()
{
    string word;
    vector<string> input;

    // �˴������ֹ��
    while(cin >> word)
        input.push_back(word);

    sort(input.begin(), input.end());

    for(int i=0; i<input.size(); i++){
        cout << input[i] << ' ';
    }
    return;
}

int main(){

    iostreamIterator_v1();

    return 0;
}
