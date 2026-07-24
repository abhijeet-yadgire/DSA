class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans;
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while(left < right)
        {
            int breadth = right-left;
            int length = (height[left] < height[right]) ? height[left] : height[right];
            maxArea = max(maxArea, breadth*length);

            if(height[left] <= height[right])
            {
                 left++;
            }else{
                right--;
            }
        }

        ans = maxArea;
        return ans;
    }
};