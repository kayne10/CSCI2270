#include <iostream>
using namespace std;		

const int CAPACITY = 1000;


int main() {
	int *dArray;
	int length;
	int value;
	int itemcount;
	dArray = new int[CAPACITY];
	
	cout<<"How large is the Array?"<<endl;
	cin>>length;
	for(int i=0; i<length; i++)
	{
		cout<<"Enter a number to go in Array: "<<endl;
		cin>>value;
		itemcount=0;
		dArray[itemcount]=value;
		itemcount++;
	}
	
	cout<<"Array looks like: "<< dArray[];
	
	
	
	return 0;
}
