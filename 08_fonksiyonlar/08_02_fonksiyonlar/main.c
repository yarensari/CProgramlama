#include <stdio.h>

// Local de�i�ken global de�i�kene g�re DAHA �NCEL�KL�D�R!

void selamla();
int toplama(int,int);

int a=4;
int main()
{
	int a=3;													// a de�i�keni main fonksiyonunda local bir de�i�kendir. dolay�s�yla bu kapsam d���nda tan�ms�zd�r.
	printf("%d\n",toplama(3,5));
	
	if(1)
	{
		int a=5;												// if d�ng�s� i�in local bir de�i�kendir.
		printf("if blogundaki a degiskeninin degeri:%d\n",a);
	}
	printf("main blogundaki a degiskeninin degeri:%d\n",a);
	printf("global a degiskeninin degeri:%d\n",a);				// main'de ald��� de�eri g�sterir
	selamla();
	printf("selamla fonksiyonunda sonra a deger:%d\n",a);		// local de�i�ken daha �nceliklidir
	
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
	int sonuc=sayi1+sayi2;										// sonuc de�i�keni toplama fonksiyonda local bir de�i�kendir. dolay�s�yla sadece toplama fonksiyonunda g�z�kebilir.
	printf("Global a degiskeninin toplama fonksiyonundaki degeri:%d\n",a);
	return sonuc;
}
