#include<iostream>
using namespace std;
int modifiedBinSearch(int arr[], int low, int high, int k)
{
	if(high<low)
		return -1;
	int mid=(low+high)/2;
	if(arr[mid]==k)
		return mid;
	if(arr[low]<=arr[mid])
	{
		if(arr[low]<=k && arr[mid]>=k)
			return modifiedBinSearch(arr,low,mid-1,k);
		else
			return modifiedBinSearch(arr,mid+1,high,k);
	}
	if(arr[mid+1]<=k && arr[high]>=k)
		return modifiedBinSearch(arr,mid+1,high,k);
	return modifiedBinSearch(arr,low,mid-1,k);
}
int main()
{
	int n,k;
	cout<<"Enter number of elements in the array:"<<endl;
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the elements of array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be searched:"<<endl;
	cin>>k;
	int ret=modifiedBinSearch(arr,0,n-1,k);
	if(ret==-1)
		cout<<"Element is not present in the array"<<endl;
	else 
		cout<<"Element is found at index: "<<ret<<endl;
	return 0;
}
	
