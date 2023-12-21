#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int num = nums[left];
    while (i < j)
    {
        while (i < j && nums[j] >= num)
            j--;
        while (i < j && nums[i] <= num)
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

int main()
{
    vector<int> nums = {3, 7, 2, 9, 1, 8, 6, 5, 4};
    int n = nums.size();
    quickSort(nums, 0, n - 1);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
