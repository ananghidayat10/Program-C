#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void tambah_tengah();
void hapus_tengah();
struct node
{
char nama [35];
int nim;
string prodi;
node *prev, *next;
};
node *baru, *head=NULL, *tail=NULL,*hapus,*bantu, *bantu2;
int main()
{
do
{
	cout<<endl;
	cout<<"MENU DOUBLE LINKEDLIST"<<endl<<endl;
	cout<<"1. Tambah Depan"<<endl;
	cout<<"2. Tambah Belakang"<<endl;
	cout<<"3. Tambah Tengah"<<endl;
	cout<<"4. Hapus Depan"<<endl;
	cout<<"5. Hapus Belakang"<<endl;
	cout<<"6. Hapus tengah"<<endl;
	cout<<"7. Tampilkan Data"<<endl;
	cout<<"8. Selesai"<<endl<<endl;
	cout<<"Pilihan Anda [ 1- 8 ] : ";
	cin>>pil;
	pilih();
} while(pil!=8);
}
void pilih()
{
	if(pil==1)
	tambah_depan();
	else if(pil==2)
	tambah_belakang();
	else if(pil==3)
	tambah_tengah();
	else if(pil==4)
	hapus_depan();
	else if(pil==5)
	hapus_belakang();
	else if(pil==6)
	hapus_tengah();
	else if(pil==7)
	tampil();
else
	cout<<endl<<"Terimakasih Program Telah Selesai";
}
void buat_baru()
{
	baru = new(node);
	cout<<endl;
	cout<<"input Nim   : ";cin>>baru->nim;
	cout<<"input Nama  : ";cin>>baru->nama;
	cout<<"input Prodi : ";cin>>baru->prodi;
	baru->prev=NULL;
	baru->next=NULL;
}
void tambah_depan()
{
	buat_baru();
	if(head==NULL)
{
	head=baru;
	tail=baru;
}
else{
	baru->next=head;
	head->prev=baru;
	head=baru;
	}
	cout<<endl;
	tampil();
}
void tambah_belakang()
{
	buat_baru();
	if(head==NULL)
{
	head=baru;
	tail=baru;
}
else{
	tail->next=baru;
	baru->prev=tail;
	tail=baru;
}
	cout<<endl;
	tampil();
}
void tambah_tengah(){
 int posisi_sisip;
 if(head!=NULL){
     cout<<"akan disisipkan diposisi data ke- : ";cin>>posisi_sisip;
   baru=new node;
   baru->next=NULL;
   baru->prev=NULL;
   bantu=head;
       for(int i=1;i<posisi_sisip-1;i++)
      {bantu=bantu->next;}

      buat_baru();
      bantu2= bantu->next;
      baru->next=bantu2;
      bantu2->prev=baru;
      bantu->next=baru;
      baru->prev=bantu;
      }
   else{
       cout<<"belum ada data"<<endl;
   }
   cout<<endl;
   tampil();
} 
void hapus_depan()
{
	if (head==NULL)
	cout<<"Kosong";
	else if (head->next==NULL)
{
	hapus=head;
	head=NULL;
	tail=NULL;
	delete hapus;
}
else{
	hapus=head;
	head=hapus->next;
	head->prev=NULL;
	delete hapus;
	}
	cout<<endl;
	tampil();
}
void hapus_belakang()
{
	if (head==NULL)
	cout<<"Kosong";
	else if (head->next==NULL)
{
	hapus=head;
	head=NULL;
	tail=NULL;
	delete hapus;
}
else{
	hapus=tail;
	tail=hapus->prev;
	tail->next=NULL;
	delete hapus;
	}
	cout<<endl;
	tampil();
}
void hapus_tengah()
{
 int posisi_hapus,banyakdata,poshapus;
 if(head!=NULL){
     cout<<"akan disisipkan diposisi data ke- : ";cin>>posisi_hapus;
	banyakdata=1;
	bantu=head;
	while(bantu->next !=NULL)
	{
		bantu=bantu->next;
		banyakdata++;
	}
	if((posisi_hapus<1)||(posisi_hapus>banyakdata))
	{
		cout<<"Belum Ada data !! Masukan Data dulu aja.";
	}
	else
	{
		bantu=head;
		poshapus=1;
		while(poshapus<(posisi_hapus-1))
	{
		bantu=bantu->next;
		poshapus++;
	}
		hapus=bantu->next;
		bantu->next=hapus->next;
		delete hapus;
	  	hapus->next=NULL;
   }
	}
	else cout<<"Data Masih kosong, tidak bisa hapus data dari tengah!";
	cout<<endl;
	tampil();
}
void tampil()
{
	if (head==NULL)
	cout<<"Kosong";
	else
{
	bantu=head;
	while(bantu!=NULL)
{
	cout<<" Nim   : "<<bantu->nim;
	cout<<" Nama  : "<<bantu->nama;
	cout<<" Program Studi : "<<bantu->prodi<<endl;
	bantu=bantu->next;
}
}
}
