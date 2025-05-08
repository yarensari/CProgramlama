#include <stdio.h>

/*
	dosya islemlerinde kullanilan fonksiyonlar:
	1. feof(FILE POINTER): Dosyanin sonuna gelinip gelinmedigini anlariz. Eger dosyanin sonuna gelindiyse 0'dan farkli bir deger doner. Eger dosyanin sonuna gelinmediyse 0 degerini doner.
		while(!feof(dosya))//dosyanin sonuna gelene kadar bu donguyu devam ettir.
		{...}
	2. rewind(FILE POINTER): Dosyanin basina donmemizi saglar.
	3. fseek(FILE POINTER, KAC BYTE, NEREDEN ITIBAREN): Bu fonksiyonla imleci belirledigimiz noktaya goturebiliriz.
		NEREDENE ITIBAREN:
		(0)SEEK_SET--->dosyanin basindan itibaren
		(1)SEEK_CUR--->kalinan yerden itibaren
		(2)SEEK_END--->dosyanin sonundan itibaren
		bu ozel ifadelerle "-" operatoru kullanilirsa geriye anlamina gelir. Eger ben son 5 ifadeye erismek istiyorsam: SEEK_END-5 ifadesini kullanirim.
	4. fteel(FILE POINTER): O anda imlecin bulundugu noktanin kacinci byte oldugunu doner. Bu da ayni zamanda karaktere denktir cunku her karakter 1byte yer kaplamaktadir.
*/

#define MAX_KARAKTER_SAYISI 50

int main()
{
	FILE *dosya=fopen("deneme.txt","r");
	FILE *dosya2=fopen("deneme2.txt","w");
	int kapandiMi_R,kapandiMi_W;
	char adSoyad[MAX_KARAKTER_SAYISI],bolumBilgisi[MAX_KARAKTER_SAYISI];
	float ortalamaBilgisi;
	
	if(dosya!=NULL && dosya2!=NULL)
	{
		printf("Dosyalar basarili bir sekilde acildi.\n\n");
		while(!feof(dosya))
		{
			fscanf(dosya,"%s %f %s",&adSoyad,&ortalamaBilgisi,&bolumBilgisi);
			printf("Ad-Soyad:%s\nOrtalama:%.2f\nBolum:%s\n----------------------------------------\n",adSoyad,ortalamaBilgisi,bolumBilgisi);
			fprintf(dosya2,"Ad-Soyad:%s\nOrtalama:%.2f\nBolum:%s\n----------------------------------------\n",adSoyad,ortalamaBilgisi,bolumBilgisi);
		}
		printf("****************************************\n");
		fprintf(dosya2,"****************************************\n");
		rewind(dosya);//eger bu fonksiyon kullanilmazsa asagidaki donguye giremez!!! bunun sebebi deneme.txt dosyasinin sonunda olmamizdir.
		while(!feof(dosya))
		{
			fscanf(dosya,"%s %f %s",&adSoyad,&ortalamaBilgisi,&bolumBilgisi);
			printf("Ad-Soyad:%s\nOrtalama:%.2f\nBolum:%s\n----------------------------------------\n",adSoyad,ortalamaBilgisi,bolumBilgisi);
			fprintf(dosya2,"Ad-Soyad:%s\nOrtalama:%.2f\nBolum:%s\n----------------------------------------\n",adSoyad,ortalamaBilgisi,bolumBilgisi);
		}
		printf("deneme2.txt sonuncu karakteri %d byte degerinde.\n",ftell(dosya2));//kacinci byte degerinde oldugunu soyler. su an dosyanin sonunda oldugu icin ayni zamanda da dosya iceriginin kac byte oldugunu da soylemekte.
		
		printf("deneme.txt sonuncu karakteri %d byte degerinde.\n",ftell(dosya));
		fseek(dosya,5,SEEK_SET);//beni dosyanin basindan itibaren 5.byte'ina gotur! SEEK_SET=0
		printf("%d byte degerinde.\n",ftell(dosya));
		fseek(dosya,5,SEEK_CUR);//beni bulundugum yerden itibaren 5byte ileri gotur! SEEK_CUR=1
		printf("%d byte degerinde.\n",ftell(dosya));
		fseek(dosya,-1,SEEK_END);//son karakterden 1byte geri gotur! SEEK_END=2
		printf("%d byte degerinde.",ftell(dosya));
	}
	else
		printf("Dosya acilmasi sirasinda hata meydana geldi.");
	
	kapandiMi_R=fclose(dosya);
	kapandiMi_W=fclose(dosya2);
	if(kapandiMi_R==0 && kapandiMi_W==0)
		printf("\nDosyalar basarili bir sekilde kapatildi.");
	else
		printf("\nDosya kapatilmasi sirasinda hata meydana geldi.");
	
	return 0;
}
