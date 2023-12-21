#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &nums, int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < n && nums[left] > nums[largest])
    {
        largest = left;
    }
    if (right < n && nums[right] > nums[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(nums[largest], nums[i]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int> &nums, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main()
{
    vector<int> nums = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    int n = nums.size();
    heapSort(nums, n);
    for (int num : nums)
    {
        cout << num << "";
    }
    cout << endl;
    return 0;
}