class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = 0;
        int maxLeft = 0;

        for (int j = k; j < nums.size(); j++) {
            maxLeft = max(maxLeft, nums[j - k]);

            ans = max(ans, maxLeft + nums[j]);
        }

        return ans;
    }
};