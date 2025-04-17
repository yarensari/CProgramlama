#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//ÖRNEK-1 FONKSÝYONLAR
void diziyiOlustur(int *,int);
void diziyiYazdir(int *,int);
void maksMinBul(int *,int,int *,int *);
void ortTopBul(int *,int,int *,int *);

//ÖRNEK-2 FONKSÝYONLAR
void merhabaDunya(void);
void helloWorld(void);
void halloWelt(void);
void belirleyiciFonksiyon(void (*[])(void),int);

//ÖRNEK-3 FONKSÝYONLAR
void boslukSay(char *,int *);

//ÖRNEK-4 FONKSÝYONLAR myStrlen fonksiyonu kullanildi.
void tersiniYaz(char *);

//ÖRNEK-5 FONKSÝYONLAR
void myStrlen(char *,int *);			//normalde bunu return etmek daha mantiklidir fakat pointer mantigini daha da kavramak icin bu sekilde olusturuyoruz.
int myStrCmp(char *,char *);
	
int main()
{
	//ÖRNEK-1:Bir dizi oluþturulacak ve o dizi içerisinde yer alan minimun ile maksimum deðerler bulunacak. Ayrýca dizide yer alan elemanlarýn toplamý ve ortalamasý da bulunacak.
	puts("ORNEK-1:");
	
	int elemanSayisi=10,maks,min,ortalama,toplam=0;
	int dizi[elemanSayisi];
	
	diziyiOlustur(dizi,elemanSayisi);
	puts("Olusturulan dizi:");
	diziyiYazdir(dizi,elemanSayisi);
	maksMinBul(dizi,elemanSayisi,&maks,&min);
	printf("Dizide yer alan en buyuk eleman:%d en kucuk eleman:%d\n",maks,min);
	ortTopBul(dizi,elemanSayisi,&toplam,&ortalama);
	printf("Dizide yer alan elemanlarin toplami:%d ve ortalamasi:%d\n",toplam,ortalama);
	
	puts("------------------------------------------");
	//ÖRNEK-2:Türkçe,ingilizce ve almanca merhaba dünya yazdýran fonksiyonlar oluþturulacak. bir tane de hangi fonksiyonun kullanýlacaðýný belirleyen fonksiyon oluþturulacak.bu fonksiyon
	//bir adet fonksiyon pointerý(array þekilde), 1 adet de int deðer alacak
	puts("ORNEK-2:");
	
	void(*fonkPtr[3])(void);		//fonksiyon isaretcisi olusturuldu
	fonkPtr[0]=merhabaDunya;
	fonkPtr[1]=helloWorld;
	fonkPtr[2]=halloWelt;
	
	belirleyiciFonksiyon(fonkPtr,1);
	belirleyiciFonksiyon(fonkPtr,2);
	belirleyiciFonksiyon(fonkPtr,3);
	
	puts("------------------------------------------");
	//ÖRNEK-3:Bir string ifadede yer alan bosluk sayisi baska bir fonksiyon icerisinde hesaplanacak ve sonuc bir adres ile tutulacak.
	puts("ORNEK-3:");
	
	int boslukSayisi=0;
	char *string="how i met your mother";
	
	boslukSay(string,&boslukSayisi);
	
	printf("%s ifadesinde %d adet bosluk bulunmaktadir.\n",string,boslukSayisi);
	
	puts("------------------------------------------");
	//ÖRNEK-4:String bir ifadenin pointerla tersten yazýlmasý saðlanacak.
	puts("ORNEK-4:");
	
	char *str="yaren sari";		//NULL karakterini kendisi koyar
	
	tersiniYaz(str);
	
	puts("------------------------------------------");
	//ÖRNEK-5:Kendi strlen ve strcmp fonksiyonunu yazdirma.
	puts("ORNEK-5:");
	
	char *kullaniciGirisi="yaren";
	char *str1="yaren";
	char *str2="yarenn";
	int karakterSayisi=0,sonuc;
	
	myStrlen(kullaniciGirisi,&karakterSayisi);
	printf("%s stringinde %d adet karakter yer almaktadir.\n",kullaniciGirisi,karakterSayisi);
	
	sonuc=myStrCmp(str1,str2);
	if(sonuc==0)
		printf("%s stringi ile %s stringi birbirinin aynisidir.\n",str1,str2);
	else if(sonuc==1)
		printf("%s stringi %s stringinden sonra gelmektedir.\n",str1,str2);
	else
		printf("%s stringi %s stringinden once gelmektedir.\n",str1,str2);
	
	return 0;
}

