class Solution {
public:
    Node* flatten(Node* head) {

        Node* curr = head;

        while(curr != NULL) {

            if(curr->child != NULL) {

                Node* next = curr->next;
                Node* child = curr->child;

                // Child ko next bana do
                curr->next = child;
                child->prev = curr;

                // Child list ka last node find karo
                Node* temp = child;

                while(temp->next != NULL) {
                    temp = temp->next;
                }

                // Last child ko original next se connect karo
                temp->next = next;

                if(next != NULL) {
                    next->prev = temp;
                }

                // Child pointer remove
                curr->child = NULL;
            }

            curr = curr->next;
        }

        return head;
    }
};