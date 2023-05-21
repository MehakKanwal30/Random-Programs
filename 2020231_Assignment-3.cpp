#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class MatrixMultiply {
	private :
		double** matrix;
		int row, col;
	
	public :
		MatrixMultiply( int r = 0, int c = 0 ) {
			if ( r == 0 && c == 0 ) {
				cout << "Enter total number of rows: ";
				cin >> row;
				cout << "Enter total number of columns: ";
				cin >> col;
			}
			else {
				row = r;
				col = c;
			}
		} 
		
		void Initialize() {			
			matrix = new double*[row];
			for ( int i=0; i<row; i++ )
				matrix[i] = new double[col];
		}
		
		void fill() {
			for ( int i=0; i<row; i++ ) {
				for ( int j=0; j<col; j++ ) {
					matrix[i][j] = (double)rand() / 500;
				}
			}
		}
		
		bool MultiplyCheck( MatrixMultiply m ) {
			if ( col == m.row )
				return true;
			else
				return false;	
		}
		
		MatrixMultiply Multiply( MatrixMultiply m ) {
			MatrixMultiply result( row, m.col );
			result.Initialize();
			
			for ( int i=0; i<row; i++ ) {
				for ( int j=0; j<m.col; j++ ) {
					for ( int k=0; k<col; k++ )
						result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
			
			return result;	
		}
		
		void display() {
			for ( int i=0; i<row; i++ ){
				for ( int j=0; j<col; j++ )
					cout << left << setw(15) << setprecision(5) << matrix[i][j];
				cout << endl;	
			}
		}
	
};

int main() {
	srand(time(0));
	
	MatrixMultiply M1;
	MatrixMultiply M2;
	
	M1.Initialize();
	M2.Initialize();
	
	M1.fill();
	M2.fill();
	
	MatrixMultiply M3(1,1);
	
	if ( M1.MultiplyCheck( M2 ) ) {
		M3 = M1.Multiply( M2 );		
	}
	else
		cout << "Sorry! The Matrixs' can not be multiplied.'" << endl;	
		
	system("CLS");
	cout << "First Matriix:" << endl;
	M1.display();
	
	cout << "\nSecond Matrix:" << endl;
	M2.display();
	
	cout << "\n\nResult after multiplication:" << endl;
	M3.display();	
		
		
}
