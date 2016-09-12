#include <iostream>

using namespace std;
//class for array
class myArray {
private:
    float value;
    float items[];
    int n;
    int itemCount;
public:
    myArray();
    void set_value(float value);
    float get_value(float items[], int itemCount);
    void traverseAndPrint();

};
//Implementation
myArray::myArray() {}

void myArray::set_value(float value) {
    itemCount=0;
    value = items[itemCount];
    itemCount++;
}

float myArray::get_value() {
    return value;
}

void myArray::traverseAndPrint() {
    if(int i = 0; i<n;i++;)
    {
        cout<<items[i]<<endl;
    }
}

/*void maxSearch(float items[], int length) {
    float leftArray;
    float rightArray;
    float maxValue;
    if(length==1)
    {
        for(int i = 0; i<length; i++)
        {
            return items[0];
        }
    }
    else
        leftArray= items[0]+items[length]/2;
        rightArray= items
}
*/

int main()
{
myArray arr;
int n;
float userInput;

cout<<"How large is the array?"<<endl;
cin>>n;
arr.getlength(userLength);
for(int i=0;i<userLength;i++)
{
    cout<<"Enter a value to go in Array: "<<endl;
    cin>>userInput;
    arr.set_value(userInput);
    arr.get_value();
}
arr.traverseAndPrint();
    return 0;
}
