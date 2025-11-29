#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED
#include <iostream>

using namespace std;

struct infotypeP {
    string nama;
    string noKTP;
    int umur;
};
typedef Penumpang* adrPenumpang;
struct Penumpang {
    infotypeP info;
    adrPenumpang next;
};

void createListBis(ListBis &L);

#endif // PENUMPANG_H_INCLUDED
