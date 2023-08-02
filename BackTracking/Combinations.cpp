// https://leetcode.com/problems/combinations/
// overall time complexity is O(C(n, k) * k) or O((n choose k) * k).
// Overall, the space complexity is O(k + C(n, k)), or simply O(C(n, k)).
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, int n, int k, vector<int> &temp)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(start > n)
            return;

        temp.push_back(start);
        solve(start+1, n, k-1, temp);
        temp.pop_back();
        solve(start+1, n, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> t;
        solve(1, n, k, t);
        return ans;
    }
};
