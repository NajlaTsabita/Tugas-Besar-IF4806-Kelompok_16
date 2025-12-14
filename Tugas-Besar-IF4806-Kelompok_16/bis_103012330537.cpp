#include <iostream>
#include "header.h"

void createListBis(ListBis &L) {
    L.first = nullptr;
    L.last  = nullptr;
}

adrBis createBis(infotypeB X){
    adrBis B = new Bis;
    B->info = X;
    B->firstPenumpang = nullptr;
    B->next = nullptr;
    B->prev = nullptr;
    return B;
}

void insertLastBis(ListBis &L, adrBis B) {
    if (L.first == nullptr) {
        L.first = B;
        L.last  = B;
    } else {
        L.last->next = B;
        B->prev = L.last;
        L.last = B;
    }
}

adrBis findBis(ListBis L, string kode) {
    adrBis P = L.first;
    while (P != nullptr) {
        if (P->info.kodeBis == kode) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}


void deleteBisByKode(ListBis &L, string kode) {
    if (L.first == nullptr) {
        cout << "List bis masih kosong.\n";
        return;
    }

    adrBis P = L.first;
    while (P != nullptr && P->info.kodeBis != kode) {
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Bis dengan kode " << kode << " tidak ditemukan.\n";
        return;
    }


    if (P == L.first && P == L.last) {
        L.first = nullptr;
        L.last  = nullptr;
    } else if (P == L.first) {
        L.first = P->next;
        L.first->prev = nullptr;
    } else if (P == L.last) {
        L.last = P->prev;
        L.last->next = nullptr;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }


    deleteAllPenumpang(P);
    delete P;

    cout << "Bis dengan kode " << kode << " berhasil dihapus.\n";
}

void showData(ListBis L) {
    adrBis B = L.first;
    if (B == nullptr) {
        cout << "\nBelum ada data bis.\n";
        return;
    }

    while (B != nullptr) {
        cout << "\n-----------------------------------\n";
        cout << "Kode Bis  : " << B->info.kodeBis << endl;
        cout << "Rute      : " << B->info.rute << endl;
        int terisi = countPenumpang(B);
        cout << "Kapasitas : " << B->info.kapasitas
             << " (Terisi: " << terisi << ")\n";
        cout << "Penumpang : ";

        if (B->firstPenumpang == nullptr) {
            cout << "(Belum ada penumpang)";
        } else {
            adrPenumpang P = B->firstPenumpang;
            while (P != nullptr) {
                cout << P->info.nama;
                if (P->next != nullptr) cout << ", ";
                P = P->next;
            }
        }
        cout << endl;

        B = B->next;
    }
}


void showBisByRute(ListBis L, string rute) {
    adrBis B = L.first;
    bool found = false;

    while (B != nullptr) {
        if (B->info.rute == rute) {
            found = true;
            cout << "\n-----------------------------------\n";
            cout << "Kode Bis  : " << B->info.kodeBis << endl;
            cout << "Rute      : " << B->info.rute << endl;
            int terisi = countPenumpang(B);
            cout << "Kapasitas : " << B->info.kapasitas
                 << " (Terisi: " << terisi << ")\n";
            cout << "Penumpang : ";
            if (B->firstPenumpang == nullptr) {
                cout << "(Belum ada penumpang)";
            } else {
                adrPenumpang P = B->firstPenumpang;
                while (P != nullptr) {
                    cout << P->info.nama;
                    if (P->next != nullptr) cout << ", ";
                    P = P->next;
                }
            }
            cout << endl;
        }
        B = B->next;
    }

    if (!found) {
        cout << "Tidak ada bis dengan rute: " << rute << endl;
    }
}



bool login(User users[], int n, string username, string password, string &role) {
    for (int i = 0; i < n; i++) {
        if (users[i].username == username && users[i].password == password) {
            role = users[i].role;
            return true;
        }
    }
    return false;
}

void addUser(User users[], int &n) {
    string uname, pass, role;
    cout << "Masukkan username baru : ";
    cin >> uname;
    cout << "Masukkan password      : ";
    cin >> pass;
    cout << "Masukkan role (admin/user): ";
    cin >> role;

    users[n].username = uname;
    users[n].password = pass;
    users[n].role     = role;
    n++;

    cout << "User berhasil ditambahkan!\n";
}

void deleteUser(User users[], int &n) {
    string uname;
    cout << "Masukkan username yang ingin dihapus: ";
    cin >> uname;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (users[i].username == uname) {
            for (int j = i; j < n - 1; j++) {
                users[j] = users[j + 1];
            }
            n--;
            found = true;
            cout << "User berhasil dihapus!\n";
            break;
        }
    }
    if (!found) {
        cout << "User tidak ditemukan!\n";
    }
}

void showUsers(User users[], int n) {
    cout << "\n=== DAFTAR USER ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1
             << ". Username: " << users[i].username
             << " | Role: "  << users[i].role << endl;
    }
}

