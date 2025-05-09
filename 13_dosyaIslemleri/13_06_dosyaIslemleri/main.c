#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//ORNEK-1: FONKSIYONLAR
int dosyalariKarsilastir(FILE *,FILE *);

//ORNEK-2: FONKSIYONLAR
void buyukHarfeCevir(FILE *,FILE *);
void dosyayiYazdir(FILE *);

//ORNEK-3 FONKSIYONLAR
void tersAktar(FILE *,FILE *);
void nKarakteriTersAktar(FILE *,FILE *,int);

//ORNEK-4 FONSKIYONLAR VE STRUCTLAR
typedef struct
{
	char adSoyad[20],harfNotu[3];
	int vizeNotu,finalNotu;
	double ortalama;
}ogrenciBilgileri;

void ogrenciDurumu(FILE *,FILE *);
char * harfNotuHesapla(double);

int main()
{
	//ORNEK-1: Iki dosyanin iceriklerinin karsilastirmasi yapilacak. Eger dosyalarin icerikleri farkliysa hangi dosyanin karakter sayisinin fazla oldugu belirlenecek.
	puts("ORNEK-1:");
	
	FILE *ilkDosya=fopen("deneme1.txt","r");
	FILE *ikinciDosya=fopen("deneme2.txt","r");
	int kapandiMi_ilk,kapandiMi_ikinci,sonuc;
	
	if(ilkDosya!=NULL && ikinciDosya!=NULL)
	{
		printf("Dosyalar basarili bir sekilde acildi.\n\n");
		
		sonuc=dosyalariKarsilastir(ilkDosya,ikinciDosya);
		if(sonuc==0)
			printf("Iki dosyanin karakter sayisi birbirine esittir fakat farkli karakterler icermektedir.\n");
		else if(sonuc==1)
			printf("Iki dosyanin icerigi birbiriyle aynidir.\n");
	}
	else
		printf("Dosya acilmasi sirasinda hata meydana geldi.");
	
	
	kapandiMi_ilk=fclose(ilkDosya);
	kapandiMi_ikinci=fclose(ikinciDosya);
	if(kapandiMi_ilk==0 && kapandiMi_ikinci==0)
		printf("\nDosyalar basarili bir sekilde kapatildi.");
	else 
		printf("\nDosya kapanmasi sirasinda hata meydana geldi.");
	
	puts("\n-------------------------------------------------");
	
	//ORNEK-2:Bir dosyadan okunan butun karakterler buyuk harfe donusturulerek diger dosyaya aktarilacak.
	puts("ORNEK-2:");
	
	FILE *kucukHDosya=fopen("kucukHarf.txt","r");
	FILE *buyukHDosya=fopen("buyukHarf.txt","w");
	

	if(kucukHDosya==NULL || buyukHDosya==NULL)
	{
		fprintf(stderr,"Dosya acilmasi sirasinda hata meydana geldi.");
		exit(0);//cikis kodumuzdur. bu kod sayesinde alt satirda kalan kodlari islemeden direkt program sonlanir.
	}
	
	printf("Dosyalar basarili bir sekilde acildi.\n\n");

	buyukHarfeCevir(kucukHDosya,buyukHDosya);
	printf("Kucuk harfleri iceren dosyanin icerigi:\n");
	dosyayiYazdir(kucukHDosya);
	printf("Buyuk harfleri iceren dosyanin icerigi:\n");
	buyukHDosya=fopen("buyukHarf.txt","r");//okuma islemi yapmak icin
	dosyayiYazdir(buyukHDosya);
	
	kapandiMi_ilk=fclose(kucukHDosya);
	kapandiMi_ikinci=fclose(buyukHDosya);
	if(kapandiMi_ilk==0 && kapandiMi_ikinci==0)
		printf("\nDosyalar basarili bir sekilde kapatildi.");
	else 
		printf("\nDosya kapanmasi sirasinda hata meydana geldi.");
	
	puts("\n-------------------------------------------------");
	
	//ORNEK-3:Bir dosyada yer alan karakterler diger dosyaya tersten yazilacak. Hem butun karakterleri bastan sonra ters yazan fonksiyon olusturulacak hem de kullanicidan aldigi karakter sayisina gore tersten yazma islemini yapan fonksiyon olusturulacak.
	puts("ORNEK-3:");
	
	FILE *okumaDosyasi=fopen("okuma.txt","r");
	FILE *yazmaDosyasi=fopen("yazma.txt","w");
	
	if(okumaDosyasi==NULL || yazmaDosyasi==NULL)
	{
		fprintf(stderr,"Dosya acilmasi sirasinda hata meydana geldi.");
		exit(0);
	}
	
	//tersAktar(okumaDosyasi,yazmaDosyasi);
	nKarakteriTersAktar(okumaDosyasi,yazmaDosyasi,10);
	
	kapandiMi_ilk=fclose(okumaDosyasi);
	kapandiMi_ikinci=fclose(yazmaDosyasi);
	if(kapandiMi_ilk==0 && kapandiMi_ikinci==0)
		printf("\nDosyalar basarili bir sekilde kapatildi.");
	else 
		printf("\nDosya kapanmasi sirasinda hata meydana geldi.");
	
	puts("\n-------------------------------------------------");
	
	//ORNEK-4:notlar.txt'de yer alan ogrenci ad-soyad ve vize-final notlarina gore ogrencinin ortalamasi ve harf notu hesaplanacak. Hesaplanan bu veriler bir dosyaya kaydedilecek.
	puts("ORNEK-4:");
	
	FILE *notlar=fopen("notlar.txt","r");
	FILE *sonuclar=fopen("sonuclar.txt","w");
	
	if(notlar==NULL || sonuclar==NULL)
	{
		fprintf(stderr,"Dosya acilmasi sirasinda hata meydana geldi.");
		exit(0);
	}
	
	ogrenciDurumu(notlar,sonuclar);
	printf("Hesaplama tamamlandi.");
	
	kapandiMi_ilk=fclose(notlar);
	kapandiMi_ikinci=fclose(sonuclar);
	if(kapandiMi_ilk==0 && kapandiMi_ikinci==0)
		printf("\nDosyalar basarili bir sekilde kapatildi.");
	else 
		printf("\nDosya kapanmasi sirasinda hata meydana geldi.");	
	
	return 0;
}

