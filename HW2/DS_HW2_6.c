// LeetCode 671
// Use C++

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution{
public:
int findSecondMinimumValue(TreeNode* root){
    if(root==nullptr)
        return -1;
    
    return findvalue(root);
}
private:

    int findvalue(TreeNode* root){
        // 使用 Breadth-First-Search
				// by queue

        if(root==nullptr)
            return -1;
        
        int smallest = root -> val;
        int target = INT_MAX; // second small，INT_MAX = 2147483647
        bool found = false;

        deque<TreeNode*> queue;
        queue.push_back(root);

        // 當 queue 不為空時，去找ans
        while(!queue.empty()){

            // queue 為 FIFO
            TreeNode* node = queue.front();
            queue.pop_front();


            if(node -> val > smallest && node -> val <= target){
                target = node -> val;
                found = true;
								// 不用在繼續往下找
                continue;
            }

            if(!node -> left)
                continue;
            
            queue.push_back(node -> left);
            queue.push_back(node -> right);
        }

        return found ? target : -1;
    }
};
