#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next, * prev;
	node(int d, node* p = 0, node* n = 0)
	{
		data = d; prev = p; next = n;
	}
};
class list
{
	node* tail;
public:
	list();
	void print_back();
	void add_end(int el);
	int search(int el);
	void add_begin(int el);
	void add_pos(int el, int p);
	void print_forward();
	~list();
	void count();
	void add_sort(int el);
	bool delete_pos(int p);
	void operator=(list& o);
	bool delete_redun();
};
void list::add_sort(int el) {
	if (tail == 0)
		tail = new node(el);
	else {
		node* t = tail;
		for (; t != 0; t = t->prev)
			if (t->data > el)
				t->prev = new node(el, t, t->prev);
	}
}

list::list()
{
	tail = 0;
}
int list::search(int el) {
	int p = 0;
	node* t = tail;
	for (; t->prev != 0; t = t->prev);
	for (node* t2 = t; t != 0; t = t->next) {
		p++;
		if (t->data == el)
			return p;
	}
}

void list::add_begin(int el) {
	node* t = tail;
	for (; t->prev != 0; t = t->prev);
	t->prev = new node(el, 0, t);
}

void list::add_end(int el)
{
	if (tail == 0)
		tail = new node(el);
	else
	{
		tail = tail->next = new node(el, tail);
	}
}
void list::print_back()
{
	node* t = tail;
	for (; t != 0; t = t->prev)
		cout << t->data << " ";
	cout << endl;
}
void list::print_forward() {
	node* t = tail;
	for (; t->prev != 0; t = t->prev);
	for (node* tem = t; t != 0; t = t->next)
		cout << t->data << "  ";
	cout << endl;
}
list::~list() {

	while (tail->prev != 0) {
		tail = tail->prev;
		delete tail->next;
	}
	cout << "list deleted" << endl;

}
void list::add_pos(int el, int p) {
	int pp = 0;
	//inversadding
	for (node* t2 = tail; t2 != 0; t2 = t2->prev) {
		pp++;
		if (p == pp)
			t2->next = new node(el, t2, t2->next);
	}
	//normaladding
	/*
	node *t = tail;
	for (; t->prev != 0; t = t->prev);
	for (node* t2 = t; t2 != 0; t2 = t2->next) {
		pp++;
		if (p == pp)
			t2->prev->next= new node(el, t2->prev, t2);
	}*/
}

void list::count() {
	int count = 0;
	node* t = tail;
	for (; t->prev != 0; t = t->prev);
	//cout << t->prev << " check" << endl; 
	for (node* t2 = tail; t2 != 0; t2 = t2->prev)
		if (t->data == t2->data) {
			count++;
		}
	t->prev = new node(count, 0, t);
	cout << "end count" << endl;
}
bool list::delete_pos(int p) {
	if (tail == 0)
		return false;
	else {
		node* t = tail;
		for (int i = 1; i < p; i++)
			t = t->prev;
		t->prev->next = t->next;
		t->next->prev = t->prev;

		delete t;
		return true;
	}

}
void list:: operator=(list& o) {
	while (tail != 0);
		//delete_end;
	if (o.tail != 0){
		node* t2 = o.tail;
		for (; t2->prev != 0; t2 = t2->prev);
	node* t1 = t2;
	while (t1 != 0) {
		add_end(t1->data);
		t1 = t1->next;
	}
	}

}

bool list::delete_redun() {
	if (tail == 0)return false;
	node* t = tail;
	while (t != 0) {
		for (node* t2 = tail; t2 != 0; t2 = t2->prev) {
			node* t3 = t2->prev;
			if (t3->prev == 0) {
				if (t3->data == t->data) {
					t2->prev = 0;
					delete t3;
					break;
				}
				else return false;
			}
			if (t->data == t3->data){
				t2->prev = t3->prev;
				t3->prev->next = t2;
			delete t3;
			}
		}t = t->prev;
	}
	return true;
}


void main()
{
	list l1, l2;
	l1.add_end(3);
	l1.add_end(4);
	l1.add_end(1);
	l1.add_end(2);
	l1.add_end(3);
	l1.add_end(3);
	l1.add_end(4);
	l1.add_end(3);
	//l1.add_pos(100,3);
	cout << " backword" << endl;
	l1.print_back();
	cout << " forword" << endl;
	l1.print_forward();
	//l1.count();
	l1.delete_pos(3);
	cout << " forword2 " << endl;
	//l1.print_forward();
	cout << "found el the ele is in " << l1.search(4) << endl;
	cout << " backword" << endl;
	l1.print_back();
	l2 = l1;
	cout << "-----------\n 2listt  backword" << endl;

	l2.delete_redun();
	l2.print_back();
}