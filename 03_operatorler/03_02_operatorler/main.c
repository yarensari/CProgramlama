#include <stdio.h>

int main()
{
	// MANTIKSAL (�L��K�SEL) OPERAT�RLER
	// sorgu sonucu ya 0 ya da 1 olabilir. e�er 0 => sorgu sonucu yanl��, 1 => sorgu sonucu do�ru
	int sayi1 = 25, sayi2 = 32;
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 > sayi2);							// b�y�kl�k sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 < sayi2);							// k���kl�k sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 == sayi2);							// e�ittir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 != sayi2);							// e�it de�ildir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 >= sayi2);							// b�y�k e�ittir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 <= sayi2);							// k���k e�ittir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, !(sayi1 == sayi2));						// �nlem her �eyi terse �evirir
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, (sayi1!=sayi2) && (sayi1<sayi2));			// & (and) operat�r�	
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, (sayi1==sayi2) || (sayi1>sayi2));			// | (or) operat�r�	
	
	// B�T D�ZEY�NDEK� MANTIKSAL OPERAT�RLER
	int bitDuzeyi  = 64;											// 0100 0000
	int bitDuzeyi2 = 32;											// 0010 0000
	
	printf("and operator sonuc : %d\n", bitDuzeyi & bitDuzeyi2); 	// 0100 0000 & 0010 0000 = 0000 0000 
	printf("or operator sonuc  : %d\n", bitDuzeyi | bitDuzeyi2);	// 0100 0000 | 0010 0000 = 0110 0000
	
	return 0;
}
