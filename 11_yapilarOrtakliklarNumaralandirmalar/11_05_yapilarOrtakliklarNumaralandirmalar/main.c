#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct//typedef struct OgrenciBilgileri{}Ogrenci; seklinde de kullanilabilir.
{
	char isim[20];//20 byte
	char soyisim[50];//50 byte
	float ortalama;//6 byte
}Ogrenci;

//typedef struct OgrenciBilgileri Ogrenci;//Ogrenci kelimesini gordugun yere struct OgrenciBilgileri'ni yaz

void bilgileriDoldur(Ogrenci *);
void bilgileriYazdir(Ogrenci *);//sadece adresi gonderir.buyuk yapilar icin avantajdir.adres gonderilmeseydi degiskenin kopyasi gonderilirdi ve gereksiz yer kullanilirdi.
void ogrenciBilgileriniDegistir(Ogrenci *,Ogrenci *);

int main()
{
	Ogrenci ogr1,ogr2;
	
	bilgileriDoldur(&ogr1);
	bilgileriDoldur(&ogr2);
	
	puts("\nBirinci ogrencinin bilgileri:");
	bilgileriYazdir(&ogr1);
	
	puts("Ikinci ogrencinin bilgileri:");
	bilgileriYazdir(&ogr2);
	
	ogrenciBilgileriniDegistir(&ogr1,&ogr2);
	
	puts("Birinci ogrencinin bilgileri:");
	bilgileriYazdir(&ogr1);
	
	puts("Ikinci ogrencinin bilgileri:");
	bilgileriYazdir(&ogr2);
	
	return 0;
}

void bilgileriDoldur(Ogrenci *ogrPtr)
{
	puts("Lutfen ogrencinin adini giriniz:");
	scanf("%s",&ogrPtr->isim);//(*ogrPtr).isim ile denktir.pgrPtr bir adres degeri tutmaktadir.
	puts("Lutfen ogrencinin soyismini giriniz:");
	scanf("%s",&ogrPtr->soyisim);
	puts("Lutfen ogrencinin ortalamasini giriniz:");
	scanf("%f",&ogrPtr->ortalama);//. operatoru sadece yapilar icin kullanilmaktadir.
}

void bilgileriYazdir(Ogrenci *ogrPtr)
{
	printf("Ogrencinin ismi:%s\n",ogrPtr->isim);
	printf("Ogrencinin soyismi:%s\n",ogrPtr->soyisim);
	printf("Ogrencinin ortalamasi:%.2f\n",ogrPtr->ortalama);
	printf("\n");
}

void ogrenciBilgileriniDegistir(Ogrenci *ogrPtr1,Ogrenci *ogrPtr2)
{
	Ogrenci gecici;
	//ilk struct'in kopyasi alindi
	strcpy(gecici.isim,ogrPtr1->isim);
	strcpy(gecici.soyisim,ogrPtr1->soyisim);
	gecici.ortalama=ogrPtr1->ortalama;
	//ilk struct ikinci struct'a esit oldu
	strcpy(ogrPtr1->isim,ogrPtr2->isim);
	strcpy(ogrPtr1->soyisim,ogrPtr2->soyisim);
	ogrPtr1->ortalama=ogrPtr2->ortalama;
	//ikinci struct kopyasi alinan gecici structa esitlendi ve swap islemi tamamlandi
	strcpy(ogrPtr2->isim,gecici.isim);
	strcpy(ogrPtr2->soyisim,gecici.soyisim);
	ogrPtr2->ortalama=gecici.ortalama;
}
