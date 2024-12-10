#include <iostream>
using namespace std;

void mergeSort(int array[],int left,int right);
void merge(int array[],int left,int mid,int right);
int binarySearch(int array[],int size,int target);

void mergeSort(int array[],int left,int right) {
    if (left<right) {
        int mid=left +(right-left)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid+1,right);

        merge(array,left,mid,right);
    }
}

void merge(int array[],int left,int mid,int right) {
    int n1=mid-left+1;
    int n2=right-mid;

    int* leftArray=new int[n1];
    int* rightArray=new int[n2];

    for (int i=0;i <n1;i++)
        leftArray[i]=array[left + i];
    for (int j =0; j <n2;j++)
        rightArray[j]=array[mid + 1 + j];

    int i=0;
    int j=0;
    int k=left;
    while (i<n1 && j<n2) {
        if (leftArray[i]<=rightArray[j]) {
            array[k]=leftArray[i];
            i++;
        } else {
            array[k]=rightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        array[k]=leftArray[i];
        i++;
        k++;
    }
    while (j<n2) {
        array[k]=rightArray[j];
        j++;
        k++;
    }
}

int binarySearch(int array[],int size,int target) {
    int left=0,right=size-1;

    while (left<=right) {
        int mid = left +(right-left) / 2;

        if (array[mid]==target)
            return mid;
        if (array[mid]<target)
            left = mid+1;
        else
            right=mid-1;
    }
    return -1;
}

int main() {
    int array[]={14,2,6,10,8,31,26,22,18};
    int size =sizeof(array)/sizeof(array[0]);
    
    cout<<"Original array: ";
    for (int i=0; i<size;i++)
        cout<<array[i]<< " ";
    cout<<endl;

    mergeSort(array,0,size-1);
    cout << "Array after merge sorting: ";
    for (int i=0; i<size;i++)
        cout<<array[i]<< " ";
    cout <<endl;

    int target=22;
    int result = binarySearch(array,size,target);
    if (result !=-1)
        cout << "Element " <<target<< " found at index: " << result <<" using binary search " <<endl;
    else
        cout << "Element " << target << " not found in the array." << endl;

    return 0;
}
