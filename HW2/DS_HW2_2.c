// Leetcode 206
// Use C

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode *previous = NULL;

    struct ListNode *next = NULL;

    if( head == NULL ) 
			return NULL;

    while( head!= NULL ){  // 每一個都要反轉
    
        next = head->next; //先連接，用以保存節點
        head->next = previous;  //斷開
        previous = head;        //往前移 
        head = next;       
    }
    return previous;
}