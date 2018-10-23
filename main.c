/** 
 *	VAQL_C
 *  Copyright (C) Simon Raichl 2018
 *  MIT License
 *  Use this as you want, share it as you want, do basically whatever you want with this :)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "VAQL.h"

int main(int argc, char *argv[]) {
	int array1[] = {69, 51, 48, 52, 32, 78, 33};
	int array2[] = {5, 8, 45, 23, 48};
	int array3[] = {69, 51, 48, 52, 32, 78, 34, 32, 31, 32};
	int length1 = sizeof(array1) / sizeof(int);
	int length2 = sizeof(array2) / sizeof(int);
	int length3 = sizeof(array3) / sizeof(int);
	printf("Comparison of two arrays: %d\n", compareIntArrays(array1, array3, length1, length3));
	printf("Comparison of two arrays: %d\n", compareIntArrays(array1, array2, length1, length2));
	printf("Comparison of two arrays: %d\n", compareIntArrays(array1, array1, length1, length1));
	printf("Average: %.2lf\n", averageFromArray(array1, length1));
	//finding value of 32 in the array
	printf("First occurrence of number 32 in array { ");
	printArray(array3, length3);
	int query = findIntInArray(array3, 32, "f", length3);
	printf("} is on index: %d\n", query);
	printf("Last occurrence of number 32 in array { ");
	printArray(array3, length3);
	query = findIntInArray(array3, 32, "l", length3);
	printf("} is on index: %d\n", query);
	struct firstAndLast strQuery = findIntsInArray(array3, 32, length3);
	printf("Or via findIntsInArray => first: %d, last: %d, total number of occurrences: %d", strQuery.first, strQuery.last, strQuery.total);
	printf("\n");
	//replacing int in the array
	array3[query] = 0; // now this index has value 0
	//printing a mapped array => +8 per each value and then map array again and multiply every value by 2
	printArray(mapIntArray(array3, 8, "", length3), length3);
	printf("\n");
	printArray(mapIntArray(array3, 2, "*", length3), length3);
	printf("\n");
	printArray(sortIntArray(array3, "", length3), length3);
	printf("\n");
	printArray(sortIntArray(array2, "r", length2), length2);
	printf("\n");
	system("pause");
	return 0;
}
