#include <iostream>
using namespace std;

struct Node {
    string data_122;
    Node* next_122;
};

Node* front = nullptr;
Node* back = nullptr;
const int maksimalAntrian_122 = 5;
int count = 0;

bool isFull() {
    return count == maksimalAntrian_122;
}

bool isEmpty() {
    return count == 0;
}

void tambahData(string nama) {
    if (isFull()) {
        cout << "Antrian sudah penuh." << endl;
        return;
    }

    Node* newNode_122 = new Node;
    newNode_122->data_122 = nama;
    newNode_122->next_122 = nullptr;

    if (isEmpty()) {
        front = back = newNode_122;
    } else {
        back->next_122 = newNode_122;
        back = newNode_122;
    }
    count++;
}

void kurangAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
        return;
    }

    Node* temp = front;
    front = front->next_122;
    delete temp;
    count--;
}

void viewQueue() {
    cout << "Data antrian:" << endl;
    Node* current = front;
    int i = 1;
    for (int j = 0; j < maksimalAntrian_122; ++j) {
        if (current != nullptr) {
            cout << i << ". " << current->data_122 << endl;
            current = current->next_122;
        } else {
            cout << i << ". (kosong)" << endl;
        }
        i++;
    }
}

void clearQueue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next_122;
        delete temp;
    }
    back = nullptr;
    count = 0;
}

int main() {
    tambahData("Darrel");
    tambahData("Budi");

    viewQueue();

    kurangAntrian();
    viewQueue();

    clearQueue();
    viewQueue();

    return 0;
}
