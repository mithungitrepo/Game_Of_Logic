//Binary Search Implementation(Recursive + Iterative)
//Time complexity O(log n)
//Inputted array must be sorted
//Performs ordering comparison
#include<iostream>
using namespace std;
//Recursive Implementation
int binarySearch(int *arr,int low,int high,int x)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==x)
			return mid;
		else if(arr[mid]>x)
			return binarySearch(arr,low,mid-1,x);
		else
			return binarySearch(arr,mid+1,high,x);
	}
	return -1;
}
//
int binarySearchIter(int *arr, int low, int high, int x)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==x)
			return mid;
		else if(arr[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int main()
{
	int n,x;
	cout<<"Enter the size of array:";
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be searched:"<<endl;
	cin>>x;
	int index=binarySearch(arr,0,n,x);
	if(index==-1)
		cout<<"Element not found"<<endl;
	else
		cout<<"Found at index="<<index<<endl;
	index=binarySearchIter(arr,0,n,x);
	cout<<"Iter Result"<<endl;
	if(index==-1)
		cout<<"Element not found"<<endl;
	else
		cout<<"Found at index="<<index<<endl;
	return 0;
}
