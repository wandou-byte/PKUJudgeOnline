//Tree Recovery
//Problem 2255

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// TreeNode definition
struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the tree from preorder and inorder traversal
TreeNode* buildTree(const string& preorder, const string& inorder, int& preIndex, int inStart, int inEnd, map<char, int>& inMap) {
	// Base case
	if (preIndex >= preorder.size() || inStart > inEnd) {
		return NULL;
	}

	// The current root is the next element in preorder traversal
	char rootValue = preorder[preIndex++];
	TreeNode* root = new TreeNode(rootValue);

	// Find the index of the root in inorder traversal to split the tree into left and right subtrees
	int inIndex = inMap[rootValue];

	// Recursively build the left subtree
	root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);

	// Recursively build the right subtree
	root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

	return root;
}

// Function to perform postorder traversal of the tree
void postorderTraversal(TreeNode* root, vector<char>& postorder) {
	if (root == NULL) {
		return;
	}

	// Traverse the left subtree
	postorderTraversal(root->left, postorder);
	// Traverse the right subtree
	postorderTraversal(root->right, postorder);
	// Visit the root
	postorder.push_back(root->val);
}

// Function to delete the tree and free memory
void deleteTree(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	string preorder, inorder;
	// Read until EOF
	while (cin >> preorder >> inorder) {
		// Map to store the index of characters in inorder traversal for quick lookup
		map<char, int> inMap;
		for (int i = 0; i < inorder.size(); ++i) {
			inMap[inorder[i]] = i;
		}

		int preIndex = 0;
		TreeNode* root = buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);

		vector<char> postorder;
		postorderTraversal(root, postorder);

		// Output the postorder traversal
		for (vector<char>::iterator it = postorder.begin(); it != postorder.end(); ++it) {
			cout << *it;
		}
		cout << endl;

		// Clean up the tree
		deleteTree(root);
	}
	return 0;
}