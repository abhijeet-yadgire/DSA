class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int min_price = INT_MAX;
        int max_price = 0;

        for(int i = 0; i < n; i++)
        {
            if(prices[i] < min_price){
                min_price = prices[i];
            }
            else if(max_price <= prices[i] - min_price)
            {
                max_price = prices[i] - min_price;
            }

        }
        
        return max_price;
    }
};