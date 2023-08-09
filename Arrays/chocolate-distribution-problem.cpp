// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#define ll long long

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        if( n < m)
            return -1;
            
        ll ans = INT_MAX;
        sort(a.begin(), a.end());
        for(int i = 0; i+m-1 < n; i++)
        {
            if(a[i+m-1] - a[i] < ans)
                ans = a[i+m-1] - a[i];
        }
        
        return ans;
    }   
};
