#include <stdio.h>
/*
	Fonksiyonlar sayesinde yaz�lan kod daha okunabilir olmaktad�r ve kullan�labilirli�i artmaktad�r.
	donusTipi:
	void->geriye de�er d�nd�rmez
	int,float,double,char->geriye de�er d�nd�r�r
	
	donusTipi fonksiyonAdi(alacagiDegiskenler)
	{
		yapilacakIslemler;
	}
*/

// Fonksiyonlar�n tan�mlamalar� yap�l�r:
void selamla(char []);
int toplama(int,int);
char myToUpper(char);
	
int main()
{
	int sonuc;
	
	selamla("yaren");

	sonuc=toplama(3,5);
	printf("Toplama sonucu:%d\n",sonuc);
	
	printf("%c\n",myToUpper('a'));
	
	return 0;
}

void selamla(char isim[15])
{
	printf("Merhaba %s!\n",isim);
}

int toplama(int sayi1,int sayi2)
{
	return sayi1+sayi2;
}

char myToUpper(char ch)
{
	return ch-32;
}
