// struct ListNode{
//     int val;
//     ListNode* next;
//     ListNode(): val(0), next(nullptr){}
//     ListNode(int x): val(x), next(nullptr){}
//     ListNode(int x, ListNode* next): val(x), next(next){}
// };

ListNode* createList(int n){
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for(int i=2;i<=n;i++){
        ListNode* nextNode = new ListNode(i);
        curr->next = nextNode;
        curr = nextNode;
    }
    curr->next = head;
    return head;
}

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1) return n;

        ListNode* head = createList(n);
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr->next != curr){
            for(int i=1;i<k;i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        int ans = curr->val;
        delete(curr);
        return ans;
    }
};