#include <iostream>
using namespace std;

int main()
{
    int modal;
    

    int harga = 4090;
    int lot = harga * 100;
    int jumlah = modal / lot;
    int sisa = modal - (jumlah * lot);
    while (modal>0)
    {
        cout << "Masukkan modal Anda: ";
        cin >> modal;
        cout << "Dengan modal " << modal << ", Anda dapat membeli " << jumlah << " Lot saham TELKOM INDONESIA.\n"
             << "Sisa Modal anda : " << sisa << endl;
    }
    
    return 0;
}