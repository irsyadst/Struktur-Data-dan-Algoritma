#include <iostream>
#include <string>

using namespace std;

// Deklarasi konstanta untuk ukuran array
const int MAX_SIZE = 100;

// Deklarasi struct untuk data
struct Data
{
    int id;
    string nama;
    string alamat;
    int usia;
};

// Deklarasi fungsi-fungsi#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str[50];
    cout << "Masukkan sebuah kalimat : "<<endl;
    cin.getline(str,100);
    char *ptr;
    ptr=strtok(str,",");
    cout<<"Output: "<<endl;
    while(ptr !=NULL){
        cout<<ptr<<endl;
        ptr=strtok(NULL," , ");
    }
    return 0;
}
void tambahData(Data data[], int &n);
void tampilkanData(Data data[], int n);
void ubahData(Data data[], int n);
void hapusData(Data data[], int &n);

int main()
{
    Data data[MAX_SIZE]; // Array untuk menyimpan data
    int n = 0;           // Jumlah data saat ini

    int pilihan;

    do
    {
        // Tampilkan menu CRUD
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        // Panggil fungsi sesuai pilihan
        switch (pilihan)
        {
        case 1:
            tambahData(data, n);
            break;
        case 2:
            tampilkanData(data, n);
            break;
        case 3:
            ubahData(data, n);
            break;
        case 4:
            hapusData(data, n);
            break;
        case 5:
            break;
        default:
            cout << "Pilihan tidak valid\n";
            break;
        }
    } while (pilihan != 5);

    return 0;
}

void tambahData(Data data[], int &n)
{
    Data newData;

    cout << "Tambah Data\n";
    cout << "ID: ";
    cin >> newData.id;
    cout << "Nama: ";
    cin >> newData.nama;
    cout << "Alamat: ";
    cin >> newData.alamat;
    cout << "Usia: ";
    cin >> newData.usia;

    // Masukkan data baru ke array
    data[n] = newData;
    n++;

    cout << "Data berhasil ditambahkan\n";
}

void tampilkanData(Data data[], int n)
{
    if (n == 0)
    {
        cout << "Tidak ada data\n";
    }
    else
    {
        cout << "Tampilkan Data\n";
        for (int i = 0; i < n; i++)
        {
            cout << "ID: " << data[i].id << endl;
            cout << "Nama: " << data[i].nama << endl;
            cout << "Alamat: " << data[i].alamat << endl;
            cout << "Usia: " << data[i].usia << endl;
            cout << endl;
        }
    }
}

void ubahData(Data data[], int n)
{
    int id;
    bool ditemukan = false;

    cout << "Ubah Data\n";
    cout << "ID: ";
    cin >> id;

    // Cari data dengan ID yang sesuai
    for (int i = 0; i < n; i++)
    {
        if (data[i].id == id)
        {
            cout << "Nama (" << data[i].nama << "): ";
            cin >> data[i].nama;
            cout << "Alamat (" << data[i].alamat << "): ";
            cin >> data[i].alamat;
            cout << "Usia (" << data[i].usia << "): ";
            cin >> data[i].usia;
            ditemukan = true;
            break;
        }
    }
    if (ditemukan)
    {
        cout << "Data berhasil diubah\n";
    }
    else
    {
        cout << "Data tidak ditemukan\n";
    }
}

void hapusData(Data data[], int &n)
{
    int id;
    bool ditemukan = false;
    cout << "Hapus Data\n";
    cout << "ID: ";
    cin >> id;

    // Cari data dengan ID yang sesuai
    for (int i = 0; i < n; i++)
    {
        if (data[i].id == id)
        {
            // Geser data dari index i+1 hingga n-1 ke index i
            for (int j = i + 1; j < n; j++)
            {
                data[j - 1] = data[j];
            }
            n--; // Kurangi jumlah data
            ditemukan = true;
            break;
        }
    }

    if (ditemukan)
    {
        cout << "Data berhasil dihapus\n";
    }
    else
    {
        cout << "Data tidak ditemukan\n";
    }
}