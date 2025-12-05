#ifndef BIS_H_INCLUDED
#define BIS_H_INCLUDED
#include <iostream>
#include "penumpang.h"

using namespace std;

struct infoBis {
    string kodeBis;
    string rute;
    int kapasitas;
};

typedef infoBis infotypeB;

typedef struct Bis *adrBis;
struct Bis {
    infotypeB info;
    adrBis next;
    adrBis prev;
    adrPenumpang firstPenumpang;
};
struct ListBis {
    adrBis first;
    adrBis last;
};

void createListBis(ListBis &L);
adrBis createBis(infotypeB X);
void insertFirstBis(ListBis &L, adrBis B);
void insertLastBis(ListBis &L, adrBis B);
void insertAfterBis(ListBis &L, adrBis B, adrBis prec);
void deleteFirstBis(ListBis &L, adrBis &B);
void deleteLastBis(ListBis &L, adrBis &B);
void deleteAfterBis(ListBis &L, adrBis &B, adrBis prec);
adrBis findBis(ListBis L, string kode);
void showAllBis(ListBis L);

#endif // BIS_H_INCLUDED
