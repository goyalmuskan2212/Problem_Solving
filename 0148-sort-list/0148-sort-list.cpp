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
    ListNode* mergeSort(ListNode* left, ListNode* right){
        ListNode* newDummy = new ListNode(-1);
        ListNode* dummy = newDummy;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                dummy->next = left;
                left = left->next;
            }
            else{
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        if(left != NULL){
            dummy->next = left;
            left = left->next;
        }
        else{
            dummy->next = right;
            right = right->next;
        }
        return newDummy->next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeSort(left, right);
    }
};