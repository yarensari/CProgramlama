#include <stdio.h>

int main()
{
	// MANTIKSAL (ÝLÝÞKÝSEL) OPERATÖRLER
	// sorgu sonucu ya 0 ya da 1 olabilir. eðer 0 => sorgu sonucu yanlýþ, 1 => sorgu sonucu doðru
	int sayi1 = 25, sayi2 = 32;
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 > sayi2);							// büyüklük sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 < sayi2);							// küçüklük sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 == sayi2);							// eþittir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 != sayi2);							// eþit deðildir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 >= sayi2);							// büyük eþittir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, sayi1 <= sayi2);							// küçük eþittir sorgusu
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, !(sayi1 == sayi2));						// ünlem her þeyi terse çevirir
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, (sayi1!=sayi2) && (sayi1<sayi2));			// & (and) operatörü	
	printf("sayi1 = %d, sayi2 = %d, sorgu sonucu(0 veya 1) = %d\n", sayi1, sayi2, (sayi1==sayi2) || (sayi1>sayi2));			// | (or) operatörü	
	
	// BÝT DÜZEYÝNDEKÝ MANTIKSAL OPERATÖRLER
	int bitDuzeyi  = 64;											// 0100 0000
	int bitDuzeyi2 = 32;											// 0010 0000
	
	printf("and operator sonuc : %d\n", bitDuzeyi & bitDuzeyi2); 	// 0100 0000 & 0010 0000 = 0000 0000 
	printf("or operator sonuc  : %d\n", bitDuzeyi | bitDuzeyi2);	// 0100 0000 | 0010 0000 = 0110 0000
	
	return 0;
}
