#ifndef _LIST_H
#define _LIST_H
#include <cstdlib> 
#include "Struct.h"


struct List {
	ElType x;
	List *tpr; //��������
	List *certificate_otl; //�������� � �������
	List *otl3; // 3 �������� � �������� 
	List *outside; //��������� �� �������� 
	List *hostel; //��������� 

};


struct Queue {
	List *head, *tail, *ptr;
};

Queue mas[5];

//������������� ����
struct List* Init(ElType el) {
	List  *queue;
	queue = (struct List*)malloc(sizeof(struct List));
	queue->x = el;
	queue->tpr = NULL;
	queue->certificate_otl = NULL;
	queue->otl3 = NULL;
	queue->outside = NULL;
	queue->hostel = NULL;
	return(queue);
}

//���������� ����
struct List* AddEl(List*q, ElType a) {
	List  *temp, *p;
	temp = (struct List*)malloc(sizeof(struct List));
	p = q->tpr;
	q->tpr = temp;
	temp->x = a;
	temp->tpr = p;
	if (a.certificate == true) {
		p = q->certificate_otl;
		q->certificate_otl = temp;
		temp->x = a;
		temp->certificate_otl = p;
	}
	else if (a.exam1 == 5 && a.exam2 == 5 && a.exam3 == 5) {
		p = q->otl3;
		q->otl3 = temp;
		temp->x = a;
		temp->otl3 = p;
	}
	else if (a.city != "Orel") {
		p = q->outside;
		q->outside = temp;
		temp->x = a;
		temp->outside = p;
	}
	else if (a.hostel == true) {
		p = q->hostel;
		q->hostel = temp;
		temp->x = a;
		temp->hostel = p;
	}
	return(temp);
}


//������������� �������
void InitQueue(Queue *q) {
	q->head = q->tail = 0;
}

//�������
bool Empty(Queue *q) {
	if (q->head == 0) return true;
	else return false;
}

//������� �������� � �������
void Add(Queue *q, ElType a) {
	if (Empty(q)) {
		q->tail = Init(a);
		q->head = q->tail;
	}
	else {
		q->tail = AddEl(q->tail, a);
	}
}

void Clear(Queue *q) {
	q->head = q->tail = 0;
}

ElType Delete(Queue *q) {
	List *temp;
	ElType x;
	if (!Empty(q)) {
		x = q->head->x;
		temp = q->head;
		q->head = q->head->tpr;
		free(temp);
		return x;
	}
}

_CRT_SECURE_NO_WARNINGS
#endif
