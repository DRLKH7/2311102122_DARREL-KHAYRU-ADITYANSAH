#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk menentukan apakah sebuah kalimat adalah polindrom
bool isPalindrome(string sentence) {
    stack<char> charStack_122;

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char &c : sentence) {
        charStack_122.push(c);
    }

    // Bandingkan karakter di awal dan akhir
    while (!charStack_122.empty()) {
        char topChar = charStack_122.top();
        charStack_122.pop();
        if (topChar != sentence.front()) {
            return false; // Jika terdapat perbedaan, bukan polindrom
        }
        sentence.erase(0, 1); // Hapus karakter pertama dari kalimat
    }

    return true; // Jika semua karakter cocok, adalah polindrom
}

int main() {
    string kalimat;

    while (true) {
        cout << "Masukkan kalimat (tekan 0 keluar): ";
        getline(cin, kalimat);

        // Keluar dari loop jika pengguna memasukkan 'q'
        if (kalimat == "0") {
            break;
        }

        if (isPalindrome(kalimat)) {
            cout << "Kalimat tersebut adalah polindrom" << endl;
        } else {
            cout << "Kalimat tersebut bukan polindrom" << endl;
        }
    }

    return 0;
}
