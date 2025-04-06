// float veri tipleri virg�lden sonra 6 basama�a kadar kesin sonu� verirken double veri tipleri 15 basama�a kadar kesin sonu� verebilmektedir
#include <stdio.h>
#include <limits.h>				// de�i�ken tiplerinin maks-min makro tan�mlamalar�n� tutar

int main()
{
	int intSayi;
	short int shortSayi;
	long int longSayi;
	long long int longlongSayi;
	float floatSayi;
	double doubleSayi;
	
	printf("int degiskenin kapladigi alan         : %lu bit\n", 8*sizeof(intSayi));
	printf("shortint degiskenin kapladigi alan    : %lu bit\n", 8*sizeof(shortSayi));
	printf("longint degiskenin kapladigi alan     : %lu bit\n", 8*sizeof(longSayi));
	printf("longlongint degiskenin kapladigi alan : %lu bit\n", 8*sizeof(longlongSayi));
	printf("float degiskenin kapladigi alan       : %lu bit\n", 8*sizeof(floatSayi));
	printf("double degiskenin kapladigi alan      : %lu bit\n", 8*sizeof(doubleSayi));
	
	floatSayi  = 5.213124124125;
	doubleSayi = 1.1241413412412981230;
	
	printf("Float deger  : %.10f\n", floatSayi);				// float de�i�ken veri tipi 6 basama�a kadar kesin sonu� verir.
	printf("Double deger : %.17f\n", doubleSayi);				// double de�i�ken veri tipi 15 basama�a kadar kesin sonu� verir.
	
	int sayiDonusum = (int)floatSayi;	// floatSayi de�i�keninde bir de�i�iklik meydana gelmez. floatSayi de�i�keninin int k�sm� sayiDonusum de�i�kenine atan�r.
	printf("Donusturulmus hali: %d\n", sayiDonusum);
	
	printf("short veri tipinin maksimum degeri : %d\n", SHRT_MAX);
	printf("short veri tipinin minimum  degeri : %d\n", SHRT_MIN);
		
	return 0;
}

