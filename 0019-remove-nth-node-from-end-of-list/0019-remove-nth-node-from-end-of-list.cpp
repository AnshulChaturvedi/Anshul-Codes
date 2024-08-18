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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n==1){
            return NULL;
        }
        ListNode *fast = head;
        while(n--){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        ListNode *slow = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *nodetodelete = slow->next;
        if(slow->next != NULL) slow->next = slow->next->next;
        delete nodetodelete;
        return head;
    }
};