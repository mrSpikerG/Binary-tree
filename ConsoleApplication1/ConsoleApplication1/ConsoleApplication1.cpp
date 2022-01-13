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

		cout << head->value;
		/*Node<T>* tmp = this->head;

		cout << "\n"
			<< "left" << head->left
			<< "right" << head->right;*/

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
	test.add(1);
	test.add(7);
	test.add(3);

	test.show();
}
