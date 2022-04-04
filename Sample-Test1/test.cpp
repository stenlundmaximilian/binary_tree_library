#include "pch.h"
#include "bintree.h"

TEST(FindTest, FindNullptr) {
	EXPECT_THROW(find(nullptr, 1),std::out_of_range);
	std::cout << "Tests that find throws out of range if the tree size is 0" << std::endl;
}

TEST(EditTest, EditNullptr) {
	EXPECT_THROW(edit(nullptr, 1), std::out_of_range);
	std::cout << "Tests that edit throws out of range ig the tree size is 0" << std::endl;
}

TEST(Max_heightTest, Max_heightNullptr) {
	EXPECT_EQ(max_height(nullptr), 0);
	std::cout << "Tests that the maximum height of an empty tree is zero" << std::endl;
}

TEST(Min_heightTest, Min_heightNullptr) {
	EXPECT_EQ(min_height(nullptr), 0);
	std::cout << "Tests that the minimum height of an empty tree is zero" << std::endl;
}

TEST(SizeTest, SizeNullptr) {
	EXPECT_EQ(size(nullptr), 0);
	std::cout << "Tests that the size of an empty tree is zero" << std::endl;
}

TEST(Is_balancedTest, Is_balancedNullptr) {
	EXPECT_EQ(is_balanced(nullptr), true);
	std::cout << "Tests that an empty tree is considered balanced" << std::endl;
}


TEST(InsertTest, InsertRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root,1,2);
	EXPECT_EQ(root->key, 1);
	EXPECT_TRUE(root->data,2);
	delete_tree(root);

	std::cout << "Tests that a new node can be inserted in a tree of size one" << std::endl;
}

TEST(FindTest, FindRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_EQ(find(root,1), 2);
	delete_tree(root);
	std::cout << "Tests that a node can be found in a tree of size one" << std::endl;
}

TEST(editTest, EditRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	edit(root,1) = 3;
	EXPECT_EQ(root->data, 3);
	delete_tree(root);

	std::cout << "Tests that a node can be editet in a tree of size one" << std::endl;
}

TEST(Max_heightTest, Max_heightRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_EQ(max_height(root), 1);
	delete_tree(root);

	std::cout << "Tests that the maximum height of a tree of size one is one" << std::endl;
}

TEST(Min_heightTest, Min_heightRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_EQ(min_height(root), 1);
	delete_tree(root);

	std::cout << "Tests that the minimum height of a tree of size one is one" << std::endl;
}

TEST(SizeTest, SizeRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_EQ(size(root), 1);
	delete_tree(root);

	std::cout << "Tests that the minimum height of a tree of size one is one" << std::endl;
}

TEST(Is_balancedTest, Is_balancedRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_EQ(is_balanced(root), true);
	delete_tree(root);

	std::cout << "Tests that a tree of size one is balanced" << std::endl;
}

TEST(RemoveTest, RemoveRoot) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	remove(root,1);
	EXPECT_EQ(root, nullptr);
	delete_tree(root);

	std::cout << "Tests that a node can be removed from a tree of size one" << std::endl;
}


TEST(InsertTest, InsertTwoNodes) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	insert(root, 2, 3);
	EXPECT_EQ(root->key, 1);
	EXPECT_TRUE(root->data, 2);
	EXPECT_EQ(root->right->key, 2);
	EXPECT_TRUE(root->right->data, 3);
	delete_tree(root);

	std::cout << "Tests that two new node can be inserted in a tree of size two" << std::endl;
}

TEST(FindTest, FindTwoNodes) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	insert(root, 2, 3);
	EXPECT_EQ(find(root, 1), 2);
	EXPECT_EQ(find(root, 2), 3);
	delete_tree(root);
	std::cout << "Tests that a node can be found in a tree of size two" << std::endl;
}

TEST(editTest, EditTwoNodes) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	insert(root, 2, 3);
	edit(root, 1) = 3;
	edit(root, 2) = 4;
	EXPECT_EQ(root->data, 3);
	EXPECT_EQ(root->right->data, 4);
	delete_tree(root);

	std::cout << "Tests that a node can be editet in a tree of size two" << std::endl;
}

TEST(FindTest, Throw) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_THROW(find(root,2), std::out_of_range);
	delete_tree(root);
	std::cout << "Tests that std::out_of_range is thrown if you try to find a node and the node is not in the tree" << std::endl;
}

TEST(EditTest, Throw) {
	Node* root = new Node();
	root->data = NULL;
	root->key = NULL;
	root->left = nullptr;
	root->right = nullptr;
	insert(root, 1, 2);
	EXPECT_THROW(edit(root, 2) = 3, std::out_of_range);
	delete_tree(root);
	std::cout << "Tests that std::out_of_range is thrown if you try to edit a node and the node is not in the tree" << std::endl;
}

