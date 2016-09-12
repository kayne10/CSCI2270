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
    float get_value();
    float binary_search(float items[], int n);
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
//binary search function
/*float myArray::binary_search(float items[], int n) {
    int sizeA, sizeB, sizeC;
    if(n==1)
    {
        return items[0];
    }
    else
            sizeA = sizeB = sizeC = n/3;
        }
        float *rightArray=new float[sizeA];
        float *middleArray=new float[sizeB];
        float *leftArray= new float[sizeC];
        for(int i=0; i<sizeA;i++)
        {
           rightArray[i]=items[i];
        }
        for(int i=0; i<sizeB;i++)
        {
            middleArray[i]=items[i+sizeA];
        }
        for(int i=0; i<sizeC; i++)
        {
            leftArray[i]=items[i+sizeA+sizeB]
        }
        float A = binary_search(rightArray, sizeA);
        float B = binary_search(middleArray, sizeB);
        float C = binary_search(leftArray, sizeC);
        if(A.empty() && B.empty() && C.empty())
        {
            return "";
        }
        else if(!A.empty())
        {
            return A;
        }
        else if(!B.empty())
        {
            return B;
        }
        else if(!C.empty())
        {
            return C;
        }
    }
}
*/



int main()
{
myArray arr;
int n;
float userInput;

cout<<"How large is the array?"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<"Enter a value to go in Array: "<<endl;
    cin>>userInput;
    arr.set_value(userInput);
    arr.get_value();
}
    return 0;
}
