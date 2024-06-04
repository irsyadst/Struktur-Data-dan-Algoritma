#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct kontak
{
    int nomor_urut;
    string nama;
    string nomer;
    string email;
    string alamat;
    vector<string> hubungan; 
    kontak* next;
};

kontak* head = nullptr;
int nomor_terakhir = 0;

void tampilkan_kontak()
{
    if (head == nullptr)
    {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    kontak* current = head;
    while (current != nullptr)
    {
        cout << "Nomor Urut   : " << current->nomor_urut << endl;
        cout << "Nama         : " << current->nama << endl;
        cout << "Nomor Telepon: " << current->nomer << endl;
        cout << "Email        : " << current->email << endl;
        cout << "Alamat       : " << current->alamat << endl;
        cout << "-------------------------------------" << endl;
        current = current->next;
    }
}

void tambah_ke_grup() {
    if (head == nullptr) {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    int nomor_urut;
    cout << "Masukkan Nomor Urut kontak yang akan ditambahkan ke grup: ";
    cin >> nomor_urut;

    kontak* current = head;
    while (current != nullptr) {
        if (current->nomor_urut == nomor_urut) {
            string grup;
            cout << "Masukkan nama grup: ";
            cin >> grup;
            current->hubungan.push_back(grup);
            cout << "Kontak berhasil ditambahkan ke grup " << grup << "." << endl;

            // Simpan data grup ke dalam file
            ofstream grup_file;
            grup_file.open("grup.txt", ios::app);
            if (grup_file.is_open()) {
                grup_file << grup << "," << current->nama << endl;
                grup_file.close();
            } else {
                cout << "Gagal membuka file grup.txt." << endl;
            }

            return;
        }
        current = current->next;
    }

    cout << "Kontak dengan Nomor Urut " << nomor_urut << " tidak ditemukan." << endl;
}

void tampilkan_data_grup() {
    ifstream grup_file("grup.txt");
    if (grup_file.is_open()) {
        // Buat map untuk menyimpan anggota grup berdasarkan nama grup
        map<string, vector<string>> anggota_grup;

        string line;
        while (getline(grup_file, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                string grup = line.substr(0, pos);
                string nama_kontak = line.substr(pos + 1);
                
                anggota_grup[grup].push_back(nama_kontak);
            }
        }
        grup_file.close();

        for (const auto& entry : anggota_grup) {
            const string& grup = entry.first;
            const vector<string>& anggota = entry.second;

            cout << "Grup: " << grup << ", Anggota: ";
            for (const string& anggota_kontak : anggota) {
                cout << anggota_kontak << " ,";
            }
            cout << endl;
        }
    } else {
        cout << "Gagal membuka file grup.txt." << endl;
    }
}

void hapus_dari_grup() {
    ifstream grup_file("grup.txt");
    if (!grup_file) {
        cout << "Gagal membuka file grup.txt." << endl;
        return;
    }

    string grup_cari;
    cout << "Masukkan nama grup: ";
    cin >> grup_cari;

    // Buat map untuk menyimpan anggota grup berdasarkan nama grup
    map<string, vector<string>> anggota_grup;

    string line;
    while (getline(grup_file, line)) {
        size_t pos = line.find(",");
        if (pos != string::npos) {
            string grup = line.substr(0, pos);
            string nama_kontak = line.substr(pos + 1);
            
            anggota_grup[grup].push_back(nama_kontak);
        }
    }
    grup_file.close();

    auto it = anggota_grup.find(grup_cari);
    if (it != anggota_grup.end()) {
        vector<string>& anggota = it->second;

        if (anggota.empty()) {
            cout << "Grup " << grup_cari << " tidak memiliki anggota." << endl;
            return;
        }

        cout << "Anggota grup " << grup_cari << ":" << endl;
        for (size_t i = 0; i < anggota.size(); i++) {
            cout << i + 1 << ". " << anggota[i] << endl;
        }

        string nama_anggota_hapus;
        cout << "Masukkan nama anggota yang akan dihapus: ";
        cin >> nama_anggota_hapus;

        bool found = false;
        size_t idx = 0;
        for (size_t i = 0; i < anggota.size(); i++) {
            if (anggota[i] == nama_anggota_hapus) {
                found = true;
                idx = i;
                break;
            }
        }

        if (found) {
            anggota.erase(anggota.begin() + idx);
            cout << "Kontak " << nama_anggota_hapus << " berhasil dihapus dari grup " << grup_cari << "." << endl;

            // Simpan perubahan ke dalam file
            ofstream grup_file;
            grup_file.open("grup.txt");
            if (grup_file.is_open()) {
                for (const auto& entry : anggota_grup) {
                    const string& grup = entry.first;
                    const vector<string>& anggota = entry.second;

                    for (const string& anggota_kontak : anggota) {
                        grup_file << grup << "," << anggota_kontak << endl;
                    }
                }
                grup_file.close();
            } else {
                cout << "Gagal membuka file grup.txt." << endl;
            }
        } else {
            cout << "Anggota " << nama_anggota_hapus << " tidak ditemukan dalam grup " << grup_cari << "." << endl;
        }
    } else {
        cout << "Grup " << grup_cari << " tidak ditemukan." << endl;
    }
}


void urutkan_kontak_belakang()
{
    if (head == nullptr)
    {
        cout << "Tidak ada kontak yang tersedia." << endl;
        return;
    }

    vector<kontak*> kontak_stack;

    kontak* current = head;
    while (current != nullptr)
    {
        kontak_stack.push_back(current);
        current = current->next;
    }

    cout << "Kontak yang diurutkan dari belakang:" << endl;
    for (int i = kontak_stack.size() - 1; i >= 0; i--)
    {
        kontak* contact = kontak_stack[i];
        cout << "Nomor Urut   : " << contact->nomor_urut << endl;
        cout << "Nama         : " << contact->nama << endl;
        cout << "Nomor Telepon: " << contact->nomer << endl;
        cout << "Email        : " << contact->email << endl;
        cout << "Alamat       : " << contact->alamat << endl;
        cout << "-------------------------------------" << endl;
    }
}

void urutkan_kontak()
{
    if (head == nullptr)
    {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    kontak* current = head;
    int urutan = 1;
    while (current != nullptr)
    {
        current->nomor_urut = urutan;
        current = current->next;
        urutan++;
    }
}


kontak* dequeue() {
    if (head == nullptr) {
        return nullptr; // Queue kosong
    } else {
        kontak* dequeued_contact = head;
        head = head->next;
        dequeued_contact->next = nullptr;
        return dequeued_contact;
    }
}

void hapus_kontak2()
{
    if (head == nullptr)
    {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    kontak* dequeued_contact = dequeue();
    if (dequeued_contact != nullptr)
    {
        cout << "Kontak berhasil dihapus." << endl;
        delete dequeued_contact;

        urutkan_kontak();
    }
    else
    {
        cout << "Tidak dapat menghapus kontak. Antrian kosong." << endl;
    }
}


void tambah_kontak()
{
    kontak* new_contact = new kontak;

    cout << "Masukkan nama: ";
    getline(cin, new_contact->nama);
    cout << "Masukkan nomor telepon: ";
    getline(cin, new_contact->nomer);
    cout << "Masukkan email: ";
    getline(cin, new_contact->email);
    cout << "Masukkan alamat: ";
    getline(cin, new_contact->alamat);

    new_contact->nomor_urut = nomor_terakhir + 1;
    new_contact->next = nullptr;

    if (head == nullptr)
    {
        head = new_contact;
    }
    else
    {
        kontak* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_contact;
    }

    urutkan_kontak();
    cout << "Kontak berhasil ditambahkan." << endl;
}


void perbarui_kontak()
{
    if (head == nullptr)
    {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    int nomor_urut;
    cout << "Masukkan nomor urut kontak yang ingin diperbarui: ";
    cin >> nomor_urut;
    cin.ignore();

    kontak* current = head;
    while (current != nullptr)
    {
        if (current->nomor_urut == nomor_urut)
        {
            string nama_baru, nomer_baru, email_baru, alamat_baru;

            cout << "Masukkan nama baru (kosongkan untuk tetap menggunakan data lama): ";
            getline(cin, nama_baru);
            if (!nama_baru.empty())
            {
                current->nama = nama_baru;
            }

            cout << "Masukkan nomor telepon baru (kosongkan untuk tetap menggunakan data lama): ";
            getline(cin, nomer_baru);
            if (!nomer_baru.empty())
            {
                current->nomer = nomer_baru;
            }

            cout << "Masukkan email baru (kosongkan untuk tetap menggunakan data lama): ";
            getline(cin, email_baru);
            if (!email_baru.empty())
            {
                current->email = email_baru;
            }

            cout << "Masukkan alamat baru (kosongkan untuk tetap menggunakan data lama): ";
            getline(cin, alamat_baru);
            if (!alamat_baru.empty())
            {
                current->alamat = alamat_baru;
            }

            cout << "Kontak berhasil diperbarui." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Kontak dengan nomor urut " << nomor_urut << " tidak ditemukan." << endl;
}


void hapus_kontak()
{
    if (head == nullptr)
    {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    int nomor_urut;
    cout << "Masukkan nomor urut kontak yang ingin dihapus: ";
    cin >> nomor_urut;
    cin.ignore();

    kontak* current = head;
    kontak* previous = nullptr;
    while (current != nullptr)
    {
        if (current->nomor_urut == nomor_urut)
        {
            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            cout << "Kontak berhasil dihapus." << endl;

           urutkan_kontak();

            return;
        }
        previous = current;
        current = current->next;
    }

    cout << "Kontak dengan nomor urut " << nomor_urut << " tidak ditemukan." << endl;
}


void cari_kontak_by_nama()
{
    if (head == nullptr)
    {
        cout << "Buku telepon kosong." << endl;
        return;
    }

    string nama_cari;
    cout << "Masukkan nama yang ingin dicari: ";
    getline(cin, nama_cari);

    vector<kontak*> hasil_pencarian;

    kontak* current = head;
    while (current != nullptr)
    {
        if (current->nama == nama_cari)
        {
            hasil_pencarian.push_back(current);
        }
        current = current->next;
    }

    if (hasil_pencarian.empty())
    {
        cout << "Kontak dengan nama " << nama_cari << " tidak ditemukan." << endl;
    }
    else
    {
        cout << "Hasil pencarian:" << endl;
        for (kontak* result : hasil_pencarian)
        {
            cout << "Nomor Urut   : " << result->nomor_urut << endl;
            cout << "Nama         : " << result->nama << endl;
            cout << "Nomor Telepon: " << result->nomer << endl;
            cout << "Email        : " << result->email << endl;
            cout << "Alamat       : " << result->alamat << endl;
            cout << "-------------------------------------" << endl;
        }
    }
}

void muat_database()
{
    ifstream file("database.txt");
    if (!file)
    {
        cout << "Database tidak ditemukan. Membuat database baru." << endl;
        return;
    }

    string line;
    nomor_terakhir = 0;

    while (getline(file, line))
    {
        kontak* new_contact = new kontak;
        new_contact->nomor_urut = stoi(line);

        getline(file, line);
        new_contact->nama = line;

        getline(file, line);
        new_contact->nomer = line;

        getline(file, line);
        new_contact->email = line;

        getline(file, line);
        new_contact->alamat = line;

        new_contact->next = nullptr;

        if (head == nullptr)
        {
            head = new_contact;
        }
        else
        {
            kontak* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new_contact;
        }

        nomor_terakhir++;
    }

    file.close();
}

void simpan_database()
{
    ofstream file("database.txt");
    if (!file)
    {
        cout << "" << endl;
        return;
    }

    kontak* current = head;
    while (current != nullptr)
    {
        file << current->nomor_urut << endl;
        file << current->nama << endl;
        file << current->nomer << endl;
        file << current->email << endl;
        file << current->alamat << endl;
        current = current->next;
    }

    file.close();
}

void simpan_otomatis()
{
    simpan_database();
}

int main()
{
    muat_database();

    int pilihan;
    while (true)
    {
        cout << "=====================================" << endl;
        cout << "           Kontak Telepon            " << endl;
        cout << "=====================================" << endl;
        cout << "Menu: " << endl;
        cout << "1. Tampilkan Kontak" << endl;
        cout << "2. Tampilkan Kontak dari akhir"<< endl;
        cout << "3. Tambah Kontak" << endl;
        cout << "4. Perbarui Kontak" << endl;
        cout << "5. Hapus Kontak" << endl;
        cout << "6. Cari Kontak Berdasarkan Nama" << endl;
        cout << "7. Hapus Kontak paling awal" << endl;
        cout << "8. Tambahkan ke grup" << endl;
        cout << "9. Tampilkan grup" << endl;
        cout << "10. Hapus anggota grup "<<endl;
        cout << "11. Keluar" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            tampilkan_kontak();
            system("pause");
            system("cls");
            break;
        case 2:
            urutkan_kontak_belakang();
            system("pause");
            system("cls");
            break;
        case 3:
            tambah_kontak();
            system("pause");
            system("cls");
            break;
        case 4:
            perbarui_kontak();
            system("pause");
            system("cls");
            break;
        case 5:
            hapus_kontak();
            system("pause");
            system("cls");
            break;
        case 6:
            cari_kontak_by_nama();
            system("pause");
            system("cls");
            break;
        case 7:
            hapus_kontak2();
            system("pause");
            system("cls");
            break;
        case 8:
            tambah_ke_grup();
            system("pause");
            system("cls");
            break;
        case 9:
            tampilkan_data_grup();
            system("pause");
            system("cls");
            break;
        case 10:
            hapus_dari_grup();
            system("pause");
            system("cls");
            break;
        case 11:
            simpan_otomatis();
            cout << "Terima kasih!" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}