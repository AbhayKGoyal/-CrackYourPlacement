// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_buy = prices[0];
        int ans = 0;
        int curr = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] - min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        return ans;
    }
};
