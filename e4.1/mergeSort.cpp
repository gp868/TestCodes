#include <iostream>

using namespace std;

void merge(int nums1[], int m, int nums2[], int n, int nums[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            nums[k] = nums1[i];
            i++;
        }
        else
        {
            nums[k] = nums2[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        nums[k] = nums1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        nums[k] = nums2[j];
        j++;
        k++;
    }
}

void mergeSort(int nums[], int n)
{
    if (n <= 1)
        return;
    int mid = n / 2;
    int left[mid], right[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = nums[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = nums[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, mid, right, n - mid, nums);
}

int main()
{
    int nums[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    int n = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, n);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}