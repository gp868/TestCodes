#include <iostream>
using namespace std;

void merge(int nums1[], int n1, int nums2[], int n2, int nums[]){
    int i = 0, j = 0, p = 0;
    while(i < n1 && j < n2){
        if(nums1[i] < nums2[j]){
            nums[p] = nums1[i];
            i++;
        }else{
            nums[p] = nums2[j];
            j++;
        }
        p++;
    }
    while(i < n1){
        nums[p] = nums1[i];
        i++;
        p++;
    }
    while(j < n2){
        nums[p] = nums[p];
        j++;
        p++;
    }
}

void mergeSort(int nums[], int n){
    if(n <= 1) return;
    int mid = n / 2;
    int left[mid], right[n - mid];
    for(int i = 0; i < mid; i++){
        left[i] = nums[i];
    }
    for(int i = mid; i < n; i++){
        right[i - mid] = nums[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, mid, right, n - mid, nums);
}

int main(){
    int nums[] = {1,4,7,2,5,8,3,6,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, n);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}