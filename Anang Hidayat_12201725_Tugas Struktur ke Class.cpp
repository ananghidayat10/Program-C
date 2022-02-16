#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class karyawan
{
private :
int golongan;
char Nama[50];
public :
char StatusNikah;
long GajiPokok;
long JmlhAnak;
long TunjIstri;
long TunjAnak;
long GajiKotor;
long Pajak;
long GajiBersih;
void info ()
{
cout<<"PROGRAM MENGHITUNG GAJI KARYAWAN"<<endl<<endl;
cout <<"Nama            = "; cin>> Nama ;
cout <<"Golongan        = "; cin>> golongan ;
cout <<"Status Nikah    = "; cin>> StatusNikah ;
	if (StatusNikah == 'n') {
            cout<<"Status Nikah    = "<<"Nikah"<<endl;
            cout<<"Jumlah Anak     = ";cin>>JmlhAnak;
            if (JmlhAnak>2){
                cout<<"Maksimal 2 Anak"<<endl;
            }else{
            }
        } else {
            if (StatusNikah == 'b') {
                cout<<"Status Nikah    = "<<"Belum Menikah"<<endl;
            } else {
               cout<<"Status Nikah    = "<<"Cerai"<<endl;
               cout<<"Jumlah Anak     = ";cin>>JmlhAnak;
               if (JmlhAnak>2){
            }else{
            }
            }
        }
GajiPokok=gajiPokok(golongan);
cout<<"Gajih Pokok     = "<<GajiPokok<<endl;
TunjIstri=TunjanganIsrti(GajiPokok,StatusNikah);
cout<<"Tunjangan Istri = "<<TunjIstri<<endl;
TunjAnak=TunjanganAnak(StatusNikah,JmlhAnak,GajiPokok);
cout<<"Tunjangan Anak  = "<<TunjAnak<<endl;
GajiKotor=gajikotor(GajiPokok,TunjIstri,TunjAnak);
cout<<"Gaji Kotor      = "<<GajiKotor<<endl;
Pajak=pajak(StatusNikah,GajiKotor);
cout<<"Pajak           = "<<Pajak<<endl;
GajiBersih=gaber(GajiKotor,Pajak);
cout<<"Gaji Bersih     = "<<GajiBersih;
}
long gajiPokok(char golongan)
{
	if (golongan == 1) {
	            return(750000);
	        } else {
	            if (golongan == 2) {
	                return(1000000);
	            } else {
	                if (golongan == 3) {
	                    return(1250000);
	                } else {
	                    if (golongan == 4) {
	                        return(1500000);
	                    }
	                }
	            }
	        }
}
long TunjanganIsrti(long GajiPokok, char StatusNikah)
{
	struct  tunj{
		long tunjgIstri,JmlhAnak;
	};
	tunj tunjangan;
	if (StatusNikah == 'n') {
            tunjangan.tunjgIstri = (double) 20 / 100 * GajiPokok;
        } else {
            if (StatusNikah == 'c') {
                tunjangan.tunjgIstri = 0;
            } else {
                tunjangan.tunjgIstri = 0;
            }
        }
        return(tunjangan.tunjgIstri);
}
long TunjanganAnak(char StatusNikah,long JmlhAnak,long GajiPokok)
{
	long tunjAnak;
	if (StatusNikah == 'n') {
            if (JmlhAnak > 2) {;
            } else {
                tunjAnak = (double) (JmlhAnak * 5) / 100 * GajiPokok;
            }
        } else {
            if (StatusNikah == 'c') {
            	if (JmlhAnak > 2) {;
            }else {
            	tunjAnak = (double) (JmlhAnak * 5) / 100 * GajiPokok;
			}
            	
            } else {
                if (JmlhAnak > 2) {
                } else {
                    tunjAnak = 0;
                    
                }
            }
        }
        return(tunjAnak);
}

long gajikotor(long GajiPokok,long TunjIstri,long TunjAnak)
{
	return(GajiPokok+TunjIstri+TunjAnak);
}
long pajak(char StatusNikah, long GajiKotor)
{
	long pajak;
	if (StatusNikah == 'n') {
            if (GajiKotor >= 1000000) {
                pajak = (double) 5 / 100 * GajiKotor;
            } else {
                pajak = (double) 3 / 100 * GajiKotor;
            }
        } else {
            if (StatusNikah == 'b') {
                if (GajiKotor >= 1000000) {
                    pajak = (double) 5 / 100 * GajiKotor;
                } else {
                    pajak = (double) 3 / 100 * GajiKotor;
                }
            } else {
                if (GajiKotor >= 1000000) {
                    pajak = (double) 5 / 100 * GajiKotor;
                } else {
                    pajak = (double) 3 / 100 * GajiKotor;
                }
            }
        }
        return(pajak);
}

long gaber(long GajiKotor,long Pajak)
{
	return(GajiKotor-Pajak);
}
};
int main() //Fungsi utama
{
karyawan data; // Pendefinisian variabel
data.info();
getch();
}
