#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "������:" << endl << "1.���� ������ �� �����������" << endl << "2.����� ������������, � ������� ��� �������� ����� �� ���." <<
		endl << "3.����� ������������, � ������� �������� � ��������" << endl << "4.����� ������������, ������� ��������� �� ��������� ����������� ������" << endl << "5.����� ������������, ������� ��������� � ���������." << endl
		<< "6.����� ������� ������" << endl << "7. �������� ������ �� �����������" << endl << "5.�������� ���� �������" << endl;

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
				cout << "��� ������� ��� ���������." << endl;
			}
			break;
		case 5:
			Clear(q);
			cout << "������� �������." << endl;
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
