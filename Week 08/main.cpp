#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root) {
    // build heapify
    int largerIndex = root;
    int leftIndex = root * 2 + 1;
    int rightIndex = root * 2 + 2;

    if ( leftIndex < n && arr[leftIndex] > arr[largerIndex]){
        largerIndex = leftIndex;
    }

    if( rightIndex<n && arr[rightIndex] > arr[largerIndex] ){
        largerIndex = rightIndex;
    }

    if (root == largerIndex){
        return;
    }
    auto temp = arr[root];
    arr[root] = arr[largerIndex];
    arr[largerIndex] = temp;
    heapify(arr,n,largerIndex);
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for(int i=0;i<n;i++){
        heapify(arr,n,i);
    }

    // extracting elements from heap one by one
    for(int i=n-1;i>=0;i--){
        // move the root element to the end
        std::swap(arr[0],arr[i]);
        // call max heapify on the reduced heap
        heapify(arr,i,0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int heap_arr[] = {7,23,7,5,1,17,8,10,11};
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}
