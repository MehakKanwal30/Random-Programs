#pragma once

#include "MinHeapNode.h"
#include "Queue.h"


class Huffman {
	MinHeapNode* root;
	
	public:
		Huffman() {
			root = NULL;
		}
		
		void HuffmanCodes( char data[], int freq[], int size ) {
		    MinHeapNode* left;
			MinHeapNode* right;
			MinHeapNode* top;
			
			cout << "hello" << endl;
		
		   	Queue<MinHeapNode*> minHeap;
		
		    for (int i = 0; i < size; i++) {
		    	MinHeapNode* minNode = MinHeapNode(data[i], freq[i]);
		    	minHeap.enqueue(minNode);
		    }
		    
		
		    while (minHeap.getSize() != 1) {
		    	minHeap.sort();
		        left = minHeap.front();
		        minHeap.dequeue();
		
		        right = minHeap.front();
		        minHeap.dequeue();

		        top = new MinHeapNode('$', left->freq + right->freq);
		
		        top->left = left;
		        top->right = right;
		
		        minHeap.push(top);
		    }

		    printCodes( minHeap.top(), "" );
		}
		void printCodes( string str ) {
		    if ( !root )
		        return;
		
		    if ( root->data != '$' )
		        cout << root->data << ": " << str << "\n";
		
		    printCodes( root->left, str + "0" );
		    printCodes( root->right, str + "1" );
		}
				
};
