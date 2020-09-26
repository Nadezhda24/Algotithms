#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Задачи:" << endl << "1.Ввод записи об абитуриенте" << endl << "2.Вывод абитуриентов, у которых все экзамена сданы на отл." <<
		endl << "3.Вывод абитуриентов, у которых аттестат с отличием" << endl << "4.Вывод абитуриентов, которые проживают за пределами населенного пункта" << endl << "5.Вывод абитуриентов, которые нуждаются в общажитии." << endl
		<< "6.Вывод полного списка" << endl << "7. Удаление записи об абитуриенте" << endl << "5.Удаление всех записей" << endl;

	Disck *q, *temp;
	q = (Disck*)malloc(sizeof(Disck));
	temp = (Disck*)malloc(sizeof(Disck));
	InitQueue(q);
	InitQueue(temp);
	ElType x;
	int k;
	cout << "Введите номер задания: ";
	cin >> k;

	while (k != 0) {
		switch (k)
		{
		case 1:
			cin >> x.surname/*>> x.exam1>>x.exam2>>x.exam3>>x.certificate>> x.city>>x.hostel*/;
			Add(q, x);
			break;
		case 2:
			
			break;
		case 3:
			
		case 4:
			while (!Empty(q)) {
				cout << q->mas[0].head->x.surname<< endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp)) {
				Add(q, Delete(temp));
			}
			if (Empty(q)) {
				cout << "Нет деталей для обработки." << endl;
			}
			break;
		case 5:
			Clear(q);
			cout << "Процесс сброшен." << endl;
			break;

		default:
			cout << "Неверный номер задания" << endl;
			break;
		}
		cout << "Введите номер задания: ";
		cin >> k;
	}

	system("pause");
	return 0;
}
