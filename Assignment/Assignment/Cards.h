#pragma once
#include <iostream>
#include <iomanip>
#include "Node.cpp"
using namespace std;

class Cards
{
	private :
		Node* head;

	public :
		Cards();
		void addCard(Node newCard );
		void removeCard();
		void searchCard(string c, int n );
		void displayCards();
};

