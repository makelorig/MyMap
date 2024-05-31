#include <iostream>
using namespace std;

template <typename T, typename T2>
class MyMap {
private:
	class Node {
	public:
		T key;
		T2 value;
		Node* left;
		Node* right;
		Node(const T& key,T2 value) : key(key), value(value), left(nullptr), right(nullptr) {};
	};
	Node* root;

	Node * findRecursive(Node* node,const T& key) { 
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->key == key) { 
			return node;
		}
		else if (key < node->key)
		{
			return findRecursive(node->left, key);
		}
		else if (key > node->key)
		{
			return findRecursive(node->right, key);
		}
	}

	Node* insertRecursive(Node* node, const T& key, const T2& value) {
		if (node == nullptr)
		{
			return new Node(key,value);
		}
		if (key < node->key)
		{
			node->left = insertRecursive(node->left, key,value);
		}
		else if (key > node->key)
		{
			node->right = insertRecursive(node->right, key,value);
		}
		return node;
	}
	void removeRecursive(Node*& node,const T& key) {
		if (node->left->key == key) {
			if (node->left->left == nullptr && node->right->right == nullptr) {
				delete node->left;
				node->left = nullptr;
				return;
			}
		}
		if (node->right->key == key) {
			if (node->left->left == nullptr && node->right->right == nullptr) {
				delete node->right;
				node->right = nullptr;
				return;
			}
		}
		
	}

	void showRecusive(Node* node) {
		if (node != nullptr)
		{
			showRecusive(node->left);
			cout << node->key << " : "<<node->value<<" ";
			showRecusive(node->right);
		}
	}

public:
	void remove(const T& key) {
		return removeRecursive();
	}
	bool find(const T& key) {
		return findRecursive(this->root, key);
	}

	MyMap() : root(nullptr) {};

	void insert(const T& key,const T2& value) {
		this->root = insertRecursive(root, key,value);
	}

	void show() {
		showRecusive(this->root);
		cout << endl;
	}
	T2& operator[] ( const T key){
		return findRecursive(this->root, key)->value;
	}
};


int main()
{
	MyMap<int,char> set;
	set.insert(52,'h');
	set.insert(67, 'i');
	set.insert(89, 'y');
	set.insert(55, 'n');
	set.show();

	cout << set.find(52);
	cout << set[52];


}
