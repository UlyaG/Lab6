#include <iostream>
#include "Functions.h"
using namespace std;

void errorInput() {
	cout << "Ошибка!" << endl
		<< "Повторите ввод: ";
}

void Output(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void Output(List* list, int n) {
	List* curr = list;
	for (int i = 0; i < n; i++)
	{
		cout << curr->data << ' ';
		curr = curr->tail;
	}
	cout << endl;
}

void separ() {
	for (int i = 0; i < 60; i++)
		cout << '-';
	cout << endl;
}
