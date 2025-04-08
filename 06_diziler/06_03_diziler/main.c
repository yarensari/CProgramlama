#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	// �rnek - 1 : Sat�r ve s�tunda yer alan de�erlerin toplam� bulunacak.
	/*
		00 01 02 03 04
		10 11 12 13 14
		20 21 22 23 24
		30 31 32 33 34
		40 41 42 43 44
	*/
	int matris[5][5],i,j,satirToplami,sutunToplami;
	srand(time(NULL));
	printf("Matris:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			matris[i][j]=rand()%10;
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<5;i++)
	{
		satirToplami=0;
		sutunToplami=0;
		for(j=0;j<5;j++)
		{												
			satirToplami+=matris[i][j];		// ilk sat�r: 00 01 02 03 04 s�tun de�erleri sat�r� taramal�	
			sutunToplami+=matris[j][i];		// ilk s�tun: 00 10 20 30 40 sat�r de�erleri s�tunu taramal�	
		}	
		
		printf("%d satirinin toplami:%d\t",i+1,satirToplami);
		printf("%d sutununun toplami:%d\n",i+1,sutunToplami);	 											
	}
	
	printf("--------------------------------------------------------------\n");
	
	// �rnek - 2 : Random bir �ekilde iki adet matris olu�turulacak. Olu�turulan bu matrislerin toplam�yla yeni bir matris olu�turulacak.
	int ilkMatris[5][5],ikinciMatris[5][5],toplamMatris[5][5];
	
	printf("Ilk matris:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			ilkMatris[i][j]=rand()%10;
			printf("%d\t",ilkMatris[i][j]);
		}
		printf("\n");
	}
	
	printf("Ikinci matris:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			ikinciMatris[i][j]=rand()%10;
			printf("%d\t",ikinciMatris[i][j]);
		}
		printf("\n");
	}
	
	printf("Toplam matris:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			toplamMatris[i][j]=ilkMatris[i][j]+ikinciMatris[i][j];
			printf("%d\t",toplamMatris[i][j]);
		}
		printf("\n");
	}
	
	printf("--------------------------------------------------------------\n");
	
	// �rnek - 3 : Random bir �ekilde 2 boyutlu matris olu�turulacak ve bu matrisin transpozu al�nacak.
	/*
		00 01 02 03 04				00 01 02 03 04 ile 00 10 20 30 40 yer de�i�tirecek. 
		10 11 12 13 14				10 11 12 13 14 ile 01 11 21 31 41 yer de�i�tirecek.
		20 21 22 23 24 
		30 31 32 33 34
		40 41 42 43 44
	*/
	int transpozMatris[5][5];
	
	printf("Matris:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			matris[i][j]=rand()%10;
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	
	printf("Matrisin transpozu:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			transpozMatris[i][j]=matris[j][i];
			printf("%d ",transpozMatris[i][j]);
		}
		printf("\n");
	}

	printf("--------------------------------------------------------------\n");
	// �rnek - 4 : Random bir �ekilde tek boyutlu dizi olu�turulacak. Kullan�c�dan al�nan de�erin o dizide olup olmad��� do�rusal arama metoduyla kontrol edilecek.
	int dizi[10],arananDeger,bulunduMu=0;
	
	printf("Dizi:\n");
	for(i=0;i<10;i++)
	{
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	
	printf("\nLutfen aranacak olan sayiyi giriniz:");
	scanf("%d",&arananDeger);
	
	for(i=0;i<10;i++)
	{
		if(dizi[i]==arananDeger)
		{
			bulunduMu=1;
			break;
		}
	}
	
	if(bulunduMu)
		printf("Aranan deger bulundu.\n");
	else
		printf("Aranan deger bulunamadi\n");
	
	printf("--------------------------------------------------------------\n");
	
	// �rnek - 5 : Araya sokma algoritmas� kullan�larak random bir �ekilde olu�turulan dizi k���kten b�y��e s�ralanacak.
	int eleman;
	
	printf("Dizi:\n");
	for(i=0;i<10;i++)
	{
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	/* 
		2 3 10 9 1 57 26 25 32 16  : eleman 2
		2 3 9 10 1 57 26 25 32 16 : eleman 9
		2 2 3 9 10 57 26 25 32 16 : eleman 1
	*/
	for(i=1;i<10;i++)
	{
		eleman=dizi[i];
		for(j=i-1;j>=0 && eleman<dizi[j];j--)	// eleman=1 => i=4,j=3, : j=2 : j=1 : j=0 : j=-1
		{
			dizi[j+1]=dizi[j];
		}
		dizi[j+1]=eleman;
	}
	
	printf("\nSirali dizi:\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",dizi[i]);
	}
	
	printf("\n--------------------------------------------------------------\n");
	
	// �rnek - 6 : Kabarc�k s�ralama algoritmas� kullan�larak random bir �ekilde olu�turulan dizi k���kten b�y��e do�ru s�ralanacak.
	/*
		77 45 63 56 93 31 96 78 42 5
		45 77 63 56 93 31 96 78 42 5	j=0
		45 63 77 56 93 31 96 78 42 5	j=1
		45 63 56 77 93 31 96 78 42 5	j=2
		45 63 56 77 93 31 96 78 42 5	j=3
		45 63 56 77 31 93 96 78 42 5	j=4
		45 63 56 77 31 93 96 78 42 5	j=5
		45 63 56 77 31 93 78 96 42 5	j=6
		45 63 56 77 31 93 78 42 96 5	j=7
		45 63 56 77 31 93 78 42 5  96	j=8
		
		45 63 56 77 31 93 78 42 5  96	j=0
		45 56 63 77 31 93 78 42 5  96	j=1
		45 56 63 77 31 93 78 42 5  96	j=2
		45 56 63 31 77 93 78 42 5  96	j=3
		45 56 63 31 77 93 78 42 5  96	j=4
		45 56 63 31 77 78 93 42 5  96	j=5
		45 56 63 31 77 78 42 93 5  96	j=6
		45 56 63 31 77 78 42 5  93 96	j=7
		
		45 56 63 31 77 78 42 5  93 96	j=0
		45 56 63 31 77 78 42 5  93 96	j=1
		45 56 31 63 77 78 42 5  93 96	j=2
		45 56 31 63 77 78 42 5  93 96	j=3
		45 56 31 63 77 78 42 5  93 96	j=4
		45 56 31 63 77 42 78 5  93 96	j=5
		45 56 31 63 77 42 5  78 93 96	j=6
		.
		.
		.
	*/
	printf("Dizi\n");
	for(i=0;i<10;i++)
	{
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(dizi[j]>dizi[j+1])
			{
				int geciciSayi=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=geciciSayi;
			}
		}
	}
	
	printf("\nSirali dizi:\n");
	for(i=0;i<10;i++)
		printf("%d ",dizi[i]);
	
	return 0;
}
