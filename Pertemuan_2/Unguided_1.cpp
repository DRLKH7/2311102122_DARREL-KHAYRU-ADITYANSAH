#include <iostream>
using namespace std;

int main() {
    
    int angka_122[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Data Array: ";
    for (int i = 0; i < 10; i++) {
        cout << angka_122[i] << " ";
    }
    cout << endl;

    cout << "Angka Genap : ";
    for (int i = 0; i < 10; i++) {
        if (angka_122[i] % 2 == 0) {
            cout << angka_122[i] << " ";
        }
    }
    cout << endl;

    cout << "Angka Ganjil : ";
    for (int i = 0; i < 10; i++) {
        if (angka_122[i] % 2 != 0) {
            cout << angka_122[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
 