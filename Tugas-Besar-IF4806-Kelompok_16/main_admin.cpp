#include <iostream>
#include "header.h"
using namespace std;

int main_admin(ListBis &L, User users[], int &nUser) {
	bool running = true;
	adrBis B, precB;
	adrPenumpang P, precP;
	string kode_prec, noKTP_prec;

	while (running) {
		cout << "\n-------------------------Menu Admin-------------------------" << endl;
		cout << "Pilih salah satu opsi berikut:" << endl;
		cout << "1. Insert Bis" << endl;
		cout << "2. Delete Bis" << endl;
		cout << "3. Tampilkan Semua Bis" << endl;
		cout << "4. Insert Penumpang" << endl;
		cout << "5. Delete Penumpang" << endl;
		cout << "6. Tampilkan Semua Penumpang dalam Bis" << endl;
		cout << "7. Kembali ke Menu Utama" << endl;
		cout << "------------------------------------------------------------" << endl;

		int pilihan;
		cout << "Masukkan pilihan Anda: ";
		cin >> pilihan;

		if (pilihan < 1 || pilihan > 7) {
			cout << "Pilihan tidak valid!" << endl;

		} else if (pilihan == 1) {
			// ========== INSERT BIS ==========
			int subPilihan;
			cout << "\nPilih salah satu opsi berikut:" << endl;
			cout << "1. Insert First Bis" << endl;
			cout << "2. Insert Last Bis" << endl;
			cout << "3. Insert After Bis" << endl;
			cout << "4. Kembali ke Menu Admin" << endl;
			cout << "Masukkan pilihan Anda: ";
			cin >> subPilihan;

			if (subPilihan < 1 || subPilihan > 4) {
				cout << "Pilihan tidak valid!" << endl;
			} else if (subPilihan == 4) {
				continue;
			} else {
				infotypeB X;
				cout << "\nMasukkan data bis yang akan ditambahkan:" << endl;
				cout << "Kode Bis: ";
				cin >> X.kodeBis;

				// VALIDASI KODE BIS TIDAK BOLEH DUPLIKAT
				if (isKodeBisDuplicate(L, X.kodeBis)) {
					cout << "\n[ERROR] Kode Bis " << X.kodeBis << " sudah ada dalam sistem!\n";
					continue;
				}

				cout << "Rute: ";
				cin >> X.rute;

				do {
					cout << "Kapasitas: ";
					cin >> X.kapasitas;
					if (X.kapasitas <= 0) {
						cout << "Kapasitas harus lebih dari 0!" << endl;
					}
				} while (X.kapasitas <= 0);

				do {
					cout << "Harga Tiket: ";
					cin >> X.harga;
					if (X.harga <= 0) {
						cout << "Harga harus lebih dari 0!" << endl;
					}
				} while (X.harga <= 0);

				if (subPilihan == 1) {
					B = createBis(X);
					insertFirstBis(L, B);
					cout << "Bis berhasil ditambahkan di awal list!\n";
				} else if (subPilihan == 2) {
					B = createBis(X);
					insertLastBis(L, B);
					cout << "Bis berhasil ditambahkan di akhir list!\n";
				} else if (subPilihan == 3) {
					cout << "Masukkan Kode Bis sebelum bis yang akan ditambahkan: ";
					cin >> kode_prec;
					precB = findBis(L, kode_prec);
					if (precB == nullptr) {
						cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
					} else {
						B = createBis(X);
						insertAfterBis(L, B, precB);
						cout << "Bis berhasil ditambahkan setelah " << kode_prec << "!\n";
					}
				}
			}

		} else if (pilihan == 2) {
			// ========== DELETE BIS ==========
			int subPilihan;
			cout << "\nPilih salah satu opsi berikut:" << endl;
			cout << "1. Delete First Bis" << endl;
			cout << "2. Delete Last Bis" << endl;
			cout << "3. Delete After Bis" << endl;
			cout << "4. Kembali ke Menu Admin" << endl;
			cout << "Masukkan pilihan Anda: ";
			cin >> subPilihan;

			if (subPilihan < 1 || subPilihan > 4) {
				cout << "Pilihan tidak valid!" << endl;
			} else if (subPilihan == 4) {
				continue;
			} else if (subPilihan == 1) {
				deleteFirstBis(L, B);
				cout << "Bis pertama berhasil dihapus!\n";
			} else if (subPilihan == 2) {
				deleteLastBis(L, B);
				cout << "Bis terakhir berhasil dihapus!\n";
			} else if (subPilihan == 3) {
				cout << "Masukkan Kode Bis sebelum bis yang akan dihapus: ";
				cin >> kode_prec;
				precB = findBis(L, kode_prec);
				if (precB == nullptr) {
					cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
				} else {
					deleteAfterBis(L, B, precB);
					cout << "Bis setelah " << kode_prec << " berhasil dihapus!\n";
				}
			}

		} else if (pilihan == 3) {
			// ========== TAMPILKAN SEMUA BIS ==========
			showAllBis(L);

		} else if (pilihan == 4) {
			// ========== INSERT PENUMPANG ==========
			int subPilihan;
			cout << "\nPilih salah satu opsi berikut:" << endl;
			cout << "1. Insert First Penumpang" << endl;
			cout << "2. Insert Last Penumpang" << endl;
			cout << "3. Insert After Penumpang" << endl;
			cout << "4. Kembali ke Menu Admin" << endl;
			cout << "Masukkan pilihan Anda: ";
			cin >> subPilihan;

			if (subPilihan < 1 || subPilihan > 4) {
				cout << "Pilihan tidak valid!" << endl;
			} else if (subPilihan == 4) {
				continue;
			} else {
				cout << "Masukkan Kode Bis tujuan: ";
				cin >> kode_prec;
				B = findBis(L, kode_prec);

				if (B == nullptr) {
					cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
				} else {
					infotypeP Y;
					cout << "\nMasukkan data penumpang yang akan ditambahkan:" << endl;
					cout << "Nama: ";
					cin >> Y.nama;

					cout << "No KTP (16 digit): ";
					cin >> Y.noKTP;

					// VALIDASI KTP
					if (!validateKTP(Y.noKTP)) {
						cout << "\n[ERROR] Nomor KTP tidak valid! Harus 16 digit angka.\n";
						continue;
					}

					if (isKTPDuplicateInSystem(L, Y.noKTP)) {
						cout << "\n[ERROR] KTP sudah terdaftar dalam sistem!\n";
						continue;
					}

					do {
						cout << "Umur: ";
						cin >> Y.umur;
						if (Y.umur <= 0) {
							cout << "Umur harus lebih dari 0!" << endl;
						}
					} while (Y.umur <= 0);

					if (subPilihan == 1) {
						P = createPenumpang(Y);
						insertFirstPenumpang(B, P);
						cout << "Penumpang berhasil ditambahkan di awal list!\n";
					} else if (subPilihan == 2) {
						P = createPenumpang(Y);
						insertLastPenumpang(B, P);
						cout << "Penumpang berhasil ditambahkan di akhir list!\n";
					} else if (subPilihan == 3) {
						cout << "Masukkan No KTP penumpang sebelum penumpang yang akan ditambahkan: ";
						cin >> noKTP_prec;
						precP = findPenumpang(B, noKTP_prec);
						if (precP == nullptr) {
							cout << "Penumpang dengan No KTP " << noKTP_prec << " tidak ditemukan." << endl;
						} else {
							P = createPenumpang(Y);
							insertAfterPenumpang(B, P, precP);
							cout << "Penumpang berhasil ditambahkan setelah " << noKTP_prec << "!\n";
						}
					}
				}
			}

		} else if (pilihan == 5) {
			// ========== DELETE PENUMPANG ==========
			int subPilihan;
			cout << "\nPilih salah satu opsi berikut:" << endl;
			cout << "1. Delete First Penumpang" << endl;
			cout << "2. Delete Last Penumpang" << endl;
			cout << "3. Delete After Penumpang" << endl;
			cout << "4. Kembali ke Menu Admin" << endl;
			cout << "Masukkan pilihan Anda: ";
			cin >> subPilihan;

			if (subPilihan < 1 || subPilihan > 4) {
				cout << "Pilihan tidak valid!" << endl;
			} else if (subPilihan == 4) {
				continue;
			} else {
				cout << "Masukkan Kode Bis tujuan: ";
				cin >> kode_prec;
				B = findBis(L, kode_prec);

				if (B == nullptr) {
					cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
				} else {
					if (subPilihan == 1) {
						deleteFirstPenumpang(B, P);
						cout << "Penumpang pertama berhasil dihapus!\n";
					} else if (subPilihan == 2) {
						deleteLastPenumpang(B, P);
						cout << "Penumpang terakhir berhasil dihapus!\n";
					} else if (subPilihan == 3) {
						cout << "Masukkan No KTP penumpang sebelum penumpang yang akan dihapus: ";
						cin >> noKTP_prec;
						precP = findPenumpang(B, noKTP_prec);
						if (precP == nullptr) {
							cout << "Penumpang dengan No KTP " << noKTP_prec << " tidak ditemukan." << endl;
						} else {
							deleteAfterPenumpang(B, P, precP);
							cout << "Penumpang setelah " << noKTP_prec << " berhasil dihapus!\n";
						}
					}
				}
			}

		} else if (pilihan == 6) {
			// ========== TAMPILKAN SEMUA PENUMPANG ==========
			cout << "Masukkan Kode Bis untuk menampilkan penumpang: ";
			cin >> kode_prec;
			B = findBis(L, kode_prec);
			if (B == nullptr) {
				cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
			} else {
				showAllPenumpang(B);
			}

		} else if (pilihan == 7) {
			// ========== KEMBALI KE MENU UTAMA ==========
			cout << "Kembali ke Menu Utama...\n";
			running = false;
		}
	}
	return 0;
}
