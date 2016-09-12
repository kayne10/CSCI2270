#include <iostream>
#include <array>

using namespace std;


typedef unsigned int UINT;

int operationCount, totalCost, compareCost = 0;
//Bubble Sort
//Code modified from https://github.com/trmchale1/bubbleSort/blob/master/bubbleSort.cpp
void bubbleSort(int userVals[], int n){
	totalCost++;
	int tempVal;
	totalCost++;
	for(int i = 0; i < (n-1); i++)
	{
		for(int j = i + 1; j<n; j++){
		    compareCost++;
		    compareCost++;
		    totalCost++;
			if(userVals[i] > userVals[j])
			compareCost++;
			{
			    totalCost++;
				tempVal = userVals[i];totalCost++;
				userVals[i] = userVals[j];totalCost++;
				userVals[j] = tempVal;totalCost++;
				operationCount++;totalCost++;
			}
		}

}
}


//Computing the number of costs


//Selection Sort
//code modified from https://github.com/SkylaBlue/SelectionSort/blob/master/selection.cpp

void selectionSort(int array[], int size)
{
    // first iteration to find the lowest value
  for (UINT i = 0; i < size; i++)
  {
      totalCost++;compareCost++;
    if (array[0] > array[i])
        totalCost++;compareCost++;
    {
      int temp = array[0];totalCost++;
      array[0] = array[i];totalCost++;
      array[i] = temp;totalCost++;
      operationCount++;
    }
  }

  for (UINT i = 1; i < size; i++)
  {
    for (UINT j = i+1; j < size; j++)
    {
      if (array[i] > array[j])
      {
          compareCost++;compareCost++;compareCost++;
          totalCost++;totalCost++;totalCost++;
        int temp = array[i];totalCost++;
        array[i] = array[j];totalCost++;
        array[j] = temp;totalCost++;
        operationCount++;
      }
    }
  }
}
//Computing number of costs

//Insertion Sort
void insertionSort(int A[], int sizeA) {
    for(int i=0; i< sizeA; i++)
        {
            int index = A[i]; totalCost++; compareCost++;
            int j = i; totalCost++;
            while((j>0) && (A[j-1] > index))
            {
                A[j] = A[j-1];totalCost++;compareCost++;
                j = j-1;totalCost++;
            }
            A[j] = index; totalCost++;operationCount++;
        }
}
//Computing number of costs, comparisons, and swaps

//QuickSort
void quickSort(int A[],int left,int right){
    int i = left; totalCost++;
    int j = right; totalCost++;
    int pivot = A[((left+right) / 2)]; totalCost++;
    while(i<=j)
        {
            while(A[i] < pivot)
            {
                i++; totalCost++;totalCost++;compareCost++;compareCost++;
            }
            while(A[j] > pivot)
            {
                j--; totalCost++;totalCost++;compareCost++;compareCost++;
            }
            if(i<=j)
            {
                int tmp = A[i];totalCost++;compareCost++;
                A[i] = A[j];totalCost++;
                A[j] = tmp;totalCost++;
                i++;totalCost++;totalCost++;
                j--;totalCost++;operationCount++;
            }
        }
    if(left<j)
    {
        quickSort(A,left,j);totalCost++;compareCost++;
    }
    if(i<right)
    {
        quickSort(A,i,right);totalCost++;compareCost++;
    }
}
//Computing the number of costs, swaps, and comparisons


void merge(int A[],int low,int high,int mid,int size);

//Merge Sort
void mergeSort(int A[],int low,int high,int size) {
    if(low<high)
    {
        int mid = (low+high) / 2;totalCost++;
        mergeSort(A,low,mid, size/2);totalCost++;
        mergeSort(A, mid+1, high, size/2);totalCost++;
        merge(A, low, high, mid, size);totalCost++;operationCount++;
    }
}

void merge(int A[],int low,int high,int mid,int size) {
    int i = low;totalCost++;
    int k = low;totalCost++;
    int j = mid+1;totalCost++;
    int c[size];totalCost++;
    while(i<=mid && j<=high)
    {
        if(A[i] < A[j])
        {
            c[k] = A[i];totalCost++;
            k++;totalCost++;totalCost++;
            i++;totalCost++;totalCost++;compareCost++;compareCost++;operationCount++;
        }
        else
        {
            c[k] = A[j];totalCost++;
            k++;totalCost++;totalCost++;
            j++;totalCost++;totalCost++;compareCost++;operationCount++;operationCount++;
        }
    }
    while(i<=mid)
    {
        c[k]=A[i];totalCost++;
        k++;totalCost++;totalCost++;
        i++;totalCost++;totalCost++;compareCost++;operationCount++;
    }
    while(j<=high)
    {
        c[k] = A[j];totalCost++;
        k++;totalCost++;totalCost++;
        j++;totalCost++;totalCost++;compareCost++;operationCount++;
    }
    for(i=low; i<k;)
    {
        A[i] = c[i];totalCost++;compareCost++;operationCount++;
    }
}
//Computing the number of costs, comparisons, and swaps


int main()
{
int size=4;
int A[4] = {4,1,2,3};
bubbleSort(A, size);
cout<<"Operations: "<<operationCount<<endl;
cout<<"Costs: "<<totalCost<<endl;
cout<<"Comparisons: "<<compareCost<<endl;
    return 0;
}
