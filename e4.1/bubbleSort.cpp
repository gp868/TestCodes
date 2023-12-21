#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &nums, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> nums = {9, 6, 3, 8, 5, 2, 1, 4, 7};
    int n = nums.size();
    bubbleSort(nums, n);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}