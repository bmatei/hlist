#pragma once
#include <cstdint>
#include <string>

struct Node;



class HList {
public:
	HList();
	~HList();
	void addFront(int new_data);
	void addBack(int new_data);
	void addElement(int new_data, int position);
	void removeElement(int position);
	void removeFront();
	void removeBack();
	void print_list();
	int searchFirstOccurence(int data);
	int searchLastOccurence(int data);
	void moveElement(Node* data, int position);
	
	int searchNthOccurence(int data, int &N);

//optional
	void sort(std::string criteria);


private:
	 
	Node *head_ref;
	Node *tail;
	std::uint32_t n;

};