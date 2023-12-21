#include <iostream>
using namespace std;

void heapify(int nums[], int n, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if(left < n && nums[left] > nums[largest]){
        largest = left;
    }
    if(right < n && nums[right] > nums[largest]){
        largest = right;
    }
    if(largest != i){
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(int nums[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(nums, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main(){
    int nums[] = {9,6,3,8,5,2,7,4,1};
    int n = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, n);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
