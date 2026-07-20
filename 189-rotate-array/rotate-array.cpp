class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> temp = nums;
        for(int i = 0; i < nums.size(); i++){
            int numsIndex = (i + k) % nums.size();
            nums[numsIndex] = temp[i];
        }
    }
};