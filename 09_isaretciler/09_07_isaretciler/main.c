#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//SORU-1 FONKSÝYONLAR
void diziyiOlustur(int *,int);
void diziyiDuzYazdir(int *,int);
void diziyiTersYazdir(int *,int);

//SORU-2 FONKSÝYONLAR
void myStrCat(char *,char *);
void myStrCpy(char *,char *);

//SORU-3 FONKSÝYONLAR
void karakterTespiti(char *,char,int *);

//SORU-4 FONKSÝYONLAR
void toplama(int,int);
void carpma(int,int);
void bolme(int,int);
void cikarma(int,int);
void belirleyiciFonksiyon(void (*[])(int,int),int,int,int);

int main()
{
	//SORU-1:Random bir dizi olusturulacak. bu dizi önce düz bir þekilde sonra da ters bir sekilde konsol ekranýna yazdýrýlacak. bunlar yapýlýrken pointerlar kullanýlacak
	puts("SORU-1:");
	
	int elemanSayisi=10;
	int dizi[elemanSayisi];
	
	diziyiOlustur(dizi,elemanSayisi);
	puts("Olusturulan dizinin duz hali:");
	diziyiDuzYazdir(dizi,elemanSayisi);
	puts("\nOlusturulan dizinin ters hali:");
	diziyiTersYazdir(dizi,elemanSayisi);
	
	puts("\n---------------------------------------------");
	
	//SORU-2:strcat ve strcpy fonksiyonlarý pointerla olusturulacak.
	/*
		strcat:ikinci stringi birinci stringin sonuna ekler
		strcpy:ikinci stringi birinci stringten kopyalar
	*/
	puts("SORU-2:");
	
	char str1Cat[100]="yaren";	//ekleme yapýlacak boyutu belirtilmeli
	char *str2Cat="sari";	//kopyalama yapýlacak boyutu belirtilmeli
	char *str1Cpy="of";
	char str2Cpy[100]="sari";
	
	myStrCat(str1Cat,str2Cat);
	puts(str1Cat);
	myStrCpy(str1Cpy,str2Cpy);
	puts(str2Cpy);
	
	puts("---------------------------------------------");
	
	//SORU-3:Kullanýcýdan bir string ve karakter alýnacak. Stringte o karakterin kac kere gectigi belirlenecek.
	puts("SORU-3:");
	
	char kullaniciGirisi[100];
	char karakter;
	int karakterSayisi=0;
	
	puts("Lutfen stringi giriniz:");
	gets(kullaniciGirisi);
	fflush(stdin);
	puts("Lutfen karakteri giriniz:");
	karakter=getchar();

	karakterTespiti(kullaniciGirisi,karakter,&karakterSayisi);
	printf("Girdiginiz ifade %d adet %c karakter yer almaktadir.\n",karakterSayisi,karakter);
	
	puts("---------------------------------------------");
	
	//SORU-4:Fonksiyon isaretcileri array'i olusturulacak.gelen sayiya göre toplama,cikarma,carpma ve bolme islemleri yapilacak.
	//fonksiyon=>(fonksiyon isaretcisi array'i,islem_sayisi,degerler'i alacak
	puts("SORU-4:");
	
	int a=3;
	int b=5;
	int i;
	void (*fonkPtr[4])(int,int);
	fonkPtr[0]=toplama;	//adrese atama yaptýk
	fonkPtr[1]=cikarma;
	fonkPtr[2]=carpma;
	fonkPtr[3]=bolme;
	
	for(i=1;i<5;i++)
		belirleyiciFonksiyon(fonkPtr,i,a,b);
		
	return 0;
}

void diziyiOlustur(int *dizi,int elemanSayisi)
{
	srand(time(NULL));
	int *ptr=dizi;
	
	for(;ptr<dizi+elemanSayisi;ptr++)
		*ptr=rand()%10;
}

void diziyiDuzYazdir(int *dizi,int elemanSayisi)
{
	int *ptr=dizi;
	
	for(;ptr<=dizi+elemanSayisi;ptr++)
		printf("%d ",*ptr);
}

void diziyiTersYazdir(int *dizi,int elemanSayisi)
{
	int *ptr=dizi+elemanSayisi;
	
	for(;ptr>=dizi;ptr--)
		printf("%d ",*ptr);
}

//ikinci string birinci stringin sonuna eklenir
//birinci string'in sonuna gel üzerine ekleme yap ikinci stringle
void myStrCat(char *str1,char *str2)
{
	char *ptr1,*ptr2;
	int karakterSayisi1;
	
	karakterSayisi1=strlen(str1);
	ptr1=str1+karakterSayisi1;	//str1'in son karakterine gel
	ptr2=str2;	//str2'nin ilk karakterine gel
	while(*ptr2!='\0')
	{
		*ptr1=*ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1='\0';	//stringin sonunda olmalý
}

//strcpy:ikinci stringi birinci stringten kopyalar
//ikinci stringe birinci stringi kopyala
void myStrCpy(char *str1,char *str2)
{
	char *ptr1,*ptr2;
	ptr1=str1;
	ptr2=str2;
	
	while(*ptr1!='\0')
	{
		*ptr2=*ptr1;
		ptr1++;
		ptr2++;
	}
	*ptr2='\0';
}

void karakterTespiti(char *kullaniciGirisi,char karakter,int *karakterSayisi)
{
	char *ptr=kullaniciGirisi;
	
	while(*ptr!='\0')	//while(*ptr)==while(*ptr!='\0') ile ayni
	{
		if(*ptr==karakter)
			*karakterSayisi+=1;
		ptr++;
	}
}

void toplama(int a,int b)
{
	printf("%d+%d=%d\n",a,b,a+b);
}

void carpma(int a,int b)
{
	printf("%d*%d=%d\n",a,b,a*b);
}

void bolme(int a,int b)
{
	printf("%d/%d=%d\n",a,b,a/b);
}

void cikarma(int a,int b)
{
	printf("%d-%d=%d\n",a,b,a-b);
}

void belirleyiciFonksiyon(void (*fonkPtr[4])(int,int),int sayi,int a,int b)
{
	switch(sayi)
	{
		case 1:	//toplama
			fonkPtr[0](a,b);
			break;
		case 2:	//cikarma
			fonkPtr[1](a,b);
			break;
		case 3:	//carpma
			fonkPtr[2](a,b);
			break;
		case 4:	//bolme
			fonkPtr[3](a,b);
			break;
		default:
			printf("yanlis islem yapildi.\n");
	}
}
