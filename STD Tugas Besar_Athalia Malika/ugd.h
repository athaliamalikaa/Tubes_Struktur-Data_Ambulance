#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include<bits/stdc++.h>
#include<cstdlib>
#include<iomanip>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define Head(Q) ((Q).Head)
#define Tail(Q) ((Q).Tail)
#define Top(S) ((S).Top)


struct Pasien{
	string nama;
	string penyakit;
	int prioritas;
};

typedef struct Node *adr;

struct Node{
	Pasien info;
	adr next;
};

struct Stack{
	adr Top;
};

struct Queue{
	adr Head, Tail;
};

adr createNode(Pasien pasien);

//Stack
bool isStackEmpty(Stack S);
void initializeStack(Stack &S);
void push(Stack &S, Pasien pasien);
Pasien pop(Stack &S);

//Queue
bool isQueueEmpty(Queue Q);
void initializeQueue(Queue &Q);
Pasien dequeue(Queue &Q);
void enqueue(Queue &Q, Pasien pasien);
void printQueue(Queue Q);

Pasien generatePasien(string nama, int jenis);

#endif
