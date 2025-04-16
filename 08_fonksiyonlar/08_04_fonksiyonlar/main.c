#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
	Fonksiyona deðiþken olarak dizi gönderildiði zaman adres göndermiþ oluruz. Dolayýsýyla adresi gönderilen dizi deðiþkeninin içerisindeki deðerlerin deðiþimi her yerde etki eder.
*/
// ÖRNEK-1 FONKSÝYONLAR
void diziyiOlustur(int [],int);
void diziyiYazdir(int [],int);
void diziyiSirala(int [],int);

// ÖRNEK-2 FONKSÝYONLAR
int anagramKontrol(char [],char[]);
void stringSirala(char [],int);

// ÖRNEK-3 FONKSÝYONLAR --- ÖRNEK-1'de yer alan diziyiOlustur, diziyiSirala ve diziyiYazdir fonksiyonlarý da kullanýldý.
int enBuyukDegeriBul(int [],int,int);
int enKucukDegeriBul(int [],int,int);

// ÖRNEK-4 FONKSÝYONLAR
int unluSayisiniBul(char []);

// ÖRNEK-5 FONKSÝYONLAR
int fibonacciRecursive(int);

// ÖRNEK-6 FONKSÝYONLAR
int binarySearcRecursive(int [],int,int,int);

int main()
{
	// ÖRNEK-1:Seçmeli sýralama algoritmasý fonksiyon haline getirilecek.
	puts("ORNEK-1:");
	
	int elemanSayisi=25;
	int dizi[elemanSayisi];
	
	diziyiOlustur(dizi,elemanSayisi);
	printf("Sirasiz dizi:\n");
	diziyiYazdir(dizi,elemanSayisi);
	printf("\n");
	
	diziyiSirala(dizi,elemanSayisi);
	printf("Sirali dizi:\n");
	diziyiYazdir(dizi,elemanSayisi);
	
	puts("\n----------------------------------------------------------------");
	
	// ÖRNEK-2:String ifadelerin anagram olup olmadýðýný kontrol eden kod fonksiyonlaþtýrýlacak.
	puts("ORNEK-2:");	
	
	char ilkString[50],ikinciString[50];
	
	puts("Lutfen anagram kontrolu yapilacak olan ilk stringi giriniz:");
	gets(ilkString);
	puts("Lutfen anagram kontrolu yapilacak olan ikinci stringi giriniz:");
	gets(ikinciString);
	
	if(anagramKontrol(ilkString,ikinciString))
		puts("Anagramdir.");
	else
		puts("Anagram degildir.");
	
	puts("----------------------------------------------------------------");
	
	// ÖRNEK-3: Random bir þekilde oluþturulmuþ dizide yer alan en büyük ve en küçük n. deðeri bul.
	puts("ORNEK-3:");
	
	elemanSayisi=15;
	int randomDizi[elemanSayisi],enBuyuk,enKucuk;
	diziyiOlustur(randomDizi,elemanSayisi);
	puts("Dizi:");
	diziyiYazdir(randomDizi,elemanSayisi);
	
	puts("\nLutfen en buyuk olarak kacinci sayiyi gormek istediginizi giriniz:");
	scanf("%d",&enBuyuk);
	puts("Lutfen en kucuk olarak kacinci sayiyi gormek istediginizi giriniz:");
	scanf("%d",&enKucuk);
	
	printf("%d. sirada yer alan en buyuk sayi:%d\n",enBuyuk,enBuyukDegeriBul(randomDizi,elemanSayisi,enBuyuk));
	printf("%d. sirada yer alan en kucuk sayi:%d\n",enBuyuk,enKucukDegeriBul(randomDizi,elemanSayisi,enKucuk));
	
	puts("Sirali Dizi");
	diziyiYazdir(randomDizi,elemanSayisi);
	
	puts("\n----------------------------------------------------------------");
	
	// ÖRNEK-4: Kullanýcýdan alýnan string ifadede kaç adet ünlü harf olduðu bulunaacak.
	puts("ORNEK-4:");
	
	char kullaniciGirisi[50];
	
	puts("Lutfen unlu harf kontrolu yapilacak olan ifadeyi giriniz:"); 
	fflush(stdin);	
	gets(kullaniciGirisi);
	
	unluSayisiniBul(kullaniciGirisi);

	puts("\n----------------------------------------------------------------");
	
	// ÖRNEK-5: Kullanýcýdan bir üst limit alýnan Fibonacci serisi oluþturulacak.
	/*
		Fibonacci serisi:
		0 1 1 2 3 5 8=>kendinden önceki iki deðeri toplayarak yeni deðeri oluþturur 
	*/
	puts("ORNEK-5:");
	
	int ustLimit,i;
	
	printf("Lutfen Fibonacci serisi icin ust limit degerini giriniz:");
	scanf("%d",&ustLimit);
	
	for(i=0;i<ustLimit;i++)
		printf("%d ",fibonacciRecursive(i));
	
	puts("\n----------------------------------------------------------------");
	
	// ÖRNEK-6: Binary Search (Ýkili Arama) algoritmasýný recersive fonksiyonla yapýlacak
	puts("ORNEK-6:");
	
	elemanSayisi=10;
	int seri[elemanSayisi],arananDeger,sonuc;
	
	diziyiOlustur(seri,elemanSayisi);
	printf("Olusturulan dizi: ");
	diziyiYazdir(dizi,elemanSayisi);
	
	diziyiSirala(seri,elemanSayisi);
	printf("\nSiralanmis dizi: ");
	diziyiYazdir(seri,elemanSayisi);
		
	printf("\nLutfen aradiginiz degeri girin:");
	scanf("%d",&arananDeger);	
	
	sonuc=binarySearcRecursive(seri,9,0,arananDeger);
	if(sonuc!=-1)
		puts("Aranan deger bulundu!");
	else
		puts("Aranan deger bulunamadi.");
		
	return 0;
}

