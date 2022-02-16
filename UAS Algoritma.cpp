#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main ()
{
	gotoxy(0,0); cout << "REKAPITULASI GAJI KARYAWAN";
	gotoxy(0,1); cout << "PT.MAJU JAYA";
	gotoxy(0,3); cout << "BULAN : ";
	gotoxy(0,4); cout << "TAHUN : ";
	gotoxy(0,5); cout << "=====================================================================================================================";
	gotoxy(0,6); cout << "| No |     Nama    | Gol | S Nikah | Jml Anak |   Gapok    | Tunj Istri | Tunj Anak|   Gakot   |  Pajak   |  Gaber  |";
	gotoxy(0,7); cout << "=====================================================================================================================";
	
	for(int i = 1; i <= 12; i++) {
		gotoxy(0, 7+i);
		cout << "|    |             |     |         |          |            |            |          |           |          |         |";
	}
	
	gotoxy(0,20); cout << "=====================================================================================================================";
	gotoxy(0,21); cout << "|                                        TOTAL|            |            |          |           |          |         |";
	gotoxy(0,22); cout << "=====================================================================================================================";
	
	int i = 1;
	char jw, Bulan[30], Tahun[30], Nama[30], StatusNikah, Nikah;
	long int Gol, JmlAnak, Gapok, TunjIstri, TunjAnak, Gakot, Pajak, Gaber, TotGap, TotIs, TotNak, TotGakot, TotPaj, TotGaber;
  const char nikah = 'n';
  const char belum_nikah = 'b';
  const char cerai = 'c';

  TotGap = 0;
  TotIs = 0;
  TotNak = 0;
  TotGakot = 0;
  TotPaj = 0;
  TotGaber = 0;

	gotoxy(8,3); cin >> Bulan;
	gotoxy(8,4); cin >> Tahun;
	
	do {
		gotoxy(2, 7 + i); cout << i;
		gotoxy(7, 7 + i); cin >> Nama;
		gotoxy(21, 7 + i);cin >> Gol;

    switch(Gol) {
      case 1:
        Gapok = 750000;
        break;
      case 2:
        Gapok = 1000000;
        break;
      case 3:
        Gapok = 1250000;
        break;
      case 4:
        Gapok = 1500000;
        break;
      default:
        Gapok = 0;
    }

		gotoxy(48, 7 + i); cout << Gapok << endl;
		gotoxy(27, 7 + i); cin >> StatusNikah;
		
    switch(StatusNikah) {
      case nikah:
			  TunjIstri = (Gapok * 20 / 100) ;
        gotoxy(27, 7 + i); cout << "Nikah";
        break;
      case belum_nikah:
				TunjIstri = 0;
        gotoxy(27, 7 + i); cout << "Belum";
        break;
      case cerai:
        TunjIstri = 0;
        gotoxy(27, 7 + i); cout << "Cerai";
        break;
      default:
        TunjIstri = 0;
    }

		gotoxy(61, 7 + i); cout << TunjIstri;

    if(StatusNikah == nikah || StatusNikah == cerai) {
		  gotoxy(37, 7 + i); cin >> JmlAnak;
    } else {
      JmlAnak = 0;
    }

    // Hitung tunjangan anak
		if (JmlAnak <= 2) {
			TunjAnak = JmlAnak * (Gapok * 5 / 100); // 5%
		} else {
			TunjAnak = JmlAnak * (Gapok * 10 / 100); // 10%
		}

		gotoxy(74, 7 + i); cout << TunjAnak;

		Gakot = Gapok + TunjIstri + TunjAnak;
		gotoxy(85, 7 + i); cout << Gakot;
		
    if (Gakot >= 1000000) {
			Pajak = Gakot * 5 / 100; // pajak 5%
		} else if (Gakot <= 1000000) {
			Pajak = Gakot * 3 / 100; // pajak 3%
		}

		gotoxy(97,7+i); cout << Pajak;
		
    // Gaji bersih
    Gaber = Gakot - Pajak;
		gotoxy(108,7+i); cout << Gaber;

		TotGap = TotGap + Gapok;
		TotIs = TotIs + TunjIstri;
		TotNak = TotNak + TunjAnak;
		TotGakot = TotGakot + Gakot;
		TotPaj = TotPaj + Pajak;
		TotGaber = TotGaber + Gaber;

		gotoxy(48,21); cout << TotGap;
		gotoxy(61,21); cout << TotIs;
		gotoxy(74,21); cout << TotNak;
		gotoxy(85,21); cout << TotGakot;
		gotoxy(97,21); cout << TotPaj;
		gotoxy(108,21); cout << TotGaber;
		gotoxy(80,4); cout << "Isi Data Lagi [Y/T] : ";

		cin >> jw;
		i++;

		gotoxy(80,4) ; cout << "                          ";
	} while (jw == 'y'|| jw == 'Y');
	getch();
}
