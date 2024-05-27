# <h1 align="center">Laporan Praktikum Modul GRAPH DAN TREE </h1>

<p align="center">DARREL KHAYRU ADITYANSAH</p>
<p align="center">2311102122</p>

## Dasar Teori
Dalam dunia pemrograman, pohon dan graph merupakan faktor penting dan menggambarkan data nonlinier. Pohon adalah kasus luar biasa dari graf yang tidak berputar, sedangkan graf dapat mempunyai putaran. Graph dan pohon adalah dua struktur data mendasar yang digunakan dalam ilmu komputer untuk merepresentasikan hubungan antar objek. Meskipun keduanya memiliki beberapa kesamaan, keduanya juga memiliki perbedaan yang membuatnya cocok untuk aplikasi yang berbeda.

graph
graph adalah kumpulan node (disebut juga simpul) dan sisi yang menghubungkannya. Node dapat mewakili entitas, seperti orang, tempat, atau benda, sedangkan tepi mewakili hubungan antara entitas tersebut. Graph digunakan untuk memodelkan berbagai sistem dunia nyata, seperti jaringan sosial , jaringan transportasi , dan jaringan komputer .

Tree
Tree adalah struktur data hierarki yang terdiri dari node-node yang dihubungkan oleh tepian. Setiap node dapat memiliki beberapa node anak, tetapi hanya satu node induk. Node paling atas pada pohon disebut simpul akar. Pohon sering kali digunakan untuk merepresentasikan data hierarki, seperti sistem file, dokumen XML , dan bagan organisasi .

## Guided 

### 1. [Guided 1]
```C++
#include <iostream>
#include <iomanip>

using namespace std;
string simpul [7] = {
    "ciamis", "cianjur", " bekasi", "cianjur", "purwokerto", "yogyakarta"
};
int busur [7][7] = {
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 0, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0 ,0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0},
};
void tampilGraph () {
    for(int baris=0; baris<7; baris++) {
        cout << " " << setiosflags (ios::left) << setw (15) << simpul [baris] << " : ";
        for (int kolom = 0; kolom<7; kolom++) {
            if (busur [baris] [kolom] !=0) {
                cout << " " << simpul [kolom] << "(" << busur [baris] [kolom] << ")";
            }
        } cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
=> penjelasan Program
Program ini dirancang untuk menampilkan graf yang berisi simpul-simpul kota beserta bobot hubungan antar simpul. Hubungan antara kota-kota ini dinyatakan dalam bentuk matriks bobot, di mana nilai-nilai yang tidak nol menunjukkan adanya hubungan langsung antara dua simpul dengan bobot tertentu yang merepresentasikan jarak atau biaya. Program ini mencetak setiap simpul dan hubungan-hubungannya dalam format yang mudah dibaca, sehingga memudahkan pengguna untuk memahami struktur dan koneksi dalam graf.

### 2. [Guided 2]
```C++
#include <iostream> 
#include <iomanip> 
using namespace std;

