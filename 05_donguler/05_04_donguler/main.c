#include <stdio.h>
#include <math.h>

int main()
{
	// SORU - 1 : * iþareti kullanarak þekiller oluþtur. 
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
		     *1				5 tane sol      *      5 tane sað		(11-1)/2 = 5
		    ***3			4 tane sol     ***     4 tane sað		(11-3)/2 = 4
	  	   *****5			3 tane sol    *****    3 tane sað		(11-5)/2 = 3
		  *******7			2 tane sol   *******   2 tane sað			  .
		 *********9			1 tane sol  *********  1 tane sað		 	  .	
		***********11		0 tane sol *********** 0 tane sað			  .			
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
	
	// SORU - 2: Þifre sorgulamasý yapýlacak. Kullanýcýdan döngü kullanýlarak þifre karakterleri alýnacak. Bu karakterlerde büyük ve küçük harf
	// kullanýlmasý gerekmekte. Sayý da kullanýlmalý ve þifrenin karakter sayýsý 8 ile 16 arasýnda olmalý.
	printf("SORU - 2\n");
	
	char sifre[16], gelenKarakter;		
	int buyukHarf = 0, kucukHarf = 0, karakterSayisi = 0, sayiSorgu = 0; 
	i = 0;
	
	printf("Lutfen sifrenizi giriniz: ");
	fflush(stdin);													// bir önceki soruda kalan scanf'in '\n' karakter buffer'ýn temizlenmesiyle silinir.
	do{
		gelenKarakter = getchar();
		sifre[i] = gelenKarakter;
		if(buyukHarf == 0)
		{
			if(gelenKarakter >= 'A' && gelenKarakter <= 'Z')		// büyük harf kullanýldý mý? (isupper da kullanýlabilir)
				buyukHarf = 1;										// büyük harf kullanýldý.	
		}		
		if(kucukHarf == 0)
		{
			if(gelenKarakter >= 'a' && gelenKarakter <= 'z')		// küçük harf kullanýldý mý? (islower da kullanýlabilir)
			kucukHarf = 1;										    // küçük harf kullanýldý.
		}		
		if(sayiSorgu == 0)
		{
			if(gelenKarakter >= '0' && gelenKarakter <= '9')		// sayý kullanýldý mý? (isdigit de kullanýlabilir)
			sayiSorgu = 1;											// sayý kullanýldý.
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
	
	// SORU - 3 : Kullanýcýdan bir sayý alýnacak ve o sayýnýn mükemmel sayý olup olmadýðý kontrol edilecek. Ayný zaman 1 ile 1000 arasýndaki bütün
	// mükemmel sayýlar yazdýrýlacak.
	// mükemmel sayý : kendisi hariç bütün pozitif tam sayý bölenlerinin toplamý kendisine eþit olan sayýdýr.
	// 6 sayýsý : pozitif bölenler = 1, 2, 3 : 1 + 2 + 3 = 6
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
		
	// 1 ile 1000 arasýndaki mükemmel sayýlar
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
	
	// SORU - 4 : Kullanýcýdan bir deðer aralýðý alýnacak ve o aralýkta yer alan bütün asal sayýlar yazdýrýlacak.	
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
		if(i == 1)						 // 1 deðeri gelirse sorgulamadan geç
			continue;
		bolunduMu = 0;
		for(j = (i - 1); j > 1; j--)	// 2 deðeri buraya girmez ve direkt bolunduMu = 0 olarak kalýr.			
		{
			if(i % j == 0)	
			{
				bolunduMu = 1;
				break;					// geriye kalaný kontrol etmeye gerek yok!
			} 	
				
		}
		if(bolunduMu == 0)
			printf("%d sayisi asaldir.\n", i);
	}
	
	printf("---------------------------------\n");
	
	// SORU - 5 : Kullanýcýdan alýnan 3 basamaklý sayýnýn armstrong olup olmadýðý sorgulanacak. Ekstra olarak 1 ile 1000 arasýndaki Armstrong sayýlar yazdýrýlacak.
	// Armstrong Sayý : 371 => 3^3 + 7^3 + 1^3 = 371. Basamaklarýnýn küp toplamý kendisini veren sayýlara Armstrong sayýlar denir 	
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
	
	// 1 ile 1000 arasýndaki armstrong sayýlar
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
	
	// SORU - 6 : Soru 3'te yapýlan mükemmel sayý sorgusunu döngü þartý kullanmadan sadece break ve continue ile yapýlacak
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
