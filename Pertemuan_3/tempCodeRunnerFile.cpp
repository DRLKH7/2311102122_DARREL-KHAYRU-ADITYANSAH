#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama_122;
    int harga_122;
    Node* prev;
    Node* next;
    Node(string nama, int harga) : nama_122(nama), harga_122(harga), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void tambah_depan(string nama, int harga) {
        Node* new_node = new Node(nama, harga);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void tambah_belakang(string nama, int harga) {
        Node* new_node = new Node(nama, harga);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void tambah_tengah(string nama, int harga, string nama_sebelumnya) {
        Node* temp = head;
        while (temp && temp->nama_122 != nama_sebelumnya) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Produk sebelumnya tidak ditemukan" << endl;
            return;
        }
        Node* new_node = new Node(nama, harga);
        new_node->prev = temp;
        new_node->next = temp->next;
        if (temp->next)
            temp->next->prev = new_node;
        temp->next = new_node;
    }

    void hapus(string nama) {
        Node* temp = head;
        while (temp && temp->nama_122 != nama) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Produk tidak ditemukan" << endl;
            return;
        }
        if (temp == head && temp == tail) {
            delete temp;
            head = nullptr;
            tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void update_data(string nama, string nama_baru, int harga_baru) {
        Node* temp = head;
        while (temp) {
            if (temp->nama_122 == nama) {
                temp->nama_122 = nama_baru;
                temp->harga_122 = harga_baru;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    void tampilkan_data() {
          if (!head) {
            cout << "Linked list kosong" << endl;
            return;
        }
        Node* temp = head;
        cout << "-----------------------" << endl;
        cout << "|   Nama     |  HARGA |" << endl;
        cout << "-----------------------" << endl;
        while (temp) {
           cout << "| " << setw(10) << left << temp->nama_122 << " | " << setw(6) << right << temp->harga_122 << " |" << endl;
            temp = temp->next;
        }
        cout << "-----------------------" << endl;
    }
};

int main() {
    DoubleLinkedList I;
    // Menambah data awal
    I.tambah_belakang("Originote", 60000);
    I.tambah_belakang("Somethinc", 150000);
    I.tambah_belakang("Skintific", 100000);
    I.tambah_belakang("Wardah", 50000);
    I.tambah_belakang("Hanasui", 30000);

    int choice;
    string nama_122, nama_sebelumnya, nama_baru;
    int harga_122, harga_baru;

    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk baru: ";
                cin >> nama_122;
                cout << "Masukkan harga produk: ";
                cin >> harga_122;
                I.tambah_belakang(nama_122, harga_122);
                break;
            case 2:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_122;
                I.hapus(nama_122);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_122;
                cout << "Masukkan nama baru: ";
                cin >> nama_baru;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                I.update_data(nama_122, nama_baru, harga_baru);
                break;
            case 4:
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> nama_122;
                cout << "Masukkan harga produk: ";
                cin >> harga_122;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> nama_sebelumnya;
                I.tambah_tengah(nama_122, harga_122, nama_sebelumnya);
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                cout << "Data Produk : " << endl;
                I.tampilkan_data();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 8);

    return 0;
}
