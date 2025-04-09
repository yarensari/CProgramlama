#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// SORU - 1 : rand fonksiyonu kullanýlarak 2 adet iki boyutlu matris oluþturulacak. Oluþturulan bu matrislerin çarpýmýyla yeni bir matris oluþturulacak.
	/*
		1. matrisin satýrýyla 2. matrisin sütunlarý çarpýlýp toplanýr.
		1 2 3	9 2 8		00 01 02		00 = 00 * 00 + 01 * 10 + 02 * 20	satýrlar: 00 01 02 þeklinde sabit
		5 4 1	1 0 8		10 11 12		01 = 00 * 01 + 01 * 11 + 02 * 31	sütunlar: 00 10 20 - 01 11 21 - 02 12 22
		2 3 5	6 4 2		20 21 22		02 = 00 * 02 + 01 * 12 + 01 * 22	çarpýlacak olanlar: (00 01 02) * (00 10 20)
																									(00 01 02) * (01 11 21)
																									(00 01 02) * (02 12 22)
																				satýrlar: 10 11 12 þeklinde sabit
																				sütunlar: 00 10 20 - 01 11 21 - 02 12 22
																				çarpýlacak olanlar: (10 11 12) * (00 10 20)
																									(10 11 12) * (01 11 21)
																									(10 11 12) * (02 12 22)
																				satýrlar: 20 21 22 þeklinde sabit
																				sütunlar: 00 10 20 - 01 11 21 - 02 12 22
																				çarpýlacak olanlar: (20 21 22) * (00 10 20)
																									(20 21 22) * (01 11 21)
																									(20 21 22) * (02 12 22)
	*/
	printf("SORU - 1\n");
	
	int ilkMatris[5][5],ikinciMatris[5][5],carpimMatris[5][5],eleman=0,i,j,k;
	srand(time(NULL));
	
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
	
	printf("Matrislerin carpimi:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<5;k++)
			{
				eleman+=ilkMatris[i][k]*ikinciMatris[k][j];	
			}
			carpimMatris[i][j]=eleman;
			printf("%d\t",carpimMatris[i][j]);
			eleman=0;
		}
		printf("\n");
	}
	
	printf("------------------------------------\n");
	
	// SORU - 2 : Tek boyutlu bir matris oluþturulacak. Kullanýcýdan satýr ve sütun bilgisi alýnarak oluþturulan tek boyutlu matris iki boyutlu matrise dönüþtürülecek.
	printf("SORU - 2\n");
		
	int dizi[12],satir,sutun;
	k=0;
	
	for(i=0;i<12;i++)
	{
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	
	printf("\nLutfen satir ve sutun sayisini sirasiyla giriniz:");
	scanf("%d%d",&satir,&sutun);
	int olusturulanMatris[satir][sutun];
	
	if(satir*sutun!=12)
		printf("Girdiginiz satir ve sutun degerlerinin carpimi 10'a esit degildir. Matris olusturulamiyor.\n");
	else
	{
		for(i=0;i<satir;i++)
		{
			for(j=0;j<sutun;j++)
			{ 
				olusturulanMatris[i][j]=dizi[k];
				k++;
				printf("%d\t",olusturulanMatris[i][j]);
			}
			printf("\n");
		}
	}
	
	printf("------------------------------------\n");
	
	// SORU - 3 : Kullanýcýdan matris oluþturulmasý saðlanacak. Oluþturulan bu matrisin simetrik olup olmadýðý kontrol edilecek.
	/*
		1 2 3 				00'a göre  : 01 ve 10 kontrol edilecek.
		2 1 2				11'e göre  : 02 ve 20 kontrol edilecek. 	
		3 2 1				22'ye göre : 12 ve 21 kontrol edilecek.
	*/
	printf("SORU - 3\n");
	
	printf("Lutfen satir ve sutun sayilarini sirasiyla giriniz:");
	scanf("%d%d",&satir,&sutun);
	int matris[satir][sutun], gelenDeger,simetriMi=1;
	
	printf("Lutfen %d adet matris degerlerini giriniz:\n", satir*sutun);
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
		{
			scanf("%d",&gelenDeger);
			matris[i][j]=gelenDeger;	
			printf("%d ",matris[i][j]);	
		}
		printf("\n");
	}
	
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
		{
			if(i==j)
			{
				if(matris[i][j]!=1)
				{
					simetriMi=0;
					break;
				}
			}else if(i<j)
			{
				if(matris[i][j] != matris[j][i])
				{
					simetriMi=0;
					break;
				}
			}
		}
	}
	
	if(simetriMi)
		printf("Girdiginiz matris simetridir.\n");
	else
		printf("Girdiginiz matris simetri degildir.\n");
		
	printf("------------------------------------\n");
	
	// SORU - 4 : Seçmeli sýralama algoritmasý ile rastgele oluþturulan dizi küçükten büyüðe sýralanacak.
	/*
		Dizideki ilk eleman seçilir ve en küçük eleman olarak kabul edilir. Dizide yer alan bütün elemanlarla ilk eleman karþýlaþtýrýlýr. Aralarýndaki en küçük eleman tespit edilir ve ilk 
		elemana yazýlýr. 
	*/
	printf("SORU - 4:\n");
	
	int randomDizi[10],enKucuk,enKucukIndeks;
	srand(time(NULL));
	
	printf("Sirasiz dizi:\n");
	for(i=0;i<10;i++)
	{
		randomDizi[i]=rand()%10;
		printf("%d ",randomDizi[i]);
	}

	// 8 0 7 8 1 5 5 7 9 5
	printf("\nSirali dizi:\n");
	for(i=0;i<10;i++)
	{																
		enKucuk=randomDizi[i];	
		enKucukIndeks=i;																				
		for(j=i+1;j<10;j++)														
		{
			if(randomDizi[j]<enKucuk)							
			{
				enKucuk=randomDizi[j];	
				enKucukIndeks=j;											
			}
		}
		int gecici=randomDizi[i];															
		randomDizi[i]=randomDizi[enKucukIndeks];						
		randomDizi[enKucukIndeks]=gecici;											
	}
	
	for(i=0;i<10;i++)
		printf("%d ",randomDizi[i]);
		
	printf("\n------------------------------------\n");
	
	// SORU - 5 : Ýkili arama algoritmasýyla dizide yer alan elemanýn olup olmadýðý sorgulanacak
	/*
		ortadaki eleman tespit edilir ve aranan deðere yakýnlýðýný tespit etmek için < > sorgulamasý yapýlýr.
		sorgulama sonucuna göre kontrolün yapýldýðý deðer aralýðý deðiþtirilir.
	*/
	printf("SORU - 5:\n");
	int eb,ek,arananDeger,kontrolEdilenIndeks=0,bulunduMu=0;
	
	printf("Olusturulan dizi: ");
	for(i=0;i<10;i++)
	{
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	
	printf("\nSiralanmis dizi: ");
	for(i=0;i<10;i++)
	{																
		enKucuk=dizi[i];	
		enKucukIndeks=i;																				
		for(j=i+1;j<10;j++)														
		{
			if(dizi[j]<enKucuk)							
			{
				enKucuk=dizi[j];	
				enKucukIndeks=j;											
			}
		}
		int gecici=dizi[i];															
		dizi[i]=dizi[enKucukIndeks];						
		dizi[enKucukIndeks]=gecici;											
	}
	
	for(i=0;i<10;i++)
		printf("%d ",dizi[i]);
	
	printf("\nLutfen aradiginiz degeri girin:");
	scanf("%d",&arananDeger);
	//3 5 5 5 6 7 7 8 9 9 10
	eb=10;
	ek=0;
	while(eb>ek)
	{
		kontrolEdilenIndeks=(eb+ek)/2;			// (10+0)/2=5; 
		if(dizi[kontrolEdilenIndeks]==arananDeger)
		{
			bulunduMu=1;
			printf("Aranan deger bulundu!\n");
			break;
		}
		else if(arananDeger>dizi[kontrolEdilenIndeks])
			ek=kontrolEdilenIndeks+1;			// kontrol edilen yerde aranan deðer bulunamadý. bir sonraki indekse geç ve deðer aralýðýný küçült.
		else
			eb=kontrolEdilenIndeks-1;			// kontrol edilen yerde aranan deðer bulunamadý. bir önceki indekse geç ve deðer aralýðýný büyült.
	}
	
	if(bulunduMu==0)
		printf("Aradiginiz deger dizide bulunamadi.\n");
	
	return 0;
}
