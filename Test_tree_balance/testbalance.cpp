#include "bintree.h"
#include <vector>
#include <array>
#include <iostream>
#include <random>
#include <algorithm>

int main() {
	int nodes = 9000; //number of nodes in each tree
	int trees = 800; //number of trees to average over
	std::vector<int> v; //vector with the values from 1 to 9000
	for (int i = 1; i <= nodes; i++) {
		v.push_back(i);
	}
	std::shuffle(v.begin(),v.end(),std::default_random_engine(000530)); //shuffles the vector with my birthday as random seed
	std::vector<int> min_v; //vector with min height of tree
	std::vector<int> max_v; //vector with max height of tree
	std::vector<int> min_max_v;

	for (int i = 0; i < trees; i++) { 
		Node* root = new Node(); //create node
		root->data = NULL;
		root->key = NULL;
		root->left = nullptr;
		root->right = nullptr;

		for (int i : v) //insert the vector into the tree
			insert(root, i, i);
		
		min_v.push_back(min_height(root)); //store the min height value
		max_v.push_back(max_height(root)); //store the max height value
		min_max_v.push_back(max_height(root) - min_height(root)); //store the difference between max_height and min_height
		//std::next_permutation(v.begin(),v.end());
		auto rng = std::default_random_engine{};
		std::shuffle(v.begin(),v.end(),rng);  //shuffle the vector
		delete_tree(root); //delete the tree
	}

	int x1 = 0;
	int x2 = 0;
	for (int i : max_v) { //finds all values related to max
		x1 += i;
		if (i > x2) {
			x2 = i;
		}
	}

	int x3 = 0;
	int x4 = nodes;
	for (int i : min_v) { // finds all values related to min
		x3 += i;
		if (i < x4) {
			x4 = i;
		}
	}

	int x5 = 0;
	int x6 = 0;
	int x7 = nodes;
	for (int i : min_max_v) { //finds all values related to the difference of max and min
		x5 += i;
		if (i > x6) {
			x6 = i;
		}
		if (i < x7) {
			x7 = i;
		}
	}

	std::cout << "avg height: " << x1 / trees << std::endl;
	std::cout << "max height: " << x2 << std::endl;
	std::cout << "avg min height: " << x3 / trees << std::endl;
	std::cout << "min height: " << x4 << std::endl;
	std::cout << "avg height difference: " << x5 / trees << std::endl;
	std::cout << "max height difference: " << x6 << std::endl;
	std::cout << "min height difference: " << x7 << std::endl;
}
