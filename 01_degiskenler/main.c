// Deðiþkenler bellekte uygun adrese deðer atamamýzý saðlayan ifadelerdir

// ÝSÝMLENDÝRME KURALLARI
/*
int sayi1;		// tanýmlanan ifade tekrardan tanýmlanamaz
int sayý;		// türkçe karakter kullanýlamaz
int sayi 2;		// boþluk karakteri isimlendirmede kullanýlamaz
int 2sayi;		// deðiþken sayýyla baþlayamaz
int for;		// keyword deðiþken ismi olarak kullanýlamaz
*/

#include <stdio.h>

int main()
{
	int sayi1, sayi2 = 5;				// tam sayýlarý tutmayý saðlayan       keyword => int
	float sayi3 = 7.2;					// ondalýklý sayýlarý tutmayý saðlayan keyword => float
	double sayi4 = 1.9;					// ondalýklý sayýlarý tutmayý saðlayan keyword => double *float veri tipine göre deðer aralýðý daha fazladýr*
	char karakter = 'x';				// karakterleri tutmayý saðlayan 	   keyword => char
	
	sayi1 = 2;
	
	printf("%d %i %.2f %.2lf %c\n", sayi1, sayi2, sayi3, sayi4, karakter);
	// oluþturulan deðiþkenlerin bellekteki adreslerinin hexadecimal olarak yazdýrýlmasý
	printf("%#X %#X %#X %#X %#X\n", &sayi1, &sayi2, &sayi3, &sayi4, &karakter);				
	
	return 0;
}
