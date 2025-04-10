#include <stdio.h>

/*
	C programlama dilinde haz�r bir string veri tipi bulunmamaktad�r. Dolay�s�yla karakter dizileriyle string veri tipleri tutulabilir hale getirilmelidir.
	tek karakterli char veri tipi haf�zada 1 byte yer tutar.

*/

int main()
{
	// char isim[]={'y','a','r','e','n','\0'}; 	// bu �ekilde de de�er atamas� yap�labilir. NULL karakter EKLENMEL�D�R!
	// char *isim="yaren";						// pointerla da tan�mlama yap�labilir.
	char isim[]="yaren";	// 'y','a','r','e','n','\0'=>sonunda NULL karakteri vard�r. bu karakterle string'in bitti�i anla��l�r. direkt bir atama yap�ld���nda eleman say�s� yazmaya gerek yok.
	
	printf("%d byte yer kaplar.\n",sizeof(isim));	// NULL karakteriyle birlikte haf�zada 6 byte yer kaplar.
	
	printf("%s",isim);								// char veri tipiyle olu�turulan string veri tipidir. '\0' karakter bas�lmaz ��nk� o C dilinin anlamas� i�in olu�turulan bir karakterdir.
	
	printf("\n---------------------------------------\n");
	
	char veri[20];
	
	scanf("%s",veri);								// diziler adresi de tutarlar. adres operat�r� kullanmak opsiyoneldir.
	printf("%s",veri);
	
	printf("\n---------------------------------------\n");
	
	char isimler[4][10]={"Yaren","Duygu","Derya","Betul"};		// isimler[maksKelimeSayisi][maksHarfSayisi]. maksHarfSayisi yaz�lmal�d�r.
	char soyisimler[4][10]={"Sari","Suseven","Zor","Kurt"};
	int i;
	
	for(i=0;i<4;i++)
		printf("Ogrencinin adi-soyadi:%s %s\n",isimler[i],soyisimler[i]);
	
	printf("\n");
	
	for(i=0;i<4;i++)
		printf("Ogrencinin adi-soyadi:%c.%s\n",isimler[i][0],soyisimler[i]);	// tek bir karakter bast�r�nca art�k string olmuyor, char oluyor.
	
	printf("---------------------------------------\n");
	
	for(i=0;i<4;i++)
	{
		printf("Lutfen %d. ogrencinin ismini ve soyismini giriniz:",i+1);
		scanf("%s%s",isimler[i],soyisimler[i]);
	}

	for(i=0;i<4;i++)
		printf("%d. ogrencinin adi-soyadi:%s %s\n",i+1,isimler[i],soyisimler[i]);	
	
	
	return 0;
}
