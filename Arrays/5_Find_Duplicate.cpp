// https://leetcode.com/problems/find-the-duplicate-number/

// Approach 1 TC = O(N^2) SC = O(1) with 2 nested loops
// Approach 3 TC = O(N * Log N) SC = O(1) sorting
// Approach 2 TC = O(N) SC = O(N) with Set
// Approach 4 TC = O(N) SC = O(1) with slow-fast

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }while(true);
        
        fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast)
                break;
        }while(true);
            
        return fast;
    }
};


// Approach 4 TC = O(N) SC = O(1) Bit-Manipulation
