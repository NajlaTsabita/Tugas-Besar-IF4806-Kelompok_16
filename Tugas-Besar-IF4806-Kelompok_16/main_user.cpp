#include <iostream>
#include "header.h"

using namespace std;

int main_user(ListBis &L, User users[], int nUser) {
	bool running = true;

	while (running) {
		cout << "\n-------------------MENU USER-------------------\n";
		cout << "Pilih salah satu opsi berikut:" << endl;
		cout << "1. Tampilkan semua bis & penumpang" << endl;
		cout << "2. Cari bis berdasarkan rute" << endl;
		cout << "3. Tampilkan semua penumpang unik" << endl;
		cout << "4. Pesan Tiket (Tambah Penumpang)" << endl;
		cout << "5. Tambah bis setelah bis lain" << endl;
		cout << "6. Hapus bis berdasarkan kode bis" << endl;
		cout << "7. Tambah penumpang setelah penumpang lain" << endl;
		cout << "8. Hapus penumpang berdasarkan KTP" << endl;
		cout << "9. Laporan Keuntungan" << endl;
		cout << "10. Kembali ke Menu Utama" << endl;
		cout << "----------------------------------------------\n";

		int pilihan;
		string rute;

		cout << "Masukkan pilihan Anda: ";
		cin >> pilihan;

		if (pilihan < 1 || pilihan > 10) {
			cout << "\n[ERROR] Pilihan tidak valid!\n";
		} else if (pilihan == 1){
			// TAMPILKAN SEMUA BIS & PENUMPANG
			showData(L);

		} else if (pilihan == 2){
			// CARI BIS BERDASARKAN RUTE
			cout << "\nMasukkan rute yang ingin dicari: ";
			cin >> rute;
			showBisByRute(L, rute);

		} else if (pilihan == 3){
			// TAMPILKAN SEMUA PENUMPANG UNIK
			showAllPenumpangUnique(L);

		} else if (pilihan == 4){
			// PESAN TIKET (TAMBAH PENUMPANG)
			cout << "\n========== DAFTAR BIS TERSEDIA ==========\n";
			adrBis temp = L.first;
			bool adaBis = false;

			while (temp != nullptr) {
				int terisi = countPenumpang(temp);
				int tersedia = temp->info.kapasitas - terisi;

				cout << "Kode: " << temp->info.kodeBis
				     << " | Rute: " << temp->info.rute
				     << " | Tersedia: " << tersedia << "/" << temp->info.kapasitas << " kursi"
				     << " | Harga: Rp " << temp->info.harga << endl;
				adaBis = true;
				temp = temp->next;
			}
			cout << "=========================================\n";

			if (!adaBis) {
				cout << "\n[ERROR] Belum ada bis yang tersedia.\n";
			} else {
				string kodeBis;
				cout << "\nMasukkan Kode Bis tujuan: ";
				cin >> kodeBis;

				adrBis B = findBis(L, kodeBis);
				if (B == nullptr) {
					cout << "\n[ERROR] Bis dengan kode " << kodeBis << " tidak ditemukan!\n";
				} else {
					int jumlahPenumpang = countPenumpang(B);
					if (jumlahPenumpang >= B->info.kapasitas) {
						cout << "\n[ERROR] Bis sudah penuh! Kapasitas: " << B->info.kapasitas
						     << ", Penumpang saat ini: " << jumlahPenumpang << "\n";
					} else {
						infotypeP data;

						cout << "\n=== DATA PENUMPANG ===\n";
						cout << "Nama: ";
						cin >> data.nama;

						if (data.nama.empty()) {
							cout << "\n[ERROR] Nama tidak boleh kosong!\n";
						} else {
							cout << "No KTP (16 digit): ";
							cin >> data.noKTP;

							if (!validateKTP(data.noKTP)) {
								cout << "\n[ERROR] Nomor KTP tidak valid! Harus 16 digit angka.\n";
							} else if (isKTPDuplicateInSystem(L, data.noKTP)) {
								cout << "\n[ERROR] KTP sudah terdaftar dalam sistem!\n";
							} else {
								cout << "Umur: ";
								cin >> data.umur;

								if (data.umur <= 0 || data.umur > 150) {
									cout << "\n[ERROR] Umur tidak valid! Harus antara 1-150 tahun.\n";
								} else {
									adrPenumpang P = createPenumpang(data);
									insertLastPenumpang(B, P);

									cout << "\n[SUCCESS] Penumpang berhasil ditambahkan ke bis " << kodeBis << "!\n";
									cout << "Nama: " << data.nama << "\n";
									cout << "Rute: " << B->info.rute << "\n";
									cout << "Harga Tiket: Rp " << B->info.harga << "\n";
									cout << "Sisa kursi: " << (B->info.kapasitas - countPenumpang(B)) << " kursi\n";
								}
							}
						}
					}
				}
			}

		} else if (pilihan == 5){
			// TAMBAH BIS SETELAH BIS LAIN
			cout << "\n========== DAFTAR BIS ==========\n";
			adrBis temp = L.first;
			if (temp == nullptr) {
				cout << "Belum ada bis dalam sistem.\n";
			} else {
				while (temp != nullptr) {
					cout << "Kode: " << temp->info.kodeBis
					     << " | Rute: " << temp->info.rute << endl;
					temp = temp->next;
				}
				cout << "================================\n";

				string kode_prec;
				cout << "\nMasukkan Kode Bis sebelum bis yang akan ditambahkan: ";
				cin >> kode_prec;

				adrBis precB = findBis(L, kode_prec);
				if (precB == nullptr) {
					cout << "\n[ERROR] Bis dengan kode " << kode_prec << " tidak ditemukan!\n";
				} else {
					infotypeB X;
					cout << "\n=== DATA BIS BARU ===\n";
					cout << "Kode Bis: ";
					cin >> X.kodeBis;

					// VALIDASI KODE BIS TIDAK BOLEH DUPLIKAT
					if (isKodeBisDuplicate(L, X.kodeBis)) {
						cout << "\n[ERROR] Kode Bis " << X.kodeBis << " sudah ada dalam sistem!\n";
					} else {
						cout << "Rute: ";
						cin >> X.rute;

						do {
							cout << "Kapasitas: ";
							cin >> X.kapasitas;
							if (X.kapasitas <= 0) {
								cout << "[ERROR] Kapasitas harus lebih dari 0!\n";
							}
						} while (X.kapasitas <= 0);

						do {
							cout << "Harga Tiket: ";
							cin >> X.harga;
							if (X.harga <= 0) {
								cout << "[ERROR] Harga harus lebih dari 0!\n";
							}
						} while (X.harga <= 0);

						adrBis B = createBis(X);
						insertAfterBis(L, B, precB);
						cout << "\n[SUCCESS] Bis berhasil ditambahkan setelah " << kode_prec << "!\n";
					}
				}
			}

		} else if (pilihan == 6){
			// HAPUS BIS BERDASARKAN KODE BIS
			cout << "\n========== DAFTAR BIS ==========\n";
			adrBis temp = L.first;
			if (temp == nullptr) {
				cout << "Belum ada bis dalam sistem.\n";
			} else {
				while (temp != nullptr) {
					cout << "Kode: " << temp->info.kodeBis
					     << " | Rute: " << temp->info.rute
					     << " | Penumpang: " << countPenumpang(temp) << endl;
					temp = temp->next;
				}
				cout << "================================\n";

				string kodeBis;
				cout << "\nMasukkan Kode Bis yang akan dihapus: ";
				cin >> kodeBis;

				deleteBisByKode(L, kodeBis);
			}

		} else if (pilihan == 7){
			// TAMBAH PENUMPANG SETELAH PENUMPANG LAIN
			cout << "\n========== DAFTAR BIS TERSEDIA ==========\n";
			adrBis temp = L.first;
			while (temp != nullptr) {
				int terisi = countPenumpang(temp);
				cout << "Kode: " << temp->info.kodeBis
				     << " | Rute: " << temp->info.rute
				     << " | Tersedia: " << (temp->info.kapasitas - terisi) << "/" << temp->info.kapasitas << " kursi"
				     << " | Harga: Rp " << temp->info.harga << endl;
				temp = temp->next;
			}
			cout << "=========================================\n";

			string kodeBis;
			cout << "\nMasukkan Kode Bis tujuan: ";
			cin >> kodeBis;

			adrBis B = findBis(L, kodeBis);
			if (B == nullptr) {
				cout << "\n[ERROR] Bis tidak ditemukan!\n";
			} else {
				int jumlahPenumpang = countPenumpang(B);
				if (jumlahPenumpang >= B->info.kapasitas) {
					cout << "\n[ERROR] Bis sudah penuh!\n";
				} else {
					// Tampilkan daftar penumpang di bis ini
					cout << "\n=== PENUMPANG DI BIS " << kodeBis << " ===\n";
					adrPenumpang tampil = B->firstPenumpang;
					int no = 1;
					while (tampil != nullptr) {
						cout << no << ". " << tampil->info.nama
						     << " (KTP: " << tampil->info.noKTP << ")\n";
						tampil = tampil->next;
						no++;
					}

					string ktpPrec;
					cout << "\nMasukkan No KTP penumpang sebelumnya: ";
					cin >> ktpPrec;

					adrPenumpang precP = findPenumpang(B, ktpPrec);
					if (precP == nullptr) {
						cout << "\n[ERROR] Penumpang dengan KTP " << ktpPrec << " tidak ditemukan!\n";
					} else {
						infotypeP data;
						cout << "\n=== DATA PENUMPANG BARU ===\n";
						cout << "Nama: ";
						cin >> data.nama;

						if (data.nama.empty()) {
							cout << "\n[ERROR] Nama tidak boleh kosong!\n";
						} else {
							cout << "No KTP (16 digit): ";
							cin >> data.noKTP;

							if (!validateKTP(data.noKTP)) {
								cout << "\n[ERROR] KTP tidak valid!\n";
							} else if (isKTPDuplicateInSystem(L, data.noKTP)) {
								cout << "\n[ERROR] KTP sudah terdaftar!\n";
							} else {
								cout << "Umur: ";
								cin >> data.umur;

								if (data.umur <= 0 || data.umur > 150) {
									cout << "\n[ERROR] Umur tidak valid!\n";
								} else {
									adrPenumpang P = createPenumpang(data);
									insertAfterPenumpang(B, P, precP);
									cout << "\n[SUCCESS] Penumpang berhasil ditambahkan setelah "
									     << precP->info.nama << "!\n";
									cout << "Total biaya: Rp " << B->info.harga << endl;
								}
							}
						}
					}
				}
			}

		} else if (pilihan == 8){
			// HAPUS PENUMPANG BERDASARKAN KTP
			deletePenumpangByKTP(L);

		} else if (pilihan == 9){
			// LAPORAN KEUNTUNGAN
			tampilkanKeuntungan(L);

		} else if (pilihan == 10){
			// KEMBALI KE MENU UTAMA
			cout << "\nKembali ke Menu Utama...\n";
			running = false;
		}
	}
	return 0;
}
