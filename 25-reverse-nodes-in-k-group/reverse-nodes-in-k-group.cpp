class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head)
        {
            return nullptr;
        }
        
        ListNode* node = head;
        int count = 0;
        while (node && count < k) 
        {
            node = node->next;
            count++;
        }

        if (count < k) 
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        count = 0;

        while (curr && count < k) 
        {
            next = curr->next;    
            curr->next = prev;      
            prev = curr;          
            curr = next;           
            count++;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
