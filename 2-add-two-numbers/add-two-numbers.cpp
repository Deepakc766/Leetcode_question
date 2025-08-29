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
     ListNode* sum=new ListNode(5);
     ListNode* it=sum;
     int carry=0;
     while(l1 || l2 || carry){
        int s=0;
       int u=0;
       int v=0;
       if(l1)u=l1->val;
       if(l2)v=l2->val;
       s=u+v+carry;
       int digit=s%10;
       carry=s/10;
    ListNode* node=new ListNode(digit);
    it->next=node;
   if(l1)l1=l1->next;
   if(l2)l2=l2->next;
    it=it->next;
     }

     return sum->next;
    }
};