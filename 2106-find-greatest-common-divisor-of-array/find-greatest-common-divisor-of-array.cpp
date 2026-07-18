class Solution {
public:
    int findGCD(vector<int>& nums) {
        if(nums.empty())
        return 0;
        sort(nums.begin(),nums.end());

        int smallest = nums[0];
        int largest = nums[nums.size() - 1];

        int ans = 1;
        int i = smallest;
        int count = 0;

        for(int i = 1; i <= smallest; i++)
        { 

            if(smallest % i == 0 && largest % i == 0 && ans <= i){
                ans = i;
                count++;
            }

            if(count == 0){
                ans = 1;
            }
        }

        return ans;
    }
};