#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED
#include <iostream>

using namespace std;

struct Bis;
typedef Bis* adrBis;

struct infotypeP {
    string nama;
    string noKTP;
    int umur;
};
typedef struct Penumpang *adrPenumpang;
struct Penumpang {
    infotypeP info;
    adrPenumpang next;
};

adrPenumpang createPenumpang(infotypeP X);
void insertFirstPenumpang(adrBis B, adrPenumpang P);
void insertLastPenumpang(adrBis B, adrPenumpang P);
void insertAfterPenumpang(adrBis B, adrPenumpang P, adrPenumpang prec);
void deleteFirstPenumpang(adrBis B, adrPenumpang &P);
void deleteLastPenumpang(adrBis B, adrPenumpang &P);
void deleteAfterPenumpang(adrBis B, adrPenumpang &P, adrPenumpang prec);
adrPenumpang findPenumpang(adrBis B, string noKTP);
void showAllPenumpang(adrBis B);

int  countPenumpang(adrBis B);

#endif // PENUMPANG_H_INCLUDED
