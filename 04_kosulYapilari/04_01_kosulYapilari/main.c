#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// 0'dan farklý olan her deðer doðru olarak kabul edilir
	if(0)
		printf("if bloguna girdi");
	else if(192)
		printf("else if bloguna girdi");
	else
		printf("else bloguna girdi");
		
	printf("\n*********************************\n");
	
	int sayi1, sayi2;
	srand(time(NULL));			// srand fonksiyonu sayesinde program her çalýþtýðýnda rand fonksiyonunun farklý deðerler üretilmesi saðlanýr.
	sayi1 = rand() % 100;		// rand fonksiyonundan üretilen deðerini 100'e göre modu alýnarak 0 ile 100 arasýnda sayý üretmesi saðlanýr.
	sayi2 = rand() % 100;
	
	printf("sayi1 = %d, sayi2 = %d\n", sayi1, sayi2);
	
	if(sayi1 < sayi2)
		printf("%d degeri %d degerinden kucuktur.", sayi1, sayi2);
	else if(sayi1 == sayi2)
		printf("%d degeri %d degerine esittir.", sayi1, sayi2);
	else
		printf("%d degeri %d degerinden buyuktur.", sayi1, sayi2);
		
	printf("\n*********************************\n");
		
	int sayi;
	sayi = rand()%1000;			// 0 ile 1000 arasýnda sayý üretilir
	printf("Olusturulan sayi : %d\n", sayi);
	
	if(sayi % 2 == 0)
		printf("%d sayisi cifttir.", sayi);
	else
		printf("%d sayisi tektir.", sayi);
	
	printf("\n*********************************\n");
	
	float number1, number2;
	float result;
	char _operator;
	
	printf("Lutfen hesaplamasi yapilacak sayilari sirasiyla giriniz: ");
	scanf("%f%f", &number1, &number2);
	
	printf("Lutfen yapilacak islemi giriniz(+, -, *, /): ");
	fflush(stdin);			// buffer temizlenir! buffer temizlenmediði zaman deðeri almadan direkt geçebilir.
	scanf("%c", &_operator);
	
	if(_operator == '+')
		result = number1 + number2;
	else if(_operator == '-')
		result = number1 - number2;
	else if(_operator == '*')
		result = number1 * number2;
	else if(_operator == '/')
		result = number1 / number2;
	else 
	{
		printf("Tanimsiz bir islem girisi yaptiniz!");
		return 0;
	}
		
	printf("%.1f %c %.1f = %.2f", number1, _operator, number2, result);
	
	return 0;
}
