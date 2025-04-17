#include <stdio.h>
/*
	HATIRLATMA:string'lerin sonunda her zaman \0 karakter yer alýr.
	karakter dizilerinin bir sonraki indekse geçiþi 1byte þeklinde artarak saðlanýr.
*/
int main()
{
	char *kullaniciGirisi="Yaren Sari";		// BAÞLANGIÇ ADRESÝNÝ TUTAR.
	char *ptr=kullaniciGirisi;
	//char kullaniciGirisi[]="Yaren Sari";	// ayný yola çýkar
	
	while(*kullaniciGirisi!='\0')
	{
		printf("%#X adresinde tutulan deger:%c\n",kullaniciGirisi,*kullaniciGirisi);	//1byte 1byte artýþ olur
		kullaniciGirisi++;
	}
	printf("%#X adresinde tutulan deger:%c\n",kullaniciGirisi,*kullaniciGirisi);		//stringin sonunda yer alan NULL karakterdir.

	printf("%s",ptr);						//string þeklinde yazdýrmak için baþlangýç adresi gereklidir!
	
	//iki boyutlu char dizisi tanýmý:
	char *isimlerSoyisimler[]={"Yaren Sari","Duygu Suseven","Derya Zor","Betul Kurt","Ezgi Boz"};	//[]parantez kaç adet string ifadesinin bulunacaðýný tutar
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("%s\n",isimlerSoyisimler[i]);
	}	
	
	return 0;
}
