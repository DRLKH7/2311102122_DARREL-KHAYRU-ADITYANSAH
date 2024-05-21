#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    c = tolower(c); // Ubah menjadi huruf kecil untuk konsistensi
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(const string& kalimat) {
    int count = 0;
    for (char c : kalimat) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat_122;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat_122);

    int jumlahVokal = countVowels(kalimat_122);

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}
