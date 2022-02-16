#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string.h>
//untuk memanggil class/object/fungsi yang terdapat di dalam namespace tersebut
using namespace std;
//Program dasar dalam penentuan koordinat
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//fungsi cetakc untuk mencetak ditengah layar
void cetakc(int a, char *teks)
{
	gotoxy(40-((strlen(teks)/2)),a);cout<<teks;
}
//fungsi cetak untuk mencetak pada koordinat tertentu
void cetak(int a, int b, char *teks)
{
	gotoxy(a,b);cout<<teks;
}
//bagian untuk menaruh fungsi yang akan dijalankan
void header();
void tabel();
void isi();
char tanya();
long gajiPokok(char golongan);
long TunIsrti(long gapok, char status);
long TunjaAnak(char status,long jmlhAnak,long gapok);
long pjk(char status, long gakot);
long gakt(long gapok,long tunjIstri,long tunjAnak);
long gabr(long gakot,long pajak);
long jmlhgpok(long jmlgapok,long gapok);
long jmlhtnjistri(long jmlTunjIstri,long tunjIstri);
long jmlhtunjanak(long jmlTnjAnak,long tunjAnak);
long jmlhgkot(long jmlgakot,long gakot);
long jmlhpjk(long jmlpajak,long pajak);
long jmlhgabr(long jmlgaber,long gaber);
//Bagian fungsi (function) utama, fungsi yang akan dibaca oleh kompilator pertama kali secara otomatis,
int main ()
{
	header();
	tabel();
	getch();
	isi();
}
//Definisi fungsi tanpa nilai balik untuk mencetak bagian header
void header(){
	cetak(45,0, "REKAPITULASI GAJI KARYAWAN");
	cetak(50,1, "PT. MAJU JAYA");
	cetak(0,3, "BULAN : ");
	cetak(0,4, "TAHUN : ");
}
//Definisi fungsi tanpa nilai balik untuk mencetak bagian Tabel
void tabel(){
	cetak(0,5, "======================================================================================================================");
	cetak(0,6, "| No |     Nama     | Gol | Status Nikah | Jmlh Anak |  Gapok  | Tunj Istri | TunjAnak |  Gakot  |  Pajak |  Gaber   |");
	cetak(0,7, "======================================================================================================================");
	for(int i=1;i<=12;i++)
	{
	cetak(0,7+i, "|    |              |     |              |           |         |            |          |         |        |          |");
	}
	cetak(0,20, "======================================================================================================================");
	cetak(0,21, "|                                              Total |         |            |          |         |        |          |");
	cetak(0,22, "======================================================================================================================");
}

struct input
	{
		int i=1,golongan;
		char bulan[30],tahun[25], nama[45],status, jwb;
		long gapok, jmlhAnak ,tunjIstri,tunjAnak,gakot, pajak, gaber, jmlgapok=0,jmlTunjIstri=0,jmlTnjAnak=0,jmlgakot=0,jmlpajak=0,jmlgaber=0;
	};
	input masuk;
	
void isi ()
{

	
	gotoxy(8,3);cin>>masuk.bulan;
	gotoxy(8,4);cin>>masuk.tahun;
	do
	{
		gotoxy(2,7+masuk.i);cout<<masuk.i;
		gotoxy(7,7+masuk.i);cin>>masuk.nama;
		gotoxy(22,7+masuk.i);cin>>masuk.golongan;
		gotoxy(28,7+masuk.i);cin>>masuk.status;
		if (masuk.status == 'n') {
            gotoxy(28,7+masuk.i);cout<<"Nikah";
        } else {
            if (masuk.status == 'b') {
                gotoxy(28,7+masuk.i);cout<<"Belum menikah";
            } else {
               gotoxy(28,7+masuk.i);cout<<"Cerai";
            }
        }
		masuk.gapok=gajiPokok(masuk.golongan);
        gotoxy(55,7+masuk.i);cout<<masuk.gapok;
        masuk.tunjIstri=TunIsrti(masuk.gapok, masuk.status);
		gotoxy(65,7+masuk.i);cout<<masuk.tunjIstri;
		masuk.tunjAnak=TunjaAnak(masuk.status,masuk.jmlhAnak,masuk.gapok);
		gotoxy(77,7+masuk.i);cout<<masuk.tunjAnak;
		masuk.gakot=gakt(masuk.gapok,masuk.tunjIstri,masuk.tunjAnak);
		gotoxy(88,7+masuk.i);cout<<masuk.gakot;
		masuk.pajak=pjk(masuk.status,masuk.gakot);
		gotoxy(98,7+masuk.i);cout<<masuk.pajak;
		masuk.gaber=gabr(masuk.gakot,masuk.pajak);
		gotoxy(107,7+masuk.i);cout<<masuk.gaber;
		masuk.jmlgapok=jmlhgpok(masuk.jmlgapok,masuk.gapok);
		gotoxy(54,21);cout<<masuk.jmlgapok;
		masuk.jmlTunjIstri=jmlhtnjistri(masuk.jmlTunjIstri,masuk.tunjIstri);
	    gotoxy(65,21);cout<<masuk.jmlTunjIstri;
	    masuk.jmlTnjAnak=jmlhtunjanak(masuk.jmlTnjAnak,masuk.tunjAnak);
	    gotoxy(77,21);cout<<masuk.jmlTnjAnak;
	    masuk.jmlgakot=jmlhgkot(masuk.jmlgakot,masuk.gakot);
	    gotoxy(88,21);cout<<masuk.jmlgakot;
	    masuk.jmlpajak=jmlhpjk(masuk.jmlpajak,masuk.pajak);
	    gotoxy(98,21);cout<<masuk.jmlpajak;
	    masuk.jmlgaber=jmlhgabr(masuk.jmlgaber,masuk.gaber);
	    gotoxy(107,21);cout<<masuk.jmlgaber;
		masuk.jwb=tanya();
		masuk.i++;
	}while(masuk.jwb=='y'||masuk.jwb=='Y');
	getch();
}

