/** 
 *	VAQL_C
 *  Copyright (C) Simon Raichl 2018
 *  MIT License
 *  Use this as you want, share it as you want, do basically whatever you want with this :)
 */

/**
 * returns the sorted array
 * @param array
 * @param mode
 * @param length
 * @returns int[]
 */
 
int *sortIntArray(int *array, char *mode, int length){
	int i = 0, j, buffer;
	while (i < length){
		j = 0;
		while(j < length){
			if (mode == "r" ? array[i] > array[j] : array[i] < array[j]){
                buffer = array[j];
                array[j] = array[i];
                array[i] = buffer;
            }
            j++;
		}
		i++;
	}
	return array;
}
 
/**
 * compares two int arrays and returns the int with value 0 or 1
 * @param array1
 * @param array2
 * @param length1
 * @param length2
 * @returns int
 */

int compareIntArrays(int *array1, int *array2, int length1, int length2){
	int i = 0;
	int result = 0;
	if (length1 == length2){
		while(array1[i] == array2[i] && i < length1){
			result = 1;
			i++;
		}
	}	
	return array1[i] == array2[i] ? result : 0;
}

/**
 * finds first or last occurrence in the array and returns index where the value is found.
 * @param array1
 * @param query
 * @param mode
 * @param length
 * @returns int
 */

int findIntInArray(int *array, int query, char *mode, int length){
	int i = 0;
	int result = NULL;
	while (i < length){
		if (query == array[i]){
			result = i;
			if (mode != "l" && mode == "" || mode == "f"){
				break;
			}
		}
		i++;
	}
	return result;
}

/**
 * finds first and last occurrence and total number of occurrences in the array and returns index where the value is found.
 * @param array1
 * @param query
 * @param length
 * @returns struct
 */
 
struct firstAndLast{
	int first;
	int last;
	int total;
};

struct firstAndLast findIntsInArray(int *array, int query, int length){
	struct firstAndLast result;
	result.first = 0;
	result.last = 0;
	result.total = 0;
	
	int i = 0;
	int first = 0;
	while (i < length){
		if (query == array[i]){
			if (first == 0){
				result.first = i;
				first++;
			}
			result.last = i;
			result.total++;
		}
		i++;
	}
	return result;
}

/**
 * maps all values in the array with given value and operator.
 * @param array
 * @param expression
 * @param *op
 * @param length
 * @returns int[]
 */

int *mapIntArray(int *array, int expression, char *op, int length){
	int i = 0;
	while (i < length){
		if (op == "" || op == "+"){
			array[i] = array[i] + expression;
		}
		else if (op == "/") {
			array[i] = array[i] / expression;
		}
		else if (op == "*") {
			array[i] = array[i] * expression;
		}
		else if (op == "-"){
			array[i] = array[i] - expression;
		}
		i++;
	}
	return array;
}

/**
 * makes a simple average from the array.
 * @param array
 * @param length
 * @returns float
 */

float averageFromArray(int *array, int length){
	int i = 0;
	float num = 0.0F;
	while (i < length){
		num += (float)array[i];
		i++;
	}
	return num / length;
}

/**
 * prints all values in the array to console.
 * @param array1
 * @param length
 * @returns void
 */

void printArray(int *array, int length){
	int i = 0;
	while (i < length){
		printf("%d ", array[i]);
		i++;
	}
}
