#include <stdio.h>
#include <string.h>

struct Ogrenci{
	char isim[20];
	char soyisim[50];
	float ortalama;
};

int main()
{
	struct Ogrenci ogr={"Yaren","Sari",2.71};
	struct Ogrenci *ogrPtr;
	
	ogrPtr=&ogr;	//ogrPtr ogr degiskeninin adresini tutuyor
	
	printf("Adresi:%#X\n\n",ogrPtr);
	printf("Ogrencinin ismi:%s\n",(*ogrPtr).isim);		//bu sekilde erisim saglanabilir
	printf("Ogrencinin soyismi:%s\n",ogrPtr->soyisim);	//bu sekilde de erisim saglanabilir
	printf("Ogrencinin ortalamasi:%.2f\n\n",ogrPtr->ortalama);
	
	//pointer kullanarak deger atama:
	strcpy((*ogrPtr).isim,"Ogun");
	strcpy((*ogrPtr).soyisim,"Birinci");
	(*ogrPtr).ortalama=3.74;
	
	printf("Ogrencinin ismi:%s\n",(*ogrPtr).isim);	//bu sekilde erisim saglanabilir
	printf("Ogrencinin soyismi:%s\n",ogrPtr->soyisim);	//bu sekilde de erisim saglanabilir
	printf("Ogrencinin ortalamasi:%.2f\n\n",ogrPtr->ortalama);
	
	return 0;
}
