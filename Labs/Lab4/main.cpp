#include <iostream>

using namespace std;

//--1--
/*long factorial(int a,int n)
{
    long result;
    if(n==0)
        result = 1;
    else
        result = a*(factorial(a,n-1));
    return result;

}
*/
//--2--
int maxArray(int array[], int array_length)
{
    int sizeA,sizeB;
    int maxA,maxB;

    if(array_length == 1){
        return array[0];
    }
    else{
        if(array_length %2 == 1)
        {
            sizeA= array_length/2;
            sizeB= (array_length/2)+1;
        }
        else {
            sizeA = sizeB = array_length/2;
        }
        int *rightArray=new int[sizeA];
        int *leftArray=new int[sizeB];
        for(int i=0; i<sizeA;i++)
        {
           rightArray[i]=array[i];
        }
        for(int i=0; i<sizeB;i++)
        {
            leftArray[i]=array[i+sizeA];
        }
        maxA=maxArray(rightArray,sizeA);
        maxB=maxArray(leftArray, sizeB);
        if(maxA>maxB)
        {
            return maxA;
        }
        else if(maxA==maxB) {
            return maxA;
        }
        else {
            return maxB;
        }
    }
}

//--3--
string binary_search(string array[], int array_length, string word)
{
    int sizeA, sizeB;

    if(array_length==1)
    {
        if(word==array[0])
        {
            return word;
        }
        else {
            return "";
        }
    }
    else {
        if(array_length%2==1)
        {
            sizeA= array_length/2;
            sizeB= (array_length/2)+1;
        }
        else {
            sizeA = sizeB = array_length/2;
        }
        string *rightArray=new string[sizeA];
        string *leftArray=new string[sizeB];
        for(int i=0; i<sizeA;i++)
        {
           rightArray[i]=array[i];
        }
        for(int i=0; i<sizeB;i++)
        {
            leftArray[i]=array[i+sizeA];
        }
        string A = binary_search(rightArray, sizeA, word);
        string B = binary_search(leftArray, sizeB, word);
        if(A.empty() && B.empty())
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
    }
}


int main()
{
    /*int a,b;
    long result;
    result = factorial(a,b);*/
    int array_length;

    int c[6]={10,3,45,63,21,98};
    array_length=sizeof(c)/sizeof(c[0]);
    int max_number;
    max_number = maxArray(c,array_length);
    cout<<max_number<<endl;

    string d[4]={"burgers","turkey","bacon","hotdog"};
    string e=binary_search(d,4, "hotdog");
    cout<<e<<endl;
    if(e.empty())
    {
        cout<<"Couldn't find string"<<endl;
    }
    return 0;
}
