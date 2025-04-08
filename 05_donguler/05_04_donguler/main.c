#include <stdio.h>
#include <math.h>

int main()
{
	// SORU - 1 : * i�areti kullanarak �ekiller olu�tur. 
	/*
		a : 
		*
		**
		***
		****
		*****
		******
	*/
	printf("SORU - 1 : a\n");
	
	int i, j, piramitLimit;
	
	printf("Lutfen piramit limitini giriniz: ");
	scanf("%d", &piramitLimit);
	
	for(i = 1; i <= piramitLimit; i++)
	{
		for(j = i; j > 0; j--)
		{
			printf("*"); 
		}
		printf("\n");
	}
	
	printf("---------------------------------\n");
	
	/*
		b :
		******
		*****
		****
		***
		**
		*
	*/	
	printf("SORU - 2 : b\n");
	
	printf("Lutfen piramit limitini giriniz: ");
	scanf("%d", &piramitLimit);
	
	for(i = piramitLimit; i > 0; i--)
	{
		for(j = i; j > 0; j--)
		{
			printf("*");		
		}	
		printf("\n");
	}
	
	printf("---------------------------------\n");
	
	/*
		c:
		***********
		*********
		*******
		*****
		***
		**
		*
	*/	
	printf("SORU - 2 : c\n");
	
	printf("Lutfen piramit limitini giriniz: ");
	scanf("%d", &piramitLimit);
	
	for(i = piramitLimit; i > 0; i-=2)
	{
		for(j = i; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	
	printf("---------------------------------\n");
	
	/*
		d:
		     *1				5 tane sol      *      5 tane sa�		(11-1)/2 = 5
		    ***3			4 tane sol     ***     4 tane sa�		(11-3)/2 = 4
	  	   *****5			3 tane sol    *****    3 tane sa�		(11-5)/2 = 3
		  *******7			2 tane sol   *******   2 tane sa�			  .
		 *********9			1 tane sol  *********  1 tane sa�		 	  .	
		***********11		0 tane sol *********** 0 tane sa�			  .			
	*/
	printf("SORU - 1 : d\n");
	
	printf("Lutfen piramit limitini giriniz: ");
	scanf("%d", &piramitLimit);	
	
	for(i = 1; i <= piramitLimit; i+=2)
	{
		for(j = (piramitLimit-i)/2; j >= 0; j--)
		{
			printf(" ");
		}
		for(j = i; j > 0; j--)
		{

			printf("*");
		}
		for(j = (piramitLimit-i)/2; j >= 0; j--)
		{
			printf(" ");
		}		
		printf("\n");
	}
	
	printf("---------------------------------\n");
	
	// SORU - 2: �ifre sorgulamas� yap�lacak. Kullan�c�dan d�ng� kullan�larak �ifre karakterleri al�nacak. Bu karakterlerde b�y�k ve k���k harf
	// kullan�lmas� gerekmekte. Say� da kullan�lmal� ve �ifrenin karakter say�s� 8 ile 16 aras�nda olmal�.
	printf("SORU - 2\n");
	
	char sifre[16], gelenKarakter;		
	int buyukHarf = 0, kucukHarf = 0, karakterSayisi = 0, sayiSorgu = 0; 
	i = 0;
	
	printf("Lutfen sifrenizi giriniz: ");
	fflush(stdin);													// bir �nceki soruda kalan scanf'in '\n' karakter buffer'�n temizlenmesiyle silinir.
	do{
		gelenKarakter = getchar();
		sifre[i] = gelenKarakter;
		if(buyukHarf == 0)
		{
			if(gelenKarakter >= 'A' && gelenKarakter <= 'Z')		// b�y�k harf kullan�ld� m�? (isupper da kullan�labilir)
				buyukHarf = 1;										// b�y�k harf kullan�ld�.	
		}		
		if(kucukHarf == 0)
		{
			if(gelenKarakter >= 'a' && gelenKarakter <= 'z')		// k���k harf kullan�ld� m�? (islower da kullan�labilir)
			kucukHarf = 1;										    // k���k harf kullan�ld�.
		}		
		if(sayiSorgu == 0)
		{
			if(gelenKarakter >= '0' && gelenKarakter <= '9')		// say� kullan�ld� m�? (isdigit de kullan�labilir)
			sayiSorgu = 1;											// say� kullan�ld�.
		}		
		karakterSayisi++;
		i++;
	}while(gelenKarakter != '\n');
	
	if(buyukHarf)
	{
		if(kucukHarf)
		{
			if(sayiSorgu)
			{
				if(i >= 8 && i <= 16)
				{
					printf("Sifreniz basariyla olusturuldu!\n");
					printf("Olusturulan sifre: ");
					for(j = 0; j <= i; j++)
						printf("%c", sifre[j]);
				}
				else
					printf("Sifre 8 ile 16 karakter uzunlugunda olmalidir. Sifre olusturulamadi.\n");
			}
			else
				printf("Sifrede en az bir sayi karakteri yer almalidir. Sifre olusturulamadi.\n");
		}
		else
			printf("Sifrede en az bir kucuk harf yer almalidir. Sifre Olusturulamadi.\n");
	}
	else
		printf("Sifrede en az bir buyuk harf yer almalidir. Sifre olusturulamadi.\n");
	
	printf("---------------------------------\n");
	
	// SORU - 3 : Kullan�c�dan bir say� al�nacak ve o say�n�n m�kemmel say� olup olmad��� kontrol edilecek. Ayn� zaman 1 ile 1000 aras�ndaki b�t�n
	// m�kemmel say�lar yazd�r�lacak.
	// m�kemmel say� : kendisi hari� b�t�n pozitif tam say� b�lenlerinin toplam� kendisine e�it olan say�d�r.
	// 6 say�s� : pozitif b�lenler = 1, 2, 3 : 1 + 2 + 3 = 6
	printf("SORU - 3\n");
		
	int gelenSayi, bolenlerinToplami = 0;
	
	printf("Lutfen mukemmel sayi sorgusu yapilacak sayiyi giriniz: ");
	scanf("%d", &gelenSayi);
	
	for(i = 1; i < gelenSayi; i++)
	{
		if(gelenSayi % i == 0)
			bolenlerinToplami += i;	 
	} 
	
	if(gelenSayi == bolenlerinToplami)
		printf("Girdiginiz sayi mukemmel bir sayidir!\n");
	else
		printf("Girdiginiz sayi mukemmel sayi degildir.\n");
		
	// 1 ile 1000 aras�ndaki m�kemmel say�lar
	printf("1 ile 1000 arasinda yer alan mukemmel sayilar:\n");
	for(i = 1; i <= 1000; i++)
	{
		bolenlerinToplami = 0;
		for(j = 1; j < i; j++)
		{
			if(i % j == 0)
				bolenlerinToplami += j;
		}
		if(i == bolenlerinToplami)
			printf("%d sayisi mukemmel bir sayidir.\n", i);
	}
	
	printf("---------------------------------\n");
	
	// SORU - 4 : Kullan�c�dan bir de�er aral��� al�nacak ve o aral�kta yer alan b�t�n asal say�lar yazd�r�lacak.	
	printf("SORU - 4\n");
	
	int bolunduMu = 0, altLimit, ustLimit;
	printf("Lutfen asal sayi sorgusu yapilacak limitler giriniz: ");
	scanf("%d%d", &altLimit, &ustLimit);
	
	if(altLimit > ustLimit)
	{
		int temp;
		temp = altLimit;		
		altLimit = ustLimit;	
		ustLimit = temp;		
	}
	
	for(i = altLimit; i <= ustLimit; i++)			
	{
		if(i == 1)						 // 1 de�eri gelirse sorgulamadan ge�
			continue;
		bolunduMu = 0;
		for(j = (i - 1); j > 1; j--)	// 2 de�eri buraya girmez ve direkt bolunduMu = 0 olarak kal�r.			
		{
			if(i % j == 0)	
			{
				bolunduMu = 1;
				break;					// geriye kalan� kontrol etmeye gerek yok!
			} 	
				
		}
		if(bolunduMu == 0)
			printf("%d sayisi asaldir.\n", i);
	}
	
	printf("---------------------------------\n");
	
	// SORU - 5 : Kullan�c�dan al�nan 3 basamakl� say�n�n armstrong olup olmad��� sorgulanacak. Ekstra olarak 1 ile 1000 aras�ndaki Armstrong say�lar yazd�r�lacak.
	// Armstrong Say� : 371 => 3^3 + 7^3 + 1^3 = 371. Basamaklar�n�n k�p toplam� kendisini veren say�lara Armstrong say�lar denir 	
	printf("SORU - 5\n");
	
	int sorgulanacakSayi, basamak, kuplerinToplami = 0, geciciSayi;
	printf("Lutfen armstrong sorgusu yapilacak olan sayiyi giriniz: ");
	scanf("%d", &sorgulanacakSayi);
	geciciSayi = sorgulanacakSayi;
	
	while(geciciSayi != 0)
	{
		basamak = geciciSayi % 10;
		kuplerinToplami += pow(basamak, 3);
		geciciSayi /= 10;
	}
	
	if(kuplerinToplami == sorgulanacakSayi)
		printf("%d sayisi armstrong bir sayidir!\n", sorgulanacakSayi);
	else 
		printf("%d sayisi armstrong sayi degildir.\n", sorgulanacakSayi);
	
	// 1 ile 1000 aras�ndaki armstrong say�lar
	printf("1 ile 1000 arasinda yer alan armstrong sayilar:\n");
	for(i = 1; i < 1000; i++)
	{
		kuplerinToplami = 0;
		geciciSayi = i;
		while(geciciSayi != 0)
		{
			basamak = geciciSayi % 10;
			kuplerinToplami += pow(basamak, 3);
			geciciSayi /= 10;
		}
		if(i == kuplerinToplami)
			printf("%d sayisi armstrong bir sayidir!\n", i);
	}
	
	printf("---------------------------------\n");
	
	// SORU - 6 : Soru 3'te yap�lan m�kemmel say� sorgusunu d�ng� �art� kullanmadan sadece break ve continue ile yap�lacak
	printf("SORU - 6:\n");
	
	printf("Lutfen mukemmel sayi sorgusu yapilacak sayiyi giriniz: ");
	scanf("%d", &gelenSayi);

	i = 1;
	bolenlerinToplami = 0;
	while(1)
	{
		if(gelenSayi == i)
		{
			if(bolenlerinToplami == gelenSayi)
				printf("%d sayisi mukemmel bir sayidir!", gelenSayi);
			else
				printf("%d sayisi mukemmel sayi degildir.", gelenSayi);
			break;
		}
		if(gelenSayi % i == 0)
			bolenlerinToplami += i;
		i++;
	}
	
	return 0;
}
