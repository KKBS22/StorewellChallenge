#include "./lib/MakeSquare.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv) {
	int ret = 0;
	Node *pNodeHead = NULL;
	if(argc < 3) {
		printf("Error : Incorrect args \n");
		printf("Usage : ./squareCompute <LENGTH> <WIDTH>");
		exit(1);
	} else {
		int length = atoi(argv[1]);
		int width = atoi(argv[2]);
		if ((length == 0) || (width == 0)) {
			printf("Error : Length, Width value cant be zero \n");
		} else {
#ifdef TESTING
       printf("Length is %zu , Width id %zu \n", (size_t)length, (size_t)width);
#endif
			ret = cutSquare(&pNodeHead, (size_t)length, (size_t)width);
		}
	}
	if (ret == SUCCESS_CUT) {
		displaySquareCut(pNodeHead);
	} else {
		printf("Error : Unable to compute cut squares \n");
	}

	freeData(pNodeHead);
	return EXIT_SUCCESS;
}

