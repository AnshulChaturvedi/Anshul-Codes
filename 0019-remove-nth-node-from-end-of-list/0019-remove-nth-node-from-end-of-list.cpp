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
        int len = 0;
        ListNode *temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        int pos = len-n;
        if(pos == 0){
            return head->next;
        }
        ListNode *curr = head;
        for(int i=0;i<pos-1;i++){
            curr = curr->next;
        }
        if(curr->next != NULL) curr->next = curr->next->next;
        return head;
    }
};