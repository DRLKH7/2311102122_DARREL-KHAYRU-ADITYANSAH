#include <iostream>
using namespace std;

int main() {
    int pilih;
    int bil[10];
    bool tersimpan = false;

    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Input Array" << endl;
        cout << "2. Tampil Array" << endl;
        cout << "3. Cari Nilai Minimum" << endl;
        cout << "4. Cari Nilai Maksimum" << endl;
        cout << "5. Hitung Rata-rata" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan 10 bilangan bulat: ";
                for (int i = 0; i < 10; i++) {
                    cin >> bil[i];
                }
                tersimpan = true;
                cout<<endl;
                break;
                cout<<endl;
            case 2:
                if (tersimpan) {
                    cout << "Isi Array: ";
                    for (int i = 0; i < 10; i++) {
                        cout << bil[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Array belum diisi." << endl;
                }
                cout<<endl;
                break;

            case 3:
                if (tersimpan) {
                    int minVal = bil[0];
                    for (int i = 1; i < 10; i++) {
                        if (bil[i] < minVal) {
                            minVal = bil[i];
                        }
                    }
                    cout << "Nilai Minimum: " << minVal << endl;
                } else {
                    cout << "Array belum diisi." << endl;
                }
                cout<<endl;
                break;
            case 4:
                if (tersimpan) {
                    int maxVal = bil[0];
                    for (int i = 1; i < 10; i++) {
                        if (bil[i] > maxVal) {
                            maxVal = bil[i];
                        }
                    }
                    cout << "Nilai Maksimum: " << maxVal << endl;
                } else {
                    cout << "Array belum diisi." << endl;
                }
                cout<<endl;
                break;

            case 5:
                if (tersimpan) {
                    int sum = 0;
                    for (int i = 0; i < 10; i++) {
                        sum += bil[i];
                    }
                    double average = static_cast<double>(sum) / 10;
                    cout << "Rata-rata: " << average << endl;
                } else {
                    cout << "Array belum diisi." << endl;
                }
                cout<<endl;
                break;

            case 6:
                cout << "Terima kasih" << endl;
                cout<<endl;
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;

        }
    }

    return 0;
}
