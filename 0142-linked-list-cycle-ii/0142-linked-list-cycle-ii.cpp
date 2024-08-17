/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        //detecting whether cycle is present or Not
        bool found = false;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                found = true;
                break;
            }
        }
        //position where cycle begins
        if(found){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return NULL;
    }
};