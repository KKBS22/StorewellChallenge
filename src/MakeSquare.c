#include "../lib/MakeSquare.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// #################################################
// # name   : displaySquareCut
// # args   : pNode - Pointer to list
// # 
// # return : VOID
// #################################################
void 
displaySquareCut(Node *pNode) {
#ifdef TESTING
       printf("Displaying dquare details \n");
#endif       
	Node* pCurNode = pNode;
	if (pCurNode == NULL) {
		printf("Error : No Cuts \n");
		exit(1);
	}
	while(pCurNode != NULL) {
		for (size_t i = 0 ; i < pCurNode->sqCut->numSquares; i++) {
			printf("%zux%zu ", pCurNode->sqCut->sizeSide, pCurNode->sqCut->sizeSide);
		}
		pCurNode = pCurNode->nNext;	
	}
	printf("\n");
} 

// #################################################
// # name   : cutSquare
// # args   : pNode  - Double pointer to list
// #        : length - Length of rectangle
// #        : width  - Width of rectangle
// # return : int    - 15 - If Squares cut
// #                   16 - Error
// #################################################
int 
cutSquare(Node **pNode, size_t length, size_t width) {
#ifdef TESTING
       printf("Cut Square : Length is %zu , Width id %zu \n", 
	      (size_t)length, (size_t)width);
#endif
	if (length == width) {
#ifdef TESTING
       printf("Def case \n");
#endif
		insertNodeEnd(pNode, length, 1);
		return 15;
	} else {
		cutSquareRecursive(pNode, length, width);
	}
	return 15;
} 

// #################################################
// # name   : makeSquare
// # args   : sqSize   - Size of square to cut
// #        : nSquares - Total number of squares
// # return : Square   - Pointer to square
// #################################################
Square* 
makeSquare(size_t sqSize, size_t nSquares) {
#ifdef TESTING
       printf("Make Square : Size is %zu \n", sqSize);
#endif
	Square *pSquare = (Square*)calloc(1, sizeof(Square));
	if (pSquare == NULL) {
		printf("Error : Unable to make square \n");
		exit(1);
	} else {
		pSquare->sizeSide = sqSize;
		pSquare->numSquares = nSquares;
#ifdef TESTING
       printf("Make Square : Size is %zu number of squares %zu \n", 
	      pSquare->sizeSide, pSquare->numSquares);
#endif
	}
	return pSquare; 
}


// #################################################
// # name   : insertNode
// # args   : pHead     - Pointer to head node
// #        : sqSize    - Size fo square
// #        : noSqaures - Number of sqaures
// # return : VOID
// #################################################
void 
insertNode(Node** pHead, size_t sqSize, size_t noSquares) {
	Node* pNewNode = (Node*) calloc(1, sizeof(Node));
	pNewNode->nNext = NULL;
	if (pNewNode == NULL) {
		printf("Error : Unable to create Node \n");
		exit(1);
	} else {
#ifdef TESTING
       printf("Insert Node\n");
#endif
		pNewNode->sqCut = makeSquare(sqSize, noSquares);
		pNewNode->nNext = *pHead;
		*pHead = pNewNode;
	}
}


// #################################################
// # name   : insertNodeEnd
// # args   : pHead     - Pointer to head node
// #        : sqSize    - Size fo square
// #        : noSqaures - Number of sqaures
// # return : VOID
// #################################################
void 
insertNodeEnd(Node** pHead, size_t sqSize, size_t noSquares) {
	Node* pNewNode = (Node*) calloc(1, sizeof(Node));
      	Node* pCurrent = *pHead;
	pNewNode->nNext = NULL;
	if (pNewNode == NULL) {
		printf("Error : Unable to create Node \n");
		exit(1);
	} else {
#ifdef TESTING
       printf("Insert Node\n");
#endif

		pNewNode->sqCut = makeSquare(sqSize, noSquares);
      		if (*pHead == NULL) {
			*pHead = pNewNode;
			return;
		}
		while(pCurrent->nNext != NULL) {
			pCurrent = pCurrent->nNext;
		}
		pCurrent->nNext = pNewNode;
	}
}


// #################################################
// # name   : cutSquareRecursive
// # args   : pNode     - Pointer to head node
// #        : length    - Length of rectangle
// #        : width     - Width  of rectangle
// # return : VOID
// #################################################
void 
cutSquareRecursive(Node **pNode, size_t length, size_t width) {
	int quo, mod;
	if (length < width) {
		quo = width / length;
		if ((mod = width % length) != 0) {
			insertNodeEnd(pNode, length, quo);
			cutSquareRecursive(pNode, length, mod);			
		} else {
			insertNodeEnd(pNode, length, quo);
			return;
		}
	} else {
		quo = length / width;
		if ((mod = length % width) != 0) {
			insertNodeEnd(pNode, width, quo);
			cutSquareRecursive(pNode, width, mod);			
		} else {
			insertNodeEnd(pNode, width, quo);
			return;
		}
	}
}


// #################################################
// # name   : freeData
// # args   : pNode     - Pointer to head node
// # return : VOID
// #################################################
void 
freeData(Node *pNode) {
	Node* pCurFree;
	while(pNode != NULL) {
#ifdef TESTING
	printf("Calling free \n");
#endif

		pCurFree = pNode;
		free(pCurFree->sqCut);
		pNode = pNode->nNext;
		free(pCurFree);
	}
	free(pNode);	
}
