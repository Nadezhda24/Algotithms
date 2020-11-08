#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "������:" << endl << "1.���� ������ �� �����������" << endl << "2.����� ������������, � ������� ��� �������� ����� �� ���." <<
		endl << "3.����� ������������, � ������� �������� � ��������" << endl << "4.����� ������������, ������� ��������� �� ��������� ����������� ������" << endl << "5.����� ������������, ������� ��������� � ���������." << endl
		<< "6.����� ������� ������" << endl << "7.�������� ������ �� �����������" << endl << "8.�������� ���� �������" << endl;

	Disck *q, *temp,*temp2;
	q = (Disck*)malloc(sizeof(Disck));
	temp = (Disck*)malloc(sizeof(Disck));
	temp2 = (Disck*)malloc(sizeof(Disck));
	InitQueue(q);
	InitQueue(temp);
	InitQueue(temp2);
	ElType x;
	int k;
	cout << "������� ����� �������: ";
	cin >> k;

	while (k != 0) {
		switch (k)
		{
		case 1:
			cout << "������� �������: ";
			cin >> x.surname;
			cout << "������� 1�� ������: ";
			cin >> x.exam1;
			cout << "������� 2�� ������: ";
			cin >> x.exam2;
			cout << "������� 3�� ������: ";
			cin >> x.exam3;
			cout << "������� ������� ���������: ";
			cin >> x.certificate;
			cout << "������� �����: ";
			cin >> x.city;
			cout << "������� �������� ������������� � ���������: ";
			cin >> x.hostel;
			Add(q, x);
			break;
		case 2:
			cout << "����� ������������, � ������� ��� �������� ����� �� ���:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 2)) {
				while (!Empty(temp, 2)) {
					if (temp->mas[0].head->x.exam1 == 5 && temp->mas[0].head->x.exam2 == 5 && temp->mas[0].head->x.exam3 == 5)
					cout << "������� " << temp->mas[2].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "������ ����" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 3:
			cout << "����� ������������, � ������� �������� � ��������:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 1)) {
				while (!Empty(temp, 1)) {
					if (temp->mas[0].head->x.certificate = 1)
					cout << "������� " << temp->mas[1].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "������ ����" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 4:
			cout << "����� ������������, ������� ��������� �� ��������� ����������� ������:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 3)) {
				while (!Empty(temp, 3)) {
					if(strcmp(temp->mas[0].head->x.city, "Orel") != 0)
					cout << "������� " << temp->mas[3].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "������ ����" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 5:
			cout << "����� ������������, ������� ��������� � ���������:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 4)) {
				while (!Empty(temp, 4)) {
					if (temp->mas[0].head->x.hostel == 1)
					cout << "������� " << temp->mas[4].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "������ ����" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 6:
			cout << "������ ������:" << endl;
			while (!Empty(q, 0)) {
				x = Pop(q);
				Add(temp, x);
				Add(temp2, x);
			}
			if (!Empty(temp, 0)) {
				while (!Empty(temp, 0)) {
					cout << "������� " << temp->mas[0].head->x.surname << endl;
					x = Pop(temp);
				}
				Clear(temp);
			}
			else {
				cout << "������ ����" << endl;
			}
			while (!Empty(temp2, 0)) {
				x = Pop(temp2);
				Add(q, x);
			}
			break;
		case 7:
			char sur[50];
			cout << "������� �������: ";
			cin >> sur;
			if (!Empty(q, 0)) {
				while (!Empty(q, 0)) {
					if (strcmp(q->mas[0].head->x.surname, sur) != 0) {
						x = Pop(q);
						Add(temp, x);
					}
					else {
						cout << "������� " << q->mas[0].head->x.surname << " ������" << endl;
						x = Pop(q);
					}
				}
				Clear(q);
			}
			else {
				cout << "������ ����" << endl;
			}
			
			while (!Empty(temp, 0)) {
				Add(q, Pop(temp));
			}
			break;
		case 8:
			Clear(q);
			cout << "������ ������" << endl;
			break;

		default:
			cout << "�������� ����� �������" << endl;
			break;
		}
		cout << "������� ����� �������: ";
		cin >> k;
	}

	system("pause");
	return 0;
}
