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

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            ListNode* current = (l1 != nullptr) ? l1 : (l2 != nullptr) ? l2 : nullptr;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum %= 10;

            if (current != nullptr) {
                current->val = sum; 
                tail->next = current;
            } else {
                tail->next = new ListNode(sum); 
            }

            tail = tail->next;
        }

        tail->next = nullptr;
        return dummy.next;
    }
};