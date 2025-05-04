#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Ogrenci{
	char isim[20];//20 byte
	char soyisim[50];//50 byte
	float ortalama;//6 byte
};

int main()
{
	//Bir adet yer ayirma
	struct Ogrenci *ogrPtr;//memory allocation fonksiyonundan donen degeri tutmak icin.malloc'tan donen baslangic adresini tutar
	
	printf("%d byte yer kaplar.\n\n",sizeof(struct Ogrenci));
	ogrPtr=(struct Ogrenci*)malloc(sizeof(struct Ogrenci));
	
	strcpy(ogrPtr->isim,"Yaren");
	strcpy(ogrPtr->soyisim,"Sari");
	ogrPtr->ortalama=2.71;
	
	printf("Ogrencinin ismi:%s\n",ogrPtr->isim);
	printf("Ogrencinin soyismi:%s\n",ogrPtr->soyisim);
	printf("Ogrencinin ortalamasi:%.2f\n",ogrPtr->ortalama);
	
	free(ogrPtr);//alinan alan geri verilir.
	
	//Dizi icin yer ayirma
	struct Ogrenci *ogrPtrArr;
	int elemanSayisi,i;
	
	puts("Lutfen eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	
	ogrPtrArr=(struct Ogrenci*)malloc(sizeof(struct Ogrenci)*elemanSayisi);
	
	for(i=0;i<elemanSayisi;i++)
	{
		printf("Lutfen %d. ogrencinin ismini giriniz:\n",i+1);
		fflush(stdin);
		gets(ogrPtrArr[i].isim);//dizi struct'inda deger alirken bu seilde . operatoru ve [] operatoru kullanilir.
		printf("Lutfen %d. ogrencinin soyismini giriniz:\n",i+1);
		scanf("%s",&ogrPtrArr[i].soyisim);
		printf("Lutfen %d. ogrencinin ortalamasini giriniz:\n",i+1);
		scanf("%f",&ogrPtrArr[i].ortalama);
		printf("\n");
	}
	
	for(i=0;i<elemanSayisi;i++)
	{
		printf("%d. ogrencinin ismi:%s\n",i+1,ogrPtrArr[i].isim);
		printf("%d. ogrencinin soyismi:%s\n",i+1,ogrPtrArr[i].soyisim);
		printf("%d. ogrencinin ortalamasi:%.2f\n\n",i+1,ogrPtrArr[i].ortalama);
	}
	
	free(ogrPtrArr);
	
	return 0;
}
