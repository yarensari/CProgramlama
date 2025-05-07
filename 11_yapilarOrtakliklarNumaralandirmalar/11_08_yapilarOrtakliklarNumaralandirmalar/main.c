#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ORNEK-1 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	int saat;
	int dakika;
	double saniye;
}saatBilgileri;

saatBilgileri saniyeyiAyir(double);

//ORNEK-2 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	char sembol[3];
	char tamAdi[20];
	int atomNumarasi;
}element;

void bilgileriGoster(element *,char *,int);//kopyalari gonderilir *

//ORNEK-3 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	int urunID;//4byte
	double urunFiyat;//8byte
	char urunAdi[20];//20byte
}urunBilgileri;

void urunEkle(urunBilgileri *,int,double,char *);
int urunAra(urunBilgileri *,int,int);
void urunGoster(urunBilgileri *,int,int);

//ORNEK-4 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	int x;	
	int y;
}Nokta;

typedef struct
{
	Nokta koordinat[4];
}dikdortgen;

float alanHesapla(dikdortgen);


int main()
{
	//ORNEK-1:Kullanicidan alinan saniye bilgisi struct kullanilarak saat,dakika ve saniyeye donusturulecek.
	//1saat=3600saniye, 1dakika=60saniye	
	puts("ORNEK-1:");
	
	double kullaniciGirisi;
	saatBilgileri kullaniciSaati;
	
	puts("Lutfen donusturulecek olan saniye degerini giriniz:");
	scanf("%lf",&kullaniciGirisi);
	
	kullaniciSaati=saniyeyiAyir(kullaniciGirisi);
	
	printf("%dsaat %ddakika %.2lfsaniye\n",kullaniciSaati.saat,kullaniciSaati.dakika,kullaniciSaati.saniye);
	
	puts("--------------------------------------------");
	
	//ORNEK-2:Element sorgulama programi.hazir bir array olusturulacak.kullanicidan hangi elementi aramak istedigi bilgisi alinacak.bu islemler dongu icerisinde yapilacak ve kullanici cikmak istediginde dongu sonlanacak.
	puts("ORNEK-2:");
	
	int elementSayisi=5;
	char kullaniciArama[5];
	element elementListesi[]={{"H","Hidrojen",1},{"He","Helyum",2},{"B","Bor",5},{"N","Azot",7},{"F","Flor",9}};
	
	while(1)
	{
		puts("Lutfen aramak istediginiz elementin sembolunu giriniz (Cikis yapmak icin Q tuslayiniz):");
		scanf("%s",kullaniciArama);
		
		if(strcmp(kullaniciArama,"Q")==0)
		{
			printf("Cikis yapiliyor...\n");
			break;
		}
		bilgileriGoster(elementListesi,kullaniciArama,elementSayisi);
	}
	
	puts("--------------------------------------------");
	
	//ORNEK-3:Kullanicidan alinan urun sayisina gore dinamik bir dizi olusturulacak ve urun eklenmesine olanak saglanacak.Ayni zamanda kullanici bu urunu arayabilecek.Urun bilgileri id,urun fiyati ve urun adi bilgilerini icerecek.
	puts("ORNEK-3:");
	
	int urunSayisi,urunID,i,arananID;
	double urunFiyati;
	char urunAdi[20];
	urunBilgileri *urunlerListesi;
		
	puts("Lutfen gireceginiz urun sayisini tuslayiniz:");
	scanf("%d",&urunSayisi);
	urunlerListesi=(urunBilgileri *)calloc(urunSayisi,sizeof(urunlerListesi));
	
	for(i=0;i<urunSayisi;i++)
	{
		printf("Lutfen gireceginiz urunun ID degerini tuslayiniz:\n");
		scanf("%d",&urunID);
		
		printf("Lutfen gireceginiz urunun adini tuslayiniz:\n");
		scanf("%s",urunAdi);
		fflush(stdin);
		
		printf("Lutfen gireceginiz urunun fiyat bilgisini tuslayiniz:\n");
		scanf("%lf",&urunFiyati);
	
		urunEkle(urunlerListesi,urunID,urunFiyati,urunAdi);
	}
	puts("Urunler basariyla eklendi...");
	
	puts("Lutfen aradiginiz urunun ID degerini tuslayiniz:");
	scanf("%d",&arananID);
	
	urunGoster(urunlerListesi,urunSayisi,arananID);
	
	puts("--------------------------------------------");
	
	//ORNEK-4:Kullanicidan 4 adet koordinat bilgisi alinacak.Alinan bu koordinat bilgileriyle alan hesaplamasi yapilacak.Koordinat degiskenleri ic ice struct yapisi kullanilarak saglanacak
	puts("ORNEK-4:");
	
	dikdortgen kullaniciKoordinat;
	float sonuc;
	
	for(i=0;i<4;i++)//4kenar
	{
		printf("Lutfen N%d icin x ve y koordinat bilgilerini sirasiyla giriniz:\n",i);
		scanf("%d%d",&kullaniciKoordinat.koordinat[i].x,&kullaniciKoordinat.koordinat[i].y);
	}
	
	sonuc=alanHesapla(kullaniciKoordinat);
	printf("Girdiginiz koordinatlara gore olusan dikdortgenin alan degeri:%.2f\n",sonuc);
	
	return 0;
}

