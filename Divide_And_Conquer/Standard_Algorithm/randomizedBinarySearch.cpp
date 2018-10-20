#include<iostream>
#include<ctime>
#include<cstdlib>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
int getRandom(int low, int high)
{
	srand(time(NULL));
	return low+(rand()%(high-low+1));
}
int randomizedBinarySearch(int *arr, int low, int high, int k)
{
	if(low>high)
		return -1;
	int rand_mid=getRandom(low,high);
	if(arr[rand_mid]==k)
		return rand_mid;
	else if(arr[rand_mid]>k)
		return randomizedBinarySearch(arr,low,rand_mid-1,k);
	return randomizedBinarySearch(arr,rand_mid+1,high,k);
}
int main(void)
{
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int *arr=new int[n]; //Allocating space for array dynamically
	cout<<"Enter the elements of the array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the element to be searched:"<<endl;
	int k;
	cin>>k;
	auto start=high_resolution_clock::now();
	int found_index=randomizedBinarySearch(arr,0,n-1,k);
	auto stop=high_resolution_clock::now();
	if(found_index!=-1)
		cout<<"Element found at index "<<found_index;
	else
		cout<<"Element is not present in the array. Thank you!";
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<"Time taken to execute the function is "<<duration.count()<<"microseconds"<<endl;
	return 0;
}

	
	
