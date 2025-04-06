#include <stdio.h>
#include <math.h>

int main()
{
	// SORU - 1 : Kullanýcýdan a, b ve c deðerleri alýnarak delta hesaplamasý yapýlacak. Delta hesap sonucunun 0'dan büyük olup olmadýðý yazdýrýlacak.
	// delta = b^2 - 4*a*c
	int a, b, c, delta;
	printf("Delta hesaplamasi yapilacak a, b ve c degerlerini sirasiyla giriniz: ");
	scanf("%d%d%d", &a, &b, &c);

	delta = pow(b, 2) - 4*a*c;
	printf("Delta sonucu = %d\n", delta);
	printf("Delta sonucunun 0'dan buyuk olma sorgusu : %d\n", delta > 0);
	printf("Delta sonucunun 0'dan kucuk olma sorgusu : %d\n", delta < 0);
	printf("Delta sonucunun 0'a esit olma sorgusu    : %d\n", delta == 0);
	
	// SORU - 2 : Kullanýcýdan vize, final notlarýný yüzdeleriyle birlikte alýnacak. Alýnan bu deðerlerle yüzdelik hesaplama yapýlacak. Dersin çan eðrisine göre dersi geçiyorsa 1 geçmiyorsa
	// 0 deðeri yazdýrýlacak.
	int vizeNotYuzdelik;
	float ogrenciOrtalamasi, vizeNotu, finalNotu;
	float canEgrisiNot = 60.0;
	
	printf("Vize notunu ve final notunu sirasiyla giriniz: ");
	scanf("%f%f", &vizeNotu, &finalNotu);
	printf("Vizenin yuzdelik degerini giriniz: ");
	scanf("%d", &vizeNotYuzdelik);
	
	ogrenciOrtalamasi = (vizeNotu * vizeNotYuzdelik / 100) + (finalNotu * (100 - vizeNotYuzdelik) / 100);
	printf("Ogrencinin ders ortalamasi: %.2f\n", ogrenciOrtalamasi);
	printf("Ogrencinin dersi gecme durumu(1->Gecti, 0->Kaldi): %d", ogrenciOrtalamasi >= canEgrisiNot);
	
	// SORU - 3 : Kullanýcýdan yarýçap deðeri alýnarak dairenin alaný ve çevresi hesaplanacak.
	// dairenin çevresi = 2*pi*r
	// dairenin alaný   = pi*r^2
	float yaricap, daireninCevresi, daireninAlani;
	printf("Hesaplamasi yapilacak dairenin yaricapini giriniz: ");
	scanf("%f", &yaricap);
	
	daireninCevresi = 2 * M_PI * yaricap;
	daireninAlani   = M_PI * pow(yaricap, 2);
	
	printf("Dairenin cevresi = %.2f\n", daireninCevresi);
	printf("Dairenin alani   = %.2f\n", daireninAlani);
	
	return 0;
}
