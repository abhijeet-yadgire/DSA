class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        
        int sum = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        leftSum[0] = sum;
        for(int i = 0; i < n; i++)
        {
            if (i > 0) {
                sum = sum + nums[i-1];
            }
            leftSum[i] = sum;
            totalSum = totalSum - nums[i];
            rightSum[i] = totalSum;
        }
        
        
        vector<int> result(n,0);
        for(int i = 0; i < n; i++)
        {
            result[i] = abs(leftSum[i] - rightSum[i]);
        }
        return result;
    }
};