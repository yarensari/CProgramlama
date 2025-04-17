#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
	iþaretçiler yardýmýyla dizi yönetimi:
	eðer pointer dizinin baþlangýç adresini tutar ve 4byte ileri giderse dizinin bir diðer indeksine geçmiþ olur. 4byte geçiþ +1 ile saðlanýr.
	!DÝZÝNÝN ADI AYNI ZAMANDA DÝZÝNÝN ADRESÝ ANLAMINA GELÝR!
*/

int main()
{
	int i;
	int dizi[10];		// dizilerin belirli bir baþlangýç adresi vardýr ve o baþlangýç adresinden ilerleyerek devam eder.
	int *ptr1=&dizi[0];
	int *ptr2=dizi;		// dizinin adý baþlangýç adresi anlamýna gelir.
	srand(time(NULL));
	
	printf("Dizinin baslangic adresi:%#X\n",ptr1);
	printf("Dizinin baslangic adresi:%#X\n",ptr2);
	
	for(i=0;i<10;i++)
	{
		printf("%d.indeksteki yerin adresi:%#X ",i,ptr1+i);
		*(ptr1+i)=rand()%100;
		printf("ve degeri:%d\n",*(ptr1+i));
	}
	
	for(ptr1=dizi;ptr1!=dizi+10;ptr1++)
	{
		printf("Adres:%#X ve deger:%d\n",ptr1,*ptr1);	
	}
	
	// POINTER ARÝTMETÝÐÝ 
	int *p=dizi;
	
	printf("%d\n",(*p)++);		// pointerýn gösterdiði yerdeki deðeri yazdýr sonra da o deðeri 1 arttýr
	printf("%d\n",*(p++));		// pointerýn gösterdiði yerdeki deðeri yazdýr sonra da gösterdiðin yeri 1 arttýr
	printf("%d\n",*(++p));		// önce pointerýn gösterdiði yeri 1 arttýr sonra da oradaki deðeri yazdýr
	printf("%d\n",++(*p));		// önce pointerýn gösterdiði yerdeki deðeri 1 arttýr sonra da o deðeri yazdýr
	
	return 0;
}
