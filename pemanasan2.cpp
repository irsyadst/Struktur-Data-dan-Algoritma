//MUHAMMAD IRSYAD
//2211102048
#include <iostream>

using namespace std;
struct saham
{
    string ns;
    int hs;
};

int main()
{
    saham a;
    saham b;
    int uang;
    cout << "Masukkan nama saham 1 : ";
    cin >> a.ns;
    cout << "Masukkan harga saham 1 : ";
    cin >> a.hs;
    cout << "Masukkan nama saham 2 : ";
    cin >> b.ns;
    cout << "Masukkan harga saham 2 : ";
    cin >> b.hs;

    cout << "Nama saham 1 : " << a.ns << endl;
    cout << "Harga lembar Saham 1: " << a.hs << endl;
    cout << "Nama saham 2 : " << b.ns << endl;
    cout << "Harga lembar Saham 2: " << b.hs << endl;
    int pilih;
    do
    {
        cout << "Pilih saham yang mau anda beli : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:{
            cout << "Masukkan Jumlah uang : ";
            cin >> uang;
            do
            {
                if (uang>a.hs * 100)
            {
                cout << "Dengan Modal Rp." << uang << " anda dapat membeli " << uang / (a.hs * 100) << " LOT saham " << a.ns << endl;
            cout << "Sisa Modal anda Rp." << uang - ((uang / (a.hs * 100)) * (a.hs * 100)) << endl;
            }else
            {
                cout << "Uang yang anda masukkan kurang";
            }
            } while (uang > a.hs * 100);

            break;
        }
        case 2:{
            cout << "Masukkan Jumlah uang : ";
            cin >> uang;
            do
            {
                if (uang>b.hs * 100)
            {
                cout << "Dengan Modal Rp." << uang << " anda dapat membeli " << uang / (b.hs * 100) << " LOT saham " << b.ns << endl;
            cout << "Sisa Modal anda Rp." << uang - ((uang / (b.hs * 100)) * (b.hs * 100)) << endl;
            }else
            {
                cout << "Uang yang anda masukkan kurang";
            }
            } while (uang > b.hs * 100);

            break;
        }
        }
    } while (pilih = 0);
}