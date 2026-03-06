#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here

void List::remove(int target_index){
	if (target_index < 0 || target_index >= size) {
		return; // Invalid index
	}
	
	Node* searching = root;
	
	if (target_index == 0) {
		root = searching->next; // Move root to the next node
		delete searching; // Delete the old root
	} else {
		for (int i = 0; i < target_index - 1; i++) {
			searching = searching->next; // Move to the node before the target
		}
		Node* to_delete = searching->next; // Node to be deleted
		searching->next = to_delete->next; // Bypass the node to be deleted
		delete to_delete; // Delete the target node
	}
	size--;
}