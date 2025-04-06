#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char karakter  = 'a';
	char karakter2 = '5';
	
	printf("%c karakterinin hafizada kapladigi alan : %d byte\n", karakter, sizeof(karakter));
	printf("%c karakterinin decimal karsiligi : %d, hexadecimal karsiligi : %X\n", karakter, karakter, karakter);


	// isalpha, isdigit, isalnum, islower, isupper, tolower, toupper
	// yanlýþ => 0, doðru => 0'dan farklý bir deðer döner
	printf("%c karakterinin isalpha sonucu = %d\n", karakter, isalpha(karakter));		// deðiþkenin alfabetik olup olmadýðýný sorgular
	printf("%c karakterinin isalpha sonucu = %d\n", karakter2, isalpha(karakter2));		// isalpha fonksiyonuna direkt 5 ifadesi gönderilirse ascii tablosunda yer alan 5 decimal deðerinin karþýlýðýný kontrol eder
	
	printf("%c karakterinin isdigit sonucu = %d\n", karakter, isdigit(karakter));		// deðiþkenin rakam olup olmadýðýný sorgular
	printf("%c karakterinin isdigit sonucu = %d\n", karakter2, isdigit(karakter2));

	printf("%c karakterinin isalnum sonucu = %d\n", karakter, isalnum(karakter));		// deðiþkenin rakam ve alfabetik olup olmadýðýný sorgular
	printf("%c karakterinin isalnum sonucu = %d\n", karakter2, isalnum(karakter2));	
	printf("+ icin isalnum sonucu          = %d\n", isalnum('+'));
	
	printf("H karakterinin islower sonucu  = %d\n", islower('H'));						// deðiþkenin küçük olup olmadýðýný kontrol eder. küçük ise => 0'dan farklý
	printf("h karakterinin islower sonucu  = %d\n", islower('h'));
	
	printf("H karakterinin isupper sonucu  = %d\n", isupper('H'));						// deðiþkenin büyük olup olmadýðýný kontrol eder. büyük ise => 0'dan farklý
	printf("h karakterinin isupper sonucu  = %d\n", isupper('h'));
	
	printf("H icin tolower sonucu : %c\n", tolower('H'));								// karakteri büyük harfe çevirir
	printf("h icin toupper sonucu : %c\n", toupper('h'));								// karkateri küçük harfe çevirir
	
		
	// atoi ve atof fonksiyonlarý
	char karakterDizisi[] = "1234.1234";	// string ifade
	int tamSayi;
	float ondalikliSayi;
	
	tamSayi = atoi(karakterDizisi);			// atoi => string ifadeyi tam sayýya çevirir
	ondalikliSayi = atof(karakterDizisi);	// atof => string ifadeyi ondalýklý sayýya çevirir
	
	printf("String ifadenin tam sayi hali = %d\n", tamSayi);
	printf("String ifadenin ondalikli sayi hali = %.4f\n", ondalikliSayi);
	
	
	return 0;
}
