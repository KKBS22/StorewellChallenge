#ifndef MAKE_SQUARE_H
#define MAKE_SQUARE_H

#include <stdlib.h>

//#define TESTING

#define SUCCESS_CUT        15
#define ERROR_COMPUTE      16


typedef struct _square {
	size_t sizeSide;
	size_t numSquares;
	int    area;
} Square; 

typedef struct _node {
	Square       *sqCut;
	struct _node *nNext;
} Node;

// Function to display the squares cut
void displaySquareCut(Node *pNode);

// Function to Cut square given a rectangle
int cutSquare(Node **pNode, size_t length, size_t width);

// Helper function to insert node
void insertNode(Node** head, size_t sqSize, size_t noSquares);

// Helper function to insert node at end of list
void insertNodeEnd(Node** pHead, size_t sqSize, size_t noSquares);

// Function to make a square
Square* makeSquare(size_t sqSize, size_t nSquares);

// Function to compute the list of max sqaure that can be cut
void cutSquareRecursive(Node **pNode, size_t length, size_t width);

// Function to free allocated memory
void freeData(Node *pNode);

#endif
