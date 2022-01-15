#include <iostream>
using namespace std;
template <typename T>
struct Node {
	T value;
	Node* right;
	Node* left;
	Node()
	{
		this->left = NULL;
		this->right = NULL;
	}
};

template <typename T>
class tree {
private:
	unsigned long long size;
	Node<T>* head;

	void add(T value, Node<T>** tmp) {
		if ((*tmp) == NULL) {
			(*tmp) = new Node<T>;
			(*tmp)->value = value;
			size++;
			//this->head = (*tmp);
			return;
		}

		if (value > (*tmp)->value) {
			add(value, &(*tmp)->right);
		}
		else {
			add(value, &(*tmp)->left);
		}
	}

	
	void show(Node<T>** tmp,unsigned int depth) {

		for (unsigned int i = 0; i < depth; i++) {
			cout << "-";
		}

		cout << (*tmp)->value<<"\n";
		if ((*tmp)->right != NULL) {
			show(&(*tmp)->right,depth+1);
		}
		if ((*tmp)->left != NULL) {
			show(&(*tmp)->left,depth+1);
		}

	}

public:
	tree()
	{
		this->head = NULL;
		this->size = 0;
	}

	void add(T value) {
		Node<T>** tmp = &this->head;
		this->add(value, tmp);
	}

	void show() {
		Node<T>** tmp = &this->head;
		show(tmp,0);
	}

	Node<T>* getHead() {
		return head;
	}
	void remove() {

	}

};

int main()
{

	tree<int> test;


	Node<int>* tmp = test.getHead();
	test.add(5);
	test.add(7);
	test.add(3);
	test.add(8);
	test.add(7);
	test.add(10);
	test.add(1);
	test.add(2);
	test.show();
}
