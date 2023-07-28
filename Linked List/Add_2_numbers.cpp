/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* reverse(ListNode * head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<ListNode*> st1, st2;
        ListNode *p1 = l1, *p2 = l2;
        while(p1)
        {
            st1.push(p1);
            p1 = p1->next;
        }
        while(p2)
        {
            st2.push(p2);
            p2 = p2->next;
        }

        ListNode *ans = new ListNode(-1);
        ListNode *ptr = ans;
        int carry = 0;
        while(!st1.empty() && !st2.empty())
        {
            int sum = st1.top()->val + st2.top()->val + carry;
            st1.pop();
            st2.pop();
            ptr->next = new ListNode (sum % 10);
            ptr = ptr->next;
            carry = sum / 10;
        }
        while(!st1.empty())
        {
            int sum = st1.top()->val + carry;
            st1.pop();
            ptr->next = new ListNode (sum % 10);
            ptr = ptr->next;
            carry = sum / 10;
        }
        while(!st2.empty())
        {
            int sum = st2.top()->val + carry;
            st2.pop();
            ptr->next = new ListNode (sum % 10);
            ptr = ptr->next;
            carry = sum / 10;
        }
        if(carry)
        {
            ptr->next = new ListNode (carry);
            ptr = ptr->next;
        }
        return reverse(ans->next);
    }
};
