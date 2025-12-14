#include <iostream>
#include "header.h"
using namespace std;

int main_admin() {
    bool running = true;
    ListBis L;
    createListBis(L);
    adrBis B, precB;
    adrPenumpang P, precP;
    string kode_prec, noKTP_prec;
    while (running) {
        cout << "-------------------------Menu Admin-------------------------" << endl;
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
        if (pilihan < 1 && pilihan > 6) {
            cout << "Pilihan tidak valid!" << endl;
        } else if (pilihan == 1){
            cout << "Pilih salah satu opsi berikut:" << endl;
            cout << "1. Insert First Bis" << endl;
            cout << "2. Insert Last Bis" << endl;
            cout << "3. Insert After Bis" << endl;
            cout << "4. Kembali ke Menu Admin" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;

            if (pilihan < 1 || pilihan > 4) {
                cout << "Pilihan tidak valid!" << endl;
            } else if (pilihan == 1){
                cout << "Masukkan data bis yang akan ditambahkan:" << endl;
                cout << "Kode Bis: ";
                infotypeB X;
                cin >> X.kodeBis;
                cout << "Rute: ";
                cin >> X.rute;
                cout << "Kapasitas: ";
                cin >> X.kapasitas;
                B = createBis(X);
                insertFirstBis(L, B);
            } else if (pilihan == 2){
                string kode;
                cout << "Masukkan data bis yang akan ditambahkan:" << endl;
                cout << "Kode Bis: ";
                infotypeB X;
                cin >> X.kodeBis;
                cout << "Rute: ";
                cin >> X.rute;
                cout << "Kapasitas: ";
                cin >> X.kapasitas;
                B = createBis(X);
                insertLastBis(L, B);
            } else if (pilihan == 3){
                cout << "Masukkan data bis yang akan ditambahkan:" << endl;
                cout << "Kode Bis: ";
                infotypeB X;
                cin >> X.kodeBis;
                cout << "Rute: ";
                cin >> X.rute;
                cout << "Kapasitas: ";
                cin >> X.kapasitas;
                cout << "Masukkan Kode Bis sebelum bis yang akan ditambahkan: ";
                cin >> kode_prec;
                precB = findBis(L, kode_prec);
                if (precB == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                } else {
                    B = createBis(X);
                    insertAfterBis(L, B, precB);
                }
            } else {
                return main_admin();
            }
        } else if (pilihan == 2){
            cout << "Pilih salah satu opsi berikut:" << endl;
            cout << "1. Delete First Bis" << endl;
            cout << "2. Delete Last Bis" << endl;
            cout << "3. Delete After Bis" << endl;
            cout << "4. Kembali ke Menu Admin" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;

            if (pilihan < 1 || pilihan > 4) {
                cout << "Pilihan tidak valid!" << endl;
            } else if (pilihan == 1){
                deleteFirstBis(L, B);
            } else if (pilihan == 2){
                deleteLastBis(L, B);
            } else if (pilihan == 3){
                cout << "Masukkan Kode Bis sebelum bis yang akan dihapus: ";
                cin >> kode_prec;
                precB = findBis(L, kode_prec);
                if (precB == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                } else {
                    deleteAfterBis(L, B, precB);
                }
            } else {
                return main_admin();
            }
        } else if (pilihan == 3){
            showAllBis(L);
        } else if (pilihan == 4){
            cout << "Pilih salah satu opsi berikut:" << endl;
            cout << "1. Insert First Penumpang" << endl;
            cout << "2. Insert Last Penumpang" << endl;
            cout << "3. Insert After Penumpang" << endl;
            cout << "4. Kembali ke Menu Admin" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;

            if (pilihan < 1 || pilihan > 4) {
                cout << "Pilihan tidak valid!" << endl;
            } else if (pilihan == 1){
                cout << "Masukkan Kode Bis tujuan: ";
                cin >> kode_prec;
                B = findBis(L, kode_prec);
                if (B == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                }
                cout << "Masukkan data penumpang yang akan ditambahkan:" << endl;
                infotypeP Y;
                cout << "Nama: ";
                cin >> Y.nama;
                cout << "No KTP: ";
                cin >> Y.noKTP;
                cout << "Umur: ";
                cin >> Y.umur;
                P = createPenumpang(Y);
                insertFirstPenumpang(B, P);
            } else if (pilihan == 2){
                cout << "Masukkan Kode Bis tujuan: ";
                cin >> kode_prec;
                B = findBis(L, kode_prec);
                if (B == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                }
                cout << "Masukkan data penumpang yang akan ditambahkan:" << endl;
                infotypeP Y;
                cout << "Nama: ";
                cin >> Y.nama;
                cout << "No KTP: ";
                cin >> Y.noKTP;
                cout << "Umur: ";
                cin >> Y.umur;
                P = createPenumpang(Y);
                insertLastPenumpang(B, P);
            } else if (pilihan == 3){
                cout << "Masukkan Kode Bis tujuan: ";
                cin >> kode_prec;
                B = findBis(L, kode_prec);
                if (B == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                }
                cout << "Masukkan data penumpang yang akan ditambahkan:" << endl;
                infotypeP Y;
                cout << "Nama: ";
                cin >> Y.nama;
                cout << "No KTP: ";
                cin >> Y.noKTP;
                cout << "Umur: ";
                cin >> Y.umur;
                cout << "Masukkan No KTP penumpang sebelum penumpang yang akan ditambahkan: ";
                cin >> noKTP_prec;
                precP = findPenumpang(B, noKTP_prec);
                if (precP == nullptr) {
                    cout << "Penumpang dengan No KTP " << noKTP_prec << " tidak ditemukan." << endl;
                    return main_admin();
                } else {
                    P = createPenumpang(Y);
                    insertAfterPenumpang(B, P, precP);
                }
            } else {
                return main_admin();
            }
        } else if (pilihan == 5){
            cout << "Pilih salah satu opsi berikut:" << endl;
            cout << "1. Delete First Penumpang" << endl;
            cout << "2. Delete Last Penumpang" << endl;
            cout << "3. Delete After Penumpang" << endl;
            cout << "4. Kembali ke Menu Admin" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;

            if (pilihan < 1 || pilihan > 4) {
                cout << "Pilihan tidak valid!" << endl;
            } else if (pilihan == 1){
                cout << "Masukkan Kode Bis tujuan: ";
                cin >> kode_prec;
                B = findBis(L, kode_prec);
                if (B == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                }
                deleteFirstPenumpang(B, P);
            } else if (pilihan == 2){
                cout << "Masukkan Kode Bis tujuan: ";
                cin >> kode_prec;
                B = findBis(L, kode_prec);
                if (B == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                }
                deleteLastPenumpang(B, P);
            } else if (pilihan == 3){
                cout << "Masukkan Kode Bis tujuan: ";
                cin >> kode_prec;
                B = findBis(L, kode_prec);
                if (B == nullptr) {
                    cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                    return main_admin();
                }
                cout << "Masukkan No KTP penumpang sebelum penumpang yang akan dihapus: ";
                cin >> noKTP_prec;
                precP = findPenumpang(B, noKTP_prec);
                if (precP == nullptr) {
                    cout << "Penumpang dengan No KTP " << noKTP_prec << " tidak ditemukan." << endl;
                    return main_admin();
                } else {
                    deleteAfterPenumpang(B, P, precP);
                }
            } else {
                main_admin();
            }
        } else if (pilihan == 6){
            cout << "Masukkan Kode Bis untuk menampilkan penumpang: ";
            cin >> kode_prec;
            B = findBis(L, kode_prec);
            if (B == nullptr) {
                cout << "Bis dengan Kode Bis " << kode_prec << " tidak ditemukan." << endl;
                return main_admin();
            }
            showAllPenumpang(B);
        } else {
            return 0;
        }
    }
    return 0;
}
