#include <stdio.h>
/*
	puts:
		printf fonksiyonuna alternatif olabilecek bazý durumlarda. biçimlendirme yapmamýza izin vermez.
	gets:
		scanf fonksiyonuna alternatif olabilecek bazý durumlarda. biçimlendirme yapmamýza izin vermez.
*/

int main()
{
	char isim[20];
	
	puts("Lutfen adinizi giriniz:");	// sadece string ifade bekler
	gets(isim);							// sadece string deðiþkeni bekler
	puts(isim);
	
	puts("----------------------------------");
	
	char isimler[4][10];
	char soyisimler[4][10];
	int i;
	
	for(i=0;i<4;i++)
	{
		puts("Lutfen adinizi giriniz:");
		gets(isimler[i]);				// enter'a basýldýðý zaman diðer beklemeyi yapar!
		puts("Lutfen soyadinizi giriniz:");
		gets(soyisimler[i]);
	}
	
	for(i=0;i<4;i++)
	{
		puts(isimler[i]);
		puts(isimler[i]);
	}
	
	
	return 0;
}