void diziyiOlustur(int dizi[],int elemanSayisi)
{
	int i;
	srand(time(NULL));
	
	for(i=0;i<elemanSayisi;i++)
	{
		dizi[i]=rand()%100;
	}
}

void diziyiYazdir(int dizi[],int elemanSayisi)
{
	int i;
	
	for(i=0;i<elemanSayisi;i++)
	{
		printf("%d ",dizi[i]);
	}
}

void diziyiSirala(int dizi[],int elemanSayisi)
{
	int i,j,enKucuk,enKucukIndeks;
	
	for(i=0;i<elemanSayisi;i++)
	{																
		enKucuk=dizi[i];	
		enKucukIndeks=i;																				
		for(j=i+1;j<elemanSayisi;j++)														
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
}

int anagramKontrol(char ilkString[],char ikinciString[])
{
	int i,j,sorgu=1,karakterSayisi1,karakterSayisi2;
	char eleman;
	
	karakterSayisi1=strlen(ilkString);
	karakterSayisi2=strlen(ikinciString);
	
	if(karakterSayisi1!=karakterSayisi1)
		return 0;
	else
	{
		stringSirala(ilkString,karakterSayisi1);
		stringSirala(ikinciString,karakterSayisi2);
			
		for(i=0;i<karakterSayisi1;i++)
		{
			if(ilkString[i]!=ikinciString[i])
			{
				sorgu=0;
				break;
			}
		}
		if(sorgu)
			return 1;
		else
			return 0;
	}	
}

void stringSirala(char string[],int karakterSayisi)
{
	int i,j,eleman;
	
	for(i=1;i<karakterSayisi;i++)
	{
		eleman=string[i];
		for(j=i-1;j>=0 && eleman<=string[j];j--)
		{
			string[j+1]=string[j];
		}
		string[j+1]=eleman;
	}
}

int enBuyukDegeriBul(int dizi[],int elemanSayisi,int siralama)
{
	diziyiSirala(dizi,elemanSayisi);
	
	return dizi[elemanSayisi-siralama];
}

int enKucukDegeriBul(int dizi[],int elemanSayisi,int siralama)
{
	return dizi[siralama-1];	
}

int unluSayisiniBul(char string[])
{
	int unluSayisi=0,i=0,j;
	int unluHarfler[]={'a','e','i','o','u'};
	int unluHarfSayisi[]={0,0,0,0,0};
	
	while(string[i]!='\0')
	{
		for(j=0;j<5;j++)
		{
			if(unluHarfler[j]==string[i])
			{
				unluSayisi++;
				break;
			}
		}
		unluHarfSayisi[j]+=1;
		i++;
	}
	
	if(unluSayisi>0)
	{
		for(j=0;j<5;j++)
			printf("%c karakteri %d adet bulunmaktadir.\n",unluHarfler[j],unluHarfSayisi[j]);
		printf("%s ifadesinde %d adet unlu harf yer almaktadir.\n",string,unluSayisi);
	}
}


int fibonacciRecursive(int sayi)
{
	if(sayi==0||sayi==1)
		return sayi;
	else
		return fibonacciRecursive(sayi-1)+fibonacciRecursive(sayi-2);
	/*
	i=0	
	0
	i=1
	1
	i=2
	return fibonacci(1)+fibonacci(0)=1+0=1
	i=3
	return fibonacci(3)+fibonacci(2)=[return fibonacci(2)+1]+[1+0]=1+0+1+1+0=3
	*/
}

int binarySearcRecursive(int dizi[],int enBuyuk,int enKucuk,int arananDeger)
{
	int kontrolEdilenIndeks=0;
	//0 12 16 17 21 36 39 74 86 88
	if(enBuyuk>=enKucuk)
	{
		kontrolEdilenIndeks=(enBuyuk+enKucuk)/2;
		if(dizi[kontrolEdilenIndeks]==arananDeger)
			return 1;
		if(dizi[kontrolEdilenIndeks]>arananDeger)
			return binarySearcRecursive(dizi,kontrolEdilenIndeks-1,enKucuk,arananDeger);
			
		return binarySearcRecursive(dizi,enBuyuk,kontrolEdilenIndeks+1,arananDeger);
	}

	return -1;
}
