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
    ListNode* reverse(ListNode* &head){
        ListNode *prevNode = NULL;
        ListNode *nextNode;
        while(head != NULL){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    // bool checkPalindrome(vector<int> &arr){
    //     vector<int> ans = arr;
    //     reverse(ans.begin(),ans.end());
    //     return ans == arr;
    // }

    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *middle = slow;

        ListNode *temp = reverse(middle->next);

        while(temp != NULL){
            if(temp->val != head->val){
                return false;
            }
            head = head->next;
            temp = temp->next;
        }
        return true;

        // vector<int> arr;
        // while(head != NULL){
        //     arr.push_back(head->val);
        //     head = head->next;
        // }
        // return checkPalindrome(arr);
    }
};