class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxVal = INT_MIN;
        while (left<right) {
            int val1 = min(height[left], height[right]);
            maxVal = max(maxVal, val1*(right-left));
            if (height[left]<=height[right]) {
                left++;
            }
            else right--;
        }
        return maxVal;
    }
};