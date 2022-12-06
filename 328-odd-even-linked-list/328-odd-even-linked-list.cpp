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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead = head;
        ListNode* evenhead;
        if(head == NULL) return NULL;
        if(head->next)  evenhead = head->next;
        else return head;
        ListNode* ini_even = head->next;
        while(oddhead->next->next && evenhead->next->next){
            oddhead->next = oddhead->next->next;
            evenhead->next = evenhead->next->next;
            oddhead = oddhead->next;
            evenhead = evenhead->next;
        }
        if(oddhead->next->next){
            oddhead->next = oddhead->next->next;
            oddhead = oddhead->next;
        }
        evenhead->next = NULL;
        oddhead->next = ini_even;
        return head;
    }
};