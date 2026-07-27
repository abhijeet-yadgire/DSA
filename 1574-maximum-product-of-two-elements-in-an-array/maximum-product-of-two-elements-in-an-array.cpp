class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first_num = nums[nums.size()-1];
        int second_num = nums[nums.size()-2];

        return ((first_num-1)*(second_num-1));
    }
};