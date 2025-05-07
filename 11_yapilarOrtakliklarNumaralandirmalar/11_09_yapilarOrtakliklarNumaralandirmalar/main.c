#include <stdio.h>

//SORU-1 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	float gercekKisim;
	float sanalKisim;
}gercekSanal;

typedef struct
{
	gercekSanal sayi;	
}kompleksSayi;

kompleksSayi kompleksSayilariTopla(kompleksSayi,kompleksSayi);

//SORU-2 FONKSIYONLAR VE STRUCTLAR
typedef struct
{
	int saat;
	int dakika;
	int saniye;
}saatBilgileri;

saatBilgileri saatFarkiHesapla(saatBilgileri,saatBilgileri);

//SORU-3 VE SORU-4 FONKSIYONLAR, ENUMLAR VE STRUCTLAR
typedef struct
{
	char kitapAdi[50];
	char kitapYazari[50];
	int sayfaSayisi;
	char yayinEvi[50];
}kitapBilgileri;

typedef enum
{
	ogrenci,calisan	
}yetki;

void kitapEkle(kitapBilgileri *,int);
void kitapBul(kitapBilgileri *,int);
void tumKitaplariGoster(kitapBilgileri *,int);

int main()
{
	//SORU-1:Kompleks sayilarin toplanmasi saglanacak.Kompleks sayi tek bir degiskende tutulacak (ic ice struct)
	puts("SORU-1:");
	
	kompleksSayi kompleksSayi_1,kompleksSayi_2,kompleksSayilarin_toplami;
	
	printf("Birinci kompleks sayinin gercek kismini giriniz:");
	scanf("%f",&kompleksSayi_1.sayi.gercekKisim);
	printf("Birinci kompleks sayinin sanal kismini giriniz:");
	scanf("%f",&kompleksSayi_1.sayi.sanalKisim);
	printf("Ikinci kompleks sayinin gercek kismini giriniz:");
	scanf("%f",&kompleksSayi_2.sayi.gercekKisim);
	printf("Ikinci kompleks sayinin sanal kismini giriniz:");
	scanf("%f",&kompleksSayi_2.sayi.sanalKisim);
	
	kompleksSayilarin_toplami=kompleksSayilariTopla(kompleksSayi_1,kompleksSayi_2);
	
	if(kompleksSayilarin_toplami.sayi.sanalKisim>=0)
		printf("Girilen kompleks sayilarin toplami:%.1f+%.1fi",kompleksSayilarin_toplami.sayi.gercekKisim,kompleksSayilarin_toplami.sayi.sanalKisim);
	else
		printf("Girilen kompleks sayilarin toplami:%.1f%.1fi",kompleksSayilarin_toplami.sayi.gercekKisim,kompleksSayilarin_toplami.sayi.sanalKisim);
		
	puts("\n------------------------------------------------------");
	
	//SORU-2:Kullanýcýnda 2adet saat bilgisi alinacak.Bu saat bilgilerinde saat,dakika ve saniye bilgileri yer alacak.Girilen iki saat arasindaki farki hesaplayan fonksiyon olusturulacak.Iki saat arasindaki fark ilk saate gore yapilacak.
	puts("SORU-2:");
	
	saatBilgileri saatler[2],saatlerArasiFark;
	
	printf("Lutfen ilk saat bilgilerini saat:dakika:saniye biciminde giriniz:");
	scanf("%d:%d:%d",&saatler[0].saat,&saatler[0].dakika,&saatler[0].saniye);
	printf("Lutfen ikinci saat bilgilerini saat:dakika:saniye biciminde giriniz:");
	scanf("%d:%d:%d",&saatler[1].saat,&saatler[1].dakika,&saatler[1].saniye);
	
	saatlerArasiFark=saatFarkiHesapla(saatler[0],saatler[1]);
	
	printf("Girilen saatler arasi fark:%d:%d:%d\n",saatlerArasiFark.saat,saatlerArasiFark.dakika,saatlerArasiFark.saniye);
	
	puts("\n------------------------------------------------------");
	
	//SORU-3:Kitaplik projesi olusturulacak.kitapAdi,kitapYazari,sayfaSayisi,yayinEvi bilgilerini icerecek.Kullanicidan alinan kitap sayisina gore dinamik dizi olusturulacak.Kullaniciya sadece Q tusuna basmasiyla cikabilmesini saglayacak menu olusturulacak
	//menude kitap ekle, kitap ara ve tum kitaplari goster secenekleri olacak.
	//SORU-4:Bir onceki soruda yapilan kitaplik projesine sinirlama getirilecek.Yetkiye gore kitap eklenebilecek.Eger kullanici ogrenci ise kitap ekleyemeyecek,calisan ise ekleyebilecek.
	//yetkiler enum yapisinda tutulacak.
	puts("SORU-3 ve SORU:4");
	
	int kitapSayisi;
	kitapBilgileri *kitaplik;
	yetki kullaniciYetkisi;
	char gelenKarakter;

	puts("Lutfen kutuphanenizde kac adet kitap olacagini giriniz:");
	scanf("%d",&kitapSayisi);
	kitaplik=(kitapBilgileri*)calloc(kitapSayisi,sizeof(kitapBilgileri));
	
	puts("Kisisel kutuphanenize hos geldiniz!");
	while(1)
	{
		printf("Lutfen yetkinizi giriniz (ogrenci:0-calisan:1):");
		scanf("%d",&kullaniciYetkisi);
		puts("Kitap eklemek icin 'E', kitap bulmak icin 'B', butun kitaplari gostermek icin 'G', cikis yapmak icin 'Q' tusuna basiniz.");
		fflush(stdin);
		gelenKarakter=getchar();
		
		if(gelenKarakter=='E')
		{
			if(kullaniciYetkisi==calisan)
				kitapEkle(kitaplik,kitapSayisi);
			else
				printf("Yetkiniz kitap eklemenize izin vermemektedir.\n");
		}
		else if(gelenKarakter=='B')
			kitapBul(kitaplik,kitapSayisi);
		else if(gelenKarakter=='G')
			tumKitaplariGoster(kitaplik,kitapSayisi);
		else if(gelenKarakter=='Q')
		{
			puts("Cikis yapiliyor...");
			break;
		}
		else
			printf("Yanlis giris yaptiniz. Lutfen tekrar deneyiniz.\n");
	}
	
	return 0;
}

