#include <stdio.h>

int main()
{
	// asal sayý sorgulama
	printf("Asal Sayi Sorgulama:\n");
	
	int sorgulanacakSayi, i, bolunduMu = 0;
	printf("Lutfen asal sayi sorgusu yapilacak sayiyi giriniz: ");
	scanf("%d", &sorgulanacakSayi);
	
	for(i = 2; i < sorgulanacakSayi; i++)
	{
		if((sorgulanacakSayi%i) == 0)
		{
			bolunduMu = 1;				// asal sayý deðildir.
			break;	
		}
	}
	
	if(bolunduMu == 1)
		printf("%d sayisi asal bir sayi degildir.\n", sorgulanacakSayi);
	else
		printf("%d sayisi asal bir sayidir.\n", sorgulanacakSayi);
		
	printf("******************************************\n");
	
	// EBOB - EKOK hesaplama
	printf("EBOB - EKOK Hesaplama\n");
	
	int sayi1, sayi2, EBOB, EKOK, buyukSayi, kucukSayi, sayac;
	
	printf("Lutfen EBOB - EKOK hesaplamasi yapilacak sayilari giriniz: ");
	scanf("%d%d", &sayi1, &sayi2);
	
	if(sayi1 > sayi2)
	{
		buyukSayi = sayi1;
		kucukSayi = sayi2;
	}
	else 
	{
		buyukSayi = sayi2;
		kucukSayi = sayi1;
	}		
	
	// EBOB => maksimum girilen deðerlerdeki küçük sayý kadar olabilir.
	sayac = kucukSayi; 
	while(1)
	{
		if((sayi1%sayac == 0) && (sayi2%sayac == 0))
		{
			EBOB = sayac;
			break;
		}
		sayac--;
	}
		
	// EKOK => minimum girilen deðerlerdeki büyük sayý kadar olabilir.
	sayac = buyukSayi;
	while(1)
	{
		if((sayac%sayi1 == 0) && (sayac%sayi2 == 0))
		{
			EKOK = sayac;
			break;
		}
		sayac++;
	}
	
	printf("%d ve %d sayilarinin EKOK degeri : %d\n", sayi1, sayi2, EKOK);
	printf("%d ve %d sayilarinin EBOB degeri : %d\n", sayi1, sayi2, EBOB);
	
	printf("******************************************\n");
	
	// Boþluk sayýsý hesaplama
	char ch;
	int boslukSayisi = 0;
	
	printf("Lutfen bosluk sayisi hesaplanacak cumleyi giriniz: ");
	fflush(stdin);
	
	do{
		ch = getchar();
		if(ch == ' ')
			boslukSayisi++;
				
	}while(ch != '\n');
	
	printf("Girdiginiz cumledeki bosluk sayisi: %d\n", boslukSayisi);
	
	// sayýyý terse çevirme
	int sayi, geciciSayi, sayininTersi = 0, kalan;
	
	printf("Lutfen tersi alinacak olan sayiyi giriniz: ");
	scanf("%d", &sayi);
	geciciSayi = sayi;
	
	while(geciciSayi != 0)
	{
		kalan = geciciSayi % 10;					// 1%10 = 1
		sayininTersi = sayininTersi*10 + kalan;		// 354*10+1 = 3541
		geciciSayi /= 10;							// geciciSayi = 0
	}
	
	printf("%d sayisinin tersi %d'dir\n", sayi, sayininTersi);
	
	printf("******************************************\n");
	
	// kullanýcýdan alýnan decimal sayýnýn binary seviyeye dönüþtürülmesi
	int decimalSayi;
	char bitArray[32];
	i = 0;
	
	printf("Lutfen binary duzeye cevrilecek olan sayiyi giriniz: ");
	scanf("%d", &decimalSayi);
	geciciSayi = decimalSayi;
	while(geciciSayi != 0)
	{
		if(geciciSayi%2 == 0)
			bitArray[i] = '0';
		else 
			bitArray[i] = '1';		
		i++;
		geciciSayi /= 2;
	}
	
	printf("%d sayisinin bit karsiligi:", decimalSayi);
	while(i >= 0)
	{
		printf("%c", bitArray[i]);
		i--;
	}
		
	return 0;
}
