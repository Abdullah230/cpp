#include <iostream>          //header files
#include <string>

using namespace std;

class Node {                 //node class
	string priority;
	string meal;
	Node* next;

public:
	Node() {}
	void SetRank(string aData) { priority = aData; }
	void SetFood(string aData) { meal = aData; }
	void SetNext(Node* aNext) { next = aNext; }
	string Rank() { return priority; }
	string Food() { return meal; }
	Node* Next() { return next; }
};

class List {                             //queue
	Node* head;
	Node* last;
public:
	Node* get_head() { return head; }
	List() { head = NULL; }
	void displayAllRequestsInQueue(Node* head);
	void displayRequestWithHighestPriority();
	void requestFood(string priority, string meal);
	void serveFood();
};
void List::displayRequestWithHighestPriority()
{
	cout << head->Rank() << "-" << head->Food();
}

void List::serveFood() {                        //dequeue
	Node* tmp = head;
	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}
	else {
		head = tmp->Next();
		delete tmp;
	}
}
void List::requestFood(string priority, string meal) {               //enqueue
	Node* newNode = new Node();
	newNode->SetRank(priority);
	newNode->SetNext(NULL);
	newNode->SetFood(meal);
	Node* tmp = head;
	if (tmp != NULL) {
		if (priority == "president")
		{
			Node* tmp = head;
			Node* prev = head;
			int n = 0;
			int m = 0;
			do {
				if (tmp->Rank() != "president")
				{
					if (m != 0) {
						newNode->SetNext(tmp);
						prev->SetNext(newNode);
						n = 1;
					}
					else if (m == 0)
					{
						newNode->SetNext(tmp);
						head = newNode;
						n = 1;
					}
				}
				else
				{
					prev = tmp;
					tmp = tmp->Next();
				}
				m++;
			} while (n == 0);
		}
		else if (priority == "prime minister")
		{
			Node* tmp = head;
			Node* prev = head;
			int n = 0;
			int m = 0;
			do {
				if (tmp->Rank() != "president" && tmp->Rank() != "prime minister")
				{
					if (m != 0) {
						newNode->SetNext(tmp);
						prev->SetNext(newNode);
						n = 1;
					}
					else if (m == 0)
					{
						newNode->SetNext(tmp);
						head = newNode;
						n = 1;
					}
				}
				else
				{
					prev = tmp;
					tmp = tmp->Next();
					if (tmp == NULL)
					{
						prev->SetNext(newNode);
						newNode->SetNext(NULL);
						last = newNode;
						n = 1;
					}
				}
				m++;
			} while (n == 0);
		}
		else if (priority == "speaker")
		{
			Node* tmp = head;
			Node* prev = head;
			int n = 0;
			int m = 0;
			do {
				if (tmp->Rank() != "president" && tmp->Rank() != "prime minister" && tmp->Rank() != "speaker")
				{
					if (m != 0) {
						newNode->SetNext(tmp);
						prev->SetNext(newNode);
						n = 1;
					}
					else if (m == 0)
					{
						newNode->SetNext(tmp);
						head = newNode;
						n = 1;
					}
				}
				else
				{
					prev = tmp;
					tmp = tmp->Next();
					if (tmp == NULL)
					{
						prev->SetNext(newNode);
						newNode->SetNext(NULL);
						last = newNode;
						n = 1;
					}
				}
				m++;
			} while (n == 0);
		}
		else if (priority == "minister")
		{
			Node* tmp = head;
			Node* prev = head;
			int n = 0;
			int m = 0;
			do {
				if (tmp->Rank() != "president" && tmp->Rank() != "prime minister" && tmp->Rank() != "speaker" && tmp->Rank() != "minister")
				{
					if (m != 0) {
						newNode->SetNext(tmp);
						prev->SetNext(newNode);
						n = 1;
					}
					else if (m == 0)
					{
						newNode->SetNext(tmp);
						head = newNode;
						n = 1;
					}
				}
				else
				{
					prev = tmp;
					tmp = tmp->Next();
					if (tmp == NULL)
					{
						prev->SetNext(newNode);
						newNode->SetNext(NULL);
						last = newNode;
						n = 1;
					}
				}
				m++;
			} while (n == 0);
		}
		else if (priority == "MNA")
		{
			Node* tmp = head;
			Node* prev = head;
			int n = 0;
			int m = 0;
			do {
				if (tmp->Rank() != "president" && tmp->Rank() != "prime minister" && tmp->Rank() != "speaker" && tmp->Rank() != "minister" && tmp->Rank() != "MNA")
				{
					if (m != 0) {
						newNode->SetNext(tmp);
						prev->SetNext(newNode);
						n = 1;
					}
					else if (m == 0)
					{
						newNode->SetNext(tmp);
						head = newNode;
						n = 1;
					}
				}
				else
				{
					prev = tmp;
					tmp = tmp->Next();
					if (tmp == NULL)
					{
						prev->SetNext(newNode);
						newNode->SetNext(NULL);
						last = newNode;
						n = 1;
					}
				}
				m++;
			} while (n == 0);
		}
		else
		{
			last->SetNext(newNode);
			last = newNode;
		}
	}
	else {
		head = newNode;
		last = newNode;
	}
}

void List::displayAllRequestsInQueue(Node* head) {
	Node* tmp = head;
	if (tmp != last)
	{
		cout << tmp->Rank() << "-" << tmp->Food() << endl;
		tmp = tmp->Next();
		displayAllRequestsInQueue(tmp);
	}
	else
	{
		cout << tmp->Rank() << "-" << tmp->Food() << endl;
	}
}

void main()
{
	List l1;
	int n = 0;
	do
	{
		system("cls");
		int m = 0;
		cout << "Choose appropriate option: 1-Order food   2-Serve food   3-View Queue  4-Highest priority  5-Exit" << endl;
		cin >> m;
		if (m == 1)
		{
			string priority, food;
			cin.ignore();
			cout << endl << "Enter your priority: ";
			getline(cin, priority);
			cout << endl << "Enter what you would like to order: ";
			getline(cin, food);
			l1.requestFood(priority, food);
			cout << "Thank you for placing the order, you will be served shortly!" << endl;
			system("pause");
		}
		if (m == 2)
		{
			l1.serveFood();
			cout << "Food has been served!" << endl;
			system("pause");
		}
		if (m == 3)
		{
			l1.displayAllRequestsInQueue(l1.get_head());
			system("pause");
		}
		if (m == 4)
		{
			l1.displayRequestWithHighestPriority();
			system("pause");
		}
		if (m == 5)
		{
			n = 1;
		}
	} while (n == 0);
	system("pause");
}
