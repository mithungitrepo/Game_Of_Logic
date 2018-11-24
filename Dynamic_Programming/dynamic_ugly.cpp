#include<iostream>
using namespace std;
int min(int a,int b)
{
	return (a<b)?a:b;
}
int dynamicUgly(int n)
{
	int ugly[n];
	ugly[0]=1;
	int i,i2,i3,i5;
	i2=i3=i5=0;
	int next_ugly;
	for(i=1;i<n;i++)
	{
		next_ugly=min(ugly[i2]*2,min(ugly[i3]*3,ugly[i5]*5));
		ugly[i]=next_ugly;
		if(next_ugly==ugly[i2]*2)
			i2++;
		if(next_ugly==ugly[i3]*3)
			i3++;
		if(next_ugly==ugly[i5]*5)
			i5++;
	}
	return ugly[n-1];
}
int main()
{
	int n;
	cout<<"Enter the value of n:"<<endl;
	cin>>n;
	cout<<n<<"th ugly="<<dynamicUgly(n)<<endl;
	return 0;
}
