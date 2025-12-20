#include <iostream>
#include "header.h"

using namespace std;

void insertFirstBis(ListBis &L, adrBis B) {
    if (L.first == nullptr && L.last == nullptr) {
        L.first = B;
        L.last = B;
    } else {
        B->next = L.first;
        L.first->prev = B;
        L.first = B;
    }
}

void insertAfterBis(ListBis &L, adrBis B, adrBis prec) {
    if (L.first == nullptr && L.last == nullptr) {
        L.first = B;
        L.last = B;
    } else if (prec == L.last) {
        L.last->next = B;
        B->prev = L.last;
        L.last = B;
    } else {
        B->next = prec->next;
        B->prev = prec;
        prec->next->prev = B;
        prec->next = B;
    }
}

void deleteFirstBis(ListBis &L, adrBis &B) {
    if (L.first == nullptr && L.last == nullptr) {
        B = nullptr;
        cout << "List bis kosong, tidak ada yang bisa dihapus.\n";
    } else if (L.first == L.last) {
        B = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        B = L.first;
        L.first = B->next;
        B->next = nullptr;
        L.first->prev = nullptr;
    }
}

void deleteLastBis(ListBis &L, adrBis &B) {
    if (L.first == nullptr && L.last == nullptr) {
        B = nullptr;
        cout << "List bis kosong, tidak ada yang bisa dihapus.\n";
    } else if (L.first == L.last) {
        B = L.last;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        B = L.last;
        L.last = B->prev;
        B->prev = nullptr;
        L.last->next = nullptr;
    }
}

void deleteAfterBis(ListBis &L, adrBis &B, adrBis prec) {
    if (L.first == nullptr && L.last == nullptr) {
        B = nullptr;
        cout << "List bis kosong, tidak ada yang bisa dihapus.\n";
    } else if (prec == nullptr || prec->next == nullptr) {
        B = nullptr;
        cout << "Tidak ada bis setelah posisi yang ditentukan.\n";
    } else if (prec->next == L.last) {
        B = L.last;
        L.last = prec;
        B->prev = nullptr;
        prec->next = nullptr;
    } else {
        B = prec->next;
        prec->next = B->next;
        B->next->prev = prec;
        B->next = nullptr;
        B->prev = nullptr;
    }
}

void showAllBis(ListBis L) {
    adrBis P = L.first;

    if (P == nullptr) {
        cout << "\nBelum ada data bis.\n";
        return;
    }

    cout << "\n========== DAFTAR SEMUA BIS ==========\n";
    while (P != nullptr) {
        cout << "Kode Bis  : " << P->info.kodeBis << endl;
        cout << "Rute      : " << P->info.rute << endl;
        cout << "Kapasitas : " << P->info.kapasitas << endl;
        cout << "Harga     : Rp " << P->info.harga << endl;
        cout << "--------------------------------------\n";
        P = P->next;
    }
}
