#include <iostream>
using namespace std;

int totalCost = 0;
int recurse(int a, int b) {
	if(a % b == 2)
	{
		return a;totalCost++;
	}
	else
		return recurse(a + b, a - b);totalCost++;totalCost++;
}


int main() 
{
	recurse(7,2);
	cout<<totalCost<<endl;
	return 0;
}
