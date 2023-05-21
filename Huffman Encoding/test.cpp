#include<iostream>
using namespace std;

void sorting(int f[], int size) {
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (f[i] > f[j]) {
					int temp = f[i];
					f[i] = f[j];
					f[j] = temp;

				}
			}
		}
	}
	
int main()
{
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(freq) / sizeof(freq[0]);

	sorting(freq, size);
	
	for (int j = 0; j < size; j++) {
		cout << freq[j] << " ";
	}

    return 0;
}