kompleksSayi kompleksSayilariTopla(kompleksSayi kS_1,kompleksSayi kS_2)
{
	kompleksSayi toplam;
	
	toplam.sayi.gercekKisim=kS_1.sayi.gercekKisim+kS_2.sayi.gercekKisim;
	toplam.sayi.sanalKisim=kS_1.sayi.sanalKisim+kS_2.sayi.sanalKisim;
	
	return toplam;
}

saatBilgileri saatFarkiHesapla(saatBilgileri sB_1,saatBilgileri sB_2)
{
	saatBilgileri saatFarki;

	if(sB_1.saat==sB_2.saat)
	{
		if(sB_1.dakika==sB_2.dakika)
		{
			saatFarki.saat=0;
			saatFarki.dakika=0;
			saatFarki.saniye=sB_1.saniye-sB_2.saniye;
			return saatFarki;
		}
		else
		{
			saatFarki.saat=0;
			saatFarki.dakika=sB_1.dakika-sB_2.dakika;
			saatFarki.saniye=sB_1.saniye-sB_2.saniye;
			return saatFarki;
			/*
				5:17:50---->bunun ikinci saate gore durumuna ihtiyacim var
				5:18:55
				0:-1:-5
				5:18:55---->bunun ikinci saate gore durumuna ihtiyacim var
				5:17:50
				0:1:5
			*/
		}
	}
		
	/*
		12:02:32	sB_1
		13:04:33	sB_2
		
		11:61:92	sB_1
		13:04:33	sB_2
	*/
	if(sB_1.saniye<sB_2.saniye)
	{
		sB_1.dakika-=1;
		sB_1.saniye+=60;
	}
	saatFarki.saniye=sB_1.saniye-sB_2.saniye;//92-33=59
	
	if(sB_1.dakika<sB_2.dakika)
	{
		sB_1.saat-=1;
		sB_1.dakika+=60;
	}
	saatFarki.dakika=sB_1.dakika-sB_2.dakika;//57
	
	saatFarki.saat=sB_1.saat-sB_2.saat;//-2
	
	return saatFarki;
}

