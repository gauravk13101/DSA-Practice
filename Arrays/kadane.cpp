#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int res = INT_MIN, maxEnding = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxEnding = max(maxEnding + nums[i], nums[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main()
{
    vector<int> nums = {2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
}