#include <iostream>
#include <string>
using namespace std;

// Class untuk merepresentasikan mobil
class Mobil {
private:
    string merek;
    string model;
    int tahun;
    bool tersedia;

public:
    // Constructor untuk inisialisasi mobil
    Mobil(string jenismerek, string jenismodel, int jenistahun) {
        merek = jenismerek;
        model = jenismodel;
        tahun = jenistahun;
        tersedia = true; // Saat mobil pertama kali dibuat, diasumsikan tersedia
    }

    // Function untuk menampilkan informasi mobil
    void tampilkanInfo() {
        cout << "Mobil: " << merek << " " << model << " (" << tahun << ")" << endl;
        cout << "Status: " << (tersedia ? "Tersedia" : "Tidak Tersedia") << endl;
    }

    // Function untuk menyewa mobil
    void sewaMobil() {
        if (tersedia) {
            tersedia = false;
            cout << "Mobil berhasil disewa." << endl;
        } else {
            cout << "Maaf, mobil tidak tersedia untuk disewa saat ini." << endl;
        }
    }

    // Function untuk mengembalikan mobil
    void kembalikanMobil() {
        if (!tersedia) {
            tersedia = true;
            cout << "Mobil berhasil dikembalikan." << endl;
        } else {
            cout << "Mobil sudah tersedia." << endl;
        }
    }
};

int main() {
    // Membuat objek mobil
    Mobil mobil1_122("Toyota", "innova", 2013);
    Mobil mobil2_122("Toyota", "hilux", 2017);

    // Menampilkan informasi mobil sebelum disewa
    cout << "Informasi mobil sebelum disewa:" << endl;
    mobil1_122.tampilkanInfo();
    mobil2_122.tampilkanInfo();

    // Menyewa mobil
    mobil1_122.sewaMobil();
    mobil2_122.sewaMobil();

    // Menampilkan informasi mobil setelah disewa
    cout << "\nInformasi mobil setelah disewa:" << endl;
    mobil1_122.tampilkanInfo();
    mobil2_122.tampilkanInfo();

    // Mengembalikan mobil
    mobil1_122.kembalikanMobil();
    mobil2_122.kembalikanMobil();

    // Menampilkan informasi mobil setelah dikembalikan
    cout << "\nInformasi mobil setelah dikembalikan:" << endl;
    mobil1_122.tampilkanInfo();
    mobil2_122.tampilkanInfo();

    return 0;
}
