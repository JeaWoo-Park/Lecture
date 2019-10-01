#include <iostream>

struct Node {
	int data;
	Node* tail;
	Node* left;
	Node* right;
};

struct Tree {
	int cnt;
	Node* root;
};
Node* KeyNode;
void AddNode(Tree* tree, Node node) {
	Node* newNode = new Node;
	newNode->data = node.data;
	if (tree->cnt == 0) {
		tree->root = newNode;
		tree->root->left = NULL;
		tree->root->right = NULL;
		tree->root->tail = NULL;
		tree->cnt++;
	}
	else {
		KeyNode = tree->root;
		if (node.data < KeyNode->data) {
			if (KeyNode->left == NULL) {
				KeyNode->left = newNode;
				newNode->tail = KeyNode;
			}
			else {
				KeyNode = KeyNode->left;
			}
			tree->cnt++;
		}
		else if (node.data > KeyNode->data) {
			if (KeyNode->right == NULL) {
				KeyNode->right = newNode;
				newNode->tail = KeyNode;
			}
			else {
				KeyNode = KeyNode->right;
			}
			tree->cnt++;
		}
		else {
			std::cout << "이미 같은 수 가 저장 되어 있습니다." << std::endl;
		}
	}
}

Tree* CreateTree() {
	Tree* tree = new Tree;
	if (tree == NULL) {
		std::cout << "erro" << std::endl;
	}
	else {
		tree->cnt = 0;
		tree->root = NULL;
	}
	return tree;
}
int main() {
	Tree* tree = CreateTree();
	Node node;
	node.data = 50;
	AddNode(tree, node);
	node.data = 30;
	AddNode(tree, node);
	node.data = 70;
	AddNode(tree, node);
	node.data = 20;
	AddNode(tree, node);
	node.data = 40;
	AddNode(tree, node);
	node.data = 60;
	AddNode(tree, node);
	node.data = 80;
	AddNode(tree, node);
	std::cout << "잘 됨" << std::endl;
}