#include <stdio.h>

int main()
{
	int sayi = 0;				// case'leri tetikleyecek deðer
	
	switch(sayi)
	{
		case 0:
			printf("0\n");
			break;				// break verilmezse altýndaki kod bloklarý da break görene kadar çalýþýr.
		case 1:
			printf("1\n");
			break;
		case 2:
			printf("2\n");
			break;
		case 3:
			printf("3\n");
			break;
		default:
			printf("Yanlis bir deger girdiniz.\n");
	}
	
	printf("***************************************\n");
	
	// Hesap Makinesi
	float sayi1, sayi2, sonuc;
	char islem;
	
	printf("Lutfen sayi islem sayi siralamasiyla (arada bosluk birakmadan) hesaplamak istediginiz islemi giriniz: ");
	fflush(stdin);
	scanf("%f%c%f", &sayi1, &islem, &sayi2);
	
	switch(islem)
	{
		case '+':
			sonuc = sayi1 + sayi2;
			break;
		case '-':
			sonuc = sayi1 - sayi2;
			break;
		case '*':
			sonuc = sayi1 * sayi2;
			break;
		case '/':
			sonuc = sayi1 / sayi2;
			break;
		case '%':
			sonuc = (int)sayi1 % (int)sayi2;			// float deðiþkeni kabul etmiyor. dolayýsýyla typecast yapýlmalý.
			break;
		default:
			printf("Yanlis giris yaptiniz!");
			return 0;
	}
	
	printf("%.1f%c%.1f = %.3f", sayi1, islem, sayi2, sonuc);
	
	printf("\n***************************************\n");
	
	// break keywordünün avantajý
	int haftaninGunu;
	printf("Lutfen 1 ile 7 arasinda bir gun degeri giriniz: ");
	scanf("%d", &haftaninGunu);
	
	switch(haftaninGunu)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("Haftaici!\n");
			break;
		case 6:
		case 7:
			printf("Haftasonu!\n");
			break;
		default:
			printf("Yanlis bir giris yaptiniz!\n");
	}
	
	return 0;
}
