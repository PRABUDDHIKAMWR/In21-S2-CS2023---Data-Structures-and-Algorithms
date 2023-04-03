#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int>& arr, int star, int end);
int partition(vector<int>& arr, int start, int end, int pivot);
void print(vector<int>& arr, int size);
double Median(vector<int>& arr);

int main()
{
    vector<int> arr;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        arr.push_back(el);

        quickSort(arr, 0, i); // sort the array so far
        cout << "\nSorted array so far: ";
        for (int k = 0; k <i+1 ; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        double median = Median(arr); // find the running median
        cout << "Running median: " << median <<endl;
    }

    return 0;
}

int partition(vector<int>& arr, int start, int end){

    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j <= end -1; j++){
        
        if (arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;

}

void quickSort(vector<int>& arr, int start, int end){
    
    if (end <= start) {return;}//base case

    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);

}

double Median(vector<int>& arr)
{
    int n = arr.size();
    if (n % 2 == 0) {
        return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        return (double)arr[n / 2];
    }
}
