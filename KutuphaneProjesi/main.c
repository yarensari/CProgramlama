/*
	Kutuphane Projesi
	
	Calisan ve ogrenci yetkileri tanimlanacaktir.
	Bir giris sayfasi olusturulacaktir. Kullaniciya var olan id ve sifre degeriyle giris yapma sansi verilecektir. Bunun disinda yeni uyelik olusturmasi saglanacaktir. Yeni uyelik sirasinda yetki atamasi saglanacaktir.
	Kullanici sisteme giris yaptiginda yetkisine gore yapabilecegi islemler sunulacaktir. 
	Eger kullanici ogrenci ise:
	- Kitaplari goruntuleyebilecektir.
	- Kitap arama islemini yapabilecektir.
	Eger kullanici calisan ise:
	- Yeni kitap ekleyebilecektir.
	- Uye listesini goruntuleyebilecektir.
	
	Programin basinda uyeBilgileri.txt ve kitapBilgileri.txt dosyasinda yer alan veriler dinamik bir sekilde olusturulan dizilere aktarilir ve program boyunca bu diziler kullanilir. 
	Programin sonunda uzerinde islemler yapilan diziler uyeBilgileri.txt ve kitapBilgileri.txt dosyalarina tekrardan aktarilir.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KITAP_SAYISI 50
#define MAX_UYE_SAYISI 50

//kayit olan kisinin yetkisi
typedef enum
{
	ogrenci,calisan
}kisiYetkiSeviyeleri;

//kutuphaneye uye olan kisilerin bilgileri
typedef struct
{
	char *kisiAdi;
	char *kisiSoyadi;
	int kutuphaneID;
	char sifre[17];//maks 16 karakter icerebilir.
	kisiYetkiSeviyeleri yetki;
}kisiBilgileri;

//kutuphanede yer alan kitap bilgileri
typedef struct
{
	char *kitapAdi;
	char *kitapYazarAdi;
	char *yayinEvi;
	int sayfaSayisi;
	int kitapDurumu;//kitap bosta mi yoksa alindi mi
}kitapBilgileri;

void uyeleriAktar(kisiBilgileri *);//tum uyelerin bilgilerinin bulundugu dosyadan bilgileri okuyup uyeListesi dizisine kaydedecektir.
void kitaplariAktar(kitapBilgileri *);//tum kitap bilgilerinin bulundugu dosyadan bilgileri okuyup kitaplik dizisine kaydedecektir.
int girisYap(kisiBilgileri *);//uyenin giris yapmasini saglar.
void kayitOl(kisiBilgileri *);//uyenin kayit islemini yapar.
int kisiSorgula(kisiBilgileri *,int);//id degerini degisken olarak alir. eger id degeri daha once kullanildiysa o id degerini doner. kullanilmadiysa 1 degerini doner.
void kitaplariGoruntule(kitapBilgileri *);//butun kitaplarin bilgilerini goruntuler.
void kitapAra(kitapBilgileri *);//kullanicidan alinan kitap adinin daha once kaydedilip kaydedilmedigini kontrol eder. kitap adi fonksiyonun icerisindeyken alinir.
void kitapEkle(kitapBilgileri *);//calisan yetkisine sahip olan kisi kitap ekleyebilir.
void uyeleriGoruntule(kisiBilgileri *);//calisan yetkisine sahip olan kisi butun uyeleri goruntuleyebilecektir.
void uyeleriYedekle(kisiBilgileri *);//uye bilgileri yedeklenir.
void kitaplariYedekle(kitapBilgileri *);//kitap bilgileri yedeklenir.

int main()
{
	kisiBilgileri *uyeListesi;//uye bilgilerini tutacak.
	kitapBilgileri *kitapListesi;//kitap bilgilerini tutacak.
	char kullaniciIstegi;
	int kullaniciSeviyesi;
	
	uyeListesi=(kisiBilgileri *)calloc(MAX_UYE_SAYISI,sizeof(kisiBilgileri));//dinamik sekilde array olusturulur.
	kitapListesi=(kitapBilgileri *)calloc(MAX_KITAP_SAYISI,sizeof(kitapBilgileri));
	
	uyeleriAktar(uyeListesi);//uyeBilgileri.txt dosyasindan veriler alinir.
	kitaplariAktar(kitapListesi);//kitapBilgileri.txt dosyasindan veriler alinir.
	
	printf("Kutuphaneye Hos Geldiniz.\n");
	do
	{
		printf("Eger uyeliginiz var ise 'G' yok ise 'O' tusuna basiniz. Cikis yapmak icin 'Q' tusuna basiniz.\n");
		fflush(stdin);
		scanf("%c",&kullaniciIstegi);
		
		if(kullaniciIstegi=='G' || kullaniciIstegi=='g')
		{
			printf("Giris sayfasina hos geldiniz.\n");
			kullaniciSeviyesi=girisYap(uyeListesi);
			if(kullaniciSeviyesi==-2)
			{
				printf("Girilen ID degeriyle eslesen uye bulunmamaktadir.\n");
				printf("Tekrar deneyiniz.\n");
			}
			else if(kullaniciSeviyesi==-1)
			{
				printf("Girilen sifre yanlistir.\n");
				printf("Tekrar deneyiniz.\n");
			}
			else if(kullaniciSeviyesi==calisan)
			{
				printf("Calisan girisi yapildi.\n");
				while(1)
				{
					char kullaniciIstegi;
					
					printf("Yeni kitap eklemek icin 'E'\nUyeleri goruntulemek icin 'G'\nGiris menusune donmek icin 'Q' tusuna basiniz.\n");
					fflush(stdin);
					scanf("%c",&kullaniciIstegi);
					
					if(kullaniciIstegi=='E' || kullaniciIstegi=='e')
					{
						printf("Yeni kitap ekleme sayfasina hos geldiniz.\n");
						kitapEkle(kitapListesi);
					}
					else if(kullaniciIstegi=='G' || kullaniciIstegi=='g')
					{
						printf("Uyeleri goruntuleme sayfasina hos geldiniz.\n");
						uyeleriGoruntule(uyeListesi);
					}
					else if(kullaniciIstegi=='Q' || kullaniciIstegi=='q')
					{
						printf("Giris menusune donus yapiliyor...\n");
						break;
					}
					else
						printf("Yanlis giris yaptiniz.\n");
				}
			}
			else if(kullaniciSeviyesi==ogrenci)
			{
				printf("Ogrenci girisi yapildi.\n");
				while(1)
				{
					char kullaniciIstegi;
					printf("Kitap goruntulemek icin 'G'\nKitap aramak icin 'A'\nGiris menusune donmek icin 'Q' tusuna basiniz.\n");
					fflush(stdin);
					scanf("%c",&kullaniciIstegi);//kullaniciIstegi while(1) icin local degiskendir ve global degiskenden daha onceliklidir.
					if(kullaniciIstegi=='G' || kullaniciIstegi=='g')
					{
						printf("Kitap goruntuleme sayfasina hos geldiniz.\n");
						kitaplariGoruntule(kitapListesi);
					}
					else if(kullaniciIstegi=='A' || kullaniciIstegi=='a')
					{
						printf("Kitap arama sayfasina hos geldiniz.\n");
						kitapAra(kitapListesi);
					}
					else if(kullaniciIstegi=='Q' || kullaniciIstegi=='q')
					{
						printf("Giris menusune donus yapiliyor...\n");
						break;
					}
					else
						printf("Yanlis bir tuslama yaptiniz.\nLutfen tekrar deneyiniz.\n");
				}
			}
		}
		else if(kullaniciIstegi=='O' || kullaniciIstegi=='o')
		{
			printf("Kayit olma sayfasina hos geldiniz.\n");
			kayitOl(uyeListesi);
		}
		else if(kullaniciIstegi != 'Q' && kullaniciIstegi!='q')
			printf("Yanlis bir tuslama yaptiniz. Tekrar deneyiniz.\n");
		
	}while(kullaniciIstegi!='Q' && kullaniciIstegi!='q');
	
	printf("Sistemden cikis yapildi.\n");
	uyeleriYedekle(uyeListesi);
	kitaplariYedekle(kitapListesi);
	
	return 0;
}

void uyeleriAktar(kisiBilgileri *uyeListesi)
{
	FILE *uyeDosyasi=fopen("uyeBilgileri.txt","r");
	int kapandiMi,i=0;
	char uyeAdi[50];
	char uyeSoyadi[50];

	if(uyeDosyasi==NULL)
	{
		fprintf(stderr,"uyeBilgileri.txt dosyasi acilirken hata meydana geldi.");
		exit(1);//exit(0) program basarili bir sekilde kapatildi anlamina gelir. exit(1) hata sebebiyle kapatildi anlamina gelir.
	}
	
	while(!feof(uyeDosyasi))
	{
		fscanf(uyeDosyasi,"%s\t%s\t%d\t%s\t%d\n",&uyeAdi,&uyeSoyadi,&uyeListesi[i].kutuphaneID,&uyeListesi[i].sifre,&uyeListesi[i].yetki);
		uyeListesi[i].kisiAdi=(char *)malloc(strlen(uyeAdi)*sizeof(char)+1);//null karakter icin +1
		uyeListesi[i].kisiSoyadi=(char *)malloc(strlen(uyeSoyadi)*sizeof(char)+1);
			
		strcpy(uyeListesi[i].kisiAdi,uyeAdi);
		strcpy(uyeListesi[i].kisiSoyadi,uyeSoyadi);	
		i++;		
	}
	
	kapandiMi=fclose(uyeDosyasi);
	if(kapandiMi!=0)
	{
		printf("uyeBilgileri.txt dosyasi kapatilirken hata meydana geldi.");
		exit(1);	
	}
}

void kitaplariAktar(kitapBilgileri *kitaplik)
{
	FILE *kitaplikDosyasi=fopen("kitapBilgileri.txt","r");
	int kapandiMi,i=0;
	char kitapAdi[50];
	char kitapYazari[50];
	char yayinEvi[50];
	
	if(kitaplikDosyasi==NULL)
	{
		fprintf(stderr,"kitapBilgileri.txt dosyasi acilirken hata meydana geldi.");
		exit(1);
	}

	while(!feof(kitaplikDosyasi))
	{
		fscanf(kitaplikDosyasi,"%s\t%s\t%s\t%d\t%d\n",&kitapAdi,&kitapYazari,&yayinEvi,&kitaplik[i].sayfaSayisi,&kitaplik[i].kitapDurumu);
	
		kitaplik[i].kitapAdi=(char *)malloc(strlen(kitapAdi)*sizeof(char)+1);
		kitaplik[i].kitapYazarAdi=(char *)malloc(strlen(kitapYazari)*sizeof(char)+1);
		kitaplik[i].yayinEvi=(char *)malloc(strlen(yayinEvi)*sizeof(char)+1);
			
		strcpy(kitaplik[i].kitapAdi,kitapAdi);
		strcpy(kitaplik[i].kitapYazarAdi,kitapYazari);
		strcpy(kitaplik[i].yayinEvi,yayinEvi);	
		i++;		
	}
	
	kapandiMi=fclose(kitaplikDosyasi);
	if(kapandiMi!=0)
	{
		printf("kitaplikDosyasi.txt dosyasi kapatilirken hata meydana geldi.");
		exit(1);
	}
}

int girisYap(kisiBilgileri *uyeListesi)
{
	int i;
	int idBilgisi;
	char sifreBilgisi[17];
	
	printf("Lutfen sisteme kayitli olan ID bilginizi giriniz.\n");
	scanf("%d",&idBilgisi);
	
	printf("Lutfen sisteme kayitli olan sifre bilginizi giriniz.\n");
	scanf("%s",&sifreBilgisi);
	
	for(i=0;i<MAX_UYE_SAYISI;i++)
	{
		if(uyeListesi[i].kutuphaneID==idBilgisi)
		{
			if(strcmp(uyeListesi[i].sifre,sifreBilgisi)==0)
			{
				printf("Giris islemi basariyla yapildi.\n");
				printf("Hos geldin %s\n",uyeListesi[i].kisiAdi);
				return uyeListesi[i].yetki;//yetkiSeviyesi return edilir.
			}
			return -1;//sifre basarisiz.
		}
	}
	
	return -2;//girilen id ile uyusan uye yok.
}

void kayitOl(kisiBilgileri *uyeListesi)
{
	srand(time(NULL));
	char kullaniciSifre[17];//maks 16 karakter icerebilir.
	char kullaniciGiris;
	int kullaniciID;
	int IDKontrol,i;
	char kullaniciAdi[50],kullaniciSoyadi[50];
	
	for(i=0;i<MAX_UYE_SAYISI;i++)
	{
		if(uyeListesi[i].kutuphaneID==0)
			break;
	}
	
	kullaniciID=rand()%1000;//0 ile 1000 arasinda uretilecek.
	IDKontrol=kisiSorgula(uyeListesi,kullaniciID);
	while(IDKontrol!=1)//ID daha once kullanildi.
	{
		printf("ID araniyor...\n");
		kullaniciID=rand()%1000;
		IDKontrol=kisiSorgula(uyeListesi,kullaniciID);
	}
	
	//ID atandi.
	uyeListesi[i].kutuphaneID=kullaniciID;
	printf("Kutuphane ID numaraniz:%d\n",uyeListesi[i].kutuphaneID);
	printf("Lutfen adinizi giriniz:");
	scanf("%s",&kullaniciAdi);
	printf("Lutfen soyadinizi giriniz:");
	scanf("%s",&kullaniciSoyadi);
	
	uyeListesi[i].kisiAdi=(char *)malloc(strlen(kullaniciAdi)*sizeof(char)+1);
	uyeListesi[i].kisiSoyadi=(char *)malloc(strlen(kullaniciSoyadi)*sizeof(char)+1);
	
	strcpy(uyeListesi[i].kisiAdi,kullaniciAdi);
	strcpy(uyeListesi[i].kisiSoyadi,kullaniciSoyadi);
	
	while(1)
	{
		printf("Lutfen sifrenizi giriniz:");
		scanf("%s",&kullaniciSifre);
		if(strlen(kullaniciSifre)>16)
		{
			printf("Maksimum 16 karakterli sifre olusturabilirsiniz.\nLutfen tekrar deneyinizi.\n");
			kullaniciSifre[0]='\0';
		}
		else
		{
			strcpy(uyeListesi[i].sifre,kullaniciSifre);
			break;
		}
	}
	printf("Lutfen yetkinizi giriniz. Ogrenci iseniz 0, calisan iseniz 1 tuslayiniz.\n");
	scanf("%d",&uyeListesi[i].yetki);
	
	printf("Uyelik isleminiz basariyla gerceklesmistir.\nLutfen ID ve sifre degerlerinizi unutmayiniz.\nID:%d\nSifre:%s\n",uyeListesi[i].kutuphaneID,uyeListesi[i].sifre);
	printf("Sisteme bu bilgilerle giris yapabilirsiniz.\n");
}

int kisiSorgula(kisiBilgileri *uyeListesi,int ID)
{
	int i;
	
	for(i=0;i<MAX_UYE_SAYISI;i++)
	{
		if(uyeListesi[i].kutuphaneID==ID)
			return ID;
	}
	
	return 1;//ID kullanilmamistir.
}

void kitaplariGoruntule(kitapBilgileri *kitaplik)
{
	int i;
	
	for(i=0;i<MAX_KITAP_SAYISI;i++)
	{
		if(kitaplik[i].sayfaSayisi==0)
			break;
			
		printf("%d. kitap gosterilmektedir.\n",i+1);
		printf("Kitap Adi:%s\n",kitaplik[i].kitapAdi);
		printf("Kitap Yazari:%s\n",kitaplik[i].kitapYazarAdi);
		printf("Kitap Yayin Evi:%s\n",kitaplik[i].yayinEvi);
		printf("Kitap sayfa sayisi:%d\n",kitaplik[i].sayfaSayisi);
		if(kitaplik[i].kitapDurumu==1)
			printf("Kitap su an musait degildir.\n");
		else
			printf("Kitap su an musaittir.\n");
		printf("----------------------------------------------\n");
	}
}

void kitapAra(kitapBilgileri *kitaplik)
{
	char arananKitap[50];
	int i,bulunduMu=0;
	
	printf("Lutfen aramak istediginiz kitabi giriniz:");
	scanf("%s",&arananKitap);
	
	for(i=0;i<MAX_KITAP_SAYISI;i++)
	{
		if(kitaplik[i].sayfaSayisi==0)
			break;
		if(strcmp(arananKitap,kitaplik[i].kitapAdi)==0)
		{
			bulunduMu=1;
			printf("%s kitabi kutuphanede bulundu!\n",kitaplik[i].kitapAdi);
			printf("Kitap Adi:%s\n",kitaplik[i].kitapAdi);
			printf("Kitap Yazari:%s\n",kitaplik[i].kitapYazarAdi);
			printf("Kitap Yayin Evi:%s\n",kitaplik[i].yayinEvi);
			printf("Kitap sayfa sayisi:%d\n",kitaplik[i].sayfaSayisi);
			if(kitaplik[i].kitapDurumu==1)
				printf("Kitap su an musait degildir.\n");
			else
				printf("Kitap su an musaittir.\n");	
			break;		
		}
	}
	if(bulunduMu==0)
		printf("%s kitabi kutuphanede bulunmamaktadir.\n",arananKitap);
}

void kitapEkle(kitapBilgileri *kitaplik)
{
	int i,kitapVar=0;
	char kitapAdi[50];
	char kitapYazari[50];
	char kitapYayinEvi[50];
	
	for(i=0;i<MAX_KITAP_SAYISI;i++)
	{
		if(kitaplik[i].sayfaSayisi==0)
			break;
	}
	
	if(i+1>50)
		printf("Kutuphane doludur.\nKitap eklenemiyor.\n");
	else
	{
		printf("Lutfen eklemek istediginiz kitabin adini giriniz:");
		scanf("%s",&kitapAdi);
		printf("Lutfen eklemek istediginiz kitabin yazarini giriniz:");
		scanf("%s",&kitapYazari);
		printf("Lutfen eklemek istediginiz kitabin yayin evini giriniz:");
		scanf("%s",&kitapYayinEvi);
		
		kitaplik[i].kitapAdi=(char *)malloc(strlen(kitapAdi)*sizeof(char)+1);
		kitaplik[i].kitapYazarAdi=(char *)malloc(strlen(kitapYazari)*sizeof(char)+1);
		kitaplik[i].yayinEvi=(char *)malloc(strlen(kitapYayinEvi)*sizeof(char)+1);
		
		strcpy(kitaplik[i].kitapAdi,kitapAdi);
		strcpy(kitaplik[i].kitapYazarAdi,kitapYazari);
		strcpy(kitaplik[i].yayinEvi,kitapYayinEvi);
		
		printf("Lutfen eklemek istediginiz kitabin sayfa sayisini giriniz:");
		scanf("%d",&kitaplik[i].sayfaSayisi);
	}
}

void uyeleriGoruntule(kisiBilgileri *uyeListesi)
{
	int i;
	
	for(i=0;i<MAX_UYE_SAYISI;i++)
	{
		if(uyeListesi[i].kutuphaneID==0)
			break;
		printf("%d numarali uyenin bilgileri:\n",i+1);
		printf("Uye Ad:%s\n",uyeListesi[i].kisiAdi);
		printf("Uye Soyad:%s\n",uyeListesi[i].kisiSoyadi);
		if(uyeListesi[i].yetki==ogrenci)
			printf("Uye Yetki:Ogrenci\n");
		else
			printf("Uye Yetki:Calisan\n");
		printf("Uye ID:%d\n",uyeListesi[i].kutuphaneID);
		printf("Uye Sifre:%s\n",uyeListesi[i].sifre);
		printf("----------------------------------------------\n");
	}
}

void uyeleriYedekle(kisiBilgileri *uyeListesi)
{
	FILE *uyelerDosyasi=fopen("uyeBilgileri.txt","w");
	int i,kapandiMi;
	
	if(uyelerDosyasi==NULL)
	{
		fprintf(stderr,"uyelerDosyasi.txt dosyasi acilirken hata meydana geldi.\n");
		exit(0);
	}
	
	for(i=0;i<MAX_UYE_SAYISI;i++)
	{
		if(uyeListesi[i].kutuphaneID==0)
			break;
		fprintf(uyelerDosyasi,"%s\t%s\t%d\t%s\t%d\n",uyeListesi[i].kisiAdi,uyeListesi[i].kisiSoyadi,uyeListesi[i].kutuphaneID,uyeListesi[i].sifre,uyeListesi[i].yetki);
	}
	
	kapandiMi=fclose(uyelerDosyasi);
	if(kapandiMi!=0)
		printf("uyeBilgileri.txt dosyasi kapatilirken hata meydana geldi.\n");
	else
		printf("Uyelerin yedekleme islemi basariyla yapildi.\n");	
}

void kitaplariYedekle(kitapBilgileri *kitaplik)
{
	FILE *kitaplarDosyasi=fopen("kitapBilgileri.txt","w");
	int i,kapandiMi;
	
	if(kitaplarDosyasi==NULL)
	{
		fprintf(stderr,"kitapBilgileri.txt dosyasi acilirken hata meydana geldi.");
		exit(0);
	}
	
	for(i=0;i<MAX_KITAP_SAYISI;i++)
	{
		if(kitaplik[i].sayfaSayisi==0)
			break;
		fprintf(kitaplarDosyasi,"%s\t%s\t%s\t%d\t%d\n",kitaplik[i].kitapAdi,kitaplik[i].kitapYazarAdi,kitaplik[i].yayinEvi,kitaplik[i].sayfaSayisi,kitaplik[i].kitapDurumu);
	}
	
	kapandiMi=fclose(kitaplarDosyasi);
	if(kapandiMi!=0)
		printf("kitapBilgileri.txt dosyasi kapatilirken hata meydana geldi.");
	else
		printf("Kitaplarin yedekleme islemi basariyla yapildi.");
}
