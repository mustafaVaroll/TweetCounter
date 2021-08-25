#include <iostream>
#include <fstream>
#include <string.h>



using namespace std;





void  writeline(string line)  //Bu fonksiyon aldýðý satýrlarý output.txt ye yazar
{

ofstream outputfile("output.txt",ios::app);
outputfile << line ;

outputfile.close();


}

void  writeoutput(string line,int number)// Bu fonksiyon ise aldýðý sayý ve satýrlarý wordandnumber.txt ye yazar
{


ofstream outputfil("wordandnumber.txt",ios::app);
 outputfil << line ;
 outputfil <<" ";
 outputfil << number;

outputfil.close();


}


int stopwords(string  line1)  //önceden  belli olan  stopwrods.txt dosyasýndaki kelimeleri yoksaymayý saðlar
{
  string ln;
  ifstream stpwrds;
  stpwrds.open("stopwords.txt");

while(stpwrds.good())
    {

       getline(stpwrds,ln);

        if(line1.compare(ln)==0)// Eðer gelen deðer herhangi bir stopword le aynýysa 0 deðeri döndürür
        {
            return 0;
        }

}


stpwrds.close();
return 1; // Eðer gelen deðer herhangi bir stopword le ayný deðilse 1 deðeri döndürür
}

int countword(string l3)//  Bu fonksiyon gelen deðerdeki kelimenin kaç defa tekrar ettiðini sayar ve dönderir.

{
    string kontrol;
    int counter=0;
    int x=stopwords(l3);

ifstream outptxt;
outptxt.open("output.txt");

while(!outptxt.eof()&&x!=0)//Ayrýca  stopworslerin kontrolü saðlandý.
    {


getline(outptxt,kontrol,' ');

     if( l3.compare(kontrol)==0)
     {
         counter++;
     }

}

outptxt.close();

return counter;
}


void  printfoe(int diz[])//Bu fonksiyonda  sýralanmýþ dizideki tekrar sayýlarýna göre en çok tekrarlanan kelimleri ekrana yazar.
{


   string printline;
   int num;

   ifstream printx;
   printx.open("wordandnumber.txt");




while(!printx.eof()){
printx >>printline >> num;

      if(diz[0]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

      if (diz[1]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

      if(diz[2]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

      if(diz[3]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

      if (diz[4]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;
      if(diz[5]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

      if (diz[6]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

       if(diz[7]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

       if(diz[8]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;
       if(diz[9]==num)
        cout <<"<<"<<printline<<">>" <<"      " << "<< "<<num <<">>" <<endl;

}
printx.close();
}


void siralama(int ar[])//Bu fonksiyon  dizinin içindeki elemanlarý büyükten küçüðe sýralar.
{
    int i=0,j=0,gecici=0;

    for( i=0;i<100;i++)
        for(j=i+1;j<100;j++)
    {

        if(ar[i]>ar[j])
        {
        gecici=ar[i];
        ar[i]=ar[j];
        ar[j]=gecici;

        }
    }



  }


int main()
{


  ifstream myFile;
   myFile.open("training.1600000.processed.noemoticon.csv");  //training.1600000.processed.noemoticon.csv  Bu dosyayý myFile  adýndaacýyorum

   string line;
   int counter=1;


     while(myFile.good()){

       getline(myFile,line,'"'); //" iþaretine kadarki yerleri teker teker alýyorum sadece  twitlere  ullaþmak için
       counter++;

   if(counter==13)// counter 13 ve katlarýnda twitlere geliyo

      {

      writeline(line);  //  Bu fonksiyonla twitleri ayrý bir output.txt  dosyasýna yazýyorum
       counter=1;


     }

  }
  myFile.close();


ifstream outptxt;
int dizi[1000]; // Kelimelerin kaç kere tekrar  ettiðini dizinin içine atýlacak.
int sayac=0;
outptxt.open("output.txt");
string lineout;

while(!outptxt.eof())// while döngüsü  ile bir  kelime alýp kaç defa tekrar edildiðine bakar ve  yeni kelimeye geçer bölece bütün  dosya da ki  kelimelere ayný iþlemi yapar.

{
    getline(outptxt,lineout,' ');   // output.txt boþluk gelmeden denildiki her kelime alýnsýn.

    int sayi =countword(lineout); // Gönderilen   kelimenin kaç defa tekrar edildiði sayiya atýldý

     writeoutput(lineout,sayi); // writeoutput fonksiyonu ile kellime ve sayý wordandname.txt dosyasýna atýldý.
     dizi[sayac]=sayi; //dizinin içinnede kelimenin kaç defa tekrar  sayýsý atýldý.
     sayac++;



}

siralama(dizi); // tekrar sayýlarýný büyükten küçüðe sýralar.


printfoe(dizi); // son  olarakta tekrar sayýlarý düzenlenmiþ dizinin  içindeki en büyük on tane yi kelimeleriyle  yazar.



outptxt.close();

    return 0;
}

