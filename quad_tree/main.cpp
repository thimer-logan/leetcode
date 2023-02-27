#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct_quad_tree(grid, 0, 0, grid.size());
    }

    Node* construct_quad_tree(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 1) {
            return new Node(grid[x][y], true);
        }

        int new_size = size/2;
        Node* top_left = construct_quad_tree(grid, x, y, new_size);
        Node* top_right = construct_quad_tree(grid, x, y + new_size, new_size);
        Node* bottom_left = construct_quad_tree(grid, x + new_size, y, new_size);
        Node* bottom_right = construct_quad_tree(grid, x + new_size, y + new_size, new_size);

        if (top_left->isLeaf && top_right->isLeaf && bottom_left->isLeaf && bottom_right->isLeaf && 
            top_left->val == top_right->val && top_left->val == bottom_left->val && top_left->val == bottom_right->val && 
            top_right->val == bottom_left->val && top_right->val == bottom_right->val & bottom_right->val == bottom_left->val) {
            return new Node(top_left->val, true);
        }
        
        return new Node(false, false, top_left, top_right, bottom_left, bottom_right);
    }
};
