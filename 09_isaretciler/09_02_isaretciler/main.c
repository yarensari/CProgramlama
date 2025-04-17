#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
	i�aret�iler yard�m�yla dizi y�netimi:
	e�er pointer dizinin ba�lang�� adresini tutar ve 4byte ileri giderse dizinin bir di�er indeksine ge�mi� olur. 4byte ge�i� +1 ile sa�lan�r.
	!D�Z�N�N ADI AYNI ZAMANDA D�Z�N�N ADRES� ANLAMINA GEL�R!
*/

int main()
{
	int i;
	int dizi[10];		// dizilerin belirli bir ba�lang�� adresi vard�r ve o ba�lang�� adresinden ilerleyerek devam eder.
	int *ptr1=&dizi[0];
	int *ptr2=dizi;		// dizinin ad� ba�lang�� adresi anlam�na gelir.
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
	
	// POINTER AR�TMET��� 
	int *p=dizi;
	
	printf("%d\n",(*p)++);		// pointer�n g�sterdi�i yerdeki de�eri yazd�r sonra da o de�eri 1 artt�r
	printf("%d\n",*(p++));		// pointer�n g�sterdi�i yerdeki de�eri yazd�r sonra da g�sterdi�in yeri 1 artt�r
	printf("%d\n",*(++p));		// �nce pointer�n g�sterdi�i yeri 1 artt�r sonra da oradaki de�eri yazd�r
	printf("%d\n",++(*p));		// �nce pointer�n g�sterdi�i yerdeki de�eri 1 artt�r sonra da o de�eri yazd�r
	
	return 0;
}
