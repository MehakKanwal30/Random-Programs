#pragma once

#include "Node.h"


template <class S>
class Queue {
private:
	Node<S>* head;
	Node<S>* tail;
	int size;

public:
	Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void enqueue( S data ) {
		Node<S>* newNode;
		newNode->data = data;
		
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	S dequeue() {
		if (head == NULL)
			cout << "Queue is empty yes" << endl;
		else {
			if (head == tail) {
				S data = head->data;
				Node<S>* temp = head;
				head = NULL;
				tail = NULL;
				delete(temp);
				size--;
				return data;
			}
			else {
				S data = head->data;
				Node<S>* temp = head;
				head = head->next;
				delete(temp);
				size--;
				return data;
			}
		}
	}

	int getSize() {
		return size;
	}

	S front() {
		return head->data;
	}

	void sort() {
		if (head == NULL)
			cout << "Queue is empty no" << endl;
		else {
			Node<S>* temp1 = head;
			Node<S>* temp2 = head->next;
			while (temp1 != NULL) {
				while (temp2 != NULL) {
					if (temp1->data > temp2->data) {
						S data = temp1->data;
						temp1->data = temp2->data;
						temp2->data = data;
					}
					temp2 = temp2->next;
				}
				temp1 = temp1->next;
				temp2 = temp1;
			}
		}
	}
};
