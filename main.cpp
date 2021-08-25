#include <iostream>
#include <fstream>
#include <string.h>



using namespace std;





void  writeline(string line)  //Bu fonksiyon ald��� sat�rlar� output.txt ye yazar
{

ofstream outputfile("output.txt",ios::app);
outputfile << line ;

outputfile.close();


}

void  writeoutput(string line,int number)// Bu fonksiyon ise ald��� say� ve sat�rlar� wordandnumber.txt ye yazar
{


ofstream outputfil("wordandnumber.txt",ios::app);
 outputfil << line ;
 outputfil <<" ";
 outputfil << number;

outputfil.close();


}


int stopwords(string  line1)  //�nceden  belli olan  stopwrods.txt dosyas�ndaki kelimeleri yoksaymay� sa�lar
{
  string ln;
  ifstream stpwrds;
  stpwrds.open("stopwords.txt");

while(stpwrds.good())
    {

       getline(stpwrds,ln);

        if(line1.compare(ln)==0)// E�er gelen de�er herhangi bir stopword le ayn�ysa 0 de�eri d�nd�r�r
        {
            return 0;
        }

}


stpwrds.close();
return 1; // E�er gelen de�er herhangi bir stopword le ayn� de�ilse 1 de�eri d�nd�r�r
}

int countword(string l3)//  Bu fonksiyon gelen de�erdeki kelimenin ka� defa tekrar etti�ini sayar ve d�nderir.

{
    string kontrol;
    int counter=0;
    int x=stopwords(l3);

ifstream outptxt;
outptxt.open("output.txt");

while(!outptxt.eof()&&x!=0)//Ayr�ca  stopworslerin kontrol� sa�land�.
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


void  printfoe(int diz[])//Bu fonksiyonda  s�ralanm�� dizideki tekrar say�lar�na g�re en �ok tekrarlanan kelimleri ekrana yazar.
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


void siralama(int ar[])//Bu fonksiyon  dizinin i�indeki elemanlar� b�y�kten k����e s�ralar.
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
   myFile.open("training.1600000.processed.noemoticon.csv");  //training.1600000.processed.noemoticon.csv  Bu dosyay� myFile  ad�ndaac�yorum

   string line;
   int counter=1;


     while(myFile.good()){

       getline(myFile,line,'"'); //" i�aretine kadarki yerleri teker teker al�yorum sadece  twitlere  ulla�mak i�in
       counter++;

   if(counter==13)// counter 13 ve katlar�nda twitlere geliyo

      {

      writeline(line);  //  Bu fonksiyonla twitleri ayr� bir output.txt  dosyas�na yaz�yorum
       counter=1;


     }

  }
  myFile.close();


ifstream outptxt;
int dizi[1000]; // Kelimelerin ka� kere tekrar  etti�ini dizinin i�ine at�lacak.
int sayac=0;
outptxt.open("output.txt");
string lineout;

while(!outptxt.eof())// while d�ng�s�  ile bir  kelime al�p ka� defa tekrar edildi�ine bakar ve  yeni kelimeye ge�er b�lece b�t�n  dosya da ki  kelimelere ayn� i�lemi yapar.

{
    getline(outptxt,lineout,' ');   // output.txt bo�luk gelmeden denildiki her kelime al�ns�n.

    int sayi =countword(lineout); // G�nderilen   kelimenin ka� defa tekrar edildi�i sayiya at�ld�

     writeoutput(lineout,sayi); // writeoutput fonksiyonu ile kellime ve say� wordandname.txt dosyas�na at�ld�.
     dizi[sayac]=sayi; //dizinin i�innede kelimenin ka� defa tekrar  say�s� at�ld�.
     sayac++;



}

siralama(dizi); // tekrar say�lar�n� b�y�kten k����e s�ralar.


printfoe(dizi); // son  olarakta tekrar say�lar� d�zenlenmi� dizinin  i�indeki en b�y�k on tane yi kelimeleriyle  yazar.



outptxt.close();

    return 0;
}

