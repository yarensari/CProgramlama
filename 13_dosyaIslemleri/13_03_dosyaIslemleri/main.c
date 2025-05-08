#include <stdio.h>

#define MAX_SATIR_SAYISI 50
#define MAX_KARAKTER_SAYISI 50

int main()
{
	//1satir aslinda bizim icin 1tane string demektir.
	//feof(dosya) fonksiyonu dosyanin icerisindeki verinin EOF karakterine gelip gelmedigini kontrol eder.eger EOF'ye geldiyse 1 degerini, gelmediyse 0 degerini doner
	FILE *dosya=fopen("deneme.txt","r");
	FILE *dosya2=fopen("deneme2.txt","w");
	int satirSayisi=0,kapandiMi_R,kapandiMi_W;
	char saklanacakYer[MAX_KARAKTER_SAYISI][MAX_SATIR_SAYISI];
	
	if(dosya!=NULL && dosya2!=NULL)
	{
		printf("Iki dosya da basarili bir sekilde acildi.\n");
		
		while(satirSayisi<MAX_SATIR_SAYISI && !feof(dosya))
		{
			fgets(saklanacakYer[satirSayisi],MAX_KARAKTER_SAYISI,dosya);//tutulacagiYer,maksOkuyacagiDeger,okunacakYer
			printf("%s ifadesi dosya2'ye yazildi.\n",saklanacakYer[satirSayisi]);
			fputs(saklanacakYer[satirSayisi],dosya2);//yazilacakDeger,yazilacagiYer
			satirSayisi++;
		}		
	}
	else
		printf("Dosya acilmasi sirasinda hata meydana geldi.");
	
	kapandiMi_R=fclose(dosya);
	kapandiMi_W=fclose(dosya2);
	if(kapandiMi_R==0 && kapandiMi_W==0)
		printf("Iki dosya da basarili bir sekilde kapatildi.");
	else 
		printf("Dosya kapatilmasi sirasinda bir hata meydana geldi.");
	
	return 0;
}
