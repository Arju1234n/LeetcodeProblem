class Solution {
public:
    bool isPalindrome(ListNode* head) {

        vector<int> v;

        ListNode* curr = head;

        while(curr != NULL) {
            v.push_back(curr->val);
            curr = curr->next;
        }

        int left = 0;
        int right = v.size() - 1;

        while(left < right) {
            if(v[left] != v[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};