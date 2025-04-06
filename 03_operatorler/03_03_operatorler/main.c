#include <stdio.h>

int main()
{
	// �rnek - 1 : Kullan�c�dan girilen para de�erinin banknotlar�n� tespit edilir.
	int paraMiktari;
	printf("Lutfen banknot hesaplamasi yapilacak para miktarini giriniz: ");
	scanf("%d", &paraMiktari);
	
	printf("%d adet 200 TL bulunmaktadir.\n", paraMiktari/200);
	paraMiktari %= 200;		// 200TL banknotlar� ��kart�nca kalan para miktar� bulunur. 1480TL'de 7 adet 200 bulunmaktad�r. 1480 - 1400 = 80 => 1480 % 200 = 80
	
	printf("%d adet 100 TL bulunmaktadir.\n", paraMiktari/100);
	paraMiktari %= 100;
	
	printf("%d adet 50 TL bulunmaktadir.\n", paraMiktari/50);
	paraMiktari %= 50;
	
	printf("%d adet 20 TL bulunmaktadir.\n", paraMiktari/20);
	paraMiktari %= 20;
	
	printf("%d adet 10 TL bulunmaktadir.\n", paraMiktari/10);
	paraMiktari %= 10;
	
	printf("%d adet 5 TL bulunmaktadir. \n", paraMiktari/5);
	paraMiktari %= 5;
	
	printf("%d adet 1 TL bulunmaktadir. \n", paraMiktari);
	
	// �rnek - 2 : Kullan�c�dan 3 basamakl� say� istenir. Gelen bu say�n�n tersi yazd�r�l�r. 
	int sayi, geciciSayi;
	printf("Lutfen tersi alinacak sayiyi giriniz: ");
	scanf("%d", &sayi);
	printf("Duz hali : %d ", sayi);
	printf("Ters hali : ");
	geciciSayi = sayi;
	printf("%d", geciciSayi%10);			// son basamak elde edilir
	geciciSayi /= 10;						// son basamak silinir
	
	printf("%d", geciciSayi%10);			// son basamak elde edilir
	geciciSayi /= 10;						// son basamak silinir
	
	printf("%d", geciciSayi%10);			// son basamak elde edilir
		
	return 0;
}
