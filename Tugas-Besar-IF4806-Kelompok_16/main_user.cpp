#include <iostream>
#include "header.h"

using namespace std;

int main_user() {
    bool running = true;
    while (running) {
        cout << "-------------------MENU USER-------------------\n";
        cout << "Pilih salah satu opsi berikut:" << endl;
        cout << "1. Tambah User Baru" << endl;
        cout << "2. Hapus User" << endl;
        cout << "3. Tampilkan Semua User" << endl;
        cout << "4. Tampilkan semua bis & penumpang" << endl;
        cout << "5. Cari bis berdasarkan rute" << endl;
        cout << "6. Tampilkan semua penumpang unik" << endl;
        cout << "7. Kembali ke Menu Utama" << endl;
        cout << "----------------------------------------------\n"; 

        int pilihan;
        ListBis L;
        User users[100];
        int userCount = 0;
        string rute;

        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        if (pilihan < 1 || pilihan > 7) {
            cout << "Pilihan tidak valid!" << endl;
        } else if (pilihan == 1){
            addUser(users, userCount);
        } else if (pilihan == 2){
            deleteUser(users, userCount);
        } else if (pilihan == 3){
            showUsers(users, userCount);
        } else if (pilihan == 4){
            showAllBis(L);
        } else if (pilihan == 5){
            cout << "Masukkan rute yang ingin dicari: ";
            cin >> rute;
            showBisByRute(L, rute);
        } else if (pilihan == 6){
            createListBis(L);
            showAllPenumpangUnique(L);
        } else {
            return 0;
            running = false;
        }
    }
    return 0;
}