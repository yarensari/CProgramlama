#include <stdio.h>

int main()
{
	// while : önce sorgulamayý yapar sonra çalýþýr.
	int i = 0; 
	while(i < 0)
	{
		printf("i sayisi %d\n", i);
		i++;
	}
	
	printf("***********************\n");
	
	// do-while : bir kere çalýþýr ve sonra sorgulamayý yapar.
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
			break;			// döngüyü sonlandýr
		
		if((i%2 == 0))
			continue;		// döngünün alt kýsmýnda kalanlarý es geç
			
		printf("i sayisi : %d\n", i);
	}
	
	printf("***********************\n");
	
	// basamak sayýsý bulma
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
