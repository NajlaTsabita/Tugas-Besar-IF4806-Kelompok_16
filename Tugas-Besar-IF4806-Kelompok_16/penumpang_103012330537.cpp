#include <iostream>
#include "header.h"

using namespace std;

void deleteAllPenumpang(adrBis B) {
    if (B == nullptr) return;
    adrPenumpang P = B->firstPenumpang;
    while (P != nullptr) {
        adrPenumpang del = P;
        P = P->next;
        delete del;
    }
    B->firstPenumpang = nullptr;
}

int countPenumpang(adrBis B) {
    if (B == nullptr) return 0;
    int cnt = 0;
    adrPenumpang P = B->firstPenumpang;
    while (P != nullptr) {
        cnt++;
        P = P->next;
    }
    return cnt;
}

void showAllPenumpangUnique(ListBis L) {
    string daftar[200];
    int n = 0;

    adrBis B = L.first;
    while (B != nullptr) {
        adrPenumpang P = B->firstPenumpang;
        while (P != nullptr) {
            bool ada = false;
            for (int i = 0; i < n; i++) {
                if (daftar[i] == P->info.noKTP) {
                    ada = true;
                    break;
                }
            }
            if (!ada) {
                daftar[n++] = P->info.noKTP;
            }
            P = P->next;
        }
        B = B->next;
    }

    if (n == 0) {
        cout << "Belum ada penumpang dalam sistem.\n";
    } else {
        cout << "\n=== DAFTAR PENUMPANG (UNIK) ===\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << daftar[i] << endl;
        }
    }
}



