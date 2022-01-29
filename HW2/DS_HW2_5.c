// Leetcode 725
// Use C++

// earlier parts are a larger size than the later parts
// len = total / k 
// residual = total % k

// 共有 residual 個要做修正 =>  len + 1

// 兩個指標，一個(previous)指向 A部分的尾，另一(head)指向 B部分的頭 
// 將 previous 指向 null，即可斷開

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

class Solution{
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k){
        int total = 0;

				// 計算原始的總長
        for(ListNode* head = root; head!=nullptr; head = head -> next)
            ++total;
        
				// 回傳值 ans 的型態為 vector
        vector<ListNode*> ans(k,nullptr);

        int len = total / k;
        int resi = total % k;

        ListNode* head = root;
        ListNode* previous = nullptr;

        for(int i = 0; i < k; ++i, -- resi){
            ans[i] = head;

            int part_len = len + ((resi > 0) ? 1 : 0);

            for( int j = 0; j < part_len ; ++j){

                previous = head;
                head = head -> next; 
            }

            if(previous != nullptr)
                previous -> next = nullptr;
        }
        return ans;
    }
};
