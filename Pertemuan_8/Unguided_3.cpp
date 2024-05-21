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
