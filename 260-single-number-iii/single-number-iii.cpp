class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 2)
            return nums;

        sort(nums.begin(),nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            } else {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};