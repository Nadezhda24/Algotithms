#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Задачи:" << endl << "1.Ввод записи об абитуриенте" << endl << "2.Вывод абитуриентов, у которых все экзамена сданы на отл." <<
		endl << "3.Вывод абитуриентов, у которых аттестат с отличием" << endl << "4.Вывод абитуриентов, которые проживают за пределами населенного пункта" << endl << "5.Вывод абитуриентов, которые нуждаются в общажитии." << endl
		<< "6.Вывод полного списка" << endl << "7.Удаление записи об абитуриенте" << endl << "8.Удаление всех записей" << endl;

	Disck *q, *temp,*temp2;
	q = (Disck*)malloc(sizeof(Disck));
	temp = (Disck*)malloc(sizeof(Disck));
	temp2 = (Disck*)malloc(sizeof(Disck));
	InitQueue(q);
	InitQueue(temp);
	InitQueue(temp2);
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
			cout << "Вывод абитуриентов, у которых все экзамена сданы на отл:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 2)) {
				while (!Empty(temp, 2)) {
					if (temp->mas[0].head->x.exam1 == 5 && temp->mas[0].head->x.exam2 == 5 && temp->mas[0].head->x.exam3 == 5)
					cout << "Студент " << temp->mas[2].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "Список пуст" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 3:
			cout << "Вывод абитуриентов, у которых аттестат с отличием:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 1)) {
				while (!Empty(temp, 1)) {
					if (temp->mas[0].head->x.certificate = 1)
					cout << "Студент " << temp->mas[1].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "Список пуст" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 4:
			cout << "Вывод абитуриентов, которые проживают за пределами населенного пункта:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 3)) {
				while (!Empty(temp, 3)) {
					if(strcmp(temp->mas[0].head->x.city, "Orel") != 0)
					cout << "Студент " << temp->mas[3].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "Список пуст" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 5:
			cout << "Вывод абитуриентов, которые нуждаются в общажитии:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 4)) {
				while (!Empty(temp, 4)) {
					if (temp->mas[0].head->x.hostel == 1)
					cout << "Студент " << temp->mas[4].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "Список пуст" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 6:
			cout << "Полный список:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 0)) {
				while (!Empty(temp, 0)) {
					cout << "Студент " << temp->mas[0].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "Список пуст" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 7:
			char sur[50];
			cout << "Введите фамилию: ";
			cin >> sur;
			if (!Empty(q, 0)) {
				while (!Empty(q, 0)) {
					if (strcmp(q->mas[0].head->x.surname, sur) != 0) {
						x = Pop(q);
						Add(temp, x);
					}
					else {
						cout << "Студент " << q->mas[0].head->x.surname << " удален" << endl;
						x = Pop(q);
					}
				}
				Clear(q);
			}
			else {
				cout << "Список пуст" << endl;
			}
			
			while (!Empty(temp, 0)) {
				Add(q, Pop(temp));
			}
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
