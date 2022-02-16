#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class Mhs
{
 public :
 int nim;
 char nama[35];
 char alamat[25];
};
int main()
{
Mhs data; // Pendefinisian obyek
data.nim = 123;
strcpy(data.nama, "Nanang");
strcpy(data.alamat, "Jogja");
cout <<"Nim = " << data.nim << endl;
cout <<"Nama = " << data.nama << endl;
cout <<"Alamat = " << data.alamat << endl;
getch();
}

