#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Petugas;
class Admin;

class Buku {
private:
    string judul, penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void info() {
        cout << "Judul: " << judul << " | Penulis: " << penulis
             << " | Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    friend class Petugas;
    friend class Admin;
};

class Peminjam {
private:
    string nama, ID;
    int totalPinjaman;

public:
    Peminjam(string n, string id) : nama(n), ID(id), totalPinjaman(0) {}

    void info() {
        cout << "Peminjam: " << nama << " | ID: " << ID
             << " | Total Pinjaman: " << totalPinjaman << endl;
    }

    friend class Petugas;
    friend class Admin;
};

class Petugas {
private:
    string nama, IDpetugas, levelAkses;

public:
    Petugas(string n, string id, string lvl)
        : nama(n), IDpetugas(id), levelAkses(lvl) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Buku dipinjam oleh " << p->nama << endl;
        } else {
            cout << "Buku sudah dipinjam!" << endl;
        }
    }
};