#include <stdio.h>
#include <math.h>

int main()
{
	int i,j;
	for(i = 0; i < 10; i++)		// sat�r : 10
	{
		for(j = 0; j < 10; j++)	// s�tun : 10
		{
			printf("Merhaba ");
		}
		printf("\n");
	}							// 100 kere i�lem uyguland� (sat�r * s�tun = 100)
	
	
	// faktoriyel hesaplama
	int sayi, faktoriyelSonuc = 1;		// sayi = 0 => faktoriyelSonuc = 1
	
	printf("Lutfen faktoriyel hesaplamasi yapilacak olan sayiyi giriniz : ");
	scanf("%d",&sayi);

	
	for(i = sayi; i > 0; i--)
	{
		faktoriyelSonuc *= i;
	}
	
	printf("%d! = %d\n", sayi,faktoriyelSonuc);
	
	// �stler tablosu
	
	for(i = 2; i <= 10; i++)
	{
		for(j = 1; j < 10; j++)
		{
			int sonuc = pow(i, j);
			printf("%d ", sonuc);
		}
		printf("\n");
	}
	
	return 0;
}
