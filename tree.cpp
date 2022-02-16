#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{
      int data;
      Node *kiri;
      Node *kanan;
};

//fungsi untuk menambahkan node baru
void tambah(Node **root, int databaru)
{
      //jika root masih kosong
      if((*root) == NULL)
      {
            //pembuatan node baru
            Node *baru;
            //pengalokasian memori dari node yang telah dibuat
            baru = new Node;
            //inisialisasi awal node yang baru dibuat
            baru->data = databaru;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
            cout<<"Data bertambah!";
      }
     //jika data lebih kecil dari elemen root, maka letakkan di node sebelah kiri.
      else if(databaru<(*root)->data)
            tambah(&(*root)->kiri, databaru);
     //jika data lebih besar daripada elemen root, maka letakkan di node sebelah kanan
      else if(databaru>(*root)->data)
            tambah(&(*root)->kanan, databaru);
     //jika data sama dengan data pada root
      else if(databaru == (*root)->data)
            printf("Data sudah ada!");
}

void preOrder(Node *root)  //fungsi untuk mencetak tree secara preOrder
{
   if(root != NULL)
   {
   		cout<<root->data<<"   ";
   		preOrder(root->kiri);
   		preOrder(root->kanan);
   }
}

void inOrder(Node *root) //fungsi untuk mencetak tree secara inOrder
{
   if(root != NULL)
   {
   		inOrder(root->kiri);
   		cout<<root->data<<"   ";
   		inOrder(root->kanan);
   }
}

void postOrder(Node *root) //fungsi untuk mencetak tree secara postOrder
{
   if(root != NULL)
   {
   		postOrder(root->kiri);
   		postOrder(root->kanan);
   		cout<<root->data<<"   ";
	}
}

int main()
{
      int pil, data;
      Node *pohon; 
      pohon = NULL; //inisialisasi node pohon
      
      do
      {
            system("cls"); 
            cout<<"PROGRAM TREE Dev C++";
            cout<<"\n====================";
            cout<<"\nMENU PILIHAN";
            cout<<"\n-------------\n";
            cout<<"1. Tambah Data\n";
            cout<<"2. Lihat pre-order\n";
            cout<<"3. Lihat in-order\n";
            cout<<"4. Lihat post-order\n";
            cout<<"5. Keluar\n";
            printf("Pilihan Anda [1-5] : ");
            cin>>pil;
            switch(pil)
            {
            case 1 :
                  cout<<"\nINPUT : ";
                  cout<<"\n-------";
                  cout<<"\nData baru : ";
                  cin>>data;              
                  tambah(&pohon, data);	//panggil fungsi untuk menambah node
                  break;
                 
            case 2 :
                  cout<<"\nOUTPUT PRE ORDER : ";
                  cout<<"\n------------------\n";
                  if(pohon!=NULL)
                        preOrder(pohon);   //panggil fungsi mencetak data preOrder
                  else
                        cout<<"Masih kosong!";
                  break;
                       
            case 3 :
                  cout<<"\nOUTPUT IN ORDER : ";
                  cout<<"\n------------------\n";
                  if(pohon!=NULL)
                        inOrder(pohon); //panggil fungsi mencetak data inOrder
                  else
                        cout<<"Masih kosong!";
                  break;
                      
            case 4 :
                  cout<<"\nOUTPUT POST ORDER : ";
                  cout<<"\n------------------\n";
                  if(pohon!=NULL)                
                        postOrder(pohon);  //panggil fungsi mencetak data postOrder
                  else
                        cout<<"Masih kosong!";
                  break;
            }
            getch();
      }while(pil != 5); 
}
