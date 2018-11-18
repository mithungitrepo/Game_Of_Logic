//Search for a missing integer from an array of n-1 integers in the range of 1 to n
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the elements of array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int sumOfArr=arr[0];
	for(int i=1;i<n;i++)
		sumOfArr+=arr[i];
	//Find the sum of n elements using formula 
	int sumOfN=(n+1)*(n+2)/2;
	cout<<"Missing number="<<sumOfN-sumOfArr<<endl;
	return 0;
}
