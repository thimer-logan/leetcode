#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        unordered_map<string, int> subtrees;
        helper(root, subtrees, duplicates);
        return duplicates;
    }
private:
    string helper(TreeNode* root, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
        if (root == nullptr) {
            return "";
        }

        // string may be faster & simpler than using a vector
        string tree = to_string(root->val) + "," + helper(root->left, subtrees, duplicates) + "," + helper(root->right, subtrees, duplicates);
        
        if (subtrees.find(tree) != subtrees.end()) {
            if (subtrees[tree] == 1) {
                duplicates.push_back(root);
            }

            subtrees[tree]++;
        }
        else {
            subtrees[tree] = 1;
        }

        return tree;

    }

};