#ifndef FUNCTIONS_H
#define FUNCTIONS_H


struct List
{
	int data;
	List* head;
	List* tail;
};

List* createList1(int n, int* arr);
int* createArr1(int n);
List* createList2(int n, int* arr);
int* createArr2(int* arr, int& n);

void errorInput();
void Output(int* arr, int n);
void Output(List* list, int n);
void separ();

List* pasteList(int value, int index, List*& list, int& n);
int* pasteArr(int value, int index, int* arr, int n);
List* deleteList1(int index, List* list, int& n);
int* deleteArr1(int index, int* arr, int n);
List* deleteList2(int value, List* list, int& n, bool& notThere);
int* deleteArr2(int value, int* arr, int n);
List* swapList(int index1, int index2, List* list, int n);
void swapArr(int index1, int index2, int* arr, int n);
void searchList1(int index, List* list, int n);
void searchList2(int index, List* list, int n);

int kratnost(int value, List* list, int n);
int kratnost(int value, int* arr, int n);

#endif // !FUNCTIONS_H
