class Solution {
public:

    int getSum(int num)
    {
        int sum = 0;
        int pow = 1;
        while(num > 0)
        {
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();

        int min = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            nums[i] = getSum(nums[i]);
            if(min > nums[i])
            {
                min = nums[i];
            }
        }
        return min;
    }
};