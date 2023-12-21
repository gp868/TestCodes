#include <iostream>

void heapify(int nums[], int n, int i){
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if(left >= n || right >= n){
        return;
    }
    int largest = i;
    if(nums[left] > nums[largest]){
        largest = left;
    }
    if(nums[right] > nums[largest]){
        largest = right;
    }
    if(largest != i){
        std::swap(nums[largest], nums[i]);
        heapify(nums, n, largest);
    }
}

void headSort(int nums[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(nums, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        std::swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}


int main(){
    int nums[] = {1,4,7,8,5,2,3,6,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    headSort(nums, n);
    for(int i = 0; i < n; i++){
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}