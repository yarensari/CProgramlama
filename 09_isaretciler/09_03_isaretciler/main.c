#include <stdio.h>
/*
	HATIRLATMA:string'lerin sonunda her zaman \0 karakter yer al�r.
	karakter dizilerinin bir sonraki indekse ge�i�i 1byte �eklinde artarak sa�lan�r.
*/
int main()
{
	char *kullaniciGirisi="Yaren Sari";		// BA�LANGI� ADRES�N� TUTAR.
	char *ptr=kullaniciGirisi;
	//char kullaniciGirisi[]="Yaren Sari";	// ayn� yola ��kar
	
	while(*kullaniciGirisi!='\0')
	{
		printf("%#X adresinde tutulan deger:%c\n",kullaniciGirisi,*kullaniciGirisi);	//1byte 1byte art�� olur
		kullaniciGirisi++;
	}
	printf("%#X adresinde tutulan deger:%c\n",kullaniciGirisi,*kullaniciGirisi);		//stringin sonunda yer alan NULL karakterdir.

	printf("%s",ptr);						//string �eklinde yazd�rmak i�in ba�lang�� adresi gereklidir!
	
	//iki boyutlu char dizisi tan�m�:
	char *isimlerSoyisimler[]={"Yaren Sari","Duygu Suseven","Derya Zor","Betul Kurt","Ezgi Boz"};	//[]parantez ka� adet string ifadesinin bulunaca��n� tutar
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("%s\n",isimlerSoyisimler[i]);
	}	
	
	return 0;
}
