#include<myString.h>
bool insert(char a[],int loc,char ch)//索引位置,从0开始
{
	int len=0;
	while (a[len]!=END) len++;
	len++;

	if (loc>len||loc<0)
	{
		return false;
	}
	for (int i=len;i>loc;i--)
	{
		a[i]=a[i-1];
	}
	a[loc]=ch;

	return true;
}
bool delchr(char a[],int loc)//索引位置
{
	int len=0;
	while (a[len]!=END) len++;
	len++;
	if(loc>=len||loc<0) return false;
	for (int i=loc;i<len;i++)
	{
		a[i]=a[i+1];
	}

	return true;
}
int strlen(char a[],char end)
{
	int i=0;
	while (a[i]!=end)
	{
		i++;
	}
	return i;
}
string findRepeat(string a)
{
	string maxstr;
	int maxlen=0;
	int i,j,len=a.length();
	for (i=0;i<len-1;i++)
	{
		for (j=i+1;j<len;j++)
		{
			if (a[i]==a[j])
			{
				int k,l;
				k=i+1;l=j+1;
				while (l<len&&k<j)
				{
					if(a[k]==a[l]) k++,l++;
					else break;
				}
				int count=k-i;
				if (count>maxlen)
				{
					maxlen=count;
					maxstr.assign(a,i,count);
				}

			}
		}

	}
	return maxstr;

}