#include <stdio.h>

int main()
{
	FILE *dosya=fopen("deneme.txt","r");
	FILE *dosya2=fopen("deneme2.txt","a");
	int kapandiMi;
	char ch;
	
	if(dosya!=NULL && dosya2!=NULL)
	{
		printf("Iki dosya da basarili bir sekilde acildi.\n");
		//okuma islemi:bu islem icin fopen'da acma modu olarak "r" gonderilmelidir!!!fgetc:file getc komutuyla alinmaktadir.dosyanin icerisinde yer alan verinin en sonunda EOF yer almaktadir.bu sayede verinin sonuna gelindigi anlasilir.
		//yazma islemi:bu islem icin fopen'da acma modu olarak "w" ya da "a" gonderilmelidir!!!fputc komutuyla yazma islemi gerceklesmektedir.
		do{
			ch=fgetc(dosya);
			putchar(ch);
			fputc(ch,dosya2);//int bir deger bekler ve bu deger yazilacak olan degerdir bunun yaninda yazilma isleminin yapilacagi dosyanin adresini bekler
		}while(ch!=EOF);//end of the file
		
		kapandiMi=fclose(dosya);
		if(kapandiMi==0)
			printf("\nOkuma yapilacak olan dosya basariyla kapatilmistir.");
		else
			printf("\nOkuma yapilacak olan dosya kapatilmasi sirasinda hata meydana geldi.");
			
		kapandiMi=fclose(dosya2);
		if(kapandiMi==0)
			printf("\nYazma yapilacak olan dosya basariyla kapatilmistir.");
		else
			printf("\nYazma yapilacak olan dosya kapatilmasi sirasinda hata meydana geldi.");
	}
	else
		printf("Dosyalar acilirken hata meydana geldi.");
		
	return 0;
}
