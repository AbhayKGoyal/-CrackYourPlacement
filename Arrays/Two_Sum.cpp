// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i = 0; i < v.size(); i++)
        {
            if(mp.count(k-v[i]))
            {
                ans.push_back(i);
                ans.push_back(mp[k-v[i]]);
                return ans;
            }
            mp[v[i]] = i;
        }
        return ans;
    }
};
