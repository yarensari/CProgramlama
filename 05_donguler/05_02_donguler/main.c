#include <stdio.h>

int main()
{
	// while : �nce sorgulamay� yapar sonra �al���r.
	int i = 0; 
	while(i < 0)
	{
		printf("i sayisi %d\n", i);
		i++;
	}
	
	printf("***********************\n");
	
	// do-while : bir kere �al���r ve sonra sorgulamay� yapar.
	do{
		printf("i sayisi %d\n", i);
		i++;
	}while(i < 0);
	
	printf("***********************\n");
	
	i = 0;
	while(1)
	{
		i++;
		if(10 == i)
			break;			// d�ng�y� sonland�r
		
		if((i%2 == 0))
			continue;		// d�ng�n�n alt k�sm�nda kalanlar� es ge�
			
		printf("i sayisi : %d\n", i);
	}
	
	printf("***********************\n");
	
	// basamak say�s� bulma
	int sayi, geciciSayi, basamak = 0;
	printf("Lutfen basamak hesabi yapilacak olan sayiyi giriniz: ");
	scanf("%d", &sayi);
	geciciSayi = sayi;
	while(geciciSayi != 0)
	{
		geciciSayi /= 10;
		basamak++;			
	}
	
	printf("%d sayisi %d basamaklidir.\n", sayi, basamak);
	return 0;
}
