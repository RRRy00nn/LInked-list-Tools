#include<iostream>
#include<stdio.h>
using namespace std;
typedef int Elemtype;
struct Lnode
{
	Elemtype data;
	struct Lnode* next;
};
//inicialize linked node
//if success, return address of head node, else return nullptr
Lnode* initlist();
//destroy linked node(include head node)
void destroylist(Lnode* head);
//clear node, delete all ecept head node
void clearnode(Lnode* head);
//head input
bool pushfront(Lnode* head, const Elemtype& data);
//head input elem orderly
bool pushorder(Lnode* head, const Elemtype& data);
//show elements(num) in linked node
void printnode(const Lnode* head);
//pushback
bool pushback(Lnode* head, const Elemtype& data);

//find the length of linked node 
//return length
size_t listlength(Lnode* head);
//algorithm of recursion
// if(head==nullptr) return 0;
// return listlength(head->next)+1; 


//delete first node in front
int deletefront(Lnode* head);
//delete last node 
int deleteback(Lnode* head);
//search element(num in list
Lnode* locateelem(const	Lnode* head, const Elemtype& data);
//insert data after selected elem
bool insertnextnode(Lnode* pp, const Elemtype& data);
//insert data before selected elem
bool insertpriornode(Lnode* pp, const Elemtype& data);
//merge two list ----by order---
//lc is a new head node
void mergelist(Lnode* la, Lnode* lb, Lnode* lc);

int main()
{
	Lnode* l = initlist();
	pushfront(l, 1);
	pushfront(l, 2);
	pushfront(l, 3);
	printnode(l);
	destroylist(l);
}
Lnode* initlist()
{
	Lnode* head = new(std::nothrow)Lnode;//giving first node
	if (head == nullptr) return nullptr;//lack of ram, failed to return 
	head->next = nullptr;
	return head;//pointer, an address
}
void destroylist(Lnode* head)
{
	Lnode* tmp;
	while (head != nullptr)
	{
		tmp = head->next;//save next ad
		delete head;// delete node
		head = tmp;//move to next node using ad
	}
}
void clearnode(Lnode* head)
{
	if (head == nullptr)
	{
		cout << "linked node doesnt exist" << endl;
		return;
	}//judge if node exist
	Lnode* tmp1;
	Lnode* tmp2 = head->next;//release all the node after head node
	while (tmp2 != nullptr)
	{
		tmp1 = tmp2->next;
		delete tmp2;
		tmp2 = tmp1;
	}
	head->next = nullptr;//all list is clear now, should put head into null
}
bool pushfront(Lnode* head, const Elemtype& data)
{
	if (head == nullptr)
	{
		cout << "linked node doesnt exist" << endl;
		return false;
	}
	Lnode* tmp = new(std::nothrow)Lnode;
	if (tmp == nullptr) return false;
	tmp->data = data;
	tmp->next = head->next;
	head->next = tmp;
	return true;
}
void printnode(const Lnode* head)
{
	if (head == nullptr)
	{
		cout << "linked node doesnt exist" << endl;
		return;
	}
	Lnode* a = head->next;
	while (a != nullptr)
	{
		cout << a->data << endl;
		a = a->next;
	}
}
bool pushback(Lnode* head, const Elemtype& data)
{
	if (head == nullptr)
	{
		cout << "doesnt exist" << endl;
		return false;
	}
	Lnode* a = head;
	while (a->next != nullptr)
		a = a->next;
	Lnode* tmp = new(std::nothrow)Lnode;
	if (tmp == nullptr)
		return false;
	tmp->data = data;
	tmp->next = nullptr;
	a->next = tmp;
}
size_t listlength(Lnode* head)
{
	if (head == nullptr)
	{
		cout << "list doesnt exist " << endl;
		return false;
	}
	Lnode* pp = head->next;
	size_t length = 0;
	while (pp != nullptr)
	{
		pp = pp->next;
		length++;
	}
	return length;
}
int deletefront(Lnode* head)
{
	if (head == nullptr)
	{
		cout << "doesnt exist";
		return false;
	}
	if (head->next == nullptr)
	{
		cout << "list is empty" << endl;
		return false;
	}
	Lnode* pp = head->next;
	head->next = head->next->next;
	delete pp;
	return true;
}
int deleteback(Lnode* head)
{
	if (head = nullptr)
	{
		cout << "error" << endl;
		return false;
	}
	//***
	if (head->next == nullptr)
	{
		cout << "list is empty,no nodes" << endl;
		return false;
	}//make sure list have an empty head to delete
	Lnode* pp = head;
	while (pp->next->next != nullptr)
		pp = pp->next;
	delete pp->next;
	pp->next = nullptr;
	return true;
}
Lnode* locateelem(const	Lnode* head, const Elemtype& data)
{
	Lnode* pp = head->next;
	while (pp != nullptr)
	{
		if (pp->data == data)
			return pp;
		pp = pp->next;
	}
	return pp;//return null???
}
bool insertnextnode(Lnode* pp, const Elemtype& data)
{
	if (pp == nullptr)
	{
		cout << "node pp doesnt exist" << endl;
		return false;
	}
	Lnode* tmp = new Lnode;
	tmp->data = data;
	tmp->next = pp->next;
	pp->next = tmp;
	return true;

}
bool insertpriornode(Lnode* pp, const Elemtype& data)
{
	//copy the data(in node1) into a new node which connected after node1
	// put data(insert data) into node1
	if (pp == nullptr)
	{
		cout << "node doesnt exist" << endl;
		return false;
	}
	Lnode* tmp = new Lnode;
	//copy pp's node and data into tmp
	tmp->data = pp->data;
	tmp->next = pp->next;
	//put elem that need to insert into pp
	pp->data = data;
	pp->next = tmp;
	return true;
}
bool pushorder(Lnode* head, const Elemtype& data)
{
	if (head == nullptr)
	{
		cout << "list doesnt exist";
		return false;
	}
	Lnode* tail = head;// as a loop, put last node into head pointer
	Lnode* pp = head->next;
	while (pp != nullptr)
	{
		//if elem bigger than data, put ee in front of it
		if (pp->data > data)
		{
			insertpriornode(pp, data);
			return true;
		}
		tail = pp;
		pp = pp->next;
	}
	if (pp == nullptr)
		return insertnextnode(tail, data);
	return true;
}
void mergelist(Lnode* la, Lnode* lb, Lnode* lc)
{
	//lc is a new head node
	Lnode* pa = la->next;
	Lnode* pb =lb->next;
	Lnode* pp;
	//merge
	while ((pa != nullptr) && (pb != nullptr))
	{
		if (pa->data <= pb->data)
		{
			pp = pa;
			pa = pa->next;
		}
		else
		{
			pp = pb;
			pb = pb->next;
		}
		//put smaller list(la or lb) into lc
		lc->next = pp;
		lc = lc->next;
	}
	//put other elem into new list
	if (pa != nullptr)
		lc->next = pa;
	if (pb != nullptr)
		lc->next = pb;
	//need to put la&lb as null , for safe
	la->next = lb->next = nullptr;
}