#include <iostream>

using namespace std;

/* int main(){
    for (int i = 1; i < 11; i++)
    {
        cout << i << endl;
    }

}

int main(){
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum +=i;
    }
    cout << " hasil dari penjumlahan 1-10 : " << sum;
} */

/* int main(){
    int sum = 0;
    for (int i = 0; i < 11; i++)
    {
        if (i % 2 !=0)
        {
            sum +=i;
            cout << i << endl;
        }
    }
    cout << "Hasil dari Penjumlahan Bilangan Ganjil 1-10 : " << sum;
} */
/* int main(){
    string tokoroti = "banana";
    string &bb = tokoroti;
    cout << tokoroti << endl << &tokoroti << endl << bb << endl << & bb << endl;
    string *hh = &tokoroti;
    cout << hh << endl << *hh << endl << &hh << endl;
} */
#include <iostream>
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