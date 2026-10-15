class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            set <int> uniqueOnes;
            for(int j = i; j < nums.size(); j++){
                uniqueOnes.insert(nums[j]);
                int count = uniqueOnes.size();
                ans += count * count;
            }
        }

        return ans;
    }
};