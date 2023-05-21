#pragma once

#include<iostream>
using namespace std;

class MinHeapNode {
	public:
		char data;
		int freq;
		MinHeapNode* left;
		MinHeapNode* right;
		
		MinHeapNode() {
			this->data = " ";
			this->freq = 0;
			this->left = NULL;
			this->right = NULL;
		}
		
		MinHeapNode( char data, int freq ) {
			this->data = data;
			this->freq = freq;
			this->left = NULL;
			this->right = NULL;
		}
		
		bool operator > ( const MinHeapNode& mn ) {
	        if( freq > mn.freq )
	        	return true;
	        return false;
       }
};
