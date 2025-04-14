#include <stdio.h>

// Local deðiþken global deðiþkene göre DAHA ÖNCELÝKLÝDÝR!

void selamla();
int toplama(int,int);

int a=4;
int main()
{
	int a=3;													// a deðiþkeni main fonksiyonunda local bir deðiþkendir. dolayýsýyla bu kapsam dýþýnda tanýmsýzdýr.
	printf("%d\n",toplama(3,5));
	
	if(1)
	{
		int a=5;												// if döngüsü için local bir deðiþkendir.
		printf("if blogundaki a degiskeninin degeri:%d\n",a);
	}
	printf("main blogundaki a degiskeninin degeri:%d\n",a);
	printf("global a degiskeninin degeri:%d\n",a);				// main'de aldýðý deðeri gösterir
	selamla();
	printf("selamla fonksiyonunda sonra a deger:%d\n",a);		// local deðiþken daha önceliklidir
	
	return 0;
}

void selamla()
{
	a=10;
	printf("Global degiskenin selamla fonksiyonunda guncellenmis hali:%d\n",a);
	printf("Merhaba\n");
}

int toplama(int sayi1,int sayi2)
{
	int sonuc=sayi1+sayi2;										// sonuc deðiþkeni toplama fonksiyonda local bir deðiþkendir. dolayýsýyla sadece toplama fonksiyonunda gözükebilir.
	printf("Global a degiskeninin toplama fonksiyonundaki degeri:%d\n",a);
	return sonuc;
}
