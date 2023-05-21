#include <iostream>
#include "Cards.h"

using namespace std;

int main() {
	Cards Deck;
	string col;
	int num, choice, choice2;

	while (true) {
		cout << "What would you like to do :" << endl << endl;
		cout << "1-Add Card.\n2-Remove Card.\n3-Search Card.\n4-Display Cards.\n5-Exit\n\nYour Choice : ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "What is the color of your card : " << endl << endl;
			cout << "1-Hearts.\n2-Clubs.\n3-Spades.\n4-Diamonds.\n\nYour Choice : ";
			cin >> choice2;
			if (choice2 == 1)	col = "Hearts";
			if (choice2 == 2)	col = "Clubs";
			if (choice2 == 3)	col = "Spades";
			if (choice2 == 4)	col = "Diamonds";

			cout << "Enter number of your card : ";
			cin >> num;

			Node newCard;
			newCard.setColor(col);
			newCard.setNumber(num);
			
			Deck.addCard(newCard);
			break;
		}
		case 2:
			Deck.removeCard();
			break;
		case 3: {
			cout << "Which card do you want to search for : " << endl;
			cout << "Enter card number : ";
			cin >> num;
			cout << "Enter card suit : " << endl;
			cout << "1-Hearts.\n2-Clubs.\n3-Spades.\n4-Diamonds.\n\nYour Choice : ";
			cin >> choice2;
			if (choice2 == 1)	col = "Hearts";
			if (choice2 == 2)	col = "Clubs";
			if (choice2 == 3)	col = "Spades";
			if (choice2 == 4)	col = "Diamonds";

			Deck.searchCard(col, num);
			break;
		}
		case 4:
			Deck.displayCards();
			break;
		case 5:
			exit(0);
		}
		system("pause");
		system("CLS");
	}
}
