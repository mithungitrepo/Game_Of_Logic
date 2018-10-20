//Binary Search algorithm using recursion
#include<chrono>
#include<iostream>
using namespace std;
using namespace std::chrono;
int binarySearch(int *arr, int low, int high, int k)
{
	if(low>high)
		return -1;
	int mid;
	mid=low+(high-low)/2;
	if(arr[mid]==k)
		return mid;
	else if(arr[mid]>k)
		return binarySearch(arr,low,mid-1,k);
	return binarySearch(arr,mid+1,high,k);
}

int main(void)
{
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the array elements:";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be searched:";
	int k;
	cin>>k;
	auto start=high_resolution_clock::now();
	int foundIndex=binarySearch(arr,0,n-1,k);
	auto stop=high_resolution_clock::now();
	cout<<endl;
	if(foundIndex!=-1)
		cout<<"Element found at index "<<foundIndex<<endl;
	else
		cout<<"Element is not present in the array. Thank you!";
	cout<<endl;
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<"Time taken to execute the function= "<<duration.count()<<" microseconds";
	cout<<endl;
	return 0;
}
