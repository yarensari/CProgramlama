#include <stdio.h>

/*
	C programlama dilinde hazýr bir string veri tipi bulunmamaktadýr. Dolayýsýyla karakter dizileriyle string veri tipleri tutulabilir hale getirilmelidir.
	tek karakterli char veri tipi hafýzada 1 byte yer tutar.

*/

int main()
{
	// char isim[]={'y','a','r','e','n','\0'}; 	// bu þekilde de deðer atamasý yapýlabilir. NULL karakter EKLENMELÝDÝR!
	// char *isim="yaren";						// pointerla da tanýmlama yapýlabilir.
	char isim[]="yaren";	// 'y','a','r','e','n','\0'=>sonunda NULL karakteri vardýr. bu karakterle string'in bittiði anlaþýlýr. direkt bir atama yapýldýðýnda eleman sayýsý yazmaya gerek yok.
	
	printf("%d byte yer kaplar.\n",sizeof(isim));	// NULL karakteriyle birlikte hafýzada 6 byte yer kaplar.
	
	printf("%s",isim);								// char veri tipiyle oluþturulan string veri tipidir. '\0' karakter basýlmaz çünkü o C dilinin anlamasý için oluþturulan bir karakterdir.
	
	printf("\n---------------------------------------\n");
	
	char veri[20];
	
	scanf("%s",veri);								// diziler adresi de tutarlar. adres operatörü kullanmak opsiyoneldir.
	printf("%s",veri);
	
	printf("\n---------------------------------------\n");
	
	char isimler[4][10]={"Yaren","Duygu","Derya","Betul"};		// isimler[maksKelimeSayisi][maksHarfSayisi]. maksHarfSayisi yazýlmalýdýr.
	char soyisimler[4][10]={"Sari","Suseven","Zor","Kurt"};
	int i;
	
	for(i=0;i<4;i++)
		printf("Ogrencinin adi-soyadi:%s %s\n",isimler[i],soyisimler[i]);
	
	printf("\n");
	
	for(i=0;i<4;i++)
		printf("Ogrencinin adi-soyadi:%c.%s\n",isimler[i][0],soyisimler[i]);	// tek bir karakter bastýrýnca artýk string olmuyor, char oluyor.
	
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
