# <h1 align="center">Laporan Praktikum Modul ALGORITMA SEARCHING</h1>

<p align="center">DARREL KHAYRU ADITYANSAH</p>
<p align="center">2311102122</p>

## Dasar Teori
Algoritma sequential searching yang biasanya disebut sebagai pendekatan pencarian secara beruntun merupakan pencarian yang diawali dari elemen awal sampai dengan elemen akhir secara beruntun hingga bisa menemukan elemen yang akan dikunjungi. Algoritma ini mampu melakukan pencarian dengan array yang data-datanya tidak perlu melalui pengurutan data sebelumnya. Cara kerja algoritma ini adalah dengan melakukan perbandingan antara data yang ada dengan data yang akan dicari satu per satu secara berurutan sampai dapat menemukan datanya.

Searching adalah proses mendasar untuk menemukan elemen atau item tertentu dalam kumpulan data . Kumpulan data ini dapat mengambil berbagai bentuk, seperti array, daftar, pohon, atau representasi terstruktur lainnya. Tujuan utama pencarian adalah untuk menentukan apakah elemen yang diinginkan ada dalam data, dan jika ada, untuk mengidentifikasi lokasi tepatnya atau mengambilnya kembali. Ini memainkan peran penting dalam berbagai tugas komputasi dan aplikasi dunia nyata, termasuk pengambilan informasi, analisis data, proses pengambilan keputusan, dan banyak lagi.

## Guided 

### 1. [Guided 1]
```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```
=> penjelasan Program
Program mencari angka 10 dalam sebuah array data yang berisi 10 elemen, yaitu 9, 4, 1, 7, 5, 12, 4, 13, 4, 10. Algoritma bekerja dengan memeriksa setiap elemen dalam array satu per satu. Jika angka 10 ditemukan, program akan menunjukkan indeks di mana angka tersebut berada dan mencetak pesan yang menyatakan angka ditemukan pada indeks tersebut. Jika angka 10 tidak ditemukan setelah memeriksa semua elemen, program akan mencetak pesan yang menyatakan bahwa angka tersebut tidak ada dalam array.

### 2. [Guided 2]
```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected to match array bounds

    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari) {
            b_flag = true;
        } else if (dataArray[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (b_flag) {
        cout << "\nData ditemukan pada indeks ke-" << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";

    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;

    cout << "\nData diurutkan: ";
    // Urutkan data dengan selection sort
    selection_sort();

    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    binary_search();

    _getche();
    return 0;
}
```
=> penjelasan Program
Program mengurutkan array yang berisi 7 elemen 1, 8, 2, 5, 4, 9, 7 menggunakan selection sort, dan kemudian mencari nilai yang dimasukkan pengguna menggunakan binary search. Pertama, program menampilkan array awal, meminta pengguna memasukkan nilai yang ingin dicari, kemudian mengurutkan array dan menampilkannya. Setelah itu, program menggunakan binary search untuk mencari nilai dalam array yang sudah diurutkan dan menampilkan hasil pencarian.

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search]
```C++
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
```
### output:
![Screenshot Output Unguided 1](<Unguided_1_algoritma searching.png>)


=> Penjelasan Program
Program selection sort untuk mengurutkan vektor karakter dan binary search untuk mencari keberadaan suatu huruf dalam vektor yang telah diurutkan. Pertama, program meminta pengguna untuk memasukkan sebuah kalimat dan huruf yang ingin dicari. Setelah itu, program mengubah semua huruf dalam kalimat menjadi huruf kecil dan memasukkannya ke dalam vektor. Kemudian, vektor tersebut diurutkan menggunakan selection sort, dan hasilnya ditampilkan kepada pengguna. Selanjutnya, program menggunakan binary search untuk mencari keberadaan huruf yang dicari dalam vektor yang sudah diurutkan.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat]
```C++
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
```
### output:
![Screenshot Output Unguided 2](<Unguided_2_algoritma searching.png>) 

=> Penjelasan Program
Program memproses input kalimat dari pengguna dengan tujuan menghitung jumlah huruf vokal dalam kalimat tersebut. Melalui iterasi karakter demi karakter dalam kalimat, program melakukan penghitungan huruf vokal. Setelah penghitungan selesai, program menampilkan hasilnya, yaitu jumlah huruf vokal dalam kalimat, kepada pengguna. Dengan pendekatan ini, program memberikan informasi yang berguna tentang sifat linguistik dari kalimat yang dimasukkan.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]
```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari_122 = 4;
    int count = 0;

    // Algoritma Sequential Search untuk menghitung kemunculan angka 4
    for (int i = 0; i < n; i++) {
        if (data[i] == cari_122) {        
            count++;
        }
    }
 
    cout << "Dari data {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Angka " << cari_122 << " muncul sebanyak " << count << " kali dalam data." << endl;

    return 0;
}
```
### output:
![Screenshot Output Unguided 3](<Unguided_3_algoritma searching.png>) 

=> Penjelasan Program
 pencarian berurutan (sequential search) untuk menghitung frekuensi kemunculan angka 4 dalam sebuah array. Program dimulai dengan mendeklarasikan ukuran array n sebesar 10 dan menginisialisasi array data. Angka yang akan dicari diset menjadi 4, dan variabel count diinisialisasi dengan nilai 0. Melalui loop for, program memeriksa setiap elemen dalam array data untuk melihat apakah elemen tersebut sama dengan angka yang dicari. Jika kondisi ini terpenuhi, count akan bertambah satu. Setelah iterasi selesai, program mencetak hasilnya, yang menunjukkan bahwa angka 4 muncul sebanyak 4 kali dalam array.

## Kesimpulan
Algoritma searching merupakan fondasi utama dalam proses pengolahan data yang memungkinkan kita untuk menemukan elemen yang dicari dalam kumpulan data. Dengan menggunakan berbagai algoritma pencarian seperti binary search, sequential search, dan lainnya, kita dapat menyesuaikan pendekatan pencarian sesuai dengan karakteristik data dan kebutuhan spesifik. Binary search terbukti efisien dalam mencari pada data yang sudah terurut, sementara sequential search lebih fleksibel dan cocok untuk data yang tidak terurut. Penting bagi kita untuk memahami keunggulan serta keterbatasan masing-masing algoritma ini agar dapat memilih pendekatan pencarian yang optimal sesuai dengan konteks masalah yang dihadapi.

## Referensi
[1] Yuri Rahmanto, Joni Alfian, Damayanti, Rohmat Indra Borman. (2021). Penerapan Algoritma Sequential Search pada Aplikasi Kamus Bahasa Ilmiah Tumbuhan
[2] Searching Algorithms. (Diakses pada tanggal 21 Mei 2024). https://www.geeksforgeeks.org/searching-algorithms/