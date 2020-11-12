#include <iostream>
#include <algorithm>
using namespace std;

int noOfIems;
int knapSack(int W[],int P[],int rem,int currentItem)
{
	if(currentItem>=noOfIems)
		return 0;

	int choice1;
	int choice2=0;

	//leave this item
	choice1=knapSack(W,P,rem,currentItem+1);

	//take this item
	if(W[currentItem]<=rem)
		choice2=knapSack(W,P,(rem-W[currentItem]),currentItem+1)+P[currentItem];

	return max(choice1,choice2);
}

int main()
{
	int weight[]={10,4,20,5,7};
	int benfit[]={10,15,3,1,4};
	int size=12;
	int items=5;
	noOfIems=items;

	cout<<knapSack(weight,benfit,size,0)<<endl;

}