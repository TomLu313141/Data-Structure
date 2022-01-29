// Leetcode 328
// Use C

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head) {
    
    // 若為空，回傳 head
    if ( head==0 || head->next == 0) 
        return head;
    
    // 用來記錄使否為奇數
    bool oddFlag = true;
    
    // 開 odd, even 來 run through 
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    
    // 再開兩個來紀錄原始的奇/偶的第一個
    struct ListNode* oddHead = odd;
    struct ListNode* evenHead = even;
    
    head = head->next->next;  
    
    // 拼出新的 linked list
    while (head != 0) {
        
        if (oddFlag) {
            
            odd->next = head;
            odd = odd->next;
            oddFlag = false;
            
        }else{
            
            even->next = head;
            even = even->next;
            oddFlag = true;
        }
        head = head->next;
    }
    
    if (oddFlag == 0)
        even->next = NULL;
    
    odd->next = evenHead;
    
    return oddHead;
}