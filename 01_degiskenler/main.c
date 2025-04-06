// De�i�kenler bellekte uygun adrese de�er atamam�z� sa�layan ifadelerdir

// �S�MLEND�RME KURALLARI
/*
int sayi1;		// tan�mlanan ifade tekrardan tan�mlanamaz
int say�;		// t�rk�e karakter kullan�lamaz
int sayi 2;		// bo�luk karakteri isimlendirmede kullan�lamaz
int 2sayi;		// de�i�ken say�yla ba�layamaz
int for;		// keyword de�i�ken ismi olarak kullan�lamaz
*/

#include <stdio.h>

int main()
{
	int sayi1, sayi2 = 5;				// tam say�lar� tutmay� sa�layan       keyword => int
	float sayi3 = 7.2;					// ondal�kl� say�lar� tutmay� sa�layan keyword => float
	double sayi4 = 1.9;					// ondal�kl� say�lar� tutmay� sa�layan keyword => double *float veri tipine g�re de�er aral��� daha fazlad�r*
	char karakter = 'x';				// karakterleri tutmay� sa�layan 	   keyword => char
	
	sayi1 = 2;
	
	printf("%d %i %.2f %.2lf %c\n", sayi1, sayi2, sayi3, sayi4, karakter);
	// olu�turulan de�i�kenlerin bellekteki adreslerinin hexadecimal olarak yazd�r�lmas�
	printf("%#X %#X %#X %#X %#X\n", &sayi1, &sayi2, &sayi3, &sayi4, &karakter);				
	
	return 0;
}
