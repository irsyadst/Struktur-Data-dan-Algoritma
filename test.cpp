#include <iostream>
using namespace std;

// queue array
int maksimalQueue = 13; // maksimal antrian
int front = 0;         // penanda antrian
int back = 0;          // penanda
int queue[13];         // fungsi pengecekan

bool isFull()
{
    // pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; //=1
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    // antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAntrian(int data)
{
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty()) // kondisi ketika queue kosong
        {
            cout << "Melakukan Enqueue" << endl;
            queue[0] = data;
            front++; // front = front+1;
            back++;
        }
        else
        {                             // antriannya ada isi
            cout << "Melakukan Enqueue" << endl;
            queue[back] = data; // queue[1]=data
            back++;                   // back=back+1;
        }
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
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

int countQueue()
{
    return back;
}

void clearQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queue[i] = 0;
        }
        back = 0;
        front = 0;
    }
}

void viewQueue()
{
    cout << "=== Antrian Aplikasi:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queue[i] != 0)
        {
            cout << i + 1 << ". " << queue[i] << endl;
        }
    }
}

void changeQueue(int index, int ganti)
{
    queue[index - 1] = ganti;
}

void sortQueueDescending()
{
    for (int i = 0; i < back - 1; i++)
    {
        for (int j = 0; j < back - i - 1; j++)
        {
            if (queue[j] < queue[j + 1])
            {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

int main()
{
    enqueueAntrian(4);
    viewQueue();
    enqueueAntrian(2);
    viewQueue();
    enqueueAntrian(7);
    viewQueue();
    enqueueAntrian(1);
    viewQueue();
    enqueueAntrian(5);
    viewQueue();
    dequeueAntrian();
    viewQueue();
    enqueueAntrian(3);
    viewQueue();
    changeQueue(2, 6);
    viewQueue();

    sortQueueDescending();
    cout << "=== Antrian Aplikasi Descending:" << endl;
    for (int i = 0; i < back; i++)
    {
        cout << i + 1 << ". " << queue[i] << endl;
    }

    return 0;
}
