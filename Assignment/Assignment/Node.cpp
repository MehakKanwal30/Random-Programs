#include <iostream>
using namespace std;

class Node {
	public:
		Node* next;
		string color;
		int number;

		Node() {
			next = NULL;
			color = "";
			number = 0;
		}
		void setColor(string c) {
			color = c;
		}
		void setNumber(int n) {
			number = n;
		}
};