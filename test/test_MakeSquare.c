#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>

#include "../lib/MakeSquare.h"

typedef struct _tSquare {
	size_t sizeOfSide;
	size_t nSquares;
} TSquare;

typedef struct _testValues {
	size_t  length;
	size_t  width;
	TSquare squareTable[6];
}TestValues;


typedef struct _testValuesArea {
	size_t  length;
	size_t  width;
}TestValuesArea;


TestValues testTable[] = {
				{100 , 100 , {[0] = {100 , 1}}},
				{10  ,  10 , {[0] = {10  , 1}}},
				{9   ,   9 , {[0] = {9   , 1}}},
				{6   ,   5 , {[0] = {5   , 1},         
					      [1] = {1   , 5}}},
				{100 , 135 , {[0] = {100 , 1},         
					      [1] = {35  , 2},
					      [2] = {30  , 1},
					      [3] = {5   , 6}}}
		         };

TestValuesArea testTableArea[] = {
                                	{100 , 100},
                                	{10  ,  10},
                                	{9   ,   9},
                                	{6   ,   5},
                                	{100 , 135},
					{1980,1340},
					{986 ,  97},
					{1234,4321}
                        	 };


size_t testVectorSize = sizeof(testTable) / sizeof(TestValues);
size_t testVectorArea = sizeof(testTableArea) / sizeof(TestValuesArea);

void test_cut_square() {
	for (int i = 0 ; i < testVectorSize ; i++) {
		Node *pNode = NULL;
		int ret = 0;
		
		size_t numOfSquares = sizeof(testTable[i].squareTable)/sizeof(TSquare);
		ret = cutSquare(&pNode, testTable[i].length, testTable[i].width);
		if (ret ==  15) {
			Node* pCurNode = pNode;
			while(pCurNode != NULL) {
				for(int j =0 ; j < numOfSquares; j++) {
					if (testTable[i].squareTable[j].sizeOfSide != 0) {
						assert_int_equal(pCurNode->sqCut->sizeSide, testTable[i].squareTable[j].sizeOfSide);
						assert_int_equal(pCurNode->sqCut->numSquares, testTable[i].squareTable[j].nSquares);
						pCurNode = pCurNode->nNext;
					}
				}
			}
			freeData(pNode);	
		} else {
			free(pNode);
		}	
	}
}


void test_cut_square_area() {
	for (int i = 0 ; i < testVectorArea ; i++) {
		Node *pNode = NULL;
		int ret = 0;
		
		ret = cutSquare(&pNode, testTableArea[i].length, testTableArea[i].width);
		if (ret ==  15) {
			Node* pCurNode = pNode;
			int sumArea = 0;
			while(pCurNode != NULL) {
				sumArea += pCurNode->sqCut->area;
				pCurNode = pCurNode->nNext;
			}
			assert_int_equal((testTableArea[i].length * testTableArea[i].width), sumArea);
			freeData(pNode);	
		} else {
			free(pNode);
		}	
	}
}


	
void test_square_gen() {
	Square *pSquare = makeSquare(4, 1);
	assert_int_equal(pSquare->sizeSide, 4);
	assert_int_equal(pSquare->numSquares, 1);
	free(pSquare);
}

int main() {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_square_gen),
		cmocka_unit_test(test_cut_square_area),
		cmocka_unit_test(test_cut_square)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
