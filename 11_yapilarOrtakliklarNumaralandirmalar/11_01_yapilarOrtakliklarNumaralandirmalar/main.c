#include <stdio.h>
#include <string.h>

/*
	structlar ile hazir veri tipleri birlestirilir ve yeni bir veri tipi olusturulur
	tanimlamasi:
	struct veriTipiIsmi{};
	HATIRLATMA:
	char degiskenlerine tanimlama esnasinda degil de sonradan bir atama yapilacaksa bu sekilde yapilamazdi:
	char isim[20];
	isim="yaren";
	bu sekilde yapildiginda derleme hatasi alinir.
	sonradan atama yapilacaksa:
	strcpy fonksiyonunu kullaniyorduk.
	strcpy(isim,"yaren");	yaren string isim char dizisine kopyalanir!
	kullanicidan alinan degerle atama yapilacaksa:
	gets(isim); fonksiyonu kullanilirdi.
*/

struct Ogrenci{
	char isim[20];
	char soyisim[50];
	float ortalama;
};

int main()
{
	int x;	//degisken tipi:int,degisken ismi:x
	//direkt deger atama
	struct Ogrenci ogr1={"Yaren","Sari",2.71};	//degisken tipi:struct Ogrenci,degisken ismi:ogr1
	struct Ogrenci ogr2;
	//degerlere erisim
	printf("ogr1 degiskeninin ismi:%s\n",ogr1.isim);
	printf("ogr1 degiskeninin soyismi:%s\n",ogr1.soyisim);
	printf("ogr1 degiskeninin ortalamasi:%.2f\n\n",ogr1.ortalama);
	//sonradan deger atama
	strcpy(ogr2.isim,"Ogun");	//char tipinde olduklari icin atamalar esitlik operatoruyle yapilamaz!
	strcpy(ogr2.soyisim,"Birinci");
	ogr2.ortalama=3.74;
	
	printf("ogr2 degiskeninin ismi:%s\n",ogr2.isim);
	printf("ogr2 degiskeninin soyismi:%s\n",ogr2.soyisim);
	printf("ogr2 degiskeninin ortalamasi:%.2f\n",ogr2.ortalama);	
	
	return 0;
}
