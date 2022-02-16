#include <iostream>
using namespace std;
int main()
{
    string nama;
    int jurusan;

    cout << "Masukan Nama : ";
    cin >> nama;
    cout << "1. Teknik Komputer" << endl;
    cout << "2. Teknik Informatika " << endl;
    cout << "3. Perhotelan " << endl;
    cout << "4. Sistem Informasi " << endl;
    cout << "5. Artis Bokep " << endl;
    cout << "Masukan Jurusan yang di inginkan :";
    cin >> jurusan;

    cout << "=================================================" << endl;
    cout << "Nama    : " << nama << endl;
    cout << "Jurusan : ";
    if(jurusan == 1){
        cout << "Teknik Komputer" << endl;
    }
    else if(jurusan == 2){
        cout << "Teknik Informatika " << endl;
    }
    else if(jurusan == 3){
        cout << "Perhotelan " << endl;
    }
    else if(jurusan == 4){
        cout << "Sistem Informasi " << endl;
    }
    else if(jurusan == 5){
        cout << "Artis Bokep " << endl;
    }
    else{
        cout << "Pilihan salah, silahkan ulangi" << endl;
    }
}
