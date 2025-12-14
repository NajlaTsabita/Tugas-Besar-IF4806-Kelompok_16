#ifndef BIS_H_INCLUDED
#define BIS_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct Bis *adrBis;
typedef struct infoBis infotypeB;
typedef struct Penumpang *adrPenumpang;

struct infoBis {
    string kodeBis;
    string rute;
    int kapasitas;
};

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

struct infotypeP {
    string nama;
    string noKTP;
    int umur;
};

struct Penumpang {
    infotypeP info;
    adrPenumpang next;
};

struct User {
    string username;
    string password;
    string role;
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
void deleteBisByKode(ListBis &L, string kode);
void showBisByRute(ListBis L, string rute);

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
void deleteAllPenumpang(adrBis B);
void showAllPenumpangUnique(ListBis L);

bool login(User users[], int n, string username, string password, string &role);
void addUser(User users[], int &n);
void deleteUser(User users[], int &n);
void showUsers(User users[], int n);

int main_admin();
int main_user();

#endif 

// BIS_H_INCLUDED