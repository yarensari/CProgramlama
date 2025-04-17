#include <stdio.h>
/*
	adrese yapýlan atama iþlemleri her yerde deðiþimi saðlar.
*/
void sayiDegistir(int,int);
void sayiDegistirPointer(int *,int *);		// function overloading yoktur

int main()
{
	int a=5,b=12;
	
	printf("baslangictaki deger:");
	printf("a degiskenin degeri:%d b degiskeninin degeri:%d\n",a,b);
	sayiDegistir(a,b);						// CALL BY VALUE:deðerleriyle gönder
	printf("pointer kullanmadan:");
	printf("a degiskenin degeri:%d b degiskeninin degeri:%d\n",a,b);
	sayiDegistirPointer(&a,&b);				// CALL BY REFERENCE:adresleriyle gönder
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
	gecici=*sayi1;		// gecici deðiþkenine sayi1 deðiþkeninin gösterdiði yerdeki deðer atandý
	*sayi1=*sayi2;		// sayi1 deðiþkeninin gösterdiði yerdeki deðiþken sayi2 deðiþkeninin gösterdiði yerdeki deðerle eþitlendi
	*sayi2=gecici;		// sayi2 deðiþkeninin gösterdiði yerdeki deðiþkene gecici deðiþkenin deðeri atandý
}
