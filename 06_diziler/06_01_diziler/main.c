#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Diziler
/* dizilerde deðerler:
	- ayný tip
	- ayný yerde 
	- sýralý bir þekilde
	tutulur.
	0. indeks baþlangýç adresidir.
	0. indeksten itibaren adres veri tipinin hafýzada kapladýðý yer kadar artarak devam eder.
	int veri tipi için:
	0000->baþlangýç adresi (1. eleman) (0.indeks)
	0004->(2. eleman) (1. indeks)
	0008->(3. eleman)(2. indeks)
	000C->(4. eleman)(3. indeks)...
*/ 

int main()
{
	int sayiDizisi[10] = {1,2,3,4,5};			// hafýzada deðer atamasý yapýlmasa bile 40 byte yer ayýrdýk. deðer atýlmasý yapýlmayan bölgelerde ya 0 deðeri ya da compiler'ýn ürettiði sayýlarla karþýlaþýlýr
	
	printf("Dizinin kapladigi alan: %d\n", sizeof(sayiDizisi));
	
	printf("Dizinin 1. elemaninin adresi: %#X ve degeri:%d\n", &sayiDizisi[0], sayiDizisi[0]);
	printf("Dizinin 2. elemaninin adresi: %#X ve degeri:%d\n", &sayiDizisi[1], sayiDizisi[1]);
	printf("Dizinin 3. elemaninin adresi: %#X ve degeri:%d\n", &sayiDizisi[2], sayiDizisi[2]);
	printf("Dizinin 4. elemaninin adresi: %#X ve degeri:%d\n", &sayiDizisi[3], sayiDizisi[3]);
	printf("Dizinin 5. elemaninin adresi: %#X ve degeri:%d\n", &sayiDizisi[4], sayiDizisi[4]);
	printf("Dizinin 6. elemaninin adresi: %#X ve degeri:%d\n", &sayiDizisi[5], sayiDizisi[5]);
	
	printf("----------------------------------------------\n");
	
	int i;
	for(i = 0; i < 10; i++)
	{
		sayiDizisi[i] = pow(i,2);
		printf("%d. eleman : %d\n", i+1,sayiDizisi[i]);
 	}
 	
	printf("----------------------------------------------\n");
	
	srand(time(NULL));
	int toplam = 0, ortalama = 0, enBuyuk, enKucuk, kullaniciGirisi;
	
	printf("Lutfen bir sayi giriniz: ");
	scanf("%d", &kullaniciGirisi);
	
	for(i = 0; i < 10; i++)
	{
		sayiDizisi[i] = rand()%100;
		printf("%d ", sayiDizisi[i]);
	}
	enBuyuk = sayiDizisi[0];
	enKucuk = sayiDizisi[0];
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		if(enBuyuk < sayiDizisi[i])
			enBuyuk = sayiDizisi[i];
		if(enKucuk > sayiDizisi[i])
			enKucuk = sayiDizisi[i];
		toplam += sayiDizisi[i];
		printf("%d. eleman eklendi ve yeni toplam : %d\n", i+1, toplam);
	}
	
	ortalama = toplam/10;
	printf("Dizinin ortalamasi: %d\n", ortalama);
	
	printf("Dizinin en buyuk elemani: %d\n", enBuyuk);
	printf("Dizinin en kucuk elemani: %d\n", enKucuk);
	
	for(i = 0; i < 10; i++)
	{
		if(sayiDizisi[i] > ortalama)
			printf("%d sayisi dizinin ortalamasindan buyuktur.\n", sayiDizisi[i]);
		else if(sayiDizisi[i] < ortalama)
			printf("%d sayisi dizinin ortalamasindan kucuktur.\n", sayiDizisi[i]);
		else
			printf("%d sayisi dizinin ortalamasina esittir.\n", sayiDizisi[i]);
	}
	
	for(i = 0; i < 10; i++)
	{
		if(sayiDizisi[i] % kullaniciGirisi == 0)
			printf("%d sayisi girdiginiz sayi degerinin (%d) bir katidir.\n", sayiDizisi[i], kullaniciGirisi);
	}
	
	return 0;
}
