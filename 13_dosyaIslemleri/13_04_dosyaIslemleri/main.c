#include <stdio.h>

#define MAX_KARAKTER_SAYISI 50

int main()
{
	FILE *dosya=fopen("deneme.txt","r");
	FILE *dosya2=fopen("deneme2.txt","w");
	char adSoyad[MAX_KARAKTER_SAYISI],bolumBilgisi[MAX_KARAKTER_SAYISI];
	float ortalamaBilgisi;
	int kapandiMi_R,kapandiMi_W;
	
	if(dosya!=NULL && dosya2!=NULL)
	{
		printf("Iki dosya da basarili bir sekilde acildi.\n");
		
		fscanf(dosya,"%s %f %s",&adSoyad,&ortalamaBilgisi,&bolumBilgisi);//dosyadan veri okumasini ve degiskene atanmasini saglar.
		printf("Ad-Soyad:%s\nOrtlama:%.2f\nBolum:%s\n",adSoyad,ortalamaBilgisi,bolumBilgisi);
		fprintf(dosya2,"AdSoyad:%s\nOrtalama:%.2f\nBolum:%s",adSoyad,ortalamaBilgisi,bolumBilgisi);//dosyaya veri yazmasini saglar
		/*
			fprintf ile printf fscanf ile de scanf birbirine cok benzerdir. Farklari yazildiklari yerlerdir
			printf ile konsola deger yazilirken fprintf ile dosyaya deger yazilir.
			scanf ile konsoldan deger alinirken fscanf ile dosyaya deger yazilir.
		*/
	}
	else
		printf("Dosya acilmasi sirasinda hata meydana geldi.");
		
	kapandiMi_R=fclose(dosya);
	kapandiMi_W=fclose(dosya2);
	if(kapandiMi_R==0 && kapandiMi_W==0)
		printf("Iki dosya da basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda hata meydana geldi.");

	return 0;
}