long gajiPokok(char golongan)
{
	if (masuk.golongan == 1) {
	            return(750000);
	        } else {
	            if (masuk.golongan == 2) {
	                return(1000000);
	            } else {
	                if (masuk.golongan == 3) {
	                    return(1250000);
	                } else {
	                    if (masuk.golongan == 4) {
	                        return(1500000);
	                    }
	                }
	            }
	        }
}

long TunIsrti(long gapok, char status)
{
	struct  tunj{
		long tunjgIstri;
	};
	tunj tunjangan;
	if (masuk.status == 'n') {
		gotoxy(43,7+masuk.i);cin>>masuk.jmlhAnak;
            tunjangan.tunjgIstri = (double) 20 / 100 * masuk.gapok;
        } else {
            if (masuk.status == 'c') {
            	gotoxy(43,7+masuk.i);cin>>masuk.jmlhAnak;
                tunjangan.tunjgIstri = 0;
            } else {
            	gotoxy(43,7+masuk.i);cout<<"0";
                tunjangan.tunjgIstri = 0;
            }
        }
        return(tunjangan.tunjgIstri);
}

long TunjaAnak(char status,long jmlhAnak,long gapok)
{
	long tunjhAnak;
	if (status == 'n') {
            if (jmlhAnak > 2) {
                cetak(77,4, "jumlah anak tidak boleh>2");
            } else {
                tunjhAnak = (double) (jmlhAnak * 5) / 100 * gapok;
            }
        } else {
            if (status == 'c') {
            	tunjhAnak = (double) (jmlhAnak * 5) / 100 * gapok;
            } else {
                if (jmlhAnak > 2) {
                	cetak(77,4, "jumlah anak tidak boleh>2");
                } else {
                    tunjhAnak = 0;
                    
                }
            }
        }
        return(tunjhAnak);
}

long gakt(long gapok,long tunjIstri,long tunjAnak)
{
	return(gapok+tunjIstri+tunjAnak);
}
long pjk(char status, long gakot)
{
	long pjak;
	if (status == 'n') {
            if (gakot >= 1000000) {
                pjak = (double) 5 / 100 * gakot;
            } else {
                pjak = (double) 3 / 100 * gakot;
            }
        } else {
            if (status == 'b') {
                if (gakot >= 1000000) {
                    pjak = (double) 5 / 100 * gakot;
                } else {
                    pjak = (double) 3 / 100 * gakot;
                }
            } else {
                if (gakot >= 1000000) {
                    pjak = (double) 5 / 100 * gakot;
                } else {
                    pjak = (double) 3 / 100 * gakot;
                }
            }
        }
        return(pjak);
}

long gabr(long gakot,long pajak)
{
	return(gakot-pajak);
}

long jmlhgpok(long jmlgapok,long gapok)
{
	return(jmlgapok+gapok);
}

long jmlhtnjistri(long jmlTunjIstri,long tunjIstri)
{
	return(jmlTunjIstri+tunjIstri);
}

long jmlhtunjanak(long jmlTnjAnak,long tunjAnak)
{
	return(jmlTnjAnak+tunjAnak);
}

long jmlhgkot(long jmlgakot,long gakot)
{
	return(jmlgakot+gakot);
}

long jmlhpjk(long jmlpajak,long pajak)
{
	return(jmlpajak+pajak);
}

long jmlhgabr(long jmlgaber,long gaber)
{
	return(jmlgaber+gaber);
}

char tanya(){
	char jw;
	cetak(40,4, "Isi Data Lagi[Y/T] : ");
	cin>>jw;
	cetak(40,4, "                          ");
	return (jw);
}
