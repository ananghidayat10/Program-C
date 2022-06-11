#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
 float X[300];
 float Y[300];
 float data, totalX, totalY, totalXY, totalXkuadrat, kuadrattotalX;
 float a,b ;
 int i, ulang;
 cout << "Program menghitung nilai regresi dengan format Y=e -aX+b" ;
 do
 {
    totalX=0, totalY=0, totalXY=0, totalXkuadrat=0;
    cout << endl << endl ;
 cout << "Masukkan banyak data yang ingin Anda di imput : " ;
 cin >> data ;
 cout << endl ;
 
 //input data
 for (i=0 ; i<data ; i++)
  {
   cout << "Masukkan nilai X-" << i+1 << " : " ;
   cin >> X[i];
   cout << "Masukkan nilai Y-" << i+1 << " : " ;
   cin >> Y[i];
   cout << endl;
  }
 
 cout << endl;
 
 // menghitung nilai b
  
  //menghitung nilai jumlah nilai XY
  for (i=0 ; i<data ; i++)
   totalXY=totalXY+(X[i]*Y[i]);
  
  //menghitung nilai jumlah X dan jumlah Y
  for (i=0 ; i<data ; i++)
   {
    totalX=totalX+X[i];
    totalY=totalY+Y[i];
   }
  
  //menghitung total X kuadrat
  for (i=0 ; i<data ; i++)
   totalXkuadrat=totalXkuadrat+(X[i]*X[i]);
  
  // menghitung kuadrat total X
  for (i=0 ; i<data ; i++)
   kuadrattotalX=totalX*totalX;
  
  //menghitung nilai b
  float b=((data*totalXY)-(totalX*totalY)) / ((data*totalXkuadrat)-(kuadrattotalX));
  
  
 //menghitung nilai a
  
  float a=((totalXkuadrat*totalY)-(totalX*totalXY)) / ((data*totalXkuadrat)-(kuadrattotalX));
   
 // menampilkan hasil persamaan regresi
 cout << "Regresi Lenear nya adalah Y=" << b << "X" << setiosflags(ios::showpos) << a << endl;
 getch();
    
 // fungsi mengulang program
    cout << "Ingin mengulang (Y/T) ? :" ;
    ulang=getch();
    } while (ulang=='Y' || ulang=='y');
    
 return 0;
} 
