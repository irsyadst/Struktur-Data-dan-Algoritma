#include <iostream>
using namespace std;
string arrayFolder[13];
int maksimal = 13, top = 0;
bool isFull()
{
    if (top == maksimal)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pushArray(string data)
{
    if (isFull())
    {
        cout << "data telah penuh" << endl;
    }
    else
    {
        cout << "Melakukan Push\n";
        arrayFolder[top] = data;
        top++;
    }
}
void popArray(int angka)
{
    for (int i = 0; i < angka; i++)
    {
        if (isEmpty())
        {
            cout << "tidak ada data yang dihapus" << endl;
        }
        else
        {
            arrayFolder[top - 1] = "";
            top--;
        }
    }
}
void peekArray()
{
    if (isEmpty())
    {
        cout << "tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
            cout << "anda berada pada direktori  " << top << " dari " << maksimal << " direktori" << endl;
    }
}
int countStack()
{
    return top;
}
void changeArray(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayFolder[index] = data;
    }
}
void destroyArray()
{
    for (int i = top; i <= 0; i--)
    {
        arrayFolder[i] = "";
    }
    top = 0;
}
void cetakArray()
{
    if (isEmpty())
    {
        cout << "tidak ada data yang dicetak" << endl;
    }
    else
    {
        cout << "Lokasi direktori saat ini : \n ====\n" ;
        for (int i = top; i >= 0; i--)
        {
            cout <<  arrayFolder[i] ;
        }
        cout << "/\n====\n";
    }
}
int main()
{
    pushArray("Macintosh HD");
    cetakArray();
    peekArray();
    pushArray("Aplications");
    cetakArray();
    peekArray();
    pushArray("Utilities/");
    cetakArray();
    peekArray();
    pushArray("Adobe Sync/");
    cetakArray();
    peekArray();
    pushArray("CoreSyncExtention/");
    cetakArray();
    peekArray();
    pushArray("customhook/"); 
    cetakArray();
    peekArray();
    popArray(2);
    cetakArray();
    peekArray();
    popArray(3);
    cetakArray();
    peekArray();
}