## Check for BST

Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Expected Time Complexity: O(n)

Expected Auxiliary Space: O(Height of the tree)
where n is the number of nodes in the given tree

Constraints:

1 ≤ Number of nodes ≤ 105

1 ≤ Data of a node ≤ 105

```cpp
bool isBSTutil(Node *root,int& init){
    if (root!=nullptr) {
        if(!isBSTutil(root->left,init)){
            return false;
        }
        if (root->data<=init){
            return false;
        }
        init = root->data;
        return isBSTutil(root->right, init);
    }
    return true;
}
bool isBST(Node* root) {
    int init = 0;
    return isBSTutil(root,init);
}
```