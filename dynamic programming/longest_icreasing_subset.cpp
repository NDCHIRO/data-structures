#include <bits/stdc++.h> 
using namespace std;

int size;

int LIS(int arr[],int i,int prev)
{
	if(i==size)
		return 0;
	int choice1;
	int choice2=0;

	choice1=LIS(arr,i+1,prev);//leave it

	if(prev == size || arr[i]>=arr[prev])
		choice2=LIS(arr,i+1,i)+1;
	
	return max(choice1,choice2);
}

int main()
{
	int arr[]={5, 2, 7, 3, 4, 6};
	size=sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,0, size)<<endl;
}