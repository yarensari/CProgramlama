#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//SORU-1 FONKSIYONLAR
int kelimeSayisiBul(FILE *);

//SORU-2 FONKSIYONLAR
int kelimeyiBul(FILE *,char *);

//SORU-3 FONKSIYONLAR
void metniDuzenle(FILE *,FILE *);

//SORU-4 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	char filmAd[50];
	char filmYonetmen[80];
	char yapimYil[5];
}filmBilgileri;

void filmleriEkle(FILE *,filmBilgileri *,int);

int main()
{
	//SORU-1:Bir dosyadaki kelime sayisini bulan program yazilacak.
	puts("SORU-1:");
	
	FILE *kelimeler=fopen("kelime.txt","r");
	int kapandiMi,kelimeSayisi;
	
	if(kelimeler==NULL)
	{
		fprintf(stderr,"Dosya acilma sirasinda hata meydana geldi.");
		exit(0);
	}
	
	kelimeSayisi=kelimeSayisiBul(kelimeler);
	printf("Dosyanin icerisinde %d adet kelime bulunmaktadir.\n",kelimeSayisi);
	
	kapandiMi=fclose(kelimeler);
	if(kapandiMi==0)
		printf("Dosya basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda hata meydana geldi.");

	puts("\n-------------------------------------------");
	
	//SORU-2:Kullanicidan bir kelime istenecek ve bu kelimenin o dosyada yer alip almadigi kontrol edilecek.
	puts("SORU-2:");
	
	FILE *dosya=fopen("dosya.txt","r");
	char arananKelime[50];
	int kelimeBulunduMu;
	
	if(dosya==NULL)
	{
		fprintf(stderr,"Dosya acilma sirasinda hata meydana geldi.");
		exit(0);
	}	
	
	puts("Lutfen dosyada aramak istediginiz kelimeyi giriniz:");
	scanf("%s",&arananKelime);
	
	kelimeBulunduMu=kelimeyiBul(dosya,arananKelime);
	if(kelimeBulunduMu==0)
		printf("%s kelimesi dosya.txt dosyasinda bulunmamaktadir.\n",arananKelime);
	else
		printf("%s kelimesi dosya.txt dosyasinda %d. kelimede bulundu.\n",arananKelime,kelimeBulunduMu);
	
	kapandiMi=fclose(dosya);
	if(kapandiMi==0)
		printf("Dosya basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda hata meydana geldi.");	
		
	puts("\n-------------------------------------------");
	
	//SORU-3: Cumle basindaki harfler buyuk harfe cevrilecek. Bu yeni hali baska bir dosyaya kaydedilecek.
	puts("SORU-3:");
	
	FILE *duzensiz=fopen("duzensiz.txt","r");
	FILE *duzenli=fopen("duzenli.txt","w");
	
	if(duzensiz==NULL || duzenli==NULL)
	{
		fprintf(stderr,"Dosyalarin acilmasi sirasinda hata meydana geldi.");
		exit(0);
	}
	
	metniDuzenle(duzensiz,duzenli);
	
	kapandiMi=fclose(duzensiz);
	if(kapandiMi==0)
		printf("Dosya basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda hata meydana geldi.");	
		
	kapandiMi=fclose(duzenli);
	if(kapandiMi==0)
		printf("Dosya basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda hata meydana geldi.");	
		
	puts("\n-------------------------------------------");
	
	//SORU_4: Kullanicidan alinan film sayisina gore dinamik bir sekilde film listesi olusturulacak. Olusturulan bu film listesi bir dosyaya kaydedilecek.
	puts("SORU-4:");

	FILE *filmler=fopen("filmler.txt","a");	
	int filmSayisi;
	filmBilgileri *filmListesi;
	
	if(filmler==NULL)
	{
		fprintf(stderr,"Dosya acilmasi sirasinda hata meydana geldi.");
		exit(0);
	}
	
	puts("Lutfen film listenizin kac adet film icerecegini giriniz:");
	scanf("%d",&filmSayisi);
	
	filmListesi=(filmBilgileri *)malloc(sizeof(filmBilgileri)*filmSayisi);
	
	filmleriEkle(filmler,filmListesi,filmSayisi);

	kapandiMi=fclose(filmler);
	if(kapandiMi==0)
		printf("Dosya basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda hata meydana geldi.");
			
	return 0;
}

int kelimeSayisiBul(FILE *dosya)
{
	int karakter,kelimeSayisi=0;
	
	while(!feof(dosya))
	{
		karakter=fgetc(dosya);
		
		if(karakter==' ' || karakter=='.')
		{
			kelimeSayisi++;
		}
	}
	
	return kelimeSayisi;	
}

int kelimeyiBul(FILE *dosya,char *arananKelime)
{
	rewind(dosya);//tedbir amacli
	char kontrolEdilenKelime[50];//fscanf ile alinan string ifadeyi tutacak.
	int kelimeSayisi=0;
	
	while(!feof(dosya))
	{
		fscanf(dosya,"%s",kontrolEdilenKelime);
		kelimeSayisi++;
		if(strcmp(kontrolEdilenKelime,arananKelime)==0)
			return kelimeSayisi;
	}

	return 0;//aranan kelime dosyada bulunamadi		
}

void metniDuzenle(FILE *duzensiz,FILE *duzenli)
{
	rewind(duzensiz);//tedbir amacli
	rewind(duzenli);
	int okunanKarakter;
	
	okunanKarakter=fgetc(duzensiz);
	fputc(toupper(okunanKarakter),duzenli);
	
	while(1)
	{
		okunanKarakter=fgetc(duzensiz);
		if(okunanKarakter==EOF)
		{
			fseek(duzenli,-1,SEEK_END);
			fputc('\0',duzenli);
			break;
		}
		fputc(okunanKarakter,duzenli);
		if(okunanKarakter=='.')
		{
			okunanKarakter=fgetc(duzensiz);
			fputc(toupper(okunanKarakter),duzenli);
		}
	}
}

void filmleriEkle(FILE *filmler,filmBilgileri *filmListesi,int filmSayisi)
{
	rewind(filmler);
	int i;
	
	printf("%d adet film dosyaya eklenecektir.\n",filmSayisi);
	for(i=0;i<filmSayisi;i++)
	{
		printf("%d. film:\n",i+1);
		printf("Lutfen eklemek istediginiz filmin ismini giriniz:");
		fflush(stdin);
		gets(filmListesi[i].filmAd);
		printf("Lutfen eklemek istediginiz filmin yonetmenini giriniz:");
		fflush(stdin);
		gets(filmListesi[i].filmYonetmen);
		printf("Lutfen eklemek istediginiz filmin yayinlandigi yili giriniz:");
		fflush(stdin);
		scanf("%s",&filmListesi[i].yapimYil);
		fprintf(filmler,"Film Adi:%s\nFilm Yonetmeni:%s\nYapim Yili:%s\n--------------------------------\n",&filmListesi[i].filmAd,&filmListesi[i].filmYonetmen,&filmListesi[i].yapimYil);
	}
}
