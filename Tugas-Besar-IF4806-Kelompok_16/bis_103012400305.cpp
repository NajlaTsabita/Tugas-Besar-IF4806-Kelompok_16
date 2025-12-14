#include <iostream>
#include "header.h"

using namespace std;

void insertFirstBis(ListBis &L, adrBis B){
    if (L.first == nullptr && L.last == nullptr){
        L.first = B;
        L.last = B;
    } else {
        B->next = L.first;
        L.first = B;
    }
}

void insertAfterBis(ListBis &L, adrBis B, adrBis prec){
    if (L.first == nullptr && L.last == nullptr){
        L.first = B;
        L.last = B;
    } else if (prec == L.last){
        L.last->next = B;
        B->prev = prec;
        L.last = B;
    } else {
        B->next = prec->next;
        B->prev = prec;
        prec->next = B;
        prec->next->prev = B;
    }
}

void deleteFirstBis(ListBis &L, adrBis &B){
    if (L.first == nullptr && L.last == nullptr){
        B = nullptr;
    } else if (L.first == L.last){
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

void deleteLastBis(ListBis &L, adrBis &B){
    if (L.first == nullptr && L.last == nullptr){
        B = nullptr;
    } else if (L.first == L.last){
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

void deleteAfterBis(ListBis &L, adrBis &B, adrBis prec){
    if (L.first == nullptr && L.last == nullptr){
        B = nullptr;
    } else if (prec->next == L.last){
        B = prec->next;
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

void showAllBis(ListBis L){
    adrBis P = L.first;
    printf("+-----------+--------------------+----------+\n");
    printf("| Kode Bis  |       Rute       | Kapasitas |\n");
    printf("+-----------+--------------------+----------+\n");
    while (P != nullptr){
        printf("| %-9s | %-18s | %8d |\n", P->info.kodeBis, P->info.rute, P->info.kapasitas);
        P = P->next;
    }
    printf("+-----------+--------------------+----------+\n");
}
