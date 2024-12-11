// Write a recursive function to check the given tree is a binary search tree or not. (Mention the tree implementation used i.e., Array or Pointer)

// Function to find max value in the subtree
int maxValue(struct Node* node) {
	if (node == NULL)
		return INT_MIN;
	int leftMax = maxValue(node->left);
	int rightMax = maxValue(node->right);
	return (node->data > leftMax && node->data > rightMax) ? node->data : (leftMax > rightMax ? leftMax : rightMax);
}

// Function to find min value in the subtree
int minValue(struct Node* node) {
	if (node == NULL)
		return INT_MAX;
	int leftMin = minValue(node->left);
	int rightMin = minValue(node->right);
	return (node->data < leftMin && node->data < rightMin) ? node->data : (leftMin < rightMin ? leftMin : rightMin);
}

// Returns true if the binary tree is a BST
int isBST(struct Node* node) {
	if (node == NULL)
		return 1;

	// Check if the max of the left subtree
	// is greater than current node
	if (node->left != NULL && maxValue(node->left) >= node->data)
		return 0;

	// Check if the min of the right subtree
	// is smaller than or equal to current node
	if (node->right != NULL && minValue(node->right) <= node->data)
		return 0;

	// Recursively check if left and right subtrees are BSTs
	return isBST(node->left) && isBST(node->right);
}
