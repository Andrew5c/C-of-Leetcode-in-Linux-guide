/**
* Copyright(c)
* All rights reserved.
* Author : Andrew Q.
* Date : 2020-09-12-16.49.48
* Description : ��̬�滮�����һ���ַ����е�������Ӵ�
* ����״̬��p(i,j) ��ʾ�Ӵ�{s[i]...s[j]}�Ƿ����
* ״̬ת�ƣ�p(i,j) = p(i+1,j-1) and s[i]==s[j]
* �߽������������ַ�s[i]һ�����ģ������ַ�����ʱ����s[i]==s[j]
* ���ֶ�ά�Ķ�̬�滮������ʹ��һ�����������״̬�ı仯
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s)
{
    int len = s.size();
    // ��¼������Ӵ�����ʼλ��
    int start = 0;
    int maxLen = 1;
    string ans;
    // ��ά������ÿһ����ϵĽ��
    vector<vector<bool>> dp(len, vector<bool>(len));
    // j��ʾ�Ӵ�����߽磬i�ұ߽�
    for(int j=1; j<len; j++){
        for(int i=0; i<j; i++){
            if(s[i] != s[j]){
                dp[i][j] = false;
            }else{
                if(j-i<3)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j] && (j-i+1>maxLen)){
                maxLen = j-i+1;
                start = i;
            }
        }
    }
    // ans = s.substr(start, start+maxLen);
    int p=0;
    for(int k=start; k<k+maxLen; k++){
        ans[p] = s[k];
        p++;
    }
    return ans;
}


int main(){
    string s = "dfsdabcecbaqian";
    string ans = longestPalindrome(s);
    cout << ans << endl;

    return 0;
}
