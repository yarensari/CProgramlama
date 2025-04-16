#include <stdio.h>
#include <string.h>

// GLOBAL MAKRO TANIMLAMALAR	**const int tanýmlamalarý C++'da geçerli olur. constant tanýmlama yapmak için #define kullanýlmalýdýr.**
#define satir 3
#define sutun 3

// SORU-1 FONKSÝYONLAR
int karakterSayaci(char []);

// SORU-2 FONKSÝYONLAR
int GCD_EBOB(int,int);
int GCD_EKOK(int,int);

// SORU-3 FONKSÝYONLAR
void matrisOlustur(int [][sutun]);
void matrisYazdir(int [][sutun]);
int diagonalCarpimSol(int [][sutun]);

// SORU-4 FONKSÝYONLAR matrisOlustur, matrisYazdir, diagonalCarpimSol fonksiyonlarý da kullanýldý. 
int caprazCarpimlarEsitMi(int [][sutun]);
int diagonalCarpimSag(int [][sutun]);

// SORU-5 FONKSÝYONLAR
void satirSutunTopla(int [][sutun]);

int main()
{
	// SORU-1:Kullanýcýdan bir string alýnacak ve karakter sayýmý yapýlacak. Birbirini tekrarlayan karakterler bir kere sayýlacak.
	puts("SORU-1:");
	
	char kullaniciGirisi[50];
	int karakterSayisi;
	
	puts("Lutfen karakter sayimi yapilacak olan stringi giriniz:");
	gets(kullaniciGirisi);
	
	karakterSayisi=karakterSayaci(kullaniciGirisi);
	
	printf("Girdiginiz %d adet karakter bulunmaktadir.\n",karakterSayisi);
	
	puts("------------------------------------------------------");
	
	// SORU-2:EBOB-EKOK hesabýný yapan recursive fonksiyon kullanýlacak. GCD algoritmasý kullanýlacak.
	/*
		GCD Algoritmasý
		int gcd(int a, int b) 
		{
    		if (b == 0)
        		return a;
    		return gcd(b, a % b);
		} 
		6 ve 14 sayýsý için EBOB:
		a=6,b=14
		gcd(6,14)
		b!=0
		return gcd(14,6)
		b!=0
		return gcd(6,14%6)=return gcd(6,2)
		b!=0
		return gcd(2,6%2)=return gcd(2,0)
		b==0
		return a=return 2
	*/
	puts("SORU-2:");
	
	int sayi1,sayi2;
	
	puts("Lutfen EBOB ve EKOK hesabi yapilacak olan sayilari sirasiyla giriniz:");
	scanf("%d%d",&sayi1,&sayi2);
	
	printf("%d ve %d sayisinin en buyuk ortak boleni:%d\n",sayi1,sayi2,GCD_EBOB(sayi1,sayi2));
	printf("%d ve %d sayisinin en kucuk ortak kati:%d\n",sayi1,sayi2,GCD_EKOK(sayi1,sayi2));
	
	puts("------------------------------------------------------");
	
	// SORU-3:Kullanýcýdan dizi alýnacak (matris) ve bu dizinin diagonallerinin çarpýmýný yapan fonksiyon oluþturulacak.
	puts("SORU-3:");
	
	int matris[satir][sutun];
	
	matrisOlustur(matris);
	matrisYazdir(matris);
	printf("Diagonal carpim sonucu:%d\n",diagonalCarpimSol(matris));
	
	puts("------------------------------------------------------");
	
	// SORU-4:Kullanýcýdan dizi alýnacak (matris) ve bu dizide bu sefer soldan saða çapraz çizgi çekilerek çarpým yapýlacak. Eðer bir önceki soruda hesaplanan sonuca eþitse 1 deðilse 0 dönecek.
	puts("SORU-4:");
	
	matrisOlustur(matris);
	matrisYazdir(matris);
	
	printf("Soldan saga carpim sonucu:%d\n",diagonalCarpimSol(matris));
	printf("Sagdan sola carpim sonucu:%d\n",diagonalCarpimSag(matris));
	
	if(caprazCarpimlarEsitMi(matris))
		puts("Girilen matrisin soldan saga ve sagdan sola carpimlari birbirine esittir.");
	else
		puts("Girilen matrislerin soldan saga ve sagdan sola carpimlari birbirine esit degildir.");
		
	puts("------------------------------------------------------");
	
	// SORU-5:Kullanýcýdan matris deðerleri alýnacak. Bu matrisi satýr sütun deðerlerini tek döngüde toplayabilen bir fonksiyon yazýlacak.
	puts("SORU-5:");
	
	matrisOlustur(matris);
	matrisYazdir(matris);
	
	printf("Girdiginiz matristeki satir ve sutun toplamlari:\n");
	satirSutunTopla(matris);
	
	return 0;
}

