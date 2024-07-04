// struct ListNode{
//     int val;
//     ListNode *next;
//     ListNode() : val(0) , next(nullptr) {}
//     ListNode(int x) : val(x) , next(nullptr) {}
//     ListNode(int x,ListNode* next) : val(x) , next(next) {}
// };


class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* forw = head;
        head = forw;
        int sum = 0;

        while(curr->next != NULL){
            sum += curr->val;
            if(curr->next->val == 0){
                ListNode* newNode = new ListNode(sum);
                forw->next = newNode;
                forw = newNode;
                sum = 0;
            }
            curr = curr->next;
        }
        head = head->next;
        return head;
    }
};