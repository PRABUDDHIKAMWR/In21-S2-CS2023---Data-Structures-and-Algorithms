#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{ 
   // build heapify
   int largest = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;

   if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }

   if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }

   if (largest != root) {
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;

      heapify(arr, n, largest);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{  
   
   // build heap
   for(int i = n/2; i>=0; i--){
      heapify(arr,n, i);
   }
   // extracting elements from heap one by one
   for (int j = n-1; j >= 0; j--){
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;

      heapify(arr, j, 0);
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
   //Genarating random arrays
   srand(time(nullptr));
   int length[6];
   for (int i = 0; i< 6; i++){
        length[i] = rand()%18 +3;
   }
   for (int k:length){
      int heap_arr[k];

      for (int i=0; i<k; i++){
         heap_arr[i] = rand()%100;
         int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
         cout<<"\nInput array"<<endl;
         displayArray(heap_arr,n);
  
         heapSort(heap_arr, n);
  
         cout << "Sorted array"<<endl;
         displayArray(heap_arr, n);

      }
   }
}
