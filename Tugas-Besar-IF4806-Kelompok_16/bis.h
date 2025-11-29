#ifndef BIS_H_INCLUDED
#define BIS_H_INCLUDED
#include <iostream>

using namespace std;

struct infotypeB {
    string kodeBis;
    string rute;
    int kapasitas;
};
typedef struct Bis *adrBis;
struct Bis {
    infotypeB info;
    adrBis next;
    adrBis prev;
};
struct ListBis {
    adrBis first;
    adrBis last;
};

#endif // BIS_H_INCLUDED