saatBilgileri saniyeyiAyir(double kullaniciGirisi)
{
	/*
		7350.25 bilgisi gelmis olsun.buradaki 25 salisedir.
		1saat=3600saniye
		1dakika=60saniye
		7350.25 saniye bilgisinin tam kismi saniyeyi verir.ondalikli kismi ise saliseyi verir.bu verinin int veri tipine typecast edilmesiyle tam kismi, veriden tam kismin cikartilmasiyla da ondalikli kisim
		ayri ayri elde edilir.
		
		7350saniye bilgisinde kac adet 3600 bulundugu sorusunun cevabi=saat
		7350/3600=2saat
		7350 verisinin icerdigi 3600 verilerinden kurtulmak gereklidir.bu da mod alma islemiyle saglanir ve kalan ile ayirma islemine devam edilir.
		7350%3600=150
		150/60=2dakika
		150%60=30saniye kaldi
		kalan+ondalikliKisim=saniye
		2saat2dakika30.25saniye
	*/
	saatBilgileri donusturulenSaat;
	int tamKisim;
	double ondalikliKisim;
	
	tamKisim=(int)kullaniciGirisi;//7350
	ondalikliKisim=kullaniciGirisi-tamKisim;//0.25
	
	donusturulenSaat.saat=tamKisim/3600;
	tamKisim%=3600;
	donusturulenSaat.dakika=tamKisim/60;
	tamKisim%=60;
	donusturulenSaat.saniye=tamKisim+ondalikliKisim;	
	
	return donusturulenSaat;
}

void bilgileriGoster(element *elementListesi,char *kullaniciArama,int elementSayisi)
{
	int i,bulunduMu=0;
	
	for(i=0;i<elementSayisi;i++)
	{
		if(strcmp(elementListesi[i].sembol,kullaniciArama)==0)
		{
			bulunduMu=1;	//bulundu.
			printf("Sembol:%s\n",elementListesi[i].sembol);
			printf("Tam adi:%s\n",elementListesi[i].tamAdi);
			printf("Atom numarasi:%d\n",elementListesi[i].atomNumarasi);
			break;
		}
	}
	
	if(!bulunduMu)
		printf("Girdiginiz sembole ait element bulanamadi.\n");	
}

void urunEkle(urunBilgileri *urunListesi,int urunID,double urunFiyati,char *urunAdi)
{
	int bosYer=0;
	
	while(1)
	{
		if(urunListesi[bosYer].urunID==0)
		{
			urunListesi[bosYer].urunID=urunID;
			urunListesi[bosYer].urunFiyat=urunFiyati;
			strcpy(urunListesi[bosYer].urunAdi,urunAdi);
			break;
		}
		bosYer++;
	}
}

int urunAra(urunBilgileri *urunListesi,int urunSayisi,int arananUrun)
{
	int i;
	
	for(i=0;i<urunSayisi;i++)
	{
		if(urunListesi[i].urunID==arananUrun)
			return i;//indeks degerini doner
	}
	
	return -1;//bulunamadi bilgisini doner
}

void urunGoster(urunBilgileri *urunListesi,int urunSayisi,int arananUrun)
{
	int indeks;
	
	indeks=urunAra(urunListesi,urunSayisi,arananUrun);
	
	if(indeks!=-1)
	{
		printf("Urun ID:%d\n",urunListesi[indeks].urunID);
		printf("Urun adi:%s\n",urunListesi[indeks].urunAdi);
		printf("Urun fiyat:%.2lf\n",urunListesi[indeks].urunFiyat);
	}
	else
		puts("Aranan urun listede bulunmamaktadir.");
}

float alanHesapla(dikdortgen kullaniciGirisi)
{
	/*
		N3(x1,y2)	N2(x2,y2)	y_kenar=N3-N0 || N2-N1
		N0(x1,y1)	N1(x2,y1)	x_kenar=N1-N0 || N2-N3
	*/
	int x_kenar,y_kenar;
	
	x_kenar=kullaniciGirisi.koordinat[1].x-kullaniciGirisi.koordinat[0].x;
	y_kenar=kullaniciGirisi.koordinat[3].y-kullaniciGirisi.koordinat[0].y;
	
	return x_kenar*y_kenar;
}
