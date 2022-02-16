#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cetakc(int a, char *teks)
{
	gotoxy(40-((strlen(teks)/2)),a);cout<<teks;
}
void cetak(int a, int b, char *teks)
{
	gotoxy(a,b);cout<<teks;
}
void header();
void tabel();
void isi();
char tanya();
long hrgakls(string kelas);
long hrgadskon(string promo, long harga);
long tiketanak(long jmlhAnak,long harga,long discon);
long tiketdwsa(long harga,long discon,long jmlhDwasa);
long tothrg(long hganak,long hgdwasa);
long jml2(long jumlah2,long jmlhDwasa);
long jml3(long jumlah3,long jmlhAnak);
long jml4(long jumlah4,long hganak);
long jml5(long jumlah5,long hgdwasa);
long jml(long jumlah,long totlharga);
int main ()
{
	header();
	tabel();
	getch();
	isi();
}

void header(){
	cetak(45,0, "REKAPITULASI PENJUALAN TIKET PESAWAT");
	cetak(50,1, "RAMAH TOUR & TREVEL");
	cetak(0,3, "BULAN : ");
	cetak(0,4, "TAHUN : ");
}

void tabel(){
	cetak(0,5, "======================================================================================================================");
	cetak(0,6, "| No |  Pesawat     |Kelas|     Promo    |  Harga    |  Discon | Jmlh Dewasa| Jml Anak | Hg anak |HgDewasa|TotlHarga |");
	cetak(0,7, "======================================================================================================================");
	for(int i=1;i<=12;i++)
	{
	cetak(0,7+i, "|    |              |     |              |           |         |            |          |         |        |          |");
	}
	cetak(0,20, "======================================================================================================================");
	cetak(0,21, "|                                                      Jumlah  |            |          |         |        |          |");
	cetak(0,22, "======================================================================================================================");
}

void isi(){
int i=1;
	string promo, kelas;
	char jawab, bulan[30],tahun[30] , nama[30];
	long harga, jmlhAnak ,discon,tunjAnak,jmlhDwasa,hganak, hgdwasa, totlharga,jumlah2=0,jumlah3=0,jumlah4=0,jumlah5=0,jumlah=0;
	gotoxy(8,3);cin>>bulan;
	gotoxy(8,4);cin>>tahun;
	do
	{
		gotoxy(2,7+i);cout<<i;
		gotoxy(7,7+i);cin>>nama;
		gotoxy(22,7+i);cin>>kelas;
		gotoxy(28,7+i);cin>>promo;
		gotoxy(65,7+i);cin>>jmlhDwasa;
		gotoxy(78,7+i);cin>>jmlhAnak;
		harga=hrgakls(kelas);
        gotoxy(43,7+i);cout<<harga;
        discon=hrgadskon(promo, harga);
		gotoxy(55,7+i);cout<<discon;
		hganak=tiketanak(jmlhAnak,harga,discon);
		gotoxy(88,7+i);cout<<hganak;
		hgdwasa=tiketdwsa(harga,discon,jmlhDwasa);
		gotoxy(98,7+i);cout<<hgdwasa;
		totlharga=tothrg(hganak,hgdwasa);
		gotoxy(107,7+i);cout<<setw(10)<<totlharga;
		jumlah2=jml2(jumlah2,jmlhDwasa);
	    gotoxy(62,21);cout<<setw(10)<<jumlah2;
	    jumlah3=jml3(jumlah3,jmlhAnak);
	    gotoxy(74,21);cout<<setw(10)<<jumlah3;
	    jumlah4=jml4(jumlah4,hganak);
	    gotoxy(85,21);cout<<setw(10)<<jumlah4;
	    jumlah5=jml5(jumlah5,hgdwasa);
	    gotoxy(95,21);cout<<setw(10)<<jumlah5;
	    jumlah=jml(jumlah,totlharga);
	    gotoxy(105,21);cout<<setw(10)<<jumlah;
	    jawab=tanya();
		i++;
		gotoxy(40,4);cout<<"                          ";
	}while(jawab=='y'||jawab=='Y');
}

char tanya(){
	char jw;
	cetak(40,4, "Isi Data Lagi[Y/T] : ");
	cin>>jw;
	cetak(40,4, "                          ");
	return (jw);
}

long hrgakls(string kelas)
{
	 if (kelas == "e") {
	            return(500000);
	        } else {
	            if (kelas == "b") {
	                return(750000);
	            }
	        }
}

long hrgadskon(string promo, long harga)
{
	 if (promo == "y") {
	            return((double) 25 / 100 * harga);
	        } else {
	            if (promo == "t") {
	                return((double) 5 / 100 * harga);
	            }
	        }
}

long tiketanak(long jmlhAnak,long harga,long discon)
{
	long tiktanak;
	tiktanak=jmlhAnak*(harga-discon)*50/100;
	return (tiktanak);
}

long tiketdwsa(long harga,long discon,long jmlhDwasa)
{
	long tiktdwasa;
	tiktdwasa=(harga-discon)*jmlhDwasa;
	return (tiktdwasa);
}

long tothrg(long hganak,long hgdwasa)
{
	long tothrga;
	tothrga=hganak+hgdwasa;
	return (tothrga);
}

long jml2(long jumlah2,long jmlhDwasa)
{
	long jmlh2;
	jmlh2=jumlah2+jmlhDwasa;
	return (jmlh2);
}

long jml3(long jumlah3,long jmlhAnak)
{
	long jmlh3;
	jmlh3=jumlah3+jmlhAnak;
	return (jmlh3);
}

long jml4(long jumlah4,long hganak)
{
	long jmlh4;
	jmlh4=jumlah4+hganak;
	return (jmlh4);
}

long jml5(long jumlah5,long hgdwasa)
{
	long jmlh5;
	jmlh5=jumlah5+hgdwasa;
	return (jmlh5);
}

long jml(long jumlah,long totlharga)
{
	long jmlh;
	jmlh=jumlah+totlharga;
	return (jmlh);
}

