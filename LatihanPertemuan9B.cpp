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

