#include <iostream>
#include "penumpang.h"
#include "bis.h"

using namespace std;

adrPenumpang createPenumpang(infotypeP X){
    adrPenumpang P = new Penumpang;
    P->info = X;
    P->next = nullptr;
    return P;
}

void insertFirstPenumpang(adrBis B, adrPenumpang P){
    int terisi = countPenumpang(B);
    if (B->info.kapasitas <= terisi){
        if (B->firstPenumpang == nullptr){
            B->firstPenumpang = P;
        } else {
            P->next = B->firstPenumpang;
            B->firstPenumpang = P;
        }
    } else {
        cout << "Tidak dapat menambahkan penumpang, bis sudah penuh";
    }
}

void insertLastPenumpang(adrBis B, adrPenumpang P){
    int terisi = countPenumpang(B);
    adrPenumpang Q = B->firstPenumpang;

    if (B->info.kapasitas <= terisi){
        if (B->firstPenumpang == nullptr){
            B->firstPenumpang = P;
        } else {
            while (Q->next != nullptr){
                Q = Q->next;
            }
            Q->next = P;
        }
    } else {
        cout << "Tidak dapat menambahkan penumpang, bis sudah penuh";
    }
}

void insertAfterPenumpang(adrBis B, adrPenumpang P, adrPenumpang prec){
    int terisi = countPenumpang(B);
    if (B->info.kapasitas <= terisi){
        if (B->firstPenumpang == nullptr){
            B->firstPenumpang = P;
        } else {
            P->next = prec->next;
            prec->next = P;
        }
    } else {
        cout << "Tidak dapat menambahkan penumpang, bis sudah penuh";
    }
}
void deleteFirstPenumpang(adrBis B, adrPenumpang &P){
    if (B->firstPenumpang != nullptr){
        P = nullptr;
        cout << "Tidak ada penumpang untuk dihapus";
    } else if (B->firstPenumpang->next == nullptr){
        P = B->firstPenumpang;
        B->firstPenumpang = nullptr;
    } else {
        P = B->firstPenumpang;
        B->firstPenumpang = P->next;
        P->next = nullptr;
    }
}

void deleteLastPenumpang(adrBis B, adrPenumpang &P){
    if (B->firstPenumpang != nullptr){
        P = nullptr;
        cout << "Tidak ada penumpang untuk dihapus";
    } else if (B->firstPenumpang->next == nullptr){
        P = B->firstPenumpang;
        B->firstPenumpang = nullptr;
    } else {
        adrPenumpang Q = B->firstPenumpang;
        while (Q->next->next != nullptr){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterPenumpang(adrBis B, adrPenumpang &P, adrPenumpang prec){
    if (B->firstPenumpang != nullptr){
        P = nullptr;
        cout << "Tidak ada penumpang untuk dihapus";
    } else if (B->firstPenumpang->next == nullptr){
        P = B->firstPenumpang;
        B->firstPenumpang = nullptr;
    } else {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

adrPenumpang findPenumpang(adrBis B, string noKTP){
    adrPenumpang P = B->firstPenumpang;
    while (P != nullptr && P->info.noKTP != noKTP) {
        P = P->next;
    }
    return P;
}

void showAllPenumpang(adrBis B){
    adrPenumpang P = B->firstPenumpang;
    if (P == nullptr) {
        cout << "Tidak ada penumpang dalam bis ini." << endl;
    } else {
        cout << "Daftar Penumpang dalam Bis " << B->info.kodeBis << ":" << endl;
        while (P != nullptr) {
            cout << "Nama: " << P->info.nama << ", No KTP: " << P->info.noKTP << ", Umur: " << P->info.umur << endl;
            P = P->next;
        }
    }
}

int  countPenumpang(adrBis B){
    if (B == NULL) return 0;
    int cnt = 0;
    adrPenumpang P = B->firstPenumpang;
    while (P != NULL) {
        cnt++;
        P = P->next;
    }
    return cnt;
}
