#include "bintree.h"
void insert(Node*& p, int key, double to_be_inserted) { //inserts a new node to the tree or replacese data in an existing node
	if (p->key == NULL or p->key == key) { //if there is no data in the root the new value should be stored there, the data should be replaced if it is the same key
		p->key = key;
		p->data = to_be_inserted;
		return;
	}
	else {
		Node* x = p;
		while (true)
		{
			if (key < x->key) {
				if (x->left == nullptr) { //if there is no key to the left there should be a new node with key and data added to the tree
					Node* new_node = new Node();
					new_node->key = key;
					new_node->data = to_be_inserted;
					new_node->left = nullptr;
					new_node->right = nullptr;
					x->left = new_node;
					return;
				}
				else if (x->left->key == key) { //if the key is already in the tree the data should be replaced
					x->left->data = to_be_inserted;
					return;
				}
				else {
					x = x->left; //do the same thing for the next node
				}
			}
			else {
				if (x->right == nullptr) { //same logic as above but for keys that are greater than the current key instead of less than
					Node* new_node = new Node();
					new_node->key = key;
					new_node->data = to_be_inserted;
					new_node->left = nullptr;
					new_node->right = nullptr;
					x->right = new_node;
					return;
				}
				else if (x->right->key == key) {
					x->right->data = to_be_inserted;
					return;
				}
				else {
					x = x->right;
				}
			}
		}
	}
}

const double& find(Node* p, const int& to_be_found) { //finds a value in the tree which cannot be edited
	if (p == nullptr) {
		throw std::out_of_range("Key not found\n");
	}
	Node* x = p;
	if (x->key == to_be_found) { //if the root contains the to_be_found key then the data should be returned from the root
		return x->data;
	}
	while (true) {
		if (to_be_found < x->key) { //go to the left is key is less than current key
			x = x->left;
		}
		else { //otherwise go right
			x = x->right;
		}
		if (x == nullptr) { //if the current node doesn't exist the key doesn't exist in the tree and an error should be thrown
			throw std::out_of_range("Key not found\n");
		}
		else if (x->key == to_be_found) { //if the current node contains the key then the data should be returned
			return x->data;
		}
	}
}

double& edit(Node* p, const int& to_be_changed) { //same logic as for the find function but returns a double that can be edited
	if (p == nullptr) {
		throw std::out_of_range("Key not found\n");
	}
	Node* x = p;
	if (x->key == to_be_changed) {
		return x->data;
	}
	while (true) {
		if (to_be_changed < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
		if (x == nullptr) {
			throw std::out_of_range("Key not found\n");
		}
		else if (x->key == to_be_changed) {
			return x->data;
		}
	}
}

void delete_tree(Node*& p) { //deletes the entire binary tree
	std::queue<Node*> queue;
	if (p != nullptr) {
		queue.push(p); //push the root to the queue
	}
	while (queue.size() != 0) { //goes through all the nodes of the tree 
		if (queue.front()->left != nullptr) {
			queue.push(queue.front()->left); //add the left child of the first node in the queue to the queue
		}
		if (queue.front()->right != nullptr) {
			queue.push(queue.front()->right); //add the right child of the first node in the queue to the queue
		}
		delete queue.front(); //delete the first node in the queue from the heap
		queue.pop(); //remove the first node from the queue
	}
}

unsigned int max_height(Node* p) {//returns the maximum height of the tree
	if (p == nullptr) { //if the root doesn't exist the tree has no height
		return 0;
	}
	else return 1 + std::max(max_height(p->left), max_height(p->right)); //otherwise it should return the max height between the right/left node + 1 for the current node (recursive)
}

unsigned int min_height(Node* p) { //returns the minimum height, has same logic as the max_height function but for minimum height instead
	if (p == nullptr) {
		return 0;
	}
	else {
		if (p->left != nullptr and p->right != nullptr) {
			return 1 + std::min(min_height(p->left), min_height(p->right));
		}
		else return 1 + std::max(min_height(p->left), min_height(p->right));
	}
}

unsigned int min_height_binary(Node* p) { //returns the shortest chain that leads to a node that doesn't have two children, similar logic to min_height
	if (p == nullptr) {
		return 0;
	}
	else {
		return 1 + std::min(min_height(p->left), min_height(p->right));
	}
}

unsigned int size(Node* p) { //returns the size of the binary tree, has the same logic as the function delete_tree but increaments a value by one for every node instead of deleting the node
	if (p == nullptr) {
		return 0;
	}
	int size = 0;
	std::queue<Node*> queue;
	queue.push(p);
	while (queue.size() != 0) {
		if (queue.front()->left != nullptr) {
			queue.push(queue.front()->left);
		}
		if (queue.front()->right != nullptr) {
			queue.push(queue.front()->right);
		}
		queue.pop();
		size += 1;
	}
	return size;
}

bool is_balanced(Node* p) { //checks if the tree is balanced by checking if the heightdifference is atmost one between the longest chain and the shortest chain.
	if (max_height(p) - min_height_binary(p) <= 1) {
		return true;
	}
	else {
		return false;
	}
}

void remove(Node*& p, const int& key) {//removes a node from the tree
	if (p == nullptr) {
		throw std::out_of_range("Key not found\n");
	}
	Node* x1 = p;
	Node* x2;
	if (x1->key == key) {
		x2 = nullptr;
	}
	else { //this else blocks finds the node (x1) that should be deleted by the same logic that can be found in the function 'find', it also finds the parent of the node (x2)
		while (true) {
			if (key < x1->key) {
				x2 = x1;
				x1 = x1->left;
			}
			else {
				x2 = x1;
				x1 = x1->right;
			}
			if (x1 == nullptr) {
				throw std::out_of_range("Key not found\n");
			}
			else if (x1->key == key) {
				break;
			}
		}
	}

	if (x1->left != nullptr and x1->right != nullptr) { //logic for if the node that should be deleted has two children
		x2 = x1;
		Node* x3 = x1->left;
		while (x3->right != nullptr) { //logic for finding the biggest node to the left of the node that should be deleted and it's parent 
			x2 = x3;
			x3 = x3->right;
		}
		x1->key = x3->key; //replace the key and data of the node that should be deleted with the key and data of the biggest node to the left of the node that should be deleted
		x1->data = x3->data;
		x1 = x3;
	}

	if (x1 == p) { //logic for if the node that should be deleted is the root of the tree and doesn't have two children, the child of the root becomes the new root
		if (x1->left != nullptr) {
			p = x1->left;
		}
		else {
			p = x1->right;
		}
	}
	else if (x2 != nullptr) { //logic for if the node that should be deleted doesn't have two children
		if (x2->left == x1) { //if the node that should be deleted is to the left of the parent the parents node should be linked to it's child
			if (x1->left != nullptr) {
				x2->left = x1->left;
			}
			else {
				x2->left = x1->right;
			}
		}
		if (x2->right == x1) { //same logic as above but for if the node that should be deleted is to the right of the parent
			if (x1->left != nullptr) {
				x2->right = x1->left;
			}
			else {
				x2->right = x1->right;
			}
		}
	}
	delete x1; //the node can now be deleted from the heap
	return;
}