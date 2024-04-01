#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama_122;
    string nim;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void tambahDepan(string nama_122, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama_122;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama_122, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama_122;
        newNode->nim = nim;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void tambahTengah(string nama_122, string nim, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }

        if (posisi == 1) {
            tambahDepan(nama, nim);
            return;
        }

        Node* newNode = new Node;
        newNode->nama = nama_122;
        newNode->nim = nim;

        Node* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void hapusDepan() {
        if (head == NULL) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void hapusBelakang() {
        if (head == NULL) {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void hapusTengah(int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }

        if (posisi == 1) {
            hapusDepan();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void hapusList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Seluruh list telah dihapus." << endl;
    }

    void ubahDepan(string namaLama_122, string namaBaru_122, string nimBaru) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama == namaLama_122) {
            temp->nama = namaBaru_122;
            temp->nim = nimBaru;
            return;
        }
        temp = temp->next;
    }
    cout << "Data dengan nama (" << namaLama_122 << ") tidak ditemukan." << endl;
}

void ubahBelakang(string namaLama_122, string namaBaru_122, string nimBaru) {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* temp = head;
  
    while (temp != NULL) {
        if (temp->nama == namaLama_122) {
            temp->nama = namaBaru_122;
            temp->nim = nimBaru;
            return;
        }
        temp = temp->next;
    }
    cout << "Data dengan nama " << namaLama_122 << " tidak ditemukan." << endl;
}

void ubahTengah(int posisi, string namaLama_122, string namaBaru_122, string nimBaru) {
    if (posisi <= 0) {
        cout << "Posisi harus lebih dari 0." << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < posisi; i++) {
        if (temp == NULL) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp != NULL) {
        temp->nama = namaBaru_122;
        temp->nim = nimBaru;
    } else {
        cout << "Posisi tidak valid." << endl;
    }
}

    void tampilkan() {
        if (head == NULL) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "==============================" << endl;
        cout << "|        LIST MAHASISWA      |" << endl;
        cout << "==============================" << endl;
        cout << "|       Nama    |     NIM    |" << endl;
        cout << "==============================" << endl;
        while (temp) {
            cout << "| " << setw(13) << left << temp->nama << " | " << setw(10) << right << temp->nim << " |" << endl;
            temp = temp->next;
        }
        cout << "==============================" << endl;\
    }
};

int main() {
    LinkedList I;
    int pilihan;
    string nama_122, nim, namabaru_122;
    int posisi;


    do {
        cout << endl;
        cout << "============================" << endl;
        cout << "|PROGRAM SINGLE LINKED LIST|" << endl;
        cout << "|       NON-CIRCULAR       |" << endl;
        cout << "============================" << endl;
        cout << "|1. | Tambah Depan         |" << endl;
        cout << "|2. | Tambah Belakang      |" << endl;
        cout << "|3. | Tambah Tengah        |" << endl;
        cout << "|4. | Ubah Depan           |" << endl;
        cout << "|5. | Ubah Belakang        |" << endl;
        cout << "|6. | Ubah Tengah          |" << endl;
        cout << "|7. | Hapus Depan          |" << endl;
        cout << "|8. | Hapus Belakang       |" << endl;
        cout << "|9. | Hapus Tengah         |" << endl;
        cout << "|10.| Hapus List           |" << endl;
        cout << "|11.| Tampilkan Data       |" << endl;
        cout << "|0. | Keluar               |" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        

        switch (pilihan) {
            case 1:
                cout << "-Tambah Depan-" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama_122;
                cout << "Masukkan NIM: ";
                cin >> nim;
                I.tambahDepan(nama_122, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "-Tambah Belakang-" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama_122;
                cout << "Masukkan NIM: ";
                cin >> nim;
                I.tambahBelakang(nama_122, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "-Tambah Tengah-" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama_122;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                I.tambahTengah(nama_122, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                cout << "-Ubah Depan-" << endl;
                cout << "Masukkan Nama Lama: ";
                cin >> nama_122;
                cout << "Masukkan Nama Baru: ";
                cin >> namabaru_122;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                I.ubahDepan(nama_122, namabaru_122, nim);
                cout << "Data " << nama_122 << " telah diubah menjadi " << namabaru_122 << endl;
                break;
            case 5:
                cout << "-Ubah Belakang-" << endl;
                cout << "Masukkan Nama Lama: ";
                cin >> nama_122;
                cout << "Masukkan Nama Baru: ";
                cin >> namabaru_122;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                I.ubahBelakang(nama_122, namabaru_122, nim);
                cout << "Data " << nama_122 << " telah diubah menjadi " << namabaru_122 << endl;
                break;
            case 6:
                cout << "-Ubah Tengah-" << endl;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                cout << "Masukkan Nama Baru: ";
                cin >> namabaru_122;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                I.ubahTengah(posisi, nama_122, namabaru_122, nim);
                  cout << "Data" << nama_122 << " telah diubah menjadi " << namabaru_122 << endl;
                break;
            case 7:
                cout << "-Hapus Depan-" << endl;
                I.hapusDepan();
                cout << "Data depan berhasil dihapus" << endl;
                break;
            case 8:
                cout << "-Hapus Belakang-" << endl;
                I.hapusBelakang();
                cout << "Data belakang berhasil dihapus" << endl;
                break;
            case 9:
                cout << "-Hapus Tengah-" << endl;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                I.hapusTengah(posisi);
                cout << "Data tengah berhasil dihapus" << endl;
                break;
            case 10:
                cout << "-Hapus List-" << endl;
                I.hapusList();
                break;
            case 11:
                cout << "-Tampilkan Data-" << endl;
                I.tampilkan();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                
        }
    } while (pilihan != 0);

    return 0;
}
