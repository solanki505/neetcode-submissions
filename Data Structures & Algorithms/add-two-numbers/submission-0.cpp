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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,c=0;
        ListNode*head=l1,*prev=nullptr;
        while(l1!=nullptr && l2!=nullptr){
            sum=l1->val+l2->val+c;
            l1->val=sum%10;
            c=sum/10;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            sum=l1->val+c;
            l1->val=sum%10;
            c=sum/10;
            prev=l1;
            l1=l1->next;
        }
        while(l2!=nullptr){
            prev->next=l2;
            sum=l2->val+c;
            l2->val=sum%10;
            c=sum/10;
            prev=l2;
            l2=l2->next;
        }
        if(c){
            ListNode * k=new ListNode (c);
            k->next=nullptr;
            prev->next=k;
        }
        return head;
    }
};