void kitapEkle(kitapBilgileri *kitap,int kitapSayisi)
{
	int i,j,eklenecekKitapSayisi,kapasiteKontrol=0;
	
	printf("Kitap ekleme sayfasina hos geldiniz!\n");
	printf("Kac adet kitap ekleyeceksiniz?\n");
	scanf("%d",&eklenecekKitapSayisi);
	if(eklenecekKitapSayisi>kitapSayisi)
	{
		printf("Kutuphanenin kapasitesini asmaya sebep olacak deger girdiniz. Bu sayfadan cikis yapiliyor...\n");
		kapasiteKontrol=1;	
	}
	else
	{
		for(i=0;i<kitapSayisi;i++)
		{
			if(kitap[i].sayfaSayisi==0)
			{
				for(j=0;j<eklenecekKitapSayisi;j++)
				{
					printf("Lutfen eklemek istediginiz kitabin adini giriniz:");
					fflush(stdin);
					gets(kitap[i].kitapAdi);
					printf("Lutfen eklemek istediginiz kitabin yazarini giriniz:");
					gets(kitap[i].kitapYazari);//string ifade gets fonksiyonuyla alindigi zaman bosluktan sonra string ifadeyi sonlandirmiyor.devam ediyor almaya
					fflush(stdin);
					printf("Lutfen eklemek istediginiz kitabin sayfa sayisini giriniz:");
					scanf("%d",&kitap[i].sayfaSayisi);
					fflush(stdin);
					printf("Lutfen eklemek istediginiz kitabin yayin evini giriniz:");
					gets(kitap[i].yayinEvi);
					kapasiteKontrol=1;
					i++;
				}
				break;
			}
		}
	}
	if(kapasiteKontrol==0)
		printf("Kutuphaneniz tamamen dolu. Kitap eklenemiyor!\n");
}

void kitapBul(kitapBilgileri *kitap,int kitapSayisi)
{
	int i,bulundu=0;
	char arananKitap[50];
	
	puts("Kitap arama sayfasina hos geldiniz!");
	printf("Lutfen aramak istediginiz kitabin ismini giriniz:");
	fflush(stdin);
	gets(arananKitap);
	
	for(i=0;i<kitapSayisi;i++)
	{
		if(strcmp(arananKitap,kitap[i])==0)
		{
			printf("%s kitabi bulundu!\n",kitap[i].kitapAdi);
			printf("Kitabin yazari:%s\n",kitap[i].kitapYazari);
			printf("Kitabin sayfa sayisi:%d\n",kitap[i].sayfaSayisi);
			printf("Kitabin yayin evi:%s\n",kitap[i].yayinEvi);
			bulundu=1;
		}
	}
	
	if(bulundu==0)
		printf("Aradiginiz kitap kutuphanenizde yer almamaktadir. Bu sayfadan cikis yapiliyor...\n");
}

void tumKitaplariGoster(kitapBilgileri *kitaplik,int kitapSayisi)
{
	int i;
	
	puts("Tum kitaplar gosterilecektir...");
	for(i=0;i<kitapSayisi;i++)
	{
		if(kitaplik[i].sayfaSayisi==0)
			break;
		printf("%d. kitap gosterilmektedir.\n",i+1);
		printf("%s kitabi ",kitaplik[i].kitapAdi);
		printf("%s yazarina aittir. ",kitaplik[i].kitapYazari);
		printf("%d adet sayfadan olusmaktadir. ",kitaplik[i].sayfaSayisi);
		printf("%s yayin evi tarafindan saglanmistir.\n",kitaplik[i].yayinEvi);
		puts("******************************************");
	}
}
