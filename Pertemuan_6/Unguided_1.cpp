#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
string reverseSentence(string sentence) {
    stack<char> charStack_122;
    string reversedSentence = "";

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char &c : sentence) {
        charStack_122.push(c);
    }

    // Mengambil karakter dari stack untuk membalikkan kalimat
    while (!charStack_122.empty()) {
        reversedSentence += charStack_122.top();
        charStack_122.pop();
    }

    return reversedSentence;
}

int main() {
    // Array berisi lima kalimat
    string kalimat[5] = {
        "Telkom Purwokerto",
        "Fakultas informatika",
        "darrel khayru adityansah",
        "NIM 2311102122",
        "Praktikum algoritma struktur data"
    };

    // Membalikkan dan menampilkan hasil untuk setiap kalimat
    cout << "Kalimat Asli =\n";
    for (int i = 0; i < 5; ++i) {
        cout << kalimat[i] << endl;
    }

    cout << endl;

    cout << "Kalimat Pembalikan =\n";
    for (int i = 0; i < 5; ++i) {
        string reversed = reverseSentence(kalimat[i]);
        cout << reversed << endl;
    }

    return 0;
}