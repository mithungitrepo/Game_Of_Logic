#include<iostream>
using namespace std;
int maxDivide(int a, int b)
{
	while(a%b==0)
		a=a/b;
	return a;
}
int isUgly(int num)
{
	num=maxDivide(num,2);
	num=maxDivide(num,3);
	num=maxDivide(num,5);
	return (num==1)?1:0;
}
void findUgly(int n)
{
	int count=1;
	int i=1;
	while(count<n)
	{
		i++;
		if(isUgly(i))
			count++;
	}
	cout<<n<<"th Ugly="<<i<<endl;
}

int main()
{
	int n;
	cout<<"Enter the value of n:"<<endl;
	cin>>n;
	findUgly(n);
	return 0;
}
