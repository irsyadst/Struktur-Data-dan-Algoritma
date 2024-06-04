#include <iostream>
using namespace std;

// queue array
int maksimalQueue = 13; // maksimal antrian
int front = 0;         // penanda antrian
int back = 0;          // penanda
string queue[13]; // fungsi pengecekan
bool isFull()
{ // pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; //=1
    }
    else
    {
        return false;
    }
}
// fungsi pengecekan
bool isEmpty()
{ // antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// fungsi menambahkan antrian
void enqueueAntrian(string data)
{
    if (isFull())
    {
        cout << "antrian penuh" << endl;
    }
    else
    {
        if (isEmpty()) // kondisi ketika queue kosong
        {
            cout << "Melakukan Enqueue\n";
            queue[0] = data;
            front++; // front = front+1;
            back++;
        }
        else
        {                             // antriannya ada isi
            cout << "Melakukan Enqueue\n";
            queue[back] = data; // queueTeller[1]=data
            back++;                   // back=back+1;2
        }
    }
}
// fungsi mengurangi antrian
void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queue[i] = queue[i + 1];
        }
        back--;
    }
}
// fungsi menghitung banyak antrian
int countQueue()
{
    return back;
}
// fungsi mengahpus semua antrian
void clearQueue()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queue[i] = "";
        }
        back = 0;
        front = 0;
    }
}
// fungsi melihat antrian
void viewQueue()
{
    cout << "=== Antrian Aplikasi:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queue[i] != "")
        {
            cout << i + 1 << ". " << queue[i] << endl;
        }
        else
        {
        }
    }
}
void changeQueue(int index, string ganti){
    queue[index - 1] = ganti;
}
int main()
{
    enqueueAntrian("MS Office Management");
    viewQueue();
    enqueueAntrian("Adobe Premiere Kernel");
    viewQueue();
    enqueueAntrian("Tensorflow Control Center");
    viewQueue();
    enqueueAntrian("Core BLender 3D");
    viewQueue();
    enqueueAntrian("Adobe Photoshop Kernel");
    viewQueue();
    dequeueAntrian();
    viewQueue();
    enqueueAntrian("SketchUP Helper");
    viewQueue();
    changeQueue(2, "kernel baru");
    viewQueue();
    return 0;
}