#include <iostream>
using namespace std;

void merge(int nums1[], int n1, int nums2[], int n2, int nums[], int n){
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(nums1[i] < nums2[j]){
            nums[k] = nums1[i];
            i++;
        }else{
            nums[k] = nums2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        nums[k] = nums1[i];
        i++;
        k++;
    }
    while(j < n2){
        nums[k] = nums2[j];
        j++;
        k++;
    }
}

void mergeSort(int nums[], int n){
    if(n <= 1) return;
    int mid = n / 2;
    int nums1[mid], nums2[n - mid];
    for(int i = 0; i < mid; i++){
        nums1[i] = nums[i];
    }
    for(int i = mid; i < n; i++){
        nums2[i - mid] = nums[i];
    }
    mergeSort(nums1, mid);
    mergeSort(nums2, n - mid);
    merge(nums1, mid, nums2, n - mid, nums, n);
}

int main(){
    int nums[] = {1,4,7,8,5,2,3,6,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, n);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}