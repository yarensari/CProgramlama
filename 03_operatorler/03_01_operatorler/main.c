#include <stdio.h>

int main()
{
	// AR�TMET�K OPERAT�RLER
	int sayi1 = 12, sayi2 = 4;									// = atama operat�r�
	printf("%d + %d = %d\n", sayi1, sayi2, sayi1 + sayi2);		// + toplama operat�r�
	printf("%d - %d = %d\n", sayi1, sayi2, sayi1 - sayi2);		// - ��karma operat�r�
	printf("%d * %d = %d\n", sayi1, sayi2, sayi1 * sayi2);		// * �arpma operat�r�
	printf("%d / %d = %d\n", sayi1, sayi2, sayi1 / sayi2);		// / b�lme operat�r�
	printf("%d %% %d = %d\n", sayi1, sayi2, sayi1 % sayi2);		// % mod alma operat�r�
	
	// atama operat�r�yle kullan�m�
	int sonuc = 1;
	sonuc *= 2;													// sonuc = sonuc * 2; 
	sonuc *= 3;													// sonuc = sonuc * 3;
	sonuc *= 4;													// sonuc = sonuc * 4;
	printf("Sonuc = %d\n", sonuc);
	
	int i = 5;
	printf("i degeri = %d\n", i);
	printf("i degeri = %d\n", i++);								// i de�erini yazd�r ve sonra artt�r   -5-
	printf("i degeri = %d\n", i);								// artt�r�lm�� i de�erini yazd�rd�k	   -6-
	printf("i degeri = %d\n", ++i);								// i de�erini �nce artt�r sonra yazd�r -7-
	
	// B�T D�ZEY�NDE ��LEMLER 
	int bitDuzeyi = 64;
	printf("Sola kaydirilmis sayi = %d\n", bitDuzeyi << 1);		// 2 ile �arp�l�r
	printf("Saga kaydirilmis sayi = %d\n", bitDuzeyi >> 1);		// 2'ye b�l�n�r
	
	return 0;
}
