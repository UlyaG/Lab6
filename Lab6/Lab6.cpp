#include <iostream>
#include <chrono>
#include "Functions.h"

using namespace std;
using namespace chrono;

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
			while ((item < 1) || (item > 5)) {
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
			else if ((notThere) && (item != 4))
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
