#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    string NIM;
    string nama;
    int nilai;
    Mahasiswa(string NIM, string nama, int nilai) : NIM(NIM), nama(nama), nilai(nilai) {}
};

// Node untuk setiap entri dalam hash table
struct HashNode {
    vector<Mahasiswa> mahasiswas;
};

// Class hash table
class HashTable {
private:
    HashNode table[TABLE_SIZE];

    // Fungsi hash sederhana
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

public:
    // Menambahkan data mahasiswa
    void tambahMahasiswa(string NIM, string nama, int nilai) {
        int index = hashFunc(NIM);
        table[index].mahasiswas.push_back(Mahasiswa(NIM, nama, nilai));
    }

    // Menghapus data mahasiswa berdasarkan NIM
    void hapusMahasiswa(string NIM) {
        int index = hashFunc(NIM);
        vector<Mahasiswa>& mahasiswas = table[index].mahasiswas;
        for (auto it = mahasiswas.begin(); it != mahasiswas.end(); ++it) {
            if (it->NIM == NIM) {
                mahasiswas.erase(it);
                return;
            }
        }
    }

    // Mengakses table
    const HashNode* getTable() const {
        return table;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai
    vector<Mahasiswa> cariNilaiMahasiswa(int minNilai, int maxNilai) {
        vector<Mahasiswa> ketemu;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto& mahasiswa : table[i].mahasiswas) {
                if (mahasiswa.nilai >= minNilai && mahasiswa.nilai <= maxNilai) {
                    ketemu.push_back(mahasiswa);
                }
            }
        }
        return ketemu;
    }
};

// Fungsi untuk menampilkan menu dalam kotak
void tampilkanMenu() {
    cout << "================================" << endl;
    cout << "|           Menu               |" << endl;
    cout << "================================" << endl;
    cout << "| 1. Tambah data mahasiswa     |" << endl;
    cout << "| 2. Hapus data mahasiswa      |" << endl;
    cout << "| 3. Cari data nim mahasiswa   |" << endl;
    cout << "| 4. Cari data nilai mahasiswa |" << endl;
    cout << "| 0. Keluar                    |" << endl;
    cout << "================================" << endl;
    cout << "Pilihan: ";
}

int main() {
    HashTable ht;
    int pilihan;
    string NIM, nama;
    int nilai;
    int minNilai, maxNilai;
    vector<Mahasiswa> ketemu; // Inisialisasi vektor untuk menyimpan mahasiswa yang ditemukan
    bool ditemukan; // variabel ditemukan dideklarasikan di luar blok switch

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Nim: ";
                cin >> NIM;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.tambahMahasiswa(NIM, nama, nilai);
                cout << "Data mahasiswa berhasil ditambahkan.\n";
                break;
            case 2:
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> NIM;
                ht.hapusMahasiswa(NIM);
                cout << "Data mahasiswa dengan Nim " << NIM << " berhasil dihapus.\n";
                break;
            case 3:
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> NIM;
                ditemukan = false; // Setel ulang variabel ditemukan sebelum digunakan
                for (int i = 0; i < TABLE_SIZE; ++i) {
                    for (auto& mahasiswa : ht.getTable()[i].mahasiswas) {
                        if (mahasiswa.NIM == NIM) {
                            cout << "Data mahasiswa ditemukan:\n";
                            cout << "Nim: " << mahasiswa.NIM << ", Nama: " << mahasiswa.nama << ", Nilai: " << mahasiswa.nilai << endl;
                            ditemukan = true; // Setel ke true jika mahasiswa ditemukan
                        }
                    }
                }
                if (!ditemukan) { // Jika mahasiswa tidak ditemukan, tampilkan pesan
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
                }
                break;
            case 4:
                // Mencari mahasiswa berdasarkan rentang nilai (80 - 90)
                minNilai = 80;
                maxNilai = 90;
                ketemu = ht.cariNilaiMahasiswa(minNilai, maxNilai);
                if (!ketemu.empty()) {
                    cout << "Data mahasiswa dengan nilai antara 80 dan 90:\n";
                    for (const auto& mahasiswa : ketemu) {
                        cout << "Nim: " << mahasiswa.NIM << ", Nama: " << mahasiswa.nama << ", Nilai: " << mahasiswa.nilai << endl;
                    }
                } else {
                    cout << "Data mahasiswa dengan nilai antara 80 dan 90 tidak ditemukan.\n";
                }
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
