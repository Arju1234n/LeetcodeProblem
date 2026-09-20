class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find meeting point
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        // No cycle
        if(fast == NULL || fast->next == NULL)
            return NULL;

        // Find starting point of cycle
        slow = head;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};