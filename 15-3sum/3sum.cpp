class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            int num1 = nums[i];
            int target = -num1;

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i+1;
            int right = n-1;

            while(left < right){
                if(target < nums[left] + nums[right]){
                    right--;
                }
                else if(target > nums[left] + nums[right]){
                    left++;
                }
                else{
                    answer.push_back({num1,nums[left],nums[right]});

                    while(left < right && nums[left] == nums[left+1])
                        left++;

                    while(left < right && nums[right] == nums[right-1])
                        right--;

                    left++;
                    right--;
                }
            }

        }

        return answer;
    }
};