int dosyalariKarsilastir(FILE *ilkDosya,FILE *ikinciDosya)
{
	int karakterSayisi_1,karakterSayisi_2;
	int ch_1,ch_2;//fgetc() int degerler dondurur.
	
	fseek(ilkDosya,0,SEEK_END);
	fseek(ikinciDosya,0,SEEK_END);//karakterlerin sonuna gelinir.
	karakterSayisi_1=ftell(ilkDosya);
	karakterSayisi_2=ftell(ikinciDosya);
	
	if(karakterSayisi_1<karakterSayisi_2)
	{
		printf("Ikinci dosya ilk dosyadan boyut olarak daha buyuktur.\n");
		return -1;
	}
	else if(karakterSayisi_2<karakterSayisi_1)
	{
		printf("Ilk dosya ikinci dosyadan boyut olarak daha buyuktur.\n");
		return -1;
	}
	else
	{
		rewind(ilkDosya);//dosyanin en basina geri donulur
		rewind(ikinciDosya);
		while(1)
		{
			ch_1=fgetc(ilkDosya);
    		ch_2=fgetc(ikinciDosya);

		    if(ch_1==EOF || ch_2==EOF)
       			break;

    		if(ch_1!=ch_2)
        		return 0;//farkli karakter tespit edildi.
		}
	}
		
	return 1;//butun karakter esit			
}

void buyukHarfeCevir(FILE *dosya_k,FILE *dosya_b)
{
	int karakter;
	rewind(dosya_k);
	rewind(dosya_b);
	
	//EOF integer karakter oldugu icin ona gore kontrol edilmelidir.
	while(1)
	{
		karakter=fgetc(dosya_k);
		if(karakter==EOF)
			break;
		fputc(toupper(karakter),dosya_b);
	}
	//anlamsiz son karakterden kurtulmak icin yapildi.
	fseek(dosya_b,-1,SEEK_END);
	fputc('\0',dosya_b);
}

void dosyayiYazdir(FILE *dosya)
{
	char karakter;
	
	rewind(dosya);
	
	while(!feof(dosya))
	{
		karakter=fgetc(dosya);
		printf("%c",karakter);
	}
	printf("\n");
}

