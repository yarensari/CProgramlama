// float veri tipleri virgülden sonra 6 basamaða kadar kesin sonuç verirken double veri tipleri 15 basamaða kadar kesin sonuç verebilmektedir
#include <stdio.h>
#include <limits.h>				// deðiþken tiplerinin maks-min makro tanýmlamalarýný tutar

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
	
	printf("Float deger  : %.10f\n", floatSayi);				// float deðiþken veri tipi 6 basamaða kadar kesin sonuç verir.
	printf("Double deger : %.17f\n", doubleSayi);				// double deðiþken veri tipi 15 basamaða kadar kesin sonuç verir.
	
	int sayiDonusum = (int)floatSayi;	// floatSayi deðiþkeninde bir deðiþiklik meydana gelmez. floatSayi deðiþkeninin int kýsmý sayiDonusum deðiþkenine atanýr.
	printf("Donusturulmus hali: %d\n", sayiDonusum);
	
	printf("short veri tipinin maksimum degeri : %d\n", SHRT_MAX);
	printf("short veri tipinin minimum  degeri : %d\n", SHRT_MIN);
		
	return 0;
}

