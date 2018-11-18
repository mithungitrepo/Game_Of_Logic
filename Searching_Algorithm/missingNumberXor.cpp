#include<iostream>
using namespace std;
int findMissingNumber(int *arr,int n)
{
	int xor1=arr[0],xor2=1;
	int i=0;
	for(i=1;i<n;i++)
		xor1^=arr[i];
	for(i=2;i<=n+1;i++)
		xor2^=i;
	return xor1^xor2;
}
int main()
{
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Missing Number="<<findMissingNumber(arr,n);
	return 0;
}
