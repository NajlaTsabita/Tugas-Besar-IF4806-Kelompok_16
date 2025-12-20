#include <iostream>
#include "header.h"

using namespace std;

int main() {
    bool running = true;
    User users[100];
    int nUser = 0;

    // ------------------ DATA DUMMY USER ------------------
    users[nUser++] = {"admin1", "admin1pass", "admin"};
    users[nUser++] = {"admin2", "admin2pass", "admin"};
    users[nUser++] = {"admin3", "admin3pass", "admin"};
    users[nUser++] = {"admin4", "admin4pass", "admin"};
    users[nUser++] = {"admin5", "admin5pass", "admin"};
    users[nUser++] = {"user1", "user1pass", "user"};
    users[nUser++] = {"user2", "user2pass", "user"};
    users[nUser++] = {"user3", "user3pass", "user"};
    users[nUser++] = {"user4", "user4pass", "user"};
    users[nUser++] = {"user5", "user5pass", "user"};

    // ------------------ DATA DUMMY BIS & PENUMPANG ------------------
    ListBis L;
    createListBis(L);
    adrBis B;

    insertFirstBis(L, createBis({"B001", "Jakarta-Bandung", 50, 100000}));
    B = L.first;
    insertFirstPenumpang(B, createPenumpang({"Alice", "1234567890123456", 25}));
    insertFirstPenumpang(B, createPenumpang({"Bob", "0987654321098765", 30}));
    insertFirstPenumpang(B, createPenumpang({"Charlie", "1122334455667788", 28}));
    insertFirstPenumpang(B, createPenumpang({"Diana", "5566778899001122", 22}));

    insertFirstBis(L, createBis({"B002", "Jakarta-Surabaya", 40, 150000}));
    B = L.first;
    insertFirstPenumpang(B, createPenumpang({"Eve", "6677889900112233", 27}));
    insertFirstPenumpang(B, createPenumpang({"Frank", "4433221100998877", 35}));
    insertFirstPenumpang(B, createPenumpang({"Grace", "2211003344556677", 29}));

    insertFirstBis(L, createBis({"B003", "Bandung-Yogyakarta", 20, 120000}));
    B = L.first;
    insertFirstPenumpang(B, createPenumpang({"Henry", "7788990011223344", 26}));
    insertFirstPenumpang(B, createPenumpang({"Ivy", "3344556677889900", 31}));
    insertFirstPenumpang(B, createPenumpang({"Jack", "9988776655443322", 24}));

    insertFirstBis(L, createBis({"B004", "Jakarta-Semarang", 30, 110000}));
    B = L.first;
    insertFirstPenumpang(B, createPenumpang({"Karen", "5566443322110099", 23}));
    insertFirstPenumpang(B, createPenumpang({"Leo", "2211334455667788", 34}));

    insertFirstBis(L, createBis({"B005", "Surabaya-Malang", 45, 80000}));
    B = L.first;
    insertFirstPenumpang(B, createPenumpang({"Mia", "6677554433221100", 28}));
    insertFirstPenumpang(B, createPenumpang({"Nina", "3344221100998877", 32}));

    while (running) {
        cout << "\n=================== SELAMAT DATANG ===================\n";
        cout << "pilih salah satu opsi berikut:" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar dari Program" << endl;
        cout << "======================================================\n";

        int pilihan;
        string username, password, role;

        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 3) {
            cout << "Pilihan tidak valid!" << endl;
        } else if (pilihan == 1) {
            addUser(users, nUser);
        } else if (pilihan == 2) {
            cout << "\n===== LOGIN SISTEM BIS =====\n";
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "==============================\n";

            if (!login(users, nUser, username, password, role)) {
                cout << "Login gagal! Username atau password salah.\n";
            } else {
                cout << "Login berhasil sebagai " << role << "!\n";
                if (role == "admin") {
                    main_admin(L, users, nUser);
                } else if (role == "user") {
                    main_user(L, users, nUser);
                } else {
                    cout << "Role tidak dikenali.\n";
                }
            }
        } else {
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
            running = false;
        }
    }
    return 0;
}
