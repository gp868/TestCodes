#include <iostream>
using namespace std;

void quickSort(int nums[], int left, int right){
    if(left > right) return;
    int i = left, j = right;
    int num = nums[left];
    while(i < j){
        while(i < j && nums[j] >= num) j--;
        while(i < j && nums[i] <= num) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

int main(){
    int nums[] = {1,4,7,2,5,8,3,6,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    quickSort(nums, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}