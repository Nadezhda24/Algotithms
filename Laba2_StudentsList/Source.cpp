#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "������:" << endl << "1.���� ������ �� �����������" << endl << "2.����� ������������, � ������� ��� �������� ����� �� ���." <<
		endl << "3.����� ������������, � ������� �������� � ��������" << endl << "4.����� ������������, ������� ��������� �� ��������� ����������� ������" << endl << "5.����� ������������, ������� ��������� � ���������." << endl
		<< "6.����� ������� ������" << endl << "7.�������� ������ �� �����������" << endl << "8.�������� ���� �������" << endl;

	Disck *q, *temp;
	q = (Disck*)malloc(sizeof(Disck));
	temp = (Disck*)malloc(sizeof(Disck));
	InitQueue(q);
	InitQueue(temp);
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
			while (!Empty(q,2)) {
				cout << "������� " << q->mas[2].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp,2)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 2)) {
				cout << "������ ����" << endl;
			}
			break;
		case 3:
			while (!Empty(q,1)) {
				cout << "������� " << q->mas[1].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp, 1)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 1)) {
				cout << "������ ����" << endl;
			}
		case 4:
			while (!Empty(q, 3)) {
				cout << "������� " << q->mas[3].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp,3)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 3)) {
				cout << "������ ����" << endl;
			}			break;
		case 5:
			while (!Empty(q, 4)) {
				cout << "������� " << q->mas[4].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp, 4)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 4)) {
				cout << "������ ����" << endl;
			}
			break;
		case 6:
			while (!Empty(q, 0)) {
				cout << "������� " << q->mas[0].head->x.surname << endl;
				x = Delete(q);
				Add(temp, x);
			}
			Clear(q);
			while (!Empty(temp, 0)) {
				Add(q, Delete(temp));
			}
			if (Empty(q, 0)) {
				cout << "������ ����" << endl;
			}
			break;
		case 7:
			if (!Empty(q, 0)) {
				cout << "������� " << q->mas[0].head->x.surname << " ������ �� ������"  << endl;
				Delete(q);
			}
			else cout << "������ ����" << endl;
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
