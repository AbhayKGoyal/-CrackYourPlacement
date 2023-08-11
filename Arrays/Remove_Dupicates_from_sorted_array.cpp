// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// TC = O(N)
// Two-Pointer Approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int ans = 1;
        int i = 1;
        int n = nums.size();
        while(i < n)
        {
            if(nums[i] != nums[i-1])
            {
                nums[ans] = nums[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};
