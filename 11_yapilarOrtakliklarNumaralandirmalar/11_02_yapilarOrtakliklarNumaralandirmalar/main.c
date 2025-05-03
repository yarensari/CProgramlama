#include <stdio.h>

/*
	struct ve dizilerin birlikte kullanimi:
	
	HATIRLATMA:
	array'e direkt olarak eleman atamasi yapilacaksa eleman sayisini belirtmeye gerek yoktur.
*/

struct Ogrenci{
	char isim[20];
	char soyisim[50];
	float ortalama;
};

int main()
{
	//diziye direkt deger atama:
	struct Ogrenci ogrenciler[]={{"Yaren","Sari",2.71},{"Ogun","Birinci",3.74},{"Ezgi","Boz",3.74}};
	//dizideki elemanlari yazdirma:
	printf("Ogrencinin ismi:%s\n",ogrenciler[0].isim);
	printf("Ogrencinin ismi:%s\n",ogrenciler[0].soyisim);
	printf("Ogrencinin ismi:%.2f\n\n",ogrenciler[0].ortalama);
	
	printf("Ogrencinin ismi:%s\n",ogrenciler[1].isim);
	printf("Ogrencinin ismi:%s\n",ogrenciler[1].soyisim);
	printf("Ogrencinin ismi:%.2f\n\n",ogrenciler[1].ortalama);
	
	printf("Ogrencinin ismi:%s\n",ogrenciler[2].isim);
	printf("Ogrencinin ismi:%s\n",ogrenciler[2].soyisim);
	printf("Ogrencinin ismi:%.2f\n\n",ogrenciler[2].ortalama);
	
	//kullanicidan deger alarak struct dizisini doldurma
	struct Ogrenci ogrencilerK[3];
	int i;
	
	for(i=0;i<3;i++)
	{
		puts("Ogrencinin ismini giriniz:");
		gets(ogrencilerK[i].isim);
		
		puts("Ogrencinin soyismini giriniz:");
		gets(ogrencilerK[i].soyisim);
	
		puts("Ogrencinin ortalamasini giriniz:");
		scanf("%f",&ogrencilerK[i].ortalama);
		fflush(stdin);
	}
	
	for(i=0;i<3;i++)
	{
		printf("Ogrencinin ismi:%s\n",ogrencilerK[i].isim);
		printf("Ogrencinin soyismi:%s\n",ogrencilerK[i].soyisim);
		printf("Ogrencinin ortalamasi:%.2f\n\n",ogrencilerK[i].ortalama);
	}
	
	return 0;
}
