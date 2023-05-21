#include "Cards.h"

Cards::Cards() {
	head = NULL;
}

void Cards::addCard(Node newCard ) {	
	if (head == NULL) {
		head = &newCard;
		return;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = &newCard;
	}
}

void Cards::removeCard() {
	if (head == NULL) {
		cout << "There are no cards present. Please add a card first." << endl;
		return;
	}
	else if (head->next == NULL)
		head = NULL;
		else{
			Node* temp = head;
			while (temp->next->next!= NULL) {
				temp = temp->next;
			}
		temp->next = NULL;
	}
}

void Cards::searchCard(string c, int n ) {
	Node* temp = head;
	if (head == NULL) {
		cout << "There are no cards present. Please add a card first." << endl;
		return;
	}
	
	int count = 1;
	while (true) {
		if (temp->color == c && temp->number == n) {
			cout << "The " << temp->number << " of " << temp->color << " is present in deck." << endl;
		}
		if (temp->next == NULL)
			break;
		else
			temp = temp->next;

		cout << "Card not found." << endl;
	}
}

void Cards::displayCards() {
	if (head == NULL) {
		cout << "There are no cards present. Please add a card first." << endl;
		return;
	}

	Node* temp = head;
	int count = 1;

	cout << left;
	cout << setw(5) << "No" << setw(20) << "Card Name" << endl;

	while (temp != NULL) {
		cout << setw(5) << count << temp->number << " of " << temp->color << endl;
		temp = temp->next;
	
	}
}



