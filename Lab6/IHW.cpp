#include <iostream>
#include "Functions.h"
using namespace std;



int kratnost(int value, List* list, int n) {
	List* curr = list;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (curr->data % value == 0)
			count++;
		curr = curr->tail;
	}
	return count;
}

int kratnost(int value, int* arr, int n) {

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % value == 0)
			count++;
	}
	return count;
}