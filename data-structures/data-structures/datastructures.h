#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

struct treeNode {
	int value;
	bool color; // false = black & true = red
	treeNode* left;
	treeNode* right;
};

class BST {
private:
	treeNode* root;
public:

	//Constructor creates root treeNode 
	BST(int value) {
		this->root = (treeNode*)malloc(sizeof(treeNode));
		this->root->value = value;
		this->root->left = nullptr;
		this->root->right = nullptr;
	}
	treeNode* Search(int value){
		return Search(this->root, value);
	}
	//Search in the tree for value
	treeNode* Search(treeNode* currentNode,int value) {
		if (currentNode == nullptr || currentNode->value == value) {
			return currentNode;
		}
		else if (currentNode->value > value) {
			this->Search(currentNode->left, value);
		}
		else {
			this->Search(currentNode->right, value);
		}
	}
	//Creates new treeNode in the tree at sorted placement
	void Insert(int value) {
		treeNode* insertNode = (treeNode*)malloc(sizeof(treeNode));
		insertNode->value = value;
		insertNode->left = nullptr;
		insertNode->right = nullptr;

		if (this->root == NULL) {
			this->root = insertNode;
		}
		bool inserted = false;
		treeNode* currentNode = this->root;
		while (inserted == false) {
			if (currentNode->value == value) { //value already in tree
				return; 
			}
			else if (currentNode->value > value) { // go left
				if (currentNode->left == nullptr) {
					currentNode->left = insertNode;
					inserted = true;
				}
				else {
					currentNode = currentNode->left;
				}
			}
			else if (currentNode->value < value) { // go left
				if (currentNode->right == nullptr) {
					currentNode->right = insertNode;
					inserted = true;
				}
				else {
					currentNode = currentNode->right;
				}
			}
			else {
				std::cout << "Insert new Node, this line is not supposed to appear!" << std::endl;
			}
		}
	}
	void Traverse() { //overload that gives private field to the implementation.
		Traverse(this->root);
	}
	//Recursively traverses from lowest value to highest
	void Traverse(treeNode* currentNode) { 
		if (currentNode == nullptr) {
			return;
		}
		else {
			Traverse(currentNode->left);
			std::cout << currentNode->value;
			Traverse(currentNode->right);
		}
	}
	void Destroy() {
		Destroy(this->root);
	}
	void Destroy(treeNode* node) //frees all nodes of the tree (includes root)
	{
		if (node == nullptr) {
			return;
		}

		Destroy(node->left);
		Destroy(node->right);

		free(node);
		node = NULL;
		if (this->root != nullptr) {
			this->root = nullptr;
		}
	}
};
#endif