#include <stdio.h>

int main()
{
	// ARÝTMETÝK OPERATÖRLER
	int sayi1 = 12, sayi2 = 4;									// = atama operatörü
	printf("%d + %d = %d\n", sayi1, sayi2, sayi1 + sayi2);		// + toplama operatörü
	printf("%d - %d = %d\n", sayi1, sayi2, sayi1 - sayi2);		// - çýkarma operatörü
	printf("%d * %d = %d\n", sayi1, sayi2, sayi1 * sayi2);		// * çarpma operatörü
	printf("%d / %d = %d\n", sayi1, sayi2, sayi1 / sayi2);		// / bölme operatörü
	printf("%d %% %d = %d\n", sayi1, sayi2, sayi1 % sayi2);		// % mod alma operatörü
	
	// atama operatörüyle kullanýmý
	int sonuc = 1;
	sonuc *= 2;													// sonuc = sonuc * 2; 
	sonuc *= 3;													// sonuc = sonuc * 3;
	sonuc *= 4;													// sonuc = sonuc * 4;
	printf("Sonuc = %d\n", sonuc);
	
	int i = 5;
	printf("i degeri = %d\n", i);
	printf("i degeri = %d\n", i++);								// i deðerini yazdýr ve sonra arttýr   -5-
	printf("i degeri = %d\n", i);								// arttýrýlmýþ i deðerini yazdýrdýk	   -6-
	printf("i degeri = %d\n", ++i);								// i deðerini önce arttýr sonra yazdýr -7-
	
	// BÝT DÜZEYÝNDE ÝÞLEMLER 
	int bitDuzeyi = 64;
	printf("Sola kaydirilmis sayi = %d\n", bitDuzeyi << 1);		// 2 ile çarpýlýr
	printf("Saga kaydirilmis sayi = %d\n", bitDuzeyi >> 1);		// 2'ye bölünür
	
	return 0;
}