void diziyiOlustur(int *dizi,int elemanSayisi)
{
	srand(time(NULL));
	int *ptr;	//dizinin baþlangýç adresini kaybetmemek için
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		*ptr=rand()%10;
}

void diziyiYazdir(int *dizi,int elemanSayisi)
{
	int *ptr;	//dizinin baþlangýç adresini kaybetmemek için
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		printf("%d ",*ptr);
	printf("\n");
}

void maksMinBul(int *dizi,int elemanSayisi,int *maks,int *min)
{
	int *ptr;
	ptr=dizi;
	*maks=*ptr;
	*min=*ptr;
	
	while(ptr!=(dizi+elemanSayisi))
	{
		if(*ptr<*min)
			*min=*ptr;
		else if(*ptr>*maks)
			*maks=*ptr;
		ptr++;
	}
}

void ortTopBul(int *dizi,int elemanSayisi,int *toplama,int *ortalama)
{
	int *ptr;
	for(ptr=dizi;ptr<(dizi+elemanSayisi);ptr++)
	{
		*(toplama)+=*ptr;
	}
	*(ortalama)=*(toplama)/elemanSayisi;
}

void merhabaDunya(void)
{
	printf("Merhaba Dunya\n");
}

void helloWorld(void)
{
	printf("Hello World\n");
}

void halloWelt(void)
{
	printf("Hallo Welt\n");
}

void belirleyiciFonksiyon(void (*fonkPtr[3])(void),int sayi)
{
	switch(sayi)
	{
		case 1:
			(fonkPtr[0])();
			break;
		case 2:
			(fonkPtr[1])();
			break;
		case 3:
			(fonkPtr[2])();
			break;
		default:
			printf("Hatali giris!");
	}
}

void boslukSay(char *str,int *boslukSayisi)
{
	char *ptr=str;
	while(*ptr!='\0')
	{
		if(*ptr==' ')
			(*boslukSayisi)++;
		ptr++;
	}
}

void tersiniYaz(char *str)
{
	int karakterSayisi=0;
	myStrlen(str,&karakterSayisi);
	char *ptr=str+karakterSayisi-1;	//ornek olarak:1000 1001 1002=>3 adet karakterin adresleri bunlardir. 1000+3=1003 olur ve 1 eksigi olmali ki baska adreslere bulasmasin
		
	while(ptr>=str)
	{
		printf("%c",*ptr);	
		ptr--;
	}
	printf("\n");	
}

void myStrlen(char *str,int *karakterSayisi)
{
	char *ptr=str;
	
	while(*ptr!='\0')
	{
		*karakterSayisi+=1;	//ya da (*karakterSayisi)++;
		ptr++;
	}
}

int myStrCmp(char *str1,char *str2)
{
	char *p1=str1,*p2=str2;
	
	while(*p1!='\0'&&*p2!='\0')
	{
		if(*p1==*p2)
		{
			p1++;
			p2++;
		}
		else if(*p1>*p2)
			return 1;		//ilk string ikinci stringten sonra geliyor(alfabetik olarak)
		else
			return 0;
	}
	
	if(strlen(p1)==strlen(p2))
		return 0;
	else if(strlen(p1)>strlen(p2))
		return 1;			//ilk string ikinci stringten sonra geliyor(alfabetik olarak)
	else
		return 2;
}
