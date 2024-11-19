#include <iostream>
using namespace std;
void maxHeapify(int arr[] , int i ,int N){
  int lchild = 2*i+1;
  int rchild = 2*i+2;
  // Check if left child exists and is greater than root
        if (leftChild < N && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        // Check if right child exists and is greater than the largest so far
        if (rightChild < N && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        // If largest is not the root, swap and recursively heapify
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, N); // Recursively heapify the affected subtree
        }
  
}
void convertMinToMaxHeap(int N, int arr[]){
  for(int i = (N-2)/2 ; i>=0;i--){
    maxHeapify(arr, i, N);
  }
}
int main() {
    int arr[] = {1, 3, 6, 5, 9, 8}; // Example min-heap
    int N = sizeof(arr) / sizeof(arr[0]);

    Solution::convertMinToMaxHeap(N, arr);

    cout << "Converted Max-Heap: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
