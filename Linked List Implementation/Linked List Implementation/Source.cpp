#include <iostream>>
#include <conio.h>
using namespace std;

class Node {
private:
	int i;
	Node* next;


public:
	Node() {};
	void setNext(Node* e) {
		next = e;
	};
	Node* getNext() {
		return next;
	};
	void setData(int a) {
		i = a;
	};
	int getData() {
		return i;
	};
};

class List {
private:
	Node* temp, * head, * n, * null;
public:
	List() {
		null = NULL;
		temp = NULL;
	}
	void print() {
		temp = head;
		if (temp == NULL) {
			cout << "EMPTY!" << endl;
		}

		while (temp != NULL && temp->getNext() != NULL) {
			cout << temp->getData() << "--> ";
			temp = temp->getNext();
			if (temp->getNext() == NULL) {
				cout << temp->getData() << "--> ";
				cout << "Empty!";
			}


		}
		temp = head;



	}
	void Append(int r) {
		if (temp == NULL) {
			n = new Node;
			n->setData(r);
			temp = n;
			head = n;
			temp->setNext(null);
			temp = head;
		}
		else if (temp != NULL) {
			n = new Node;
			n->setData(r);
			while (temp->getNext() != NULL) {
				temp = temp->getNext();
			}
			temp->setNext(n);
			temp = n;
			temp->setNext(null);
			temp = head;
		}
	}
	void del(int q) {
		Node* prev = NULL;

		if (head->getData() == q)
		{
			temp = head;
			head = head->getNext();
			delete temp;
		}
		else
		{
			temp = head;
			while (temp != NULL && temp->getData() != q)
			{
				prev = temp;
				temp = temp->getNext();
			}

			prev->setNext(temp->getNext());
			cout << "Deleted value: " << temp->getData() << endl << endl << endl;
			delete temp;
		}







	}



};

int main() {
	List L0;
	L0.Append(2);
	L0.Append(6);
	L0.Append(8);
	L0.Append(7);
	L0.Append(7);
	L0.Append(1);
	L0.Append(2);
	L0.Append(4);
	L0.Append(3);
	L0.Append(5);
	L0.Append(9);
	L0.print();
	cout << endl << "Deleting first term..." << endl;
	L0.del(2);
	cout << "Deleting last term..." << endl;
	L0.del(9);
	L0.print();
	_getch();
	system("CLS");
	cout << "Creating the list L1" << endl;
	List L1;
	L1.Append(5);
	L1.Append(10);
	L1.Append(15);
	L1.Append(20);
	L1.Append(25);
	L1.Append(30);
	L1.Append(35);
	L1.Append(40);
	L1.print();
	List L2, L3;
	cout << "Adding 20 and 30 to L2" << endl;
	L1.del(20);
	L1.del(30);
	L2.Append(20);
	L2.Append(30);
	cout << "Adding 5 and 10 to L3" << endl;
	L1.del(5);
	L1.del(10);
	L3.Append(5);
	L3.Append(10);
	L1.print();
	L2.print();
	L3.print();
	_getch();
	return 0;



	return 0;
}
