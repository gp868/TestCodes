#include <iostream>
using namespace std;

void heapify(int nums[], int i, int n){
    int largest = i;
    int left = i * 2 + 1, right = i * 2 + 2;
    if(left < n && nums[left] > nums[largest]){
        largest = left;
    }
    if(right < n && nums[right] > nums[largest]){
        largest = right;
    }
    if(largest != i){
        swap(nums[i], nums[largest]);
        heapify(nums, largest, n);
    }
}

void heapSort(int nums[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(nums, i, n);
    }
    for(int i = n - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
        heapify(nums, 0, i);
    }
}

int main(){
    int nums[] = {1,4,7,8,5,2,3,6,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, n);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}