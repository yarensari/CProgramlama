#include <stdio.h>
#include <string.h>
/*
	strlen: stringin karakter uzunlu�unu d�ner. NULL karakteri karakter olarak SAYMAZ!
	strcpy: g�nderilen ikinci stringi, ilkine kopyalar
		strcpy(isim1,isim2)=>isim1=isim2,isim2=isim2
	strcat: g�nderilen ikinci stringi, birincinin sonuna ekler
		isim:yarensari �eklinde olur
		soyisim:sari
	strcmp: g�nderilen iki stringi birbirleriyle kar��la�t�r�r. b�y�k-k���k harfe dikkat etmektedir
		0  => ayn�
		0> => ilki ikinciden alfabetik olarak sonra
		0< => ilki ikinciden alfabetik olarak �nce 
*/

int main()
{
	char isim1[20];
	char isim2[20];
	int karakterSayisi;
	
	puts("Lutfen isminizi giriniz:");
	gets(isim1);
	
	karakterSayisi=strlen(isim1);		// NULL karakteri saymaz
	printf("%s stringi %d karakter icermektedir.\n",isim1,karakterSayisi);
	
	strcpy(isim2,isim1);				// strcpy(destination,source)
	printf("%s stringi %s stringine kopyalanmistir\n",isim1,isim2);
	
	puts("Lutfen bir isim daha giriniz:");
	gets(isim2);
	
	strcat(isim2,isim1);				// isim2'nin sonuna isim1 eklenir	
	puts(isim1);
	puts(isim2);

	puts("Lutfen isminizi giriniz:");
	gets(isim1);
	puts("Lutfen bir isim daha giriniz:");
	gets(isim2);

	int karsilastirmaSonuc;
	
	karsilastirmaSonuc=strcmp(isim1,isim2);
	if(karsilastirmaSonuc==0)
		puts("Girdiginiz isimler aynidir.");
	else if(karsilastirmaSonuc>0)
		printf("%s ismi %s isminden alfabetik olarak sonradir.\n",isim1,isim2);
	else
		printf("%s ismi %s isminden alfabetik olarak oncedir.\n",isim1,isim2);
	
	return 0;
}
