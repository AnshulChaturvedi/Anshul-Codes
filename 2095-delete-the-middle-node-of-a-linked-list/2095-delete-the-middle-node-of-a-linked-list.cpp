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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode *temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        int pos = len/2;
        ListNode *curr = head;
        for(int i=0;i<pos-1;i++){
            curr = curr->next;
        }
        ListNode *nodetodelete = curr->next;
        if(curr->next != NULL) curr->next = curr->next->next;
        delete nodetodelete;
        return head;
    }
};