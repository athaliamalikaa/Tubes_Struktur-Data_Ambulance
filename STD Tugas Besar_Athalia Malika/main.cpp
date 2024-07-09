#include"ugd.h"

int main(){
	Queue q;
	int menu, jenis;
	string nama;
	Pasien pasien;

	initializeQueue(q);
	do{
		if(!isQueueEmpty(q)){
			printQueue(q);
		}else{
			cout << "List Pasien Kosong" << endl;
		}
		cout << endl;

		cout << "=== Rumah Sakit Bojongsoang ===" << endl;
		cout << "[1] Daftar" << endl;
		cout << "[2] Panggil Pasien" << endl;
		cout << "[3] Keluar" << endl;
		cout << ">>> "; cin >> menu;

		cout << endl;
		switch(menu){
			case 1:{
				cout << "Daftar Pasien" << endl;

				cin.ignore();
				cout << "Masukkan Nama Pasien : ";
				getline(cin >> ws, nama);

				cout << endl;
				cout << "Jenis Penyakit" << endl;
				cout << "[1]  Serangan Jantung" << endl;
				cout << "[2]  Penyakit Dalam" << endl;
				cout << "[3]  Luka Bakar" << endl;
				cout << "[4]  Persalinan" << endl;
				cout << "[5]  Kecelakaan" << endl;
				cout << "[6]  Fraktur" << endl;
				cout << "[7]  Infeksi" << endl;
				cout << "[8]  Pendarahan" << endl;
				cout << "[9]  Syok" << endl;
				cout << "[10] Dislokasi" << endl;
				cout << "[11] Trauma Minor" << endl;
				cout << "[12] Demam" << endl;
				cout << "[13] Flu" << endl;
				do{
					cout << endl;
					cout << "Masukkan Nomor dari Jenis Penyakit : "; cin >> jenis;
					if(jenis < 1 || jenis > 13){
						cout << endl;
						cout << "[!] Nomor Jenis Penyakit Tidak Valid!" << endl;
					}else{
						cout << endl;
					}
				}while(jenis < 1 || jenis > 13);

				pasien = generatePasien(nama, jenis);

				enqueue(q, pasien);

				cout << "Pasien Berhasil Didaftarkan, Harap Menunggu di Tempat yang Sudah Diseadiakan!" << endl;

				break;
			}

			case 2:{
				if(!isQueueEmpty(q)){
					pasien = dequeue(q);

					cout << "Ding.. Dong.." << endl << endl;
					cout << "Pemanggilan Pasien :" << endl;
					cout << "Nama     : " << pasien.nama << endl;
					cout << "Penyakit : " << pasien.penyakit << endl << endl;
					cout << "Harap Segera Memasuki Ruangan Tindakan, Terima Kasih" << endl;
				}else{
					cout << "List Pasien Masih Kosong" << endl;
				}

				break;
			}

			case 3:{
				cout << "Keluar dari Program" << endl;

				break;
			}

			default:{
				cout << "[!] Input Menu Tidak Valid!" << endl;

				break;
			}
		}

		if(menu != 3){
			cout << endl;
			system("pause");
			system("cls");
		}
	}while(menu != 3);

	return 0;
}
