#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlah_simpul;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlah_simpul;

    vector<string> simpul(jumlah_simpul);
    vector<vector<int>> bobot(jumlah_simpul, vector<int>(jumlah_simpul));
    int darrel_2311102122;

    
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    
    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> darrel_2311102122;
            bobot[i][j] = darrel_2311102122;
        }
    }

    
    cout << "\n";
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << simpul[i] << " --> " << simpul[j] << " = " << bobot[i][j] << endl;
        }
    }

    
    cout << "\n";
    for (const auto& s : simpul) {
        cout << "\t" << s;
    }
    cout << "\n";
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << simpul[i];
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << "\t" << bobot[i][j];
        }
        cout << "\n";
    }

    return 0;
}
