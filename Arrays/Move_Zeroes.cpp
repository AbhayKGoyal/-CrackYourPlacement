// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
            return;

        int p1 = 0;
        int p2 = 0;

        while(p2 < nums.size())
        {
            if(nums[p2])
            {
                swap(nums[p2], nums[p1]);
                p1++;
            }
            p2++;
        }
    }
};
