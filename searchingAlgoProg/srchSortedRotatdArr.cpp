#include<iostream>
using namespace std;
int findPivot(int arr[], int low, int high)
{
	int mid=low+(high-low)/2;
	if(low>high)
		return -1;
	if(low==high)
		return low;
	if(mid<high && arr[mid]>arr[mid+1])
		return mid;
	else if(mid>low && arr[mid]<arr[mid-1])
		return mid-1;
	else if(arr[low]>=arr[mid])
		return findPivot(arr,low,mid-1);
	return findPivot(arr,mid+1,high);
}
int binarySearch(int arr[],int low, int high, int k)
{
	if(high<low)
		return -1;
	int mid=low+(high-low)/2;
	if(arr[mid]==k)
		return mid;
	else if(arr[mid]>k)
		return binarySearch(arr,low,mid-1,k);
	return binarySearch(arr,mid+1,high,k);
}
int pivotedBinarySearch(int arr[],int n, int k)
{
	int pivot=findPivot(arr,0,n-1);
	if(pivot==-1)
		return binarySearch(arr,0,n-1,k);
	if(arr[0]<=k)
		return binarySearch(arr,0,pivot,k);
	return binarySearch(arr,pivot+1,n-1,k);
}	
	
int main()
{
	int n,k;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the elements of array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be searched:"<<endl;
	cin>>k;
	int ret=pivotedBinarySearch(arr,n,k);
	if(ret==-1)
		cout<<k<<" is not present in array."<<endl;
	else
		cout<<k<<" is present at index "<<ret;
	return 0;
}
