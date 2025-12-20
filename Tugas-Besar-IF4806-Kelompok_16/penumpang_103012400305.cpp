#include <iostream>
#include "header.h"

using namespace std;

adrPenumpang createPenumpang(infotypeP X) {
    adrPenumpang P = new Penumpang;
    P->info = X;
    P->next = nullptr;
    return P;
}

void insertFirstPenumpang(adrBis B, adrPenumpang P) {
    int terisi = countPenumpang(B);
    if (B->info.kapasitas > terisi) {
        if (B->firstPenumpang == nullptr) {
            B->firstPenumpang = P;
        } else {
            P->next = B->firstPenumpang;
            B->firstPenumpang = P;
        }
    } else {
        cout << "Tidak dapat menambahkan penumpang, bis sudah penuh" << endl;
    }
}

void insertLastPenumpang(adrBis B, adrPenumpang P) {
    int terisi = countPenumpang(B);
    adrPenumpang Q = B->firstPenumpang;
    if (B->info.kapasitas > terisi) {
        if (B->firstPenumpang == nullptr) {
            B->firstPenumpang = P;
        } else {
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = P;
        }
    } else {
        cout << "Tidak dapat menambahkan penumpang, bis sudah penuh" << endl;
    }
}

void insertAfterPenumpang(adrBis B, adrPenumpang P, adrPenumpang prec) {
    int terisi = countPenumpang(B);
    if (B->info.kapasitas > terisi) {
        if (B->firstPenumpang == nullptr) {
            B->firstPenumpang = P;
        } else {
            P->next = prec->next;
            prec->next = P;
        }
    } else {
        cout << "Tidak dapat menambahkan penumpang, bis sudah penuh" << endl;
    }
}

void deleteFirstPenumpang(adrBis B, adrPenumpang &P) {
    if (B->firstPenumpang == nullptr) {
        P = nullptr;
        cout << "Tidak ada penumpang untuk dihapus" << endl;
    } else if (B->firstPenumpang->next == nullptr) {
        P = B->firstPenumpang;
        B->firstPenumpang = nullptr;
    } else {
        P = B->firstPenumpang;
        B->firstPenumpang = P->next;
        P->next = nullptr;
    }
}

void deleteLastPenumpang(adrBis B, adrPenumpang &P) {
    if (B->firstPenumpang == nullptr) {
        P = nullptr;
        cout << "Tidak ada penumpang untuk dihapus" << endl;
    } else if (B->firstPenumpang->next == nullptr) {
        P = B->firstPenumpang;
        B->firstPenumpang = nullptr;
    } else {
        adrPenumpang Q = B->firstPenumpang;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterPenumpang(adrBis B, adrPenumpang &P, adrPenumpang prec) {
    if (B->firstPenumpang == nullptr) {
        P = nullptr;
        cout << "Tidak ada penumpang untuk dihapus" << endl;
    } else if (prec == nullptr || prec->next == nullptr) {
        P = nullptr;
        cout << "Posisi tidak valid untuk menghapus" << endl;
    } else {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

adrPenumpang findPenumpang(adrBis B, string noKTP) {
    adrPenumpang P = B->firstPenumpang;
    while (P != nullptr && P->info.noKTP != noKTP) {
        P = P->next;
    }
    return P;
}

void showAllPenumpang(adrBis B) {
    adrPenumpang P = B->firstPenumpang;
    if (P == nullptr) {
        cout << "\nTidak ada penumpang dalam bis ini." << endl;
    } else {
        cout << "\n========== DAFTAR PENUMPANG BIS " << B->info.kodeBis << " ==========\n";
        cout << "Rute: " << B->info.rute << endl;
        cout << "----------------------------------------------------\n";
        int no = 1;
        while (P != nullptr) {
            cout << no << ". Nama   : " << P->info.nama << endl;
            cout << "   No KTP: " << P->info.noKTP << endl;
            cout << "   Umur  : " << P->info.umur << " tahun" << endl;
            cout << endl;
            P = P->next;
            no++;
        }
        cout << "====================================================\n";
    }
}

// ============================================================
// FUNGSI VALIDASI KTP
// ============================================================
bool validateKTP(string noKTP) {
    if (noKTP.length() != 16) return false;
    for (int i = 0; i < 16; i++) {
        if (noKTP[i] < '0' || noKTP[i] > '9') return false;
    }
    return true;
}

bool isKTPDuplicateInSystem(ListBis L, string noKTP) {
    adrBis B = L.first;
    while (B != nullptr) {
        adrPenumpang P = B->firstPenumpang;
        while (P != nullptr) {
            if (P->info.noKTP == noKTP) {
                return true;
            }
            P = P->next;
        }
        B = B->next;
    }
    return false;
}