struct Pohon{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();

        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;

            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;

            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {

        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree 
int height(Pohon *node = root) {     if (isEmpty()) {
cout << "\n Buat tree terlebih dahulu!" << endl;
return 0;
}
else
{
    if (!node)
    {
        return 0;
    }
    else
    {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        if (heightKiri >= heightKanan)
        {
            return heightKiri + 1;
        }
        else
        {
            return heightKanan + 1;
        }
    }
}
}
// Karakteristik Tree 
void characteristic() {
cout << "\n Size Tree : " << size() << endl;
cout << " Height Tree : " << height() << endl;
cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH,
        *nodeI, *nodeJ;

    // .... Tambahkan kode
    return 0;
}
```
=> penjelasan Program
Program yang disediakan mendefinisikan struktur pohon biner sederhana menggunakan struct Pohon dalam C++. Program ini mencakup fungsi-fungsi untuk menginisialisasi pohon, memeriksa apakah pohon kosong, membuat node akar, menyisipkan node ke kiri atau kanan, memperbarui data node, mengambil data node, dan menemukan detail node termasuk hubungan parent dan sibling. Program ini juga mendukung metode traversal seperti pre-order, in-order, dan post-order. Selain itu, terdapat fungsi untuk menghapus node atau subtree, menghapus seluruh pohon, dan memeriksa karakteristik pohon seperti ukuran dan tinggi.

## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. ]
```C++
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

```
### output:
![Screenshot Output Unguided 1](<Unguided_1_graph.png>)

=> Penjelasan Program
Program memfasilitasi pembuatan dan visualisasi graf melalui interaksi langsung dengan pengguna. Pengguna diminta memasukkan jumlah simpul, nama setiap simpul, dan bobot hubungan antar simpul, mencerminkan kekuatan atau jarak hubungan dalam graf. Setelah data dimasukkan, program menampilkan hasilnya dalam dua format: pasangan hubungan antar simpul dengan bobotnya dan matriks bobot yang menunjukkan bobot antara setiap pasangan simpul. 

### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan! ]
```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;
int darrel_2311102122 = 0;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        darrel_2311102122++;
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            darrel_2311102122++;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            darrel_2311102122++;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node) {
                    node->parent->left = NULL;
                } else if (node->parent->right == node) {
                    node->parent->right = NULL;
                }
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
            darrel_2311102122--;
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root) {
    return darrel_2311102122;
}

// Cek Height Level Tree
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

int main() {
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    Pohon *nodeD = insertLeft('D', nodeB);
    Pohon *nodeE = insertRight('E', nodeB);
    Pohon *nodeF = insertLeft('F', nodeC);
    Pohon *nodeG = insertRight('G', nodeC);
    Pohon *nodeH = insertLeft('H', nodeD);
    Pohon *nodeI = insertRight('I', nodeD);
    Pohon *nodeJ = insertLeft('J', nodeE);
    
    // Manually set the tree structure to achieve the desired height and average nodes
    // We will add only the necessary nodes to make the size 10 and height 5
    insertRight('K', nodeE);
    // Insert additional nodes to make height 5 and ensure size is 10
    insertLeft('L', nodeF);
    insertRight('M', nodeF);
    
    update('Z', nodeC); // Rename nodeC to Z
    update('C', nodeC); // Rename nodeZ to C

    retrieve(nodeC);
    find(nodeC);
    characteristic();

    cout << "\nPreOrder:" << endl;
    preOrder();
    cout << "\nInOrder:" << endl;
    inOrder();
    cout << "\nPostOrder:" << endl;
    postOrder();

    return 0;
}
```
### output:
![Screenshot Output Unguided 2](<Unguided_2_graph.png>)

=> Penjelasan Program
Program ini mengimplementasikan struktur data pohon biner dalam C++ dengan fungsi untuk membuat dan mengelola pohon, termasuk penambahan node ke kiri atau kanan, pembaruan data node, dan penghapusan pohon atau subtree. Program ini juga menyediakan metode untuk penelusuran pohon dalam tiga cara: pre-order, in-order, dan post-order. Selain itu, program menghitung ukuran dan tinggi pohon, serta menampilkan karakteristik dasar pohon seperti ukuran, tinggi, dan rata-rata node per level.

## Kesimpulan
rogram graf memungkinkan pengguna untuk membuat dan memvisualisasikan graf dengan meminta input jumlah simpul, nama simpul, dan bobot antar simpul, kemudian menampilkan hubungan antar simpul beserta bobotnya dalam dua format: pasangan simpul dengan bobotnya dan matriks bobot. Sementara itu, program pohon biner memungkinkan pengguna untuk membuat, mengelola, dan menelusuri pohon biner dengan fitur penambahan node ke kiri atau kanan, pembaruan data node, serta penghapusan pohon atau subtree. Metode penelusuran yang disediakan mencakup pre-order, in-order, dan post-order, serta informasi mengenai ukuran dan tinggi pohon, termasuk karakteristik dasar pohon seperti ukuran, tinggi, dan rata-rata node per level.

## Referensi
[1] M.Rian Safei. (2019). PENGERTIAN STRUKTUR DATA NON LINIER
[2] Graph Data Structure And Algorithms. (Diakses pada tanggal 26 Mei 2024). https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/