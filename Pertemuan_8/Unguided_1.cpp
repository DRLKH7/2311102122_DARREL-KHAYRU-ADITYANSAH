#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>

using namespace std;

void selection_sort(vector<char>& vec) {
    int size = vec.size();
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
    }
}

bool binary_search(const vector<char>& vec, char target, int& index) {
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (vec[middle] == target) {
            index = middle;
            return true;
        }
        if (vec[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return false;
}

int main() {
    string kalimat_122;
    char huruf_122;
    vector<char> karakter;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat_122);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf_122;

    // Memasukkan karakter ke dalam vektor
    for (char c : kalimat_122) {
        if (isalpha(c)) { // Memastikan hanya huruf_122 yang dimasukkan
            karakter.push_back(tolower(c)); // Mengubah semua huruf_122 menjadi huruf_122 kecil
        }
    }

    // Mengurutkan vektor karakter menggunakan selection sort
    selection_sort(karakter);

    // Menampilkan vektor yang sudah diurutkan
    cout << "Kalimat yang sudah diurutkan: ";
    for (char c : karakter) {
        cout << c << ' ';
    }
    cout << endl;

    // Mencari huruf_122 menggunakan binary search
    int index;
    bool found = binary_search(karakter, tolower(huruf_122), index);

    if (found) {
        cout << "Huruf '" << huruf_122 << "' ditemukan pada indeks ke-" << index << " dalam kalimat yang sudah diurutkan." << endl;
    } else {
        cout << "Huruf '" << huruf_122 << "' tidak ditemukan dalam kalimat." << endl;
    }

    _getche();
    return 0;
}
