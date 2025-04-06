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
	// yanl�� => 0, do�ru => 0'dan farkl� bir de�er d�ner
	printf("%c karakterinin isalpha sonucu = %d\n", karakter, isalpha(karakter));		// de�i�kenin alfabetik olup olmad���n� sorgular
	printf("%c karakterinin isalpha sonucu = %d\n", karakter2, isalpha(karakter2));		// isalpha fonksiyonuna direkt 5 ifadesi g�nderilirse ascii tablosunda yer alan 5 decimal de�erinin kar��l���n� kontrol eder
	
	printf("%c karakterinin isdigit sonucu = %d\n", karakter, isdigit(karakter));		// de�i�kenin rakam olup olmad���n� sorgular
	printf("%c karakterinin isdigit sonucu = %d\n", karakter2, isdigit(karakter2));

	printf("%c karakterinin isalnum sonucu = %d\n", karakter, isalnum(karakter));		// de�i�kenin rakam ve alfabetik olup olmad���n� sorgular
	printf("%c karakterinin isalnum sonucu = %d\n", karakter2, isalnum(karakter2));	
	printf("+ icin isalnum sonucu          = %d\n", isalnum('+'));
	
	printf("H karakterinin islower sonucu  = %d\n", islower('H'));						// de�i�kenin k���k olup olmad���n� kontrol eder. k���k ise => 0'dan farkl�
	printf("h karakterinin islower sonucu  = %d\n", islower('h'));
	
	printf("H karakterinin isupper sonucu  = %d\n", isupper('H'));						// de�i�kenin b�y�k olup olmad���n� kontrol eder. b�y�k ise => 0'dan farkl�
	printf("h karakterinin isupper sonucu  = %d\n", isupper('h'));
	
	printf("H icin tolower sonucu : %c\n", tolower('H'));								// karakteri b�y�k harfe �evirir
	printf("h icin toupper sonucu : %c\n", toupper('h'));								// karkateri k���k harfe �evirir
	
		
	// atoi ve atof fonksiyonlar�
	char karakterDizisi[] = "1234.1234";	// string ifade
	int tamSayi;
	float ondalikliSayi;
	
	tamSayi = atoi(karakterDizisi);			// atoi => string ifadeyi tam say�ya �evirir
	ondalikliSayi = atof(karakterDizisi);	// atof => string ifadeyi ondal�kl� say�ya �evirir
	
	printf("String ifadenin tam sayi hali = %d\n", tamSayi);
	printf("String ifadenin ondalikli sayi hali = %.4f\n", ondalikliSayi);
	
	
	return 0;
}
