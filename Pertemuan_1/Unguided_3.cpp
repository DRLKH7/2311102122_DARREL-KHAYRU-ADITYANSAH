#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // array untuk menyimpan data index dan nama
    cout << "LIST DATA MAP" << endl;
    string nama_122[5] = {"DARREL", "AHMAD", "TOM", "JERI", "BAGAS"};

    // menampilkan isi array satu per satu sesuai index
    cout << "1 : " << nama_122[0] << endl;
    cout << "2 : " << nama_122[1] << endl;
    cout << "3 : " << nama_122[2] << endl;
    cout << "4 : " << nama_122[3] << endl;
    cout << "5 : " << nama_122[4] << endl;

    // menggunakan map untuk menyimpan data index dan nama dalam satu variabel
    cout << "\n";
    cout << "menampilkan  data map" << endl;
    map<int, string> makanan;
    makanan[1] = "Magelangan";
    makanan[2] = "Gado-gado";
    makanan[3] = "Ketoprak";
    makanan[4] = "Gulai";
    makanan[5] = "jengkol";
    // menampilkan isi dari data map
    cout << "makanan[1] :" << makanan[1] << endl;
    cout << "makanan[2] :" << makanan[2] << endl;
    cout << "makanan[3] :" << makanan[3] << endl;
    cout << "makanan[4] :" << makanan[4] << endl;
    cout << "makanan[5] :" << makanan[5] << endl;
    return 0;
}