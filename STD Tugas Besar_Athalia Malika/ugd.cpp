#include"ugd.h"

adr createNode(Pasien pasien){
	adr node = new Node;
	info(node) = pasien;
	next(node) = NULL;

	return node;
}

bool isStackEmpty(Stack S){
	return Top(S) == NULL;
}

void initializeStack(Stack &S){
	Top(S) = NULL;
}

void push(Stack &S, Pasien pasien){
	adr node = createNode(pasien);

	next(node) = Top(S);
	Top(S) = node;
}

Pasien pop(Stack &S){
	Pasien pasien = info(Top(S));
	adr temp = Top(S);
	Top(S) = next(Top(S));
	delete temp;

	return pasien;
}

//Queue
bool isQueueEmpty(Queue Q){
	if(Head(Q) == NULL){
		return true;
	}
	return false;
}

void initializeQueue(Queue &Q){
	Head(Q) = NULL;
	Tail(Q) = NULL;
}

Pasien dequeue(Queue &Q){
	Pasien temp = info(Head(Q));
	adr node = Head(Q);

	Head(Q) = next(Head(Q));
	if(Head(Q) == NULL){
		Tail(Q) = NULL;
	}
	delete node;

	return temp;
}

void enqueue(Queue &Q, Pasien pasien){
	adr node = createNode(pasien);


	if(Head(Q) == NULL){
		Head(Q) = Tail(Q) = node;
	}else{
		adr curr = Head(Q);
		bool loop = true;
		Stack stack;

		initializeStack(stack);
		while(curr != NULL & loop){
			Pasien temp = info(curr);
			if(pasien.prioritas > temp.prioritas){
				next(node) = curr;
				Head(Q) = node;
				loop = false;
			}else{
				curr = next(curr);
				dequeue(Q);
				push(stack, temp);
			}
		}

		if(loop){
			Head(Q) = Tail(Q) = node;
		}

		if(!isStackEmpty(stack)){
			while(!isStackEmpty(stack)){
				Pasien temp = pop(stack);
				adr ntemp = createNode(temp);
				next(ntemp) = Head(Q);
				Head(Q) = ntemp;
			}
		}
	}
}

void printQueue(Queue Q){
	adr curr = Head(Q);
	int count = 0;

	cout << "+------+----------------------+----------------------+-------+" << endl;
	cout << "| " << left << setw(4) << "No" << " | " << left << setw(20) << "Nama Pasien" << " | " << left << setw(20) << "Data Penyakit" << " | " << left << setw(5) << "Skala" << " |" << endl;
	cout << "+------+----------------------+----------------------+-------+" << endl;


	while(curr != NULL){
		count += 1;
		Pasien pasien = info(curr);


		cout << "| " << left << setw(4) << count << " | " << left << setw(20) << pasien.nama << " | " << left << setw(20) << pasien.penyakit << " | " << left << setw(5) << pasien.prioritas << " |" << endl;

		curr = next(curr);
	}
	cout << "+------+----------------------+----------------------+-------+" << endl;
}

Pasien generatePasien(string nama, int jenis){
	Pasien pasien;

	pasien.nama = nama;

	switch(jenis){
		case 1:{
			pasien.penyakit = "Serangan Jantung";
			pasien.prioritas = 10;

			break;
		}

		case 2:{
			pasien.penyakit = "Penyakit Dalam";
			pasien.prioritas = 9;

			break;
		}

		case 3:{
			pasien.penyakit = "Luka Bakar";
			pasien.prioritas = 9;

			break;
		}

		case 4:{
			pasien.penyakit = "Persalinan";
			pasien.prioritas = 8;

			break;
		}

		case 5:{
			pasien.penyakit = "Kecelakaan";
			pasien.prioritas = 8;

			break;
		}

		case 6:{
			pasien.penyakit = "Fraktur";
			pasien.prioritas = 7;

			break;
		}

		case 7:{
			pasien.penyakit = "Infeksi";
			pasien.prioritas = 6;

			break;
		}

		case 8:{
			pasien.penyakit = "Pendarahan";
			pasien.prioritas = 5;

			break;
		}

		case 9:{
			pasien.penyakit = "Syok";
			pasien.prioritas = 4;

			break;
		}

		case 10:{
			pasien.penyakit = "Dislokasi";
			pasien.prioritas = 4;


			break;
		}

		case 11:{
			pasien.penyakit = "Trauma Minor";
			pasien.prioritas = 3;

			break;
		}

		case 12:{
			pasien.penyakit = "Demam";
			pasien.prioritas = 2;

			break;
		}

		case 13:{
			pasien.penyakit = "Flu";
			pasien.prioritas = 1;

			break;
		}
	}

	return pasien;
}
