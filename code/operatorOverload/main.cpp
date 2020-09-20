/*************************************************************************
	> File Name: main.cpp
	> Author: Andrew. Q
	> Describe:
	> Created Time: 2020��09��18�� ������ 10ʱ24��26��
 ************************************************************************/

#include<iostream>
#include"Triangular.h"
using namespace std;

int main() {
    Triangular trian(9, 1);
    Triangular::iterator it = trian.begin();
    Triangular::iterator end_it = trian.end();

    while(it != end_it){
        cout << *it << ' ';
        ++it;
    }
    cout << endl;

	return 0;
}

