#include <iostream>
#include "Functions.h"
using namespace std;


List* createList1(int n, int* arr) {
	List* curr = 0, * next = 0;
	for (int i = n - 1; i >= 0; i--) {
		curr = new List;
		curr->tail = next;
		if (next)
			next->head = curr;
		next = curr;
		curr->data = *(arr + i);
	}
	curr->head = 0;
	return curr;
}

int* createArr1(int n) {
	int* rez = new int[n];
	for (int i = 0; i < n; ++i) {
		*(rez + i) = rand() % 99;
	}
	return rez;
}

List* createList2(int n, int* arr) {
	List* curr = 0, * next = 0;
	int i = n - 1;
	while (arr[i] != 0) {
		curr = new List;
		curr->tail = next;
		if (next)
			next->head = curr;
		next = curr;
		curr->data = arr[i];
		if (i == 0)
			break;
		i--;
	}
	curr->head = 0;
	return curr;
}

int* createArr2(int* arr, int& n) {
	n = 0;
	for (int i = 0; i < 100; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
			break;
		n++;
	}
	int* rez = new int[n];
	for (int i = 0; i < n; ++i) {
		rez[i] = arr[i];
	}
	delete[] arr;
	return rez;
}