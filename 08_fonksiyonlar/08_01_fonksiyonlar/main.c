#include <stdio.h>
/*
	Fonksiyonlar sayesinde yazýlan kod daha okunabilir olmaktadýr ve kullanýlabilirliði artmaktadýr.
	donusTipi:
	void->geriye deðer döndürmez
	int,float,double,char->geriye deðer döndürür
	
	donusTipi fonksiyonAdi(alacagiDegiskenler)
	{
		yapilacakIslemler;
	}
*/

// Fonksiyonlarýn tanýmlamalarý yapýlýr:
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
