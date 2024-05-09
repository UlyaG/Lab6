#include <iostream>
#include "Functions.h"
using namespace std;


List* pasteList(int value, int index, List*& list, int& n) {
	int i = 0;
	List* item = new List;
	List* curr = list;
	item->data = value;
	n++;
	if (index == 0)
	{
		item->head = 0;
		item->tail = list;
		list->head = item;

		return item;
	}
	while (1) {
		if ((i + 2) == n)
		{
			item->tail = 0;
			item->head = curr;
			curr->tail = item;
			return list;
		}
		if (index == i)
		{
			curr->head->tail = item;
			item->head = curr->head;
			item->tail = curr;
			curr->head = item;
			return list;
		}

		curr = curr->tail;
		i++;
	}
}

int* pasteArr(int value, int index, int* arr, int n) {
	int* rez = new int[n];
	bool isPaste = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == index)
		{
			rez[i] = value;
			isPaste = 1;
		}
		else if (isPaste) { rez[i] = arr[i - 1]; }
		else { rez[i] = arr[i]; }
	}
	delete[] arr;
	return rez;
}

List* deleteList1(int index, List* list, int& n) {
	List* curr = list;
	if (index == 0) {
		curr->tail->head = 0;
		n--;
		return curr->tail;
	}
	for (int i = 0; i < n; i++) {
		if (i == (n - 1)) {
			curr->head->tail = 0;
			n--;
			return list;
		}
		if (i == index)
		{
			curr->head->tail = curr->tail;
			curr->tail->head = curr->head;
			n--;
			return list;
		}
		curr = curr->tail;
	}
	return list;
}

int* deleteArr1(int index, int* arr, int n) {
	int* rez = new int[n];
	bool isDelete = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == index)
		{
			isDelete = 1;
		}
		if (isDelete) { rez[i] = arr[i + 1]; }
		else { rez[i] = arr[i]; }
	}
	delete[] arr;
	return rez;
}

List* deleteList2(int value, List* list, int& n, bool& notThere) {
	List* curr = list;

	for (int i = 0; i < n; i++) {
		if ((value == curr->data) && (i == 0)) {
			curr->tail->head = 0;
			n--;
			return curr->tail;
		}
		if ((i == (n - 1)) && (value == curr->data)) {
			curr->head->tail = 0;
			n--;
			return list;
		}
		if (value == curr->data)
		{
			curr->head->tail = curr->tail;
			curr->tail->head = curr->head;
			n--;
			return list;
		}
		curr = curr->tail;
	}
	notThere = 1;
	return list;
}

int* deleteArr2(int value, int* arr, int n) {
	int* rez = new int[n];
	bool isDelete = 0;
	for (int i = 0; i < n; i++)
	{
		if ((arr[i] == value) && (!isDelete))
		{
			isDelete = 1;
		}
		if (isDelete) { rez[i] = arr[i + 1]; }
		else { rez[i] = arr[i]; }
	}
	delete[] arr;
	return rez;
}

List* swapList(int index1, int index2, List* list, int n) {
	List* curr = list;
	List* item1 = 0;
	List* item2 = 0;
	List* item3 = 0;
	for (int i = 0; i < n; i++)
	{
		if (index1 == i)
		{
			item1 = curr;
		}
		if (index2 == i)
		{
			item2 = curr;
		}
		curr = curr->tail;
	}

	item3 = item1->head;
	item1->head = item2->head;
	item2->head = item3;
	if (index2 != 0)
		item1->head->tail = item1;
	if (index1 != 0)
		item2->head->tail = item2;

	item3 = item1->tail;
	item1->tail = item2->tail;
	item2->tail = item3;
	if (index2 != (n - 1))
		item1->tail->head = item1;
	if (index1 != (n - 1))
		item2->tail->head = item2;

	if (index2 == 0)
		return item1;
	if (index1 == 0)
		return item2;
	return list;
}

void swapArr(int index1, int index2, int* arr, int n) {
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((index1 == i) && (index2 == j))
			{
				int c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}
}

void searchList1(int index, List* list, int n) {
	List* curr = list;
	for (int i = 0; i < n; i++) {
		if (i == index)
		{
			cout << "Индекс искомого элемента: " << i << endl
				<< "Значение искомого элемента: " << curr->data << endl
				<< "Адрес искомого элемента: " << curr << endl;
		}
		curr = curr->tail;
	}
}

void searchList2(int index, List* list, int n) {
	List* curr = list;
	bool isThere = 0;
	for (int i = 0; i < n; i++) {
		if (curr->data == index)
		{
			cout << "Индекс искомого элемента: " << i << endl
				<< "Значение искомого элемента: " << curr->data << endl
				<< "Адрес искомого элемента: " << curr << endl;
			isThere = 1;
		}
		curr = curr->tail;
	}
	if (!isThere)
		cout << "Элемент не найден." << endl;
}