void tersAktar(FILE *ilkDosya,FILE *ikinciDosya)
{
	//sonuna gidip sondan basa dogru donerek aktarimi saglanacak.
	
	rewind(ikinciDosya);
	int karakterSayisi,i,ch;

	fseek(ilkDosya,0,SEEK_END);//dosya sonunda
	karakterSayisi=ftell(ilkDosya);
	printf("%d adet karakter icermektedir.\n",karakterSayisi);
	fseek(ilkDosya,-1,SEEK_END);//EOF'den onceki karaktere gelinir
	
	for(i=2;i<=karakterSayisi+1;i++)
	{
		ch=fgetc(ilkDosya);//i=2 iken son karakteri aldim
		//yaren-->n harfi SEEK_END'e gore -1. karakter. e harfi SEEK_END'e gore -2. karakter. dolayisiyla i degiskeni 2'den baslatildi.
		printf("%c",ch);
		fputc(ch,ikinciDosya);
		fseek(ilkDosya,-(i),SEEK_END);
	}
	printf("\nTum icerik basariyla aktarildi.\n");
}

void nKarakteriTersAktar(FILE *ilkDosya,FILE *ikinciDosya,int n)
{
	rewind(ikinciDosya);//onlem amacli
	char *geciciDizi;
	int karakterSayisi,i;
	
	fseek(ilkDosya,0,SEEK_END);//karakter sayisinin hesaplanabilmesi icin son karaktere gidilir
	karakterSayisi=ftell(ilkDosya);//karakter sayisi hesaplanir
	
	if(n>karakterSayisi)
		printf("Terse cevirmek istediginiz karakter sayisi dosyada yer alan ifadenin karakter sayisindan fazladir.\n");
	else
	{
		geciciDizi=(char*)calloc(n,sizeof(char));
		rewind(ilkDosya);//basa donuldu
		
		for(i=0;i<n;i++)
			geciciDizi[i]=fgetc(ilkDosya);
		
		for(i=n-1;i>=0;i--)//1.indeks 0 oldugu icin!
		{
			printf("%c",geciciDizi[i]);
			fputc(geciciDizi[i],ikinciDosya);
		}
	}
}

void ogrenciDurumu(FILE *ilkDosya,FILE *ikinciDosya)
{
	//vize:%40 final:%60 etkiliyor.
	/*
		AA:95-100
		BA:90-95		
		BB:85-90
		BC:80-85
		CC:75-80
		DC:60-75
		DD:45-60
		FF:0-45
	*/
	rewind(ilkDosya);
	rewind(ikinciDosya);
	ogrenciBilgileri ogrenci;
	
	while(!feof(ilkDosya))
	{
		fscanf(ilkDosya,"%s %d %d",&ogrenci.adSoyad,&ogrenci.vizeNotu,&ogrenci.finalNotu);//gelen ilk dosyadan ogrencinin ad-soyad,vize ve final notlari alinir
		ogrenci.ortalama=(0.4)*ogrenci.vizeNotu + (0.6)*ogrenci.finalNotu;
		strcpy(ogrenci.harfNotu,harfNotuHesapla(ogrenci.ortalama));
		if(strcmp(ogrenci.harfNotu,"FF")==0)
			fprintf(ikinciDosya,"Ad-Soyad:%s\nOrtalamasi:%.2lf\nHarf Notu:%s\nKaldiniz.\n----------------\n",ogrenci.adSoyad,ogrenci.ortalama,ogrenci.harfNotu);
		else
			fprintf(ikinciDosya,"Ad-Soyad:%s\nOrtalamasi:%.2lf\nHarf Notu:%s\nGectiniz.\n----------------\n",ogrenci.adSoyad,ogrenci.ortalama,ogrenci.harfNotu);
	}
}

char * harfNotuHesapla(double ortalama)
{
	if(ortalama>=95 && ortalama<=100) //95ile100 arasi.95'ten buyuk olan degerler burada.
		return "AA";
	else if(ortalama>=90)//95'ten kucuk olan degerler burada.90'dan buyuk olanlar da geldi.
		return "BA";
	else if(ortalama>=85)//90'dan kucuk olan degerler burada.85'ten buyuk olanlar da geldi.
		return "BB";
	else if(ortalama>=80)//85'ten kucuk olan degerler burada.80'den buyuk olanlar da geldi.
		return "BC";
	else if(ortalama>=75)
		return "CC";
	else if(ortalama>=60)
		return "DC";
	else if(ortalama>=45)
		return "DD";
	else
		return "FF";	
}
