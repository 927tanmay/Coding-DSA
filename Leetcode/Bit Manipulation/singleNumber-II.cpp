/*Count the ith set bits for each element in the array
If the count for ith is of the form 3n+1, then this bit is set in the number appearing once
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        long long int res = 0;
        for (int i = 0; i < 32; i++)
        {

            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] & (1 << i))
                    count++;
            }
            if (count % 3 == 1)
                res += 1 << i;
        }
        return res;
    }
};