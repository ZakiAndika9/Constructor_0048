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

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku dikembalikan oleh " << p->nama << endl;
        } else {
            cout << "Buku belum dipinjam!" << endl;
        }
    }

    friend class Admin;
};

class Admin {
public:
    void lihatStatistik(Peminjam* p, Buku* b) {
        cout << "Statistik Admin:\n";
        cout << "- Nama Peminjam: " << p->nama << endl;
        cout << "- Total Pinjaman: " << p->totalPinjaman << endl;
        cout << "- Status Buku: " << (b->dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    void ubahLevelAkses(Petugas* ptg, string levelBaru) {
        ptg->levelAkses = levelBaru;
        cout << "Level akses petugas diubah ke: " << levelBaru << endl;
    }
};

int main() {
    Buku* b = new Buku("Algoritma Dasar", "Jodi");
    Peminjam* p = new Peminjam("Dikel", "PMJ001");
    Petugas* t = new Petugas("Bu Jihan", "PT001", "Normal");
    Admin* a = new Admin();

    b->info();
    t->prosesPinjam(b, p);
    b->info();
    p->info();

    a->lihatStatistik(p, b);
    a->ubahLevelAkses(t, "Administrator");

    t->prosesKembali(b, p);
    b->info();

    delete b;
    delete p;
    delete t;
    delete a;

return 0;
}
