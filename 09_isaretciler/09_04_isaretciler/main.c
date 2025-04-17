#include <stdio.h>
/*
	adrese yap�lan atama i�lemleri her yerde de�i�imi sa�lar.
*/
void sayiDegistir(int,int);
void sayiDegistirPointer(int *,int *);		// function overloading yoktur

int main()
{
	int a=5,b=12;
	
	printf("baslangictaki deger:");
	printf("a degiskenin degeri:%d b degiskeninin degeri:%d\n",a,b);
	sayiDegistir(a,b);						// CALL BY VALUE:de�erleriyle g�nder
	printf("pointer kullanmadan:");
	printf("a degiskenin degeri:%d b degiskeninin degeri:%d\n",a,b);
	sayiDegistirPointer(&a,&b);				// CALL BY REFERENCE:adresleriyle g�nder
	printf("pointer kullanarak: ");
	printf("a degiskenin degeri:%d b degiskeninin degeri:%d\n",a,b);
	
	return 0;
}

void sayiDegistir(int sayi1,int sayi2)
{
	int gecici;
	gecici=sayi1;
	sayi1=sayi2;
	sayi2=gecici;
	printf("sayiDegistir fonksiyonun icerisinde\na'nin degeri:%d b'nin degeri %d\n",sayi1,sayi2);
}

void sayiDegistirPointer(int *sayi1,int *sayi2)
{
	int gecici;
	gecici=*sayi1;		// gecici de�i�kenine sayi1 de�i�keninin g�sterdi�i yerdeki de�er atand�
	*sayi1=*sayi2;		// sayi1 de�i�keninin g�sterdi�i yerdeki de�i�ken sayi2 de�i�keninin g�sterdi�i yerdeki de�erle e�itlendi
	*sayi2=gecici;		// sayi2 de�i�keninin g�sterdi�i yerdeki de�i�kene gecici de�i�kenin de�eri atand�
}
