#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Задачи:" << endl << "1.Ввод записи об абитуриенте" << endl << "2.Вывод абитуриентов, у которых все экзамена сданы на отл." <<
		endl << "3.Вывод абитуриентов, у которых аттестат с отличием" << endl << "4.Вывод абитуриентов, которые проживают за пределами населенного пункта" << endl << "5.Вывод абитуриентов, которые нуждаются в общажитии." << endl
		<< "6.Вывод полного списка" << endl << "7.Удаление записи об абитуриенте" << endl << "8.Удаление всех записей" << endl;

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
			cout << "Введите фамилию: ";
			cin >> x.surname;
			cout << "Введите 1ую оценку: ";
			cin >> x.exam1;
			cout << "Введите 2ую оценку: ";
			cin >> x.exam2;
			cout << "Введите 3ью оценку: ";
			cin >> x.exam3;
			cout << "Введите наличие аттестата: ";
			cin >> x.certificate;
			cout << "Введите город: ";
			cin >> x.city;
			cout << "Введите критерий необходимости в общежитии: ";
			cin >> x.hostel;
			Add(q, x);
			break;
		case 2:
			while (!Empty(q,2)) {
				cout << "Студент " << q->mas[2].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp,2)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 2)) {
				cout << "Список пуст" << endl;
			}
			break;
		case 3:
			while (!Empty(q,1)) {
				cout << "Студент " << q->mas[1].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp, 1)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 1)) {
				cout << "Список пуст" << endl;
			}
		case 4:
			while (!Empty(q, 3)) {
				cout << "Студент " << q->mas[3].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp,3)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 3)) {
				cout << "Список пуст" << endl;
			}			break;
		case 5:
			while (!Empty(q, 4)) {
				cout << "Студент " << q->mas[4].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp, 4)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 4)) {
				cout << "Список пуст" << endl;
			}
			break;
		case 6:
			while (!Empty(q, 0)) {
				cout << "Студент " << q->mas[0].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp, 0)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 0)) {
				cout << "Список пуст" << endl;
			}
			break;
		case 7:
			if (!Empty(q, 0)) {
				cout << "Студент " << q->mas[0].head->x.surname << " удален из списка"  << endl;
				Delete(q);
			}
			else cout << "Список пуст" << endl;
			break;
		case 8:
			Clear(q);
			cout << "Список очищен" << endl;
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
