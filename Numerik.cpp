#include <cstdlib>
#include <iostream>
#include <math.h>
#include<conio.h>
#include <stdlib.h>
#include <Windows.h>
#include<iomanip>

using namespace std;
void RegresiLinier(int n);
int main()
{
 char pil,plh;
 int n;
 system("cls");
 cout<<"\n Masukkan Jumlah Data yang akan diinputkan : ";cin>>n;
 cout<<"\n [ 1 ] Metode Regresi Linier\n"
    "\n Pilih Angka 1 untuk Melanjutkan : ";cin>>pil;
  switch(pil){
    case '1':
     system("cls");
     RegresiLinier(n);
     break;
    }
 
 system("pause");
 return 0;
}
void RegresiLinier(int q){
 system("cls");
 long jumx=0,jumy=0,jumxy=0,jumxx=0,xy=0,xx=0,X,Y;
 int n=q;
 long ratx,raty,a,b;
 float x[100],y[100];
 cout<<"\n -------------";
 cout<<"\n Input Data";
 cout<<"\n -------------";
 for (int h=1;h<=n;h++){
  cout<<"\nNilai x"<<h<<" = ";cin>>x[h];
 }
 for(int k=1;k<=n;k++){
  cout<<"\nNilai y"<<k<<" = ";cin>>y[k];
 }
 system("cls");
 cout<<"\n ===================================================================";
 cout<<"\n | Data ke  |  Xn   |     Yn      |       XY      |       X^2      |";
 cout<<"\n ===================================================================\n";
 for(int i=1;i<=n;i++){
  jumx=jumx+x[i];
  jumy=jumy+y[i];
  xy=(x[i]*y[i]);
  xx=(x[i]*x[i]);
  jumxy=jumxy+xy;
  jumxx=jumxx+xx;
 cout<<"  "<<setiosflags(ios::left)<<setw(13)<<i;
 cout<<setiosflags(ios::left)<<setw(11)<<x[i];
 cout<<setiosflags(ios::left)<<setw(16)<<y[i];
 cout<<setiosflags(ios::left)<<setw(16)<<xy;
 cout<<setiosflags(ios::left)<<setw(11)<<xx;
 cout<<"\n\n";
 }
 cout<<" -------------------------------------------------------------------\n";
 cout<<"  "<<setiosflags(ios::left)<<setw(13)<<"JUMLAH";
 cout<<setiosflags(ios::left)<<setw(11)<<jumx;
 cout<<setiosflags(ios::left)<<setw(16)<<jumy;
 cout<<setiosflags(ios::left)<<setw(16)<<jumxy;
 cout<<setiosflags(ios::left)<<setw(11)<<jumxx;
 cout<<"\n ===================================================================";
 ratx=jumx/n;
 raty=jumy/n;
 b=((jumxy*n)-(jumx*jumy))/((jumxx*n)-(jumx*jumx));
 a=raty-(b*ratx);
 cout<<"\n Nilai Rata - Rata x = "<<ratx;
 cout<<"\n Nilai Rata -  Rata y = "<<raty;
 cout<<"\n Nilai b = "<<b;
 cout<<"\n Nilai a = "<<a;
 getch();main();
}
