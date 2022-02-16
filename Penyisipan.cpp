#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int larik[15]={61, 71, 62, 41, 51, 40, 72, 65, 76, 80, 67, 50, 49, 35, 32};
	int j,x;
	cout<<"Data sebelum diurutkan"<<endl;
	for (int i=0;i<15;i++)
    {		
    	cout<<larik[i]<<" ";
	} 
	cout<<endl<<endl;
    cout<<"Proses pengurutan"<<endl;
  	int lokasi,temp;
	 for (int i=0;i<15;i++)
	{
		 lokasi = i;
		 for(int j=i+1;j<15;j++)
	 {
		if (larik[lokasi] > larik[j])
		lokasi=j;
	 }
	 temp=larik[lokasi];
	 larik[lokasi]=larik[i];
	 larik[i]=temp;
	//menampilkan hasil pengurutan
		for (int i=0;i<15;i++)
    	{	
    		cout<<larik[i]<<" ";
		}
		cout<<endl;
	}
	cout<<"\nData setelah diurutkan"<<endl;
	for (int i=0;i<15;i++)
    {		
    	cout<<larik[i]<<" ";
	} 
	getch();
	
}
