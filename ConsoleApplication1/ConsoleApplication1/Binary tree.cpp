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
	T* mas = nullptr; //немного костылей никогда не помешает :)


	void add(T value, Node<T>*& tmp) {



		if (tmp == NULL) {
			tmp = new Node<T>;
			tmp->value = value;
			return;
		}

		if (value > tmp->value) {
			add(value, tmp->right);
		}
		else {
			add(value, tmp->left);
		}
	}

	void show(Node<T>** tmp, unsigned int depth) {

		for (unsigned int i = 0; i < depth; i++) {
			cout << "-";
		}

		cout << (*tmp)->value << "\n";
		if ((*tmp)->right != NULL) {
			show(&(*tmp)->right, depth + 1);
		}
		if ((*tmp)->left != NULL) {
			show(&(*tmp)->left, depth + 1);
		}

	}

	void removeFromMas(T value) {
		T* tmp = new T[this->size - 1];
		unsigned long long j = 0;

		for (int i = 0; i < this->size; i++) {
			if (this->mas[i] != value) {
				tmp[j] = mas[i];
				j++;
			}
		}
		this->size = j;
		this->mas = new T[size];
		for (int i = 0; i < this->size; i++) {
			this->mas[i] = tmp[i];
		}
	}

	void remove(T value, Node<T>** tmp) {
		//супер-мега костыль :D
		delete this->head;
		this->head = NULL;
		unsigned long long temp = this->size;
		size = 0;
		for (int i = 0; i < temp; i++) {
			add(mas[i],this->head);
			this->size++;
		}

	}


public:
	tree()
	{
		this->head = NULL;
		this->size = 0;
	}

	//+ еще немного костылей
	bool isIn(T value) {
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i] == value) {
				return true;
			}
		}
		return false;
	}

	void remove(T value) {
		if (isIn(value) == true) {
			this->removeFromMas(value);
			Node<T>** tmp = &this->head;

			this->remove(value, tmp);
		}
		else {
			cout << "\n\nERROR:Unexpected value";
		}
	}

	void addWithoutMas(T value) {

	}

	void add(T value) {

		T* temp = new T[this->size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = mas[i];
		}
		temp[this->size] = value;
		delete mas;
		this->size++;
		mas = new T[this->size];
		for (int i = 0; i < size; i++) {
			mas[i] = temp[i];
		}
		this->add(value, this->head);
	}

	void show() {
		Node<T>** tmp = &this->head;
		show(tmp, 0);
	}

	Node<T>* getHead() {
		return head;
	}
	unsigned long long getSize() {
		return this->size;
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

	test.add(6);
	test.add(7);
	test.add(1);
	test.add(2);

	//cout<<test.isIn(2)<<"\n\n";
	test.remove(7);
	test.remove(3);
	//cout<<test.getSize()<<"\n";
	test.show();
}
