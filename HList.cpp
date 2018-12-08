#include "HList.h"
#include <iostream>
#include <string>

struct Node {

	int data;
  	Node *next;
  	Node *prev;

};

void HList::print_list() {

	Node *curent_ref = head_ref;
	while(curent_ref != NULL){

		std::cout <<  curent_ref -> data << " " << curent_ref -> next << " " << curent_ref -> prev << std::endl;
		curent_ref = curent_ref -> next;

	}

}
void HList::addElement(int new_data, int position) {

	if (position > n || position < 0) {
		std::cerr << "Position denied." << std::endl;
		return;		
	}

	Node *new_node = new Node{0,NULL,NULL};
	new_node -> data = new_data;

	Node *curent_ref = head_ref;

	if (position == 0) {
		if (head_ref == NULL) {
			head_ref = new_node;
			tail = new_node;
		}
		else {
			head_ref -> prev = new_node;
			new_node -> next = head_ref;
			head_ref = new_node;
		}

	}
	else if (position == n) {
		new_node -> prev = tail;
		tail -> next = new_node;
		tail = new_node;
		new_node -> next = NULL;
	}
	else {

		for(; position > 0 ; position--) {
			//if (curent_ref -> next != NULL) {
				curent_ref = curent_ref -> next;
			//}
		}
		new_node -> next = curent_ref;
		new_node -> prev = curent_ref -> prev;
		curent_ref -> prev -> next = new_node;
		curent_ref -> prev = new_node;
		
	}

	n++;
	std::cout << n << std::endl;
}


HList::HList():		// THE default CONSTRUCTOR //
	head_ref(NULL), tail(NULL), n(0)
{

	std::cout << "HList created." << std::endl;

}

HList::~HList() {   // THE DESTRUCTOR //

	std::cout << "HList destroyed." << std::endl;
	Node *curent_ref = head_ref;

	while (curent_ref != NULL){

		curent_ref = curent_ref -> next;

		if(curent_ref && curent_ref -> prev){
			delete curent_ref -> prev;
		}

	}
	if(tail) {
		delete tail;
	}
}

void HList::addFront(int new_data) {

	// Alocam un nou nod de date.

	Node *new_node = new Node;

	// Ii dam input datele pe care dorim sa le stocam

	new_node -> data = new_data;

	// Primul nod, nu are un antecetend, dar are urmatorul item ,
	// itemul 2(Fostul item 1) (Practic toate itemele devin item n+1.

	new_node -> next = (head_ref);
	new_node -> prev = NULL;

	if (head_ref != NULL) {
		(head_ref) -> prev = new_node;
	} 
	else {
		tail = new_node;
	}

	(head_ref) = new_node;

	n++;
	// std::cout << p -> next << std::endl;

}

void HList::addBack(int new_data) {

	Node *new_node = new Node;
	new_node -> data = new_data;
	tail -> next = new_node;
	new_node -> prev = tail;
	tail = new_node;

}

void HList::removeBack() {


	Node *tail_del = tail;
	tail = tail -> prev;
	tail_del -> prev -> next = NULL;
	delete tail_del;

}

void HList::removeFront() {

	Node *head_del;
	head_ref = head_ref -> next;
	head_del -> next -> prev = NULL;
	delete head_del;
}

int HList::searchFirstOccurence(int data) {

	Node *curent_ref;
	curent_ref = head_ref;
	int curent_pos = 0;

	for(; curent_ref -> data != data ; curent_pos++) {
		curent_ref = curent_ref -> next;
	}
	if (curent_ref -> data == data) {

		std::cout << "Itemul " << data << " apare prima data pe pozitia " << curent_pos << "." << std::endl;

		return curent_pos;
	}
	else {

		std::cout << "Itemul " << data << " nu a fost gasit in lista HList." << std::endl;
		return 0;
	}
}

int HList::searchLastOccurence(int data) {

	Node *curent_ref;
	curent_ref = tail;
	int curent_pos = n - 1;

	for (; curent_ref -> data != data ; curent_pos--) {
		curent_ref = curent_ref -> prev;
	}
	if (curent_ref -> data == data) {

		std::cout << "Itemul " << data << " apare ultima data pe pozitia " << curent_pos << "." << std::endl;

		return curent_pos;
	}
	else {

		std::cout << "Itemul " << data << " nu a fost gasit in lista HList." << std::endl;
		return 0;
	}
}

void HList::moveElement(Node* data, int position) {

if (position > n || position < 0) {
		std::cerr << "Position denied." << std::endl;
		return;		
	}

	Node *curent_ref = head_ref;

	if (position == 0) {
		if (head_ref == NULL) {
			head_ref = data;
			tail = data;
		}
		else {
			head_ref -> prev = data;
			data -> next = head_ref;
			head_ref = data;
		}

	}
	else if (position == n) {
		data -> prev = tail;
		tail -> next = data;
		tail = data;
		data -> next = NULL;
	}
	else {

		for(; position > 0 ; position--) {
			//if (curent_ref -> next != NULL) {
				curent_ref = curent_ref -> next;
			//}
		}
			
		data -> next = curent_ref;
		data -> prev = curent_ref -> prev;
		curent_ref -> prev -> next = data;
		curent_ref -> prev = data;
		
	}
	// std::cout << n << std::endl;
}

/*
void HList::sort(std::string criteria) {

	if () {

		if((head_ref -> data) > (head_ref -> next -> data)) {
			moveElement((head_ref -> next), n);
		
		}
		else if((head_ref -> data) < (head_ref -> next -> data)) {
			moveElement((head_ref), 1);

		}

	}
}
*/