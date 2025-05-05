#include <stdio.h>

//enumeration:sayilara karsilik belli kelimeler atanabilir

typedef enum
{
	pzt,sali,crs,prs=12,cuma,cts,pzr	//0'dan baslar 6'ya kadar ardisil bir sekilde sayi karsiliklarini verir.prs=12 degeri verilerek de direkt atama yapilabilir.prs=12'den sonra gelen degerlere ardisil olarak deger atamasi yapilir!!!
}haftaninGunleri;						//yani prs=12,cuma,cts,pzr=>cuma=13,cts=14,pzr=15 olur.

typedef enum
{
	acemi=1,
	ortaSeviye=2,
	ileriSeviye=3,
	prof=4
}oyunSeviyeleri;

int main()
{
	haftaninGunleri gunler;	//haftaninGunleri enumundan degisken üretilir
	
	puts("Lutfen haftanin gunlerini temsil eden 0-6 arasinda bir sayi giriniz:");
	scanf("%d",&gunler);
	
	switch(gunler)
	{
		case pzt:
		case sali:
		case crs:
		case prs:
		case cuma:
			puts("Hafta ici");
			break;
		case cts:
		case pzr:
			puts("Hafta sonu");
			break;
		default:
			puts("Hatali bir giris yaptiniz.");
	}

	oyunSeviyeleri seviyeler;
	
	puts("Lutfen oyundaki seviyenizi giriniz:");
	scanf("%d",&seviyeler);
	
	if(seviyeler==acemi)
		printf("Bu bolumu oynamaya seviyeniz yetmiyor.");
	else if(seviyeler==ortaSeviye || seviyeler==ileriSeviye)
		printf("Bu bolumu oynayabilirsiniz.");
	else if(seviyeler==prof)
		printf("Bu bolumu oynamak icin seviyeniz cok yuksek.");
	else
		printf("Hatali bir tuslama yaptiniz.");

	return 0;
}
