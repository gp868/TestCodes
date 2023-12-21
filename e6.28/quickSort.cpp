#include <iostream>

void quickSort(int nums[], int left, int right){
    if(left > right) return;
    int i = left, j = right;
    int pivot = nums[left];
    while(i < j){
        while(i < j && nums[j] >= pivot) j--;
        while(i < j && nums[i] <= pivot) i++;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[left]);
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

int main(){
    int nums[] = {1,4,7,8,5,2,9,6,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    quickSort(nums, 0, n - 1);
    for(int i = 0; i < n; i++){
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}