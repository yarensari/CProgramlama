#include <stdio.h>

//union:structlara benzer fakat degiskenler icin ortak bir hafizayi kullanir.bellekten tasarruf saglar.
//union'lar ortak bellek alanini kullandiklari icin deger atamasi yapildiginda hep ayni bellek alaninda degisiklik olur.yani int olan degiskene deger atandiysa ortak bellek alani kullanildigi icin diger degiskenlerdeki degerler yok olur

typedef union
{
	int intSayi;		//4byte
	float floatSayi;	//6byte
	double doubleSayi;	//8byte		struct olsaydi her degisken icin ayri ayri yer ayirirdi ve toplam ayirdigi alan=18byte olurdu.enum'larda en buyuk byte'a gore hafizada yer ayrilir:8byte
}Sayi;

int main()
{
	Sayi sayi;
	printf("%d byte\n",sizeof(sayi));
	
	sayi.intSayi=5;
	printf("%d\n",sayi.intSayi);		//burada 5 degeri yazar
	printf("%f\n",sayi.floatSayi);		//burada 0 -zaten atamasi olmadi-
	printf("%f\n\n",sayi.doubleSayi);	//burada 0 -zaten atamasi olmadi-
	
	sayi.floatSayi=3.8;
	printf("%d\n",sayi.intSayi);		//buradaki 5 degeri silinir cunku ortak bellek alanini kullaniyorlar
	printf("%f\n",sayi.floatSayi);		//burada 3.8 degeri yazilir
	printf("%f\n\n",sayi.doubleSayi);	//burada 0 -zaten atamasi olmadi-
	
	sayi.doubleSayi=5.784;
	printf("%d\n",sayi.intSayi);		//buradaki 5 degeri silinir cunku ortak bellek alanini kullaniyorlar
	printf("%f\n",sayi.floatSayi);		//buradaki 3.8 degeri silinir cunku ortak bellek alanini kullaniyorlar
	printf("%f\n\n",sayi.doubleSayi);	//burada 5.784 degeri yazilir
	
	return 0;
}
