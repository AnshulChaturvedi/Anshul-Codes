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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int minDist = 1e9, maxDist = -1;
        int first = -1, last = -1;
        int index = 1;
        while(curr->next != NULL){
            if( (curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
                if(first == -1){
                    first = index;
                }
                else{
                    minDist = min(minDist, index-last);
                    maxDist = index-first;
                }
                last = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if(first == last){
            return {-1,-1};
        }
        return {minDist,maxDist};
    }
};