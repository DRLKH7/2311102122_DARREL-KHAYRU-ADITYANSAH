#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama_122;
    int usia_122;
    Node* next;
    Node(string nama, int usia) : nama_122(nama), usia_122(usia), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void tambah_depan(string nama, int usia) {
        Node* new_node = new Node(nama, usia);
        new_node->next = head;
        head = new_node;
    }

    void tambah_belakang(string nama, int usia) {
        Node* new_node = new Node(nama, usia);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void tambah_tengah(string nama, int usia, int posisi) {
        if (posisi <= 1) {
            tambah_depan(nama, usia);
            return;
        }
        Node* new_node = new Node(nama, usia);
        Node* temp = head;
        for (int i = 1; i < posisi - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Posisi melebihi panjang linked list" << endl;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void hapus(string nama) {
        if (!head) {
            cout << "Linked list kosong" << endl;
            return;
        }
        if (head->nama_122 == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp && temp->nama_122 != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void ubah_data(string nama_lama, string nama_baru, int usia_baru) {
        Node* temp = head;
        while (temp) {
            if (temp->nama_122 == nama_lama) {
                temp->nama_122 = nama_baru;
                temp->usia_122 = usia_baru;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void tampil() {
        if (!head) {
            cout << "Linked list kosong" << endl;
            return;
        }
        Node* temp = head;
        cout << "-----------------------" << endl;
        cout << "|   Nama     |  Usia  |" << endl;
        cout << "-----------------------" << endl;
        while (temp) {
            cout << "| " << setw(10) << left << temp->nama_122 << " | " << setw(6) << right << temp->usia_122 << " |" << endl;
            temp = temp->next;
        }
        cout << "-----------------------" << endl;
    }
};

int main() {
    LinkedList I;
    //soal a
    I.tambah_depan("Darrel", 18);
    I.tambah_belakang("Budi", 19);
    I.tambah_belakang("Carol", 20);
    I.tambah_belakang("Ann", 18);
    I.tambah_belakang("Yusuke", 19);
    I.tambah_belakang("Akechi", 20);
    I.tambah_belakang("Hoshino", 18);
    I.tambah_belakang("Karin", 18);

    I.tampil();
   
    // soal b
    I.hapus("Akechi");

    // soal c
    I.tambah_tengah("Futaba", 18, 3);

    // soal d
    I.tambah_depan("Igor", 20);

    // soal e
    I.ubah_data("Carol", "Reyn", 18);

    // soal f
    I.tampil();
    

    return 0;
}
