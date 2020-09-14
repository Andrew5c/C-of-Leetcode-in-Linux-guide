/**
* Copyright(c)
* All rights reserved.
* Author : Andrew. Q
* Date : 2020-09-10-18.32.57
* Description : ������ת
*/
#include <iostream>

using namespace std;

int intReverse(int num)
{
    int y = 0;
    if(num/10 == 0)
        return num;

    while(num){
        // ���жϳ�10֮���Ƿ�����
        // ��Ϊ������Ҫ��10������λ����
        if((y*10)>=INT_MAX || (y*10)<=INT_MIN)
            return 0;
        y *= 10;
        y += num%10;
        num /= 10;
    }
    return y;
}


int main()
{
    int x = -123456;
    int y = 67890;
    cout << intReverse(x) << endl;
    cout << intReverse(y) << endl;
    return 0;
}
