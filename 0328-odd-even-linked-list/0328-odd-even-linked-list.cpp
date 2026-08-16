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
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newHead = fast;
        while(fast != NULL && fast->next != NULL){
            slow->next = fast->next;
            slow = fast->next;
            fast->next = slow->next;
            fast = slow->next;
        }
        slow->next = newHead;
        return head;
    }
};