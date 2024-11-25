/*
Assume each node of a tree stores some weight. In the example below, the weights of the respective nodes are 4, 2, 9, etc.

Absolute difference of each node is the difference between the sum of all left subtree node weights and all right subtree node weights.

Eg:

Absolute difference of node 3 : |0-0| = 0 

Absolute difference of node 2 : |3-5| = 2 

And so on for other nodes.

Write a function sum_ absolute_difference () which calculates and returns the sum of absolute difference of all nodes.
*/

int sum_sub_tree_weights(Node *root) {
    if(!root) return NULL;

    int left_subtree_weight = sum_sub_tree_weights(root->left);
    int right_subree_weight = sum_sub_tree_weights(root->right);

    return root->weight + left_subtree_weight + right_subree_weight;
}

int sum_absolute_difference(Node *root) {
    if(!root) return 0;

    int left_subtree_weight = sum_sub_tree_weights(root->left);
    int right_subree_weight = sum_sub_tree_weights(root->right);

    int diff = abs(left_subtree_weight - right_subree_weight);

    int left_abs_diff = sum_absolute_difference(root->left);
    int right_abs_diff = sum_absolute_difference(root->right);

    return diff + left_abs_diff + right_abs_diff;
}