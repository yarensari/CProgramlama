#include <stdio.h>
#include <math.h>

int main()
{
	// SORU - 1 : Kullan�c�dan a, b ve c de�erleri al�narak delta hesaplamas� yap�lacak. Delta hesap sonucunun 0'dan b�y�k olup olmad��� yazd�r�lacak.
	// delta = b^2 - 4*a*c
	int a, b, c, delta;
	printf("Delta hesaplamasi yapilacak a, b ve c degerlerini sirasiyla giriniz: ");
	scanf("%d%d%d", &a, &b, &c);

	delta = pow(b, 2) - 4*a*c;
	printf("Delta sonucu = %d\n", delta);
	printf("Delta sonucunun 0'dan buyuk olma sorgusu : %d\n", delta > 0);
	printf("Delta sonucunun 0'dan kucuk olma sorgusu : %d\n", delta < 0);
	printf("Delta sonucunun 0'a esit olma sorgusu    : %d\n", delta == 0);
	
	// SORU - 2 : Kullan�c�dan vize, final notlar�n� y�zdeleriyle birlikte al�nacak. Al�nan bu de�erlerle y�zdelik hesaplama yap�lacak. Dersin �an e�risine g�re dersi ge�iyorsa 1 ge�miyorsa
	// 0 de�eri yazd�r�lacak.
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
	
	// SORU - 3 : Kullan�c�dan yar��ap de�eri al�narak dairenin alan� ve �evresi hesaplanacak.
	// dairenin �evresi = 2*pi*r
	// dairenin alan�   = pi*r^2
	float yaricap, daireninCevresi, daireninAlani;
	printf("Hesaplamasi yapilacak dairenin yaricapini giriniz: ");
	scanf("%f", &yaricap);
	
	daireninCevresi = 2 * M_PI * yaricap;
	daireninAlani   = M_PI * pow(yaricap, 2);
	
	printf("Dairenin cevresi = %.2f\n", daireninCevresi);
	printf("Dairenin alani   = %.2f\n", daireninAlani);
	
	return 0;
}
