class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;

        // Start right at 0 instead of 1
        for(int right = 0; right < n; right++)
        {            
            if(nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};