int karakterSayaci(char kullaniciGirisi[])
{
	char karakterler[26];
	int i,j;
	for(i=0;i<26;i++)				// hangi karaktere yazýldýðýný anlamak için hepsine ayný karakter atanýr
		karakterler[i]='$';
	
	i=0;
	while(kullaniciGirisi[i]!='\0')
	{
		for(j=0;j<26;j++)
		{
			if(karakterler[j]=='$')
				karakterler[j]=kullaniciGirisi[i];
			if(karakterler[j]==kullaniciGirisi[i])
				break;
		}
		i++;
	}
	
	for(i=0;i<26;i++)
	{
		if(karakterler[i]=='$')
			break;
	}
	
	return i;
}

int GCD_EBOB(int sayi1,int sayi2)
{
	if(sayi2==0)
		return sayi1;
	return GCD_EBOB(sayi2,sayi1%sayi2);
}

int GCD_EKOK(int sayi1,int sayi2)
{
	return (sayi1*sayi2)/(GCD_EBOB(sayi1,sayi2));
}

void matrisOlustur(int matris[][sutun])
{
	int i,j;
	puts("Lutfen sirasiyla (3x3) matris icin degerlerinizi giriniz:(9 adet)");
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
			scanf("%d",&matris[i][j]);
	}
}

void matrisYazdir(int matris[][sutun])
{
	int i,j;
	puts("Olusturulan matris:");
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
			printf("%d ",matris[i][j]);
		printf("\n");
	}
}

int diagonalCarpimSol(int matris[][sutun])
{
	int i,j,carpim=1;

	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
		{
			if(i==j)
			{
				carpim*=matris[i][j];
				break;
			}
		}
	}
	return carpim;
}

int diagonalCarpimSag(int matris[][sutun])
{
	/*
		00 01 02		02*11*20 2+0=2,1+1=2,2+0=2=>hep satir sayisina eþit
		10 11 12		
		20 21 22		
	*/
	int i,carpim=1;
	
	for(i=0;i<satir;i++)
		carpim*=matris[i][satir-1-i];			// 0=>matris[0][0],1=>matris[1][1],2=>matris[2][0]
	// kurstaki çözüm
	/*for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
		{
			if(i+j==satir-1)
				carpim*=matris[i][j];
		}
	}*/	
	return carpim;
}

int caprazCarpimlarEsitMi(int matris[][sutun])
{
	int carpimSag,carpimSol;
	
	carpimSag=diagonalCarpimSag(matris);
	carpimSol=diagonalCarpimSol(matris);
	
	if(carpimSag==carpimSol)
		return 1;
	else
		return 0;
}

void satirSutunTopla(int matris[][sutun])
{
	/*
		00 01 02		satirToplami=00+01+02=>1.satýr		sutunToplami=00+10+20=>1.sutun
		10 11 12					=10+11+12=>2.satýr					=01+11+21=>2.sutun
		20 21 22					=20+21+22=>3.satýr					=02+12+22=>3.sutun
	*/
	int index,i,j;
	int satirToplami[satir]={0};
	int sutunToplami[sutun]={0};
	
	for(index=0;index<satir*sutun;index++)
	{
		i=index/sutun;			//0=>i=0, 1=>i=0, 2=>i=0 ; 3=>i=1, 4=>i=1, 5=>i=1 ; 6=>i=2... 	i:0-0-0 ; 1-1-1 ; 2-2-2
		j=index%sutun;			//0=>j=0, 1=>j=1, 2=>j=2 ; 3=>j=>0, 4=>j=1, 5=>j=2 ; 6=>j=0...	j:0-1-2 ; 0-1-2 ; 0-1-2
		
		satirToplami[i]+=matris[i][j];
		sutunToplami[i]+=matris[j][i];
	}
	
	for(i=0;i<3;i++)
	{
		printf("%d. satirda %d toplami bulunmustur.\n",i+1,satirToplami[i]);
		printf("%d. sutunda %d toplami bulunmustur.\n",i+1,sutunToplami[i]);
	}
}
