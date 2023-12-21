#include <iostream>

void bubbleSort(int nums[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}

int main(){
    int nums[] = {1,4,7,8,5,2,3,6,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, n);
    for(int i = 0; i < n; i++){
        std::cout << nums[i] <<' ';
    }
    std::cout << std::endl;
    return 0;
}