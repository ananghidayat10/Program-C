#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int larik[15]={55, 65, 85, 50, 59, 51, 45, 90, 35, 53, 58, 15, 54, 56, 91};
	int j,x;
	cout<<"Data sebelum diurutkan"<<endl;
	for (int i=0;i<15;i++)
    {		
    	cout<<larik[i]<<" ";
	} 
	cout<<endl<<endl;
    cout<<"Proses pengurutan"<<endl;
  	int temp;
	for(int i=1;i<15;i++)
	{
		for(int j=14;j>=0;j--)
		{
			 if(larik[j-1]>larik[j])
			 {
				 temp=larik[j];
				 larik[j]=larik[j-1];
				 larik[j-1]=temp;
			 }
		}
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
