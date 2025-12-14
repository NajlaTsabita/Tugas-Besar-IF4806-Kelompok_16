#include <iostream>
#include "header.h"

using namespace std;

int main() {
    bool running = true;
    User users[100];
    int nUser = 0;

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

    while (running) {
        cout << "=================== SELAMAT DATANG ===================\n";
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
        } else if (pilihan == 1){
            addUser(users, nUser);
        } else if (pilihan == 2){
            cout << "\n===== LOGIN SISTEM BIS =====\n";
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "==============================\n";

                if (!login(users, nUser, username, password, role)) {
                    cout << "Login gagal! Username atau password salah.\n";
                    return 0;
                } else {
                    cout << "Login berhasil sebagai " << role << "!\n";
                    if (role == "admin") {
                        main_admin();
                    } else if (role == "user") {
                        main_user();
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
