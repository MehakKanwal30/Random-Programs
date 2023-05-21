#include <iostream>
using namespace std;

class Arrays {
	private :
		int*** array;
		int x, y ,z;
		
	public :
		Arrays() {
			cout << "Enter number of 2d arrays : ";
			cin >> x;
			
			cout << "Enter number of rows in array : ";
			cin >> y;
			
			cout << "Enter number of columns in array : ";
			cin >> z;
			
			array = new int**[x];
			for ( int i=0; i<x; i++ ) {
				array[i] = new int*[y];
				
				for ( int j=0; j<y; j++ ) {
					array[i][j] = new int[z];
				}
			}
		}	
		
		fill() {
			system("CLS");
			cout << "1 2 3\n4 5 6\n7 8 9\n\n10 11 12\n13 14 15\n16 17 18\n" << endl;
			cout << "Enter your numbers in the same manner as given above, starting from the top left\n" << endl;
			
			for ( int i=0; i<x; i++ ) {
				for ( int j=0; j<y; j++ ) {
					for ( int k=0; k<z; k++ ) {
						cin >> array[i][j][k];	
						cout << "\ni = " << i << "\nj = " << j << "\nk = " << k << 	endl;	
					}
				}
			}
		}
		
		display() {
			system("CLS");
			for ( int i=0; i<x; i++ ) {
				for ( int j=0; j<y; j++ ) {
					for ( int k=0; k<z; k++ ) {
						cout << array[i][j][k] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
		}	
};

int main() {
	Arrays a;
	a.fill();
	a.display();
}
