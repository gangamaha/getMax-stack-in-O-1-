//============================================================================
// Name        : stack.cpp
// Author      : gangadhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

struct node{
	int data;
	int max;
	struct node *next;
}*start;

class stack{
public:
	//node* create_node(int);
	void push();
	int pop();
	void getMax();
	void display();
	stack(){
		start=NULL;
	}
};

int main() {
	int choice;
	stack st;
	while(1){
		cout << "Stack Operations" << endl;
		cout << "1. Push element to stack" << endl;
		cout << "2. Pop element from stack" << endl;
		cout << "3. Get Maximum value in the stack" << endl;
		cout << "4. Display entire stack: " << endl;
		cout << "Enter choice" << endl;
		cin >> choice;
		switch(choice){
		case 1: st.push();
				break;
		case 2: st.pop();
				break;
		case 3: st.getMax();
				break;
		case 4: st.display();
				break;
		default: cout << "Invalid choice entered. Exiting.." << endl;
				 return 1;
		}
	}
	return 0;
}

void stack::push(){
	int val;
	cout << "Enter value to be pushed: "<< endl;
	cin >> val;
	struct node *temp;
	temp=new(struct node);
	if(start==NULL){
		temp->data=val;
		temp->max=val;
		start=temp;
		temp->next=NULL;
	}
	else{
		temp->data=val;
		temp->max=fmax(start->max,val);
		temp->next=start;
		start=temp;
		}

}

int stack::pop(){
	struct node *ptr;
	ptr=start;
	if(ptr==NULL){
		cout << "Stack empty. Nothing to pop";
	}
	else{
		ptr=ptr->next;
		start=ptr;
	}
	return 0;
}

void stack::getMax(){
	if(start!=NULL) {
		cout << "Maximum value in stack: " << start->max << endl;
	}
	else{
		cout << "Stack Empty!!" << endl;
	}
}

bool isEmpty(){
	if(start==NULL){
		return true;
	}
	return false;
}

void stack::display(){
	struct node *ptr;
	ptr=start;
	if(isEmpty()){
		cout << "Stack Empty. Nothing to display" << endl;
	}
	while(ptr!=NULL){
		cout << ptr->data << endl;
		ptr=ptr->next;
	}
}
