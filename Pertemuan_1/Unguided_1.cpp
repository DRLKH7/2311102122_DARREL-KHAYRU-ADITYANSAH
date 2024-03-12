 #include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi panjang
double hitungLuasPersegiPanjang(double panjang_122, double lebar_122) {
    return panjang_122 * lebar_122;
}

// Fungsi untuk membandingkan dua bilangan dan menampilkan yang lebih besar
void bandingkanBilangan(int bil1, int bil2) {
    if (bil1 > bil2) {
        cout << "Bilangan pertama (" << bil1 << ") lebih besar dari bilangan kedua (" << bil2 << ")." << endl;
    } else if (bil2 > bil1) {
        cout << "Bilangan kedua (" << bil2 << ") lebih besar dari bilangan pertama (" << bil1 << ")." << endl;
    } else {
        cout << "Kedua bilangan (" << bil1 << ") dan (" << bil2 << ") sama besar." << endl;
    }
}

int main() {
    double panjang_122, lebar_122;
    int bil1, bil2;

    // Input panjang dan lebar persegi panjang
    cout << "Masukkan panjang persegi panjang: ";
    cin >> panjang_122;
    cout << "Masukkan lebar persegi panjang: ";
    cin >> lebar_122;

    // Hitung dan tampilkan luas persegi panjang
    double luas_122 = hitungLuasPersegiPanjang(panjang_122, lebar_122);
    cout << "Luas persegi panjang adalah: " << luas_122 << endl;
    // Input dua bilangan untuk dibandingkan
    cout << "\nMasukkan dua bilangan untuk dibandingkan:" << endl;
    cout << "Bilangan pertama: ";
    cin >> bil1;
    cout << "Bilangan kedua: ";
    cin >> bil2;

    // Membandingkan dua bilangan dan menampilkan hasilnya
    bandingkanBilangan(bil1, bil2);

    return 0;
}
