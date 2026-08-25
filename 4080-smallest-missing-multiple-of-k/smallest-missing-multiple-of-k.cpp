class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> arr(nums.begin(), nums.end());

        int currEle = k;
        while (arr.count(currEle)) {
            currEle += k;
        }

        return currEle;
    }
};