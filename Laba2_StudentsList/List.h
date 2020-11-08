#ifndef _LIST_H
#define _LIST_H
#include <cstdlib> 
#include <string.h>
#include "Struct.h"
#define MAX 5

struct List {
	ElType x;
	List *tpr; //основной
	List *certificate_otl; //аттестат с отличие
	List *otl3; // 3 экзамена с отличием 
	List *outside; //проживает за прделами 
	List *hostel; //общежитие 

};


struct Queue {
	List *head, *tail, *ptr;
};

struct Disck {
	Queue mas[MAX];
};


//инициализация узла
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

//добавление узла
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


//инициализация очереди
void InitQueue(Disck *q) {
	for (int i = 0; i < MAX; i++) {
		q->mas[i].head = q->mas[i].tail = 0;
	}
}

//пустота
bool Empty(Disck *q, int i) {
	if (q->mas[i].head == 0) return true;
	else return false;
}

//вставка элемента в очередь
void Add(Disck *q, ElType a) {
	if (Empty(q, 0)) {
		q->mas[0].tail = Init(a);
		q->mas[0].head = q->mas[0].tail;
	}
	else {
		q->mas[0].tail = AddEl(q->mas[0].tail, a);
	}
	if (a.certificate == true) {
		if (Empty(q, 1)) {
			q->mas[1].tail = Init(a);
			q->mas[1].head = q->mas[1].tail;
		}
		else {
			q->mas[1].tail = AddEl(q->mas[1].tail, a);
		}
	}
	if (a.exam1 == 5 && a.exam2 == 5 && a.exam3 == 5) {
		if (Empty(q, 2)) {

			q->mas[2].tail = Init(a);
			q->mas[2].head = q->mas[2].tail;
		}

		else {
			q->mas[2].tail = AddEl(q->mas[2].tail, a);
		}
	}
	if (strcmp(a.city, "Orel") != 0) {
		if (Empty(q, 3)) {

			q->mas[3].tail = Init(a);
			q->mas[3].head = q->mas[3].tail;
		}
		else {
			q->mas[3].tail = AddEl(q->mas[3].tail, a);
		}
	}
	if (a.hostel == true) {
		if (Empty(q, 4)) {

			q->mas[4].tail = Init(a);
			q->mas[4].head = q->mas[4].tail;
		}
		else {
			q->mas[4].tail = AddEl(q->mas[4].tail, a);
		}
	}

}

void Clear(Disck *q) {
	for (int i = 0; i < MAX; i++) {
		q->mas[i].head = q->mas[i].tail = 0;
	}
}

ElType Pop(Disck *q) {
	List *temp;
	ElType x;
	if (!Empty(q, 0)){
		
		if (q->mas[0].head->x.certificate == true) {
			if (!Empty(q, 1)) {
				x = q->mas[1].head->x;
				temp = q->mas[1].head;
				q->mas[1].head = q->mas[1].head->tpr;
				free(temp);
			}
		}

	if (q->mas[0].head->x.exam1 == 5 && q->mas[0].head->x.exam2 == 5 && q->mas[0].head->x.exam3 == 5) {
		if (!Empty(q, 2)) {
			x = q->mas[2].head->x;
			temp = q->mas[2].head;
			q->mas[2].head = q->mas[2].head->tpr;
			free(temp);
		}
	}

	if (strcmp(q->mas[0].head->x.city, "Orel") != 0) {
		if (!Empty(q, 3)) {
			x = q->mas[3].head->x;
			temp = q->mas[3].head;
			q->mas[3].head = q->mas[3].head->tpr;
			free(temp);
		}
	}

	if (q->mas[0].head->x.hostel == true) {
		if (!Empty(q, 4)) {
			x = q->mas[4].head->x;
			temp = q->mas[4].head;
			q->mas[4].head = q->mas[4].head->tpr;
			free(temp);
		}
	}

		x = q->mas[0].head->x;
		temp = q->mas[0].head;
		q->mas[0].head = q->mas[0].head->tpr;
		free(temp);
		return x;
	}
}


_CRT_SECURE_NO_WARNINGS
#endif
