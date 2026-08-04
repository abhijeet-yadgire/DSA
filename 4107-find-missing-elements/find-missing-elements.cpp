class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector <int> ans;
        bool arr[101] = {};
        
        int smallest = INT_MAX;
        int largest = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(smallest >= nums[i]){
                smallest = nums[i];
            }

            if(largest <= nums[i]){
                largest = nums[i];
            }

            arr[nums[i]] = true;
        }

        for(int i = smallest+1; i < largest; i++){
            if(!arr[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};