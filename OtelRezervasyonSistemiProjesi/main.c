/*
	OTEL REZERVASYON SISTEMI PROJESI
	
	Bu projede rezervasyon sistemi olusturulacaktir.
	
	Rezervasyon sisteminde 2 adet giris sekli vardir. Bunlar:
	1-personel
	2-musteri
	personel ve musteri yetkileri ayni fonksiyonlara erisemezler.
	personel yetkisine sahip bir kisi personel sifresini dogru bilirse kullanabilecegi fonksiyonlara erisebilir. Eger sifreyi dogru girmezse yetkisi musteri olarak kabul edilir.
	Personel Yetkisi:
	1-Yeni musteri girisi islemi
	2-Dolu oda bilgilerini goruntuleme islemi
	3-Odalardan cikis yapma islemi
	ve musteri yetkisinin kullanabildigi butun fonksiyonlari kullanabilir.
	Musteri Yetkisi:
	1-Oda bilgisi sorgulama islemi
	2-Fiyat bilgisi görüntüleme islemi
	Kullaniciya bir menu sunulacak ve bu menuden cikis yapildigi zaman butun veriler otelKayit.txt dosyasina kaydedilecek. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ODA_SAYISI 100 //100 adet oda bulunacaktir.

//sistem hem musteriler hem de personeller tarafindan kullanilabilecek.
typedef enum
{
	musteri,personel
}yetkiSeviyeleri;

//sadece musteri bilgilerini barindiracak. dinamik bir sekilde yer ayrilacak.
typedef struct
{
	char *musteriAdi;
	char *musteriSoyadi;
}musteriBilgileri;

//giris-cikis tarihlerini tutabilmek icin kullanilacak.
typedef struct
{
	int gun;
	int ay;
	int yil;
}tarihBilgileri;

//oteldeki odalarin bilgilerini icermektedir.
typedef struct
{
	musteriBilgileri musteri;//sadece kayit olan kisinin ad-soyad bilgisi tutulacak.
	int kisiSayisi;
	int odaDurumu;//doluysa 1, bossa 0 degerini alacak
	int odaNumarasi;//1-100 arasinda oda numaralari olacak.  
	double fiyatBilgisi;
	tarihBilgileri girisTarihi;
	tarihBilgileri cikisTarihi;
}odaBilgileri;

void yeniMusteriEkleme(odaBilgileri *);//kayit islemlerini yapar.
double fiyatHesaplama(odaBilgileri *,int);//oda numarasina gore fiyat hesaplamasi yapar, odada kac kisi kalinacagi ve kac gun kalinacagi bilgisine gore fiyat hesaplamasi yapar.	
int gunFarkiHesapla(tarihBilgileri,tarihBilgileri);//giris-cikis tarihleri arasindaki gun sayisini hesaplar.
void rezervasyonTemizle(odaBilgileri *,int);//oda cikis islemini yapar. istenen odaNumarasinin odaDurumu 0 yapilir ve musteriAdi-musteriSoyadi alanlari bosaltilir.
void odaBilgisiSorgulama(odaBilgileri *,int);//girilen odanin (odaNumarasi bilgisi degisken olarak alinacak) dolu veya bos olmasi yazdirilir.
void doluOdalariYazdirma(odaBilgileri *);//dolu olan odalarin bilgilerini gosterir.
void fiyatBilgisiYazdirma(void);//fiyat bilgisini yazdirir. 
void yedekKayitAlma(odaBilgileri *);//kayit edilen oda bilgilerini bir dosyaya kaydeder.

int main()
{
	char girilenSifre[50],personelSifre[]="abc_12345",ch;
	yetkiSeviyeleri girisYetkisi;
	odaBilgileri *odalar;//tum bilgiler bu dizide tutulacak.
	
	odalar=(odaBilgileri*)calloc(ODA_SAYISI,sizeof(odaBilgileri));//dinamik bir sekilde oda sayisi kadar bellek ayrildi.
	
	printf("Otel Rezervasyon Sistemine Hos Geldiniz!\n");
	printf("Lutfen personel iseniz sifrenizi giriniz. Eger personel degilseniz 'D' tusuna basiniz.\n");
	scanf("%s",&girilenSifre);
	
	if(strcmp(girilenSifre,personelSifre)==0)//kullanici otelin bir calisanidir.
		girisYetkisi=personel;
	else//sifre yanlissa veya D girildiyse kullanici musteri olarak kabul edilir. 
		girisYetkisi=musteri;
		
	do
	{
		printf("Yeni musteri giris islemi icin 'Y'\nDolu oda bilgileri icin 'D'\nOdalardan cikis islemi icin 'C'\nOda bilgisi sorgulamak icin 'S'\nFiyat bilgisi sorgulama icin 'F'\nCikis islemi icin 'Q' tusuna basiniz.\n");
		fflush(stdin);
		scanf("%c",&ch);
		
		switch(ch)
		{
			case 'Y':
			case 'y':
				if(girisYetkisi==musteri)//bu islemi sadece personeller yapabilir.
					printf("Yetkiniz bu islem icin yeterli degildir.\n");
				else if(girisYetkisi==personel)
					yeniMusteriEkleme(odalar);
				break;
			case 'D':
			case 'd':
				if(girisYetkisi==musteri)//bu islemi sadece personeller yapabilir.
					printf("Yetkiniz bu islem icin yeterli degildir.\n");
				else if(girisYetkisi==personel)
					doluOdalariYazdirma(odalar);
				break;
			case 'C':
			case 'c':
				if(girisYetkisi==musteri)//bu islemi sadece personeller yapabilir.
					printf("Yetkiniz bu islem icin yeterli degildir.\n");
				else if(girisYetkisi==personel)
				{
					int odaNumarasi;
					
					printf("Cikis islemi yapilacak olan oda numarasini giriniz:");
					scanf("%d",&odaNumarasi);
					rezervasyonTemizle(odalar,odaNumarasi);
				}
				break;
			case 'S':
			case 's':
				int sorgulanacakOda;

				printf("Lutfen sorgulamak istediginiz odanin numarasini giriniz:");
				scanf("%d",&sorgulanacakOda);
				odaBilgisiSorgulama(odalar,sorgulanacakOda);
				break;
			case 'F':
			case 'f':
				fiyatBilgisiYazdirma();
				break;
			case 'Q':
			case 'q':
				printf("Sistemden cikis yapiliyor...");
				yedekKayitAlma(odalar);
				break;
			default:
				printf("Yanlis bir tuslama yaptiniz.\n");
		}
	}while(ch!='Q' && ch!='q');//kullanici Q veya q girerse dongu sonlanacaktir.
	
	return 0;
}

void yeniMusteriEkleme(odaBilgileri *odalar)
{
	int odaNumarasi;
	char musteriAdi[50],kullaniciIstegi;
	char musteriSoyadi[50];
	
	printf("Hangi oda icin kayit yapilacak?\n");
	scanf("%d",&odaNumarasi);
	
	if(odalar[odaNumarasi-1].odaDurumu==1)//bu islemi sadece personeller yapabilir. 0ile99 arasindadir. calloc ile olusturuldugu icin odaDurumu basta 0'dir.
		printf("%d numarali oda %d:%d:%d tarihine kadar doludur.\n",odaNumarasi,odalar[odaNumarasi-1].cikisTarihi.gun,odalar[odaNumarasi-1].cikisTarihi.ay,odalar[odaNumarasi-1].cikisTarihi.yil);
	else
	{
		odalar[odaNumarasi-1].odaNumarasi=odaNumarasi;//odaNumarasi'na kullanicini girdigi oda numarasi atanir. 1 eksigi alinir cunku indeksler 0'dan baslar.
		
		printf("Lutfen musterinin adini giriniz:");
		scanf("%s",&musteriAdi);
		printf("Lutfen musterinin soyadini giriniz:");
		scanf("%s",&musteriSoyadi);
		
		odalar[odaNumarasi-1].musteri.musteriAdi=(char *)malloc(strlen(musteriAdi)+1);//dinamik bir sekilde char dizisi olusturulur. +1 ile NULL karakter icin olusturulur.
		odalar[odaNumarasi-1].musteri.musteriSoyadi=(char *)malloc(strlen(musteriSoyadi)+1);
		
		strcpy(odalar[odaNumarasi-1].musteri.musteriAdi,musteriAdi);
		strcpy(odalar[odaNumarasi-1].musteri.musteriSoyadi,musteriSoyadi);
		
		printf("Lutfen kisi sayisini giriniz:");
		scanf("%d",&odalar[odaNumarasi-1].kisiSayisi);
		
		printf("Lutfen giris tarihini gun:ay:yil formatinda giriniz.\n");
		scanf("%d:%d:%d",&odalar[odaNumarasi-1].girisTarihi.gun,&odalar[odaNumarasi-1].girisTarihi.ay,&odalar[odaNumarasi-1].girisTarihi.yil);
		printf("Lutfen cikis tarihini gun:ay:yil formatinda giriniz.\n");
		scanf("%d:%d:%d",&odalar[odaNumarasi-1].cikisTarihi.gun,&odalar[odaNumarasi-1].cikisTarihi.ay,&odalar[odaNumarasi-1].cikisTarihi.yil);
		
		odalar[odaNumarasi-1].fiyatBilgisi=fiyatHesaplama(odalar,odaNumarasi);
		printf("Oda icin hesaplanan fiyat %.2f'dir.\n",odalar[odaNumarasi-1].fiyatBilgisi);
		
		printf("Onayliyor musunuz? Onayliyorsaniz 'E', onaylamiyorsaniz 'H' tusuna basiniz.\n");
		fflush(stdin);
		scanf("%c",&kullaniciIstegi);
		if(kullaniciIstegi=='H' || kullaniciIstegi=='h')
		{
			printf("Rezervasyon iptal edildi.\n");
			rezervasyonTemizle(odalar,odaNumarasi);
		}
		else if(kullaniciIstegi=='E' || kullaniciIstegi=='e')
		{
			odalar[odaNumarasi-1].odaDurumu=1;
			printf("Rezervasyon islemi basariyla yapildi.\n");
		}
		else
		{
			printf("Yanlis bir giris yaptiniz. Rezervasyon iptal ediliyor.\n");
			rezervasyonTemizle(odalar,odaNumarasi);
		}
	}	
}

double fiyatHesaplama(odaBilgileri *odalar,int odaNumarasi)
{
	int gunFarki;
	
	gunFarki=gunFarkiHesapla(odalar[odaNumarasi-1].girisTarihi,odalar[odaNumarasi-1].cikisTarihi);
	
	return gunFarki*150*(odalar[odaNumarasi-1].kisiSayisi);
}

int gunFarkiHesapla(tarihBilgileri girisTarihi,tarihBilgileri cikisTarihi)
{
	tarihBilgileri tarihFarki;
	int gunFarki;
	
	if(girisTarihi.gun>cikisTarihi.gun)
	{
		cikisTarihi.ay-=1;
		cikisTarihi.gun+=30;
	}
	if(girisTarihi.ay>cikisTarihi.ay)
	{
		cikisTarihi.ay+=12;
		cikisTarihi.yil-=1;
	}
	
	tarihFarki.gun=cikisTarihi.gun-girisTarihi.gun;
	tarihFarki.ay=cikisTarihi.ay-girisTarihi.ay;
	tarihFarki.yil=cikisTarihi.yil-girisTarihi.yil;
	
	gunFarki=tarihFarki.yil*365+tarihFarki.ay*30+tarihFarki.gun;
	printf("Kalacaginiz gun sayisi:%d\n",gunFarki);
	return gunFarki;
}

void rezervasyonTemizle(odaBilgileri *odalar,int odaNumarasi)
{
	odalar[odaNumarasi-1].odaDurumu=0;
	free(odalar[odaNumarasi-1].musteri.musteriAdi);
	free(odalar[odaNumarasi-1].musteri.musteriSoyadi);	
}

void odaBilgisiSorgulama(odaBilgileri *odalar,int odaNumarasi)
{
	if(odalar[odaNumarasi-1].odaDurumu==0)
		printf("%d numarali oda musaittir.\n",odaNumarasi);
	else
		printf("%d numarali oda %d:%d:%d tarihine kadar doludur.\n",odalar[odaNumarasi-1].odaNumarasi,odalar[odaNumarasi-1].cikisTarihi.gun,odalar[odaNumarasi-1].cikisTarihi.ay,odalar[odaNumarasi-1].cikisTarihi.yil);
}

void doluOdalariYazdirma(odaBilgileri *odalar)
{
	int i;
	
	for(i=0;i<ODA_SAYISI;i++)
	{
		if(odalar[i].odaDurumu==1)
		{
			printf("%d numarali oda doludur.\n",odalar[i].odaNumarasi);
			printf("Musteri Ad-Soyad:%s %s\n",odalar[i].musteri.musteriAdi,odalar[i].musteri.musteriSoyadi);
			printf("Kisi sayisi:%d\n",odalar[i].kisiSayisi);
			printf("Giris Tarihi %d:%d:%d\n",odalar[i].girisTarihi.gun,odalar[i].girisTarihi.ay,odalar[i].girisTarihi.yil);
			printf("Cikis Tarihi %d:%d:%d\n",odalar[i].cikisTarihi.gun,odalar[i].cikisTarihi.ay,odalar[i].cikisTarihi.yil);
			printf("Fiyat bilgisi:%.2f\n",odalar[i].fiyatBilgisi);
			printf("**********************************************\n");
		}
	}
}

void fiyatBilgisiYazdirma()
{
	int kisiSayisi,gunFarki;
	tarihBilgileri girisTarihi;
	tarihBilgileri cikisTarihi;
	
	printf("Lutfen kisi bilgisini giriniz:");
	scanf("%d",&kisiSayisi);
	printf("Lutfen giris tarihini gun:ay:yil seklinde giriniz\n");
	scanf("%d:%d:%d",&girisTarihi.gun,&girisTarihi.ay,&girisTarihi.yil);
	printf("Lutfen cikis tarihini gun:ay:yil seklinde giriniz\n");
	scanf("%d:%d:%d",&cikisTarihi.gun,&cikisTarihi.ay,&cikisTarihi.yil);
	
	gunFarki=gunFarkiHesapla(girisTarihi,cikisTarihi);
	
	printf("Odemeniz gereken toplam tutar:%.2f\n",gunFarki*150.0*kisiSayisi);
}

void yedekKayitAlma(odaBilgileri *odalar)
{
	FILE *otelKayit=fopen("otelKayit.txt","a");
	int i;
	
	if(otelKayit==NULL)
	{
		fprintf(stderr,"otelKayit.txt dosyasinin acilmasi sirasinda hata meydana geldi.\n");
		exit(0);
	}
	
	for(i=0;i<ODA_SAYISI;i++)
	{
		if(odalar[i].odaDurumu==1)
		{
			fprintf(otelKayit,"Oda Numarasi:%d\nAd-Soyad:%s %s\nKisi Sayisi:%d\nGiris Tarihi:%d:%d:%d\nCikis Tarihi:%d:%d:%d\nFiyat bilgisi:%.2lf\n",odalar[i].odaNumarasi,odalar[i].musteri.musteriAdi
																																				  ,odalar[i].musteri.musteriSoyadi,odalar[i].kisiSayisi
																																				  ,odalar[i].girisTarihi.gun,odalar[i].girisTarihi.ay
																																				  ,odalar[i].girisTarihi.yil,odalar[i].cikisTarihi.gun
																																				  ,odalar[i].cikisTarihi.ay,odalar[i].cikisTarihi.yil
																																				  ,odalar[i].fiyatBilgisi);
			fprintf(otelKayit,"----------------------------------------------------\n");
		}
	}
	
	if(fclose(otelKayit)!=0)
		printf("otelKayit.txt dosyasinin kapatilmasi sirasinda hata meydana geldi.");
}

