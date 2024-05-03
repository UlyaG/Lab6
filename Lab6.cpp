#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

struct List
{
	int data;
	List* head;
	List* tail;
};

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


List *createList1(int n, int *arr) {
	List* curr = 0, * next = 0;
	for (int i = n-1; i >= 0; i--) {
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

int *createArr1(int n) {
	int* rez = new int[n];
	for (int i = 0; i < n; ++i) {
		*(rez + i) = rand() % 99;
	}
	return rez;
}

List* createList2(int n, int* arr) {
	List* curr = 0, * next = 0;
	int i = n-1;
	while(arr[i]!=0) {
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

int* createArr2(int *arr, int &n) {
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


List *pasteList(int value, int index, List* &list, int &n) {
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

List* deleteList2(int value, List* list, int& n, bool &notThere) {
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
		if (value == curr-> data)
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
	if (index2 != (n-1))
		item1->tail->head = item1;
	if (index1 != (n - 1))
		item2->tail->head = item2;

	if (index2 == 0)
		return item1;
	if (index1 == 0)
		return item2;
	return list;
}

void swapArr(int index1, int index2, int *arr, int n) {
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

int main()
{
	setlocale(LC_ALL, "ru");

	int item = 0, item0, value, index, n = 0;
	bool notThere = 0, isAct = 1;
	int* arr = new int [100];
	List* list = 0;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startArr, endArr;
	nanoseconds timeArr;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startList, endList;
	nanoseconds timeList;


	while (1) {
		cout << "Выберите способ создания списка:" << endl
			<< "1. Создать список размера N и заполнить случайными значениями." << endl
			<< "2. Создать список по введенным значениям." << endl
			<< "Ввод: ";

		while ((item < 1) || (item > 2)) {
			cin >> item;
			separ();

			switch (item) {
			case 1:
				cout << "Введите размер списка: ";
				cin >> n;
				cout << endl;

				startArr = steady_clock::now();
				arr = createArr1(n);
				endArr = steady_clock::now();
				timeArr = duration_cast<nanoseconds>(endArr - startArr);

				startList = steady_clock::now();
				list = createList1(n, arr);
				endList = steady_clock::now();
				timeList = duration_cast<nanoseconds>(endList - startList);
				break;
			case 2:
				cout << "Перечислите элементы массива, разделяя их нажатием ENTER." << endl
					<< "Допустимые значения: все, кроме 0." << endl
					<< "Допустимое количество значений: от 1 до 100." << endl
					<< "После последнего элемента введите 0." << endl;

				startArr = steady_clock::now();
				arr = createArr2(arr, n);
				endArr = steady_clock::now();
				timeArr = duration_cast<nanoseconds>(endArr - startArr);

				startList = steady_clock::now();
				list = createList2(n, arr);
				endList = steady_clock::now();
				timeList = duration_cast<nanoseconds>(endList - startList);
				break;
			default:
				errorInput();
			}

		}			

		separ();
		cout << "Созданный список:" << endl;
		Output(arr, n);
		cout << "Время создания массива: " << timeArr.count() << " наносекунд." << endl
			<< "Время создания списка: " << timeList.count() << " наносекунд." << endl;
		if (item == 2) {
			cout << "(Ввод осуществлялся в массив, а в список значения передавались из массива)" << endl;
		}
		separ();
		separ();
		item = 0;
			

		isAct = 1;
		while (isAct) {
			cout << "Выберите действие с элементом:" << endl
				<< "1. Вставить." << endl
				<< "2. Удалить." << endl
				<< "3. Обменять." << endl
				<< "4. Вывод." << endl
				<< "5. Вывести количество элементов, нацело делящихся на числа 2-9." << endl
				<< "Ввод: ";
			while ((item < 1) || (item > 4)) {
				cin >> item;
				separ();

				switch (item) {
				case 1:
					cout << "Введите значение нового элемента: ";
					cin >> value;
					index = n + 1;
					while (index > n) {
						cout << "Введите индекс нового элемента (нумерование начинается от 0): ";
						cin >> index;
					}

					startList = steady_clock::now();
					list = pasteList(value, index, list, n);
					endList = steady_clock::now();
					timeList = duration_cast<nanoseconds>(endList - startList);

					startArr = steady_clock::now();
					arr = pasteArr(value, index, arr, n);
					endArr = steady_clock::now();
					timeArr = duration_cast<nanoseconds>(endArr - startArr);
					break;
				case 2:
					cout << "Искать элемент по..." << endl
						<< "1. Индексу." << endl
						<< "2. Значению." << endl
						<< "Ввод: ";
					item0 = 0;
					while ((item0 < 1) || (item0 > 2)) {
						cin >> item0;
						switch (item0) {
						case 1:
							index = n;
							while (index >= n) {
								cout << "Введите индекс удаляемого элемента (нумерование начинается от 0): ";
								cin >> index;
							}
							startList = steady_clock::now();
							list = deleteList1(index, list, n);
							endList = steady_clock::now();
							timeList = duration_cast<nanoseconds>(endList - startList);

							startArr = steady_clock::now();
							arr = deleteArr1(index, arr, n);
							endArr = steady_clock::now();
							timeArr = duration_cast<nanoseconds>(endArr - startArr);
							break;
						case 2:
							cout << "Введите значение удаляемого элемента: ";
							cin >> value;

							startList = steady_clock::now();
							list = deleteList2(value, list, n, notThere);
							endList = steady_clock::now();
							timeList = duration_cast<nanoseconds>(endList - startList);

							if (!notThere) {
								startArr = steady_clock::now();
								arr = deleteArr2(value, arr, n);
								endArr = steady_clock::now();
								timeArr = duration_cast<nanoseconds>(endArr - startArr);
							}
							break;
						default:
							errorInput();
						}
					}

					break;
				case 3:
					index = n;
					while ((index < 0) || (index >= n)) {
						cout << "Введите индекс первого элемента для обмена: ";
						cin >> index;
					}
					value = n;
					while ((value < 0) || (value >= n)) {
						cout << "Введите индекс второго элемента для обмена: ";
						cin >> value;
					}

					startList = steady_clock::now();
					list = swapList(index, value, list, n);
					endList = steady_clock::now();
					timeList = duration_cast<nanoseconds>(endList - startList);

					startArr = steady_clock::now();
					swapArr(index, value, arr, n);
					endArr = steady_clock::now();
					timeArr = duration_cast<nanoseconds>(endArr - startArr);
					break;
				case 4:
					cout << "Искать элемент по..." << endl
						<< "1. Индексу." << endl
						<< "2. Значению." << endl
						<< "Ввод: ";
					item0 = 0;
					while ((item0 < 1) || (item0 > 2)) {
						cin >> item0;
						switch (item0) {
						case 1:
							index = n + 1;
							while ((index < 0) || (index >= n)) {
								cout << "Введите индекс элемента: ";
								cin >> index;
								separ();
								searchList1(index, list, n);
							}
							break;
						case 2:
							cout << "Введите значение элемента: ";
							cin >> index;
							separ();
							searchList2(index, list, n);
							break;
						default:
							errorInput();
						}
					}
					break;
				case 5:

					for (int i = 2; i < 10; i++)
					{
						cout << "Количество элементов в списке кратных " << i << ": " << kratnost(i, list, n) << endl;
					}

					startList = steady_clock::now();
					for (int i = 2; i < 10; i++)
					{
						kratnost(i, list, n);
					}
					endList = steady_clock::now();
					timeList = duration_cast<nanoseconds>(endList - startList);

					startArr = steady_clock::now();
					for (int i = 2; i < 10; i++)
					{
						kratnost(i, arr, n);
					}
					endArr = steady_clock::now();
					timeArr = duration_cast<nanoseconds>(endArr - startArr);
					cout << "Время работы с массивом: " << timeArr.count() << " наносекунд." << endl
						<< "Время работы со списком: " << timeList.count() << " наносекунд." << endl;
					break;
				default:
					errorInput();
				}
			}

			separ();
			if ((!notThere) && (item < 4)) {
				cout << "Отредактированный список:" << endl;
				Output(list, n);
				cout << "Время работы с массивом: " << timeArr.count() << " наносекунд." << endl
					<< "Время работы со списком: " << timeList.count() << " наносекунд." << endl;
			}
			else if ((notThere) && (item < 4))
				cout << "Заданного элемента нет в списке!" << endl;
			separ();
			separ();
			item = 0;

			cout << "Работать с элементами еще?" << endl
				<< "1. Да." << endl
				<< "2. Нет, создать новый список." << endl
				<< "Ввод: ";
			while ((item < 1) || (item > 2))
			{
				cin >> item;
				cout << endl;

				switch (item) {
				case 1:
					isAct = 1;
					break;
				case 2:
					isAct = 0;
					break;
				default:
					errorInput();
				}
			}
			item = 0;
		}
		system("cls");
		}
	}
