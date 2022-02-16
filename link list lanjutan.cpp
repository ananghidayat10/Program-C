#include <iostream>
#include <conio.h>
using namespace std;
struct node
{ char nama[20];
int umur;
float tinggi;
node *next;
};
node *awal_ptr = NULL;
node *posisi; //digunakan untuk membaca sepanjang list
int option = 0;
void tambah_awal_list()
{
node *baru;
baru = new node;
cout << "Masukkan Nama : ";
cin >> baru->nama;
cout << "Masukkan Umur : ";
cin >> baru->umur;
cout << "Masukkan tingggi : ";
cin >> baru->tinggi;
 baru->next = NULL;
if(awal_ptr == NULL)
 {
awal_ptr=baru;
awal_ptr->next = NULL;
posisi = awal_ptr;
}
 else
 {
baru->next = awal_ptr;
awal_ptr = baru;
}
}
void menambah_node_di_akhir()
{ node *temp, *temp2; 
// Temporary pointers
// menciptakan node baru
temp = new node;
cout << "Masukkan Nama : ";
cin >> temp->nama;
cout << "Masukkan Umur : ";
cin >> temp->umur;
cout << "Masukkan tingggi : ";
cin >> temp->tinggi;
temp->next = NULL;
// Set up link pada node
if (awal_ptr == NULL)
{ awal_ptr = temp;
posisi = awal_ptr;
}
else
{ temp2 = awal_ptr;
// node tidak NULL - list tidak kosong
while (temp2->next != NULL)
{ temp2 = temp2->next;
// Memindahkan pada next link dalam rantai
}
temp2->next = temp;
}
}
void display_list()
{ node *temp;
temp = awal_ptr;
cout << endl;
if (temp == NULL)
cout << "List kosong!" << endl;
else
{ while (temp != NULL)
{ // Menampilkan detail data
cout << "nama : " << temp->nama << " ";
cout << "umur : " << temp->umur << " ";
cout << "tinggi : " << temp->tinggi;
if (temp == posisi)
cout << " <<<< posisi node";
cout << endl;
temp = temp->next;
}
cout << "Akhir list!" << endl;
}
}
void hapus_awal_node()
{ node *temp;
temp = awal_ptr;
if(temp == NULL)
 cout<<"List kosong"<<endl;
 else
 {
awal_ptr = awal_ptr->next;
delete temp;
}
}
void hapus_akhir_node()
{ node *temp1, *temp2;
if (awal_ptr == NULL)
cout << "List kosong!" << endl;
 else
{ temp1 = awal_ptr;
if (temp1->next == NULL)
{ delete temp1;
awal_ptr = NULL;
}
else
{ while (temp1->next != NULL)
{ temp2 = temp1;
temp1 = temp1->next;
}
delete temp1;
temp2->next = NULL;
}
}
}
void pindah_posisi_berikutnya()
{ if (posisi->next == NULL)
{
cout << "Kamu berada pada akhir list." << endl;
}
else
posisi = posisi->next;
}
void pindah_posisi_sebelumnya()
{ if (posisi == awal_ptr)
cout << "Kamu berada pada awal list" << endl;
else
{ node *previous; // deklarasi pointer
previous = awal_ptr;
while (previous->next != posisi)
{ previous = previous->next;
}
posisi = previous;
 }
}
void tambah_tengah_list()
{
node *baru, *bantu;
int posisi_sisip;
if(awal_ptr != NULL)
 {
cout<<"Akan disisip setelah Data Ke ? : ";
cin>>posisi_sisip;
bantu=awal_ptr;
baru =new node;
for(int i=1;i<posisi_sisip-1;i++)
 {
if(bantu->next != NULL)
bantu=bantu->next;
else
 break;
}
cout << "Masukkan Nama : ";
cin >> baru->nama;
cout << "Masukkan Umur : ";
cin >> baru->umur;
cout << "Masukkan tingggi : ";
cin >> baru->tinggi;
baru->next=bantu->next;
bantu->next=baru;
}
else
 { cout<<"Belum ada data !! silahkan isi data dulu....";
 getch();}
}
void Hapus_tengah_list()
{
int banyakdata,posisi_hapus,poshapus;
node *hapus, *bantu;
if(awal_ptr != NULL)
 {
cout<<" Akan dihapus pada data ke : "; cin>>posisi_hapus;
banyakdata=1;
bantu=awal_ptr;
while(bantu->next != NULL)
{
bantu=bantu->next;
banyakdata++;
}
if((posisi_hapus<1)||(posisi_hapus>banyakdata))
 {
 cout<<"Belum ada data !! masukkan Data dula aja...\n";
 }
 else
 {
bantu=awal_ptr;
poshapus=1;
while(poshapus<(posisi_hapus-1))
{
bantu=bantu->next;
 poshapus++;
}
hapus=bantu->next;
bantu->next=hapus->next;
delete hapus;
}
}
else cout<<"Data Masih kosong, tidak bisa hapus data dari tengah!";
 getch();
}
int main()
{ awal_ptr = NULL;
do
{
 //system("cls");
display_list();
cout << endl;
cout << "MENU PILIHAN : " << endl;
cout << "0. Keluar program." << endl;
cout << "1. Tambah awal list." << endl;
 cout << "2. Tambah akhir list." << endl;
 cout << "3. Tambah tengah list."<< endl;
cout << "4. Hapus awal list." << endl;
cout << "5. Hapus akhir list." << endl;
cout << "6. Hapus tengah list." << endl;
cout << "7. Pindah posisi pointer ke sebelumnya." << endl;
cout << "8. Pindah posisi pointer ke berikutnya."<< endl;
cout << endl << " Pilihan >> ";
cin >> option;
switch (option)
{
 case 1 : tambah_awal_list();break;
case 2 : menambah_node_di_akhir(); break;
 case 3 : tambah_tengah_list();break;
case 4 : hapus_awal_node(); break;
case 5 : hapus_akhir_node(); break;
 case 6 : Hapus_tengah_list();break;
case 7 : pindah_posisi_sebelumnya(); break;
case 8 : pindah_posisi_berikutnya(); break;
}
}
while (option != 0);
}
