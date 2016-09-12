#include <iostream>

using namespace std;


class myArray {
private:
    int size;
public:
    int number;
    int arr[number];
    void getSize(int size);
    void addElement(int number);
};

void myArray::getSize(int size) {
    cout<<arr[size]<<endl;
}

void myArray::addElement(int element) {
    int i;
    for(i=0;i<size;i++){
        element = arr[i];
    }
}


int main()
{
    myArray arr;
    cout<<"How many elements are in the array?"<<endl;
    cin>>size;
    arr.getSize(size);
    cout<<"What number do you want to store?"<<endl;
    cin>arr.addElement(element);;
    arr.addElement(element);

    return 0;
}
