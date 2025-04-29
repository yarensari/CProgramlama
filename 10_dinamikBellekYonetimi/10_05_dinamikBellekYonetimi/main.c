#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ORNEK-1 FONKSIYONLAR
void diziyiOlustur(int *,int);
void diziyiYazdir(int *,int);
void diziyiSirala(int *,int);

//ORNEK-2 FONKSIYONLAR
void ikiliArama(int *,int,int);

//ORNEK-3 FONKSIYONLAR
void matrisiOlustur(int **,int,int);
void matrisiYazdir(int **,int,int);
void matrisleriTopla(int **,int **,int **,int,int);

//ORNEK-4 FONKSIYONLAR
void birimMatrisiOlustur(int ***,int,int);

//ORNEK-5 FONKSIYONLAR
void transpozAl(int ***,int **,int,int);

//GENEL FONKSIYON
void alaniGeriVer(int ***,int);

int main()
{
	//ORNEK-1:Random bir dizi olustur ve bu diziyi dinamik bellekle yonet. dizinin degerlerini pointer mantigini kullanarak yerlestir. pointer mantigi kullanarak secmeli siralama algoritmasini uygula.
	puts("ORNEK-1:");
	
	int elemanSayisi,arananDeger;
	puts("Lutfen olusturulacak olan dizinin eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	int *dizi=(int *)malloc(sizeof(int)*elemanSayisi);	//eleman sayisina gore bellekte yer ayrildi.
	
	diziyiOlustur(dizi,elemanSayisi);
	puts("Olusturulan dizi:");
	diziyiYazdir(dizi,elemanSayisi);
	diziyiSirala(dizi,elemanSayisi);
	puts("Sirali dizi:");
	diziyiYazdir(dizi,elemanSayisi);
	
	puts("------------------------------------------------");
	
	//ORNEK-2:Ornek-1'de olusturulan dizide ikili arama algoritmasini kullan.
	puts("ORNEK-2:");
	
	puts("Lutfen aradiginiz degeri giriniz:");
	scanf("%d",&arananDeger);
	ikiliArama(dizi,elemanSayisi,arananDeger);
	
	free(dizi);
	
	puts("------------------------------------------------");
	
	//ORNEK-3:2 boyutlu random-dinamik matris olusturulacak.Sonuc matrisi olusturulacak (calloc).Matris toplamasi yapilacak. Her sey dinamik bir sekilde olusturulacak.
	puts("ORNEK-3:");
	
	int satirSayisi,sutunSayisi,i;
	puts("Lutfen sirasiyla satir ve sutun sayi degerlerini giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);
	int **ilkMatris,**ikinciMatris,**sonucMatrisi;		//adreslerin adresini tutar
	ilkMatris=(int **)malloc(sizeof(int *)*satirSayisi);		//adresin adresini tutar=adresin adresini doner.
	ikinciMatris=(int **)malloc(sizeof(int *)*satirSayisi);		//sizeof(int*)olduguna dikkat et
	//sonucMatrisi icin bellekte yer ayrilmalidir.yoksa program coker
	sonucMatrisi=(int **)calloc(satirSayisi,sizeof(int *));
	for(i=0;i<satirSayisi;i++)
		sonucMatrisi[i]=(int *)calloc(sutunSayisi,sizeof(int));
	
	matrisiOlustur(ilkMatris,satirSayisi,sutunSayisi);
	matrisiOlustur(ikinciMatris,satirSayisi,sutunSayisi);
	
	puts("OLUSTURULAN MATRISLER:");
	puts("MATRIS-1:");
	matrisiYazdir(ilkMatris,satirSayisi,sutunSayisi);
	puts("MATRIS-2:");
	matrisiYazdir(ikinciMatris,satirSayisi,sutunSayisi);
	
	puts("MATRISLERIN TOPLAMI:");
	matrisleriTopla(ilkMatris,ikinciMatris,sonucMatrisi,satirSayisi,sutunSayisi);
	matrisiYazdir(sonucMatrisi,satirSayisi,sutunSayisi);
	
	alaniGeriVer(&ilkMatris,satirSayisi);
	alaniGeriVer(&ikinciMatris,satirSayisi);
	alaniGeriVer(&sonucMatrisi,satirSayisi);
	
	puts("------------------------------------------------");
	
	//ORNEK-4:Kullanicidan alinan satir ve sutun degerine gore birim matris olusturulacak.
	puts("ORNEK-4:");
	
	int **birimMatris;
	
	puts("Lutfen satir ve sutun sayilarini sirasiyla giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);
	
	birimMatrisiOlustur(&birimMatris,satirSayisi,sutunSayisi);//birimMatris uzerinde degisiklik yapabilmek icin adres degerine ihtiyac var.
	puts("Olusturulan birim matris:");
	matrisiYazdir(birimMatris,satirSayisi,sutunSayisi);	
	
	alaniGeriVer(&birimMatris,satirSayisi);
	
	puts("------------------------------------------------");
	
	//ORNEK-5:Kullanicidan satir ve sutun sayisi alinacak.random bir sekilde matris olusturulacak.olusturulan matrisin transpozu alinacak.
	puts("ORNEK-5:");
	
	int **matris,**transpozMatris;
	puts("Lutfen satir ve sutun sayilarini sirasiyla giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);	
	matris=(int **)malloc(sizeof(int *)*satirSayisi);
	
	puts("Olusturulan matris:");
	matrisiOlustur(matris,satirSayisi,sutunSayisi);
	matrisiYazdir(matris,satirSayisi,sutunSayisi);
	transpozAl(&transpozMatris,matris,satirSayisi,sutunSayisi);
	puts("Matrisin transpozu:");
	matrisiYazdir(transpozMatris,satirSayisi,sutunSayisi);
	
	alaniGeriVer(&matris,satirSayisi);
	alaniGeriVer(&transpozMatris,satirSayisi);
	
	return 0;
}

void diziyiOlustur(int *dizi,int elemanSayisi)
{
	srand(time(NULL));
	int *ptr=dizi;
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		*ptr=rand()%100;
}

void diziyiYazdir(int *dizi,int elemanSayisi)
{
	int *ptr;
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		printf("%d ",*ptr);
	printf("\n");
}

void diziyiSirala(int *dizi,int elemanSayisi)
{
	int *ptr1,*ptr2,*enKucukSayi;
	/*
		elemanSayisi=5
		*dizi=baslangic
		*ptr1=dizi+elemanSayisi=101+5=106-1=sonEleman
		baslangic->101 102 103 104 105
		101 102 103 104 105<-sonEleman
	*/
	for(ptr1=dizi;ptr1<dizi+elemanSayisi;ptr1++)
	{
		enKucukSayi=dizi+elemanSayisi-1;	//son elemani tutar
		for(ptr2=ptr1;ptr2<dizi+elemanSayisi;ptr2++)
		{
			if(*ptr2<*enKucukSayi)	//enKucukSayi degerinden daha kucuk bir sayi gelirse yeni enKucukSayi o olsun
				enKucukSayi=ptr2;
		}
		int gecici=*ptr1;
		*ptr1=*enKucukSayi;	//ptr1=enKucukSayi yapildigi zaman ptr1 artik enKucukSayi degerinin ADRESINI tutar. yani oradaki degeri tutmaz. ikisi de ayni adresi ve o adreste yer alan degiskeni gosterir. eger deger degisikligi yapilacaksa deger uzerinden degisiklik yapilmalidir.
		*enKucukSayi=gecici;
	}
}

void ikiliArama(int *dizi,int elemanSayisi,int arananDeger)
{
	/*
		ortanca deger:
		1000+3-1=1004 1008 1012 
		1000 1004 1008 1012 1016 1020 1024
		ortanca=sol+(sag-sol)/2
		sol=1000
		sag=1024
		1000+(1024-1000)/2=1000+12=1012
		1 2 8 9 15 ->arananDeger=15
	*/
	int *ptrSol=dizi,*ptrSag=dizi+elemanSayisi-1,*ptrOrtanca;
	int bulunduMu=0;
	
	while(ptrSag>=ptrSol)
	{
		ptrOrtanca=ptrSol+(ptrSag-ptrSol)/2;
		if(*ptrOrtanca==arananDeger)
		{
			bulunduMu=1;
			break;
		}
		else if(*ptrOrtanca>arananDeger)
			ptrSag=ptrOrtanca-1;	//adresler arasinda gecis yapilmalidir.
		else
			ptrSol=ptrOrtanca+1;
	}
	
	if(bulunduMu)
		printf("%d sayisi bulundu.\n",arananDeger);
	else
		printf("%d sayisi bulunamadi.\n",arananDeger);
}

void matrisiOlustur(int **matris,int satirSayisi,int sutunSayisi)
{
	int i,j;
	srand(time(NULL));
	
	for(i=0;i<satirSayisi;i++)
		matris[i]=(int *)malloc(sizeof(int)*sutunSayisi);
		
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
			matris[i][j]=rand()%10;
	}
}

void matrisiYazdir(int **matris,int satirSayisi,int sutunSayisi)
{
	int i,j;
	
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
			printf("%d\t",matris[i][j]);
		printf("\n");
	}
}

void matrisleriTopla(int **ilkMatris,int **ikinciMatris,int **sonucMatrisi,int satirSayisi,int sutunSayisi)
{
	int i,j;
		
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
			sonucMatrisi[i][j]=ilkMatris[i][j]+ikinciMatris[i][j];
	}
}

void birimMatrisiOlustur(int ***birimMatris,int satirSayisi,int sutunSayisi)
{
	int i,j;
	
	/*
		int *ptr=>adres tutar
		int **ptr=>adresin adresini tutar
		int ***ptr=>adresin adresini tutan degerin adresini tutar
		degisken	tuttugu deger	adresi	
		*ptr		#12345			#123456=>bu degisken icin bir degisiklik yapmak ve her yerde gecerli olmasini istiyorsam adresi uzerinden degisiklik yapmaliyim.
		**ptr		#123456			#1234567=>bu degisken icin bir degisiklik yapmak ve her yerde gecerli olmasini istiyorsam adresi uzerinden degisiklik yapmaliyim.bunun adresini ***ptr tutabilir
		***ptr		#1234567		#12345678=>bu degisken icin bir degisiklik yapmak ve her yerde gecerli olmasini istiyorsam adresi uzerinden degisiklik yapmaliyim.
	*/
	//alan tahsis edildi.
	*birimMatris=(int **)calloc(satirSayisi,sizeof(int *));	//#1234567 adresinin gosterdigi noktada degisiklik yapacagim.
	
	for(i=0;i<satirSayisi;i++)
		(*birimMatris)[i]=(int *)calloc(sutunSayisi,sizeof(int));
		
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
		{
			if(i==j)
				(*birimMatris)[i][j]=1;
		}
	}	
}

void transpozAl(int ***transpozMatrisi,int **matris,int satirSayisi,int sutunSayisi)
{
	int i,j;
	
	//alan tahsis edildi.
	*transpozMatrisi=(int **)calloc(sutunSayisi,sizeof(int *));
	
	for(i=0;i<satirSayisi;i++)
		(*transpozMatrisi)[i]=(int *)calloc(satirSayisi,sizeof(int));
		
    for(i=0;i<sutunSayisi;i++)
    {
        for(j=0;j<satirSayisi;j++)
            (*transpozMatrisi)[i][j]=matris[j][i];
    }
}

void alaniGeriVer(int ***matris,int satirSayisi)
{
	int i,j;
	
	for(i=0;i<satirSayisi;i++)
	{
		free((*matris)[i]);
	}
	free((*matris));
}
