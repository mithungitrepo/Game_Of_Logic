#include<iostream>
using namespace std;
int findMinimumBinSrch(int *arr, int low, int high)
{
	if(high<low)
		return arr[0];
	if(high==low)
		return arr[low];
	int mid=(low+high)/2;
	if(low<mid && arr[mid]<arr[mid-1])
		return arr[mid];
	if(mid<high && arr[mid]>arr[mid+1])
		return arr[mid+1];
	if(arr[high]>=arr[mid])
		return findMinimumBinSrch(arr,low,mid-1);
	return findMinimumBinSrch(arr,mid+1,high);
}

int main()
{
	int n;
	cout<<"Enter Number of elements in array:"<<endl;
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the elements of array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Minimum element is:"<<findMinimumBinSrch(arr,0,n-1);
	cout<<endl;
	return 0;
}
