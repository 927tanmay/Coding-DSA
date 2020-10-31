//Problem Link:- https://leetcode.com/problems/single-number-iii/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int x = nums[0], i;
        for (i = 1; i < nums.size(); i++)
            x = x ^ nums[i];
        int rmsb = x & ~(x - 1);
        int a = 0, b = 0;
        vector<int> v;
        for (i = 0; i < nums.size(); i++)
        {
            if (rmsb & nums[i])
                a = a ^ nums[i];
            else
                b = b ^ nums[i];
        }
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};