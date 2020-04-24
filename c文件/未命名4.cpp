#include<iostream>
#include<string.h>
#include<memory.h>
using namespace std;		
int  LNRS_dp(char * arr, int size)
{
	int dp[30];
    int i, j,maxlen,maxindex;
    int last_start = 0;     // ��һ����Ӵ�����ʼλ��
    maxlen = maxindex = 0;
 
    dp[0] = 1;
    for(i = 1; i < size; ++i)
    {
        for(j = i-1; j >= last_start; --j) // ��������һ����Ӵ���ʼλ��
        {
            if(arr[j] == arr[i])
            {
                dp[i] = i - j;
                last_start = j+1; // ����last_start
                break;
            }
			else if(j == last_start) // ���ظ�
			            {
			                dp[i] = dp[i-1] + 1;
			            }
        }
        if(dp[i] > maxlen)
        {
            maxlen = dp[i];
            maxindex = i + 1 - maxlen;
        }
	}
    return maxlen;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char T[100];
		cin>>T;
		int len=strlen(T);
		int x=LNRS_dp(T,len);
		if(x>0) 
		cout<<x<<endl;
		else cout<<-1<<endl; 
	}
 } 
