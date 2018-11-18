//Linear search implementation
//Time Complexity O(n)
#include<iostream>
using namespace std;
int linearSearch(int [],int ,int );
int main()
{
	int n,x;
	cout<<"Enter the size of array:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be searched:"<<endl;
	cin>>x;
	int index=linearSearch(arr,n,x);
	if(index==-1)
		cout<<"Element not found"<<endl;
	else
		cout<<"Found at index="<<index;
	return 0;
}
int linearSearch(int arr[],int n, int x)
{
	int i;
	for(i=0;i<n;i++)
		if(arr[i]==x)
			return i;
	return -1;
}
