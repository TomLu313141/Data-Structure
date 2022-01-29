// Leetcode 1372
// Use C

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int longest=0;

// 使用遞迴 run through 

void run_through(struct TreeNode* root,int direction,int paths)
{
    if(root!=0)
    {
        if(paths > longest)
            longest = paths;
        
				// 往左
        if(direction == 0)
        {
            run_through(root->left,1,paths+1);
            run_through(root->right,0,1);
        
        }else{  // 往右
            
            run_through(root->left,1,1);
            run_through(root->right,0,paths+1);
        }
    }
}


int longestZigZag(struct TreeNode* root){
    if(root == 0)
        return 0;
    
    longest = 0;

		// 分別對付 左邊先 及 右邊先
    run_through(root,0,0);    
    run_through(root,1,0);
    
    return longest;
}