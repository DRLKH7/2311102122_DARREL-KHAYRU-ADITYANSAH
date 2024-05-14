#include <iostream>
using namespace std;

const int maksimalAntrian_122 = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull () {
    if (back == maksimalAntrian_122) {
        return true;
    } else {
        return false;
    }
}

// mengecek antrian apakah masih kosong
bool ifEmpty() {
    if (back == 0){ 
        return true;
    } else {
        return false;
    }
}

// menambah antrian
void tambahData (string nama) {
    if (isFull ()) {
        cout << "Antrian sudah penuh." << endl;
    } else {
        if (ifEmpty ()) {
            queueTeller[0] = nama;
            front++;
            back++;
        } else {
            queueTeller[back] = nama;
            back++;
        }
    }
}

// mengurangi antrian
void kurangAntrian () {
    if (ifEmpty ()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i+1];
        }
        back++;
    }
}

// menghitung banyak antrian
int count () {
    return back;
}

// menghapus seluruh antrian
void clearQueue () {
    if (ifEmpty ()) {
        cout << "antrian kosong" << endl;
    } else {
        for (int i=0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

// melihat antrian
void viewQueue () {
    cout << "data antrian : " << endl;
    for (int i = 0; i < maksimalAntrian_122; i++)
    {
        if (queueTeller[i] !="") {
            cout << i+1 << ". " << queueTeller[i] << endl; 
        } else {
            cout << i+1<< ". " << "(kosong)" << endl;
        }
    }
}

// melihat main
int main(){
        tambahData("Alya");
        tambahData("Kiki");
        tambahData("Artika");

        viewQueue();

        //memngurangi antrian
        kurangAntrian();
        viewQueue();

        //menghapus seluruh antrian
        clearQueue();
        viewQueue();

        return 0;
    }