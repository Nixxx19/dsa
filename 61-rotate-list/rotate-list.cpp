class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k == 0)
            return head;

        ListNode* current = head;
        int listLength = 1;
        while (current->next) 
        {
            current = current->next;
            listLength++;
        }

        current->next = head;
        k = k % listLength;
        int newTailPosition = listLength - k;

        ListNode* newTail = head;
        for (int i = 1; i < newTailPosition; i++) 
        {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
