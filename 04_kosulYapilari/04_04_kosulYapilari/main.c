#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	// SORU - 1 : tolower, toupper, islower, isupper, isalpha, isalnum, isdigit fonksiyonlar� yaz�lacak.
	
	printf("SORU - 1\n");
	
	char karakter;
	
	// tolower (b�y�k => k���k)
	printf("tolower islemi yapilacak karakteri giriniz: ");
	karakter = getchar();					// tek bir karakter almay� sa�lar
	
	// k���k karakter ise if blo�una girmeden devam edecek
	if(karakter >= 65 && karakter <= 90)	// b�y�k karakter kontrol�
		karakter += 32;						// k���k karakter yap
	
	printf("karakter : ");
	putchar(karakter);						// char de�erini yazd�r�r
	
	printf("\n*********************************\n");
	
	// toupper (k���k => b�y�k)
	printf("toupper islemi yapilacak karakteri giriniz: ");
	fflush(stdin);
	karakter = getchar();
	
	// b�y�k karakter ise if blo�una girmeden devam edecek
	if(karakter >= 97 && karakter <= 122)	// k���k karakter kontrol�
		karakter -= 32;						// b�y�k karakter yap
		
	printf("karakter : %c", karakter);
	
	printf("\n*********************************\n");
	
	// islower (k���k m�?)
	printf("Kucuk harf kontrolu yapilacak karakteri giriniz: ");
	fflush(stdin);	
	karakter = getchar();
	
	if(karakter >= 97 && karakter <= 122)	// if(karakter >= 'a' && karakter <= 'z')
		printf("Girilen karakter kucuk harftir.");
	else 
		printf("Girilen karakter kucuk harf degildir.");
		
	printf("\n*********************************\n");
	
	// isupper (b�y�k m�?)
	printf("Buyuk harf kontrolu yapilacak karakteri giriniz: ");
	fflush(stdin);	
	karakter = getchar();
	
	if(karakter >= 65 && karakter <= 90)
		printf("Girilen karakter buyuk harftir.");
	else 
		printf("Girilen karakter buyuk harf degildir.");
		
	printf("\n*********************************\n");	
	
	// isalpha (alfabetik mi?)
	printf("Alfabetik kontrolu yapilacak karakteri giriniz: ");
	fflush(stdin);	
	karakter = getchar();
	
	if(karakter >= 97 && karakter <= 122 || karakter >=65 && karakter <= 90)
		printf("Girilen karakter alfabetiktir.");
	else 
		printf("Girilen karakter alfabetik degildir.");
		
	printf("\n*********************************\n");
	
	// isalnum (alfabetik veya numara m�?)
	printf("Alfabetik veya numara kontrolu yapilacak karakteri giriniz: ");
	fflush(stdin);	
	karakter = getchar();
	
	if(karakter >= 97 && karakter <= 122 || karakter >=65 && karakter <= 90 || karakter >= 48 && karakter <= 57)
		printf("Girilen karakter alfabetik veya numaradir.");
	else 
		printf("Girilen karakter alfabetik veya numara degildir.");
		
	printf("\n*********************************\n");
	
	// isdigit (numara m�?)
	printf("Numara kontrolu yapilacak karakteri giriniz: ");
	fflush(stdin);
	karakter = getchar();
	
	if(karakter >= 48 && karakter <= 57)
		printf("Girilen karakter bir numaradir.");
	else
		printf("Girilen karakter bir numara degildir.");
		
	printf("\n************************************************\n");

	// SORU - 2 : Kullan�c�dan al�nana maksimum 5 basamakl� say�n�n ka� basamakl� oldu�unu bul.
	
	/*printf("SORU - 2\n");
	
	int kullaniciSayisi, basamakSayisi = 0;
	printf("Lutfen basamak hesabi yapilacak olan sayiyi giriniz: ");
	scanf("%d", &kullaniciSayisi);
	
	kullaniciSayisi /= 10;				// ilk b�lme i�lemi yap�l�r
	basamakSayisi++;
	if(kullaniciSayisi == 0)
	{
		printf("%d basamaklidir.", basamakSayisi);
		return 0;
	}
	
	kullaniciSayisi /= 10;				// return edilmedi�ine g�re buradan devam edecektir
	basamakSayisi++;
	if(kullaniciSayisi == 0)
	{
		printf("%d basamaklidir.", basamakSayisi);
		return 0;
	}
	
	kullaniciSayisi /= 10;				// return edilmedi�ine g�re buradan devam edecektir
	basamakSayisi++;
	if(kullaniciSayisi == 0)
	{
		printf("%d basamaklidir.", basamakSayisi);
		return 0;
	}
	
	kullaniciSayisi /= 10;				// return edilmedi�ine g�re buradan devam edecektir
	basamakSayisi++;
	if(kullaniciSayisi == 0)
	{
		printf("%d basamaklidir.", basamakSayisi);
		return 0;
	}
	
	kullaniciSayisi /= 10;				// return edilmedi�ine g�re buradan devam edecektir
	basamakSayisi++;
	if(kullaniciSayisi == 0)
	{
		printf("%d basamaklidir.", basamakSayisi);
		return 0;
	}
	
	kullaniciSayisi /= 10;				// return edilmedi�ine g�re buradan devam edecektir
	basamakSayisi++;
	if(kullaniciSayisi == 0)
	{
		printf("%d basamaklidir.", basamakSayisi);
		return 0;
	}
	
	printf("Girilen deger format disidir (6 basamaktan fazla).");
	
	printf("\n************************************************\n");*/
	
	// SORUNUN FARKLI ��Z�M� -KURS ��Z�M�-
	printf("SORU - 2 KURS COZUMU\n");
	int randomSayi;
	srand(time(NULL));
	randomSayi = rand()%100000;
	printf("Uretilen sayi : %d\n", randomSayi);
	
	if(randomSayi < 10)
		printf("Uretilen sayi tek basamaklidir.\n");
	else if(randomSayi < 100)
		printf("Uretilen sayi iki basamaklidir.\n");
	else if(randomSayi < 1000)
		printf("Uretilen sayi uc basamaklidir.\n");
	else if(randomSayi < 10000)
		printf("Uretilen sayi dort basamaklidir.\n");
	else if(randomSayi < 100000)
		printf("Uretilen sayi bes basamaklidir.\n");
		
	printf("\n************************************************\n");
	
	// SORU - 3 : Fiyat hesaplama program� yaz�lacak. Kullan�c�ya taksit se�ene�i ve �zel kart se�ene�i sunulacak. Taksit se�ene�inden fiyat art��� meydana gelecek. �zel kartta ise fiyat
	// d����� ger�ekle�ecek
	
	printf("SORU - 3\n");
	char kullaniciIstegi;
	int taksitSayisi;
	float fiyat;
	srand(time(NULL));
	fiyat = rand()%2000;
	
	printf("Merhabalar, Fiyat Kontrol Sistemine Hosgeldiniz\n");
	printf("Alisveris tutariniz : %.2f\n", fiyat);
	printf("Taksit ile mi odeyeceksiniz? (y/n) ");
	fflush(stdin);
	scanf("%c", &kullaniciIstegi);
	
	if(kullaniciIstegi == 'y')
	{
		printf("Kac taksit istiyorsunuz? (3-6-9) ");
		scanf("%d", &taksitSayisi);
		
		switch(taksitSayisi)
		{
			case 3:
				fiyat += fiyat * 0.03;
				printf("%d taksit uygulandi.\n", taksitSayisi);
				printf("Urunun yeni fiyati : %.2f\n", fiyat);
				break;
			case 6:
				fiyat += fiyat * 0.06;
				printf("%d taksit uygulandi.\n", taksitSayisi);
				printf("Urunun yeni fiyati : %.2f\n", fiyat);
				break;
			case 9:
				fiyat += fiyat * 0.09;
				printf("%d taksit uygulandi.\n", taksitSayisi);
				printf("Urunun yeni fiyati : %.2f\n", fiyat);
				break;
			default:
				printf("Uygun bir taksit girilmedi. Taksit uygulanmiyor.\n");
		}
	}
	else if(kullaniciIstegi == 'n')
		printf("Isteginiz uzerine taksit uygulanmadi.\n");
	else
		printf("Yanlis giris yaptiniz. Taksit uygulanmiyor.\n");
		
	printf("Ozel kartiniz bulunmakta midir?(y/n) ");
	fflush(stdin);
	kullaniciIstegi = getchar();
	
	if(kullaniciIstegi == 'y')
	{
		fiyat -= fiyat * 0.1;
		printf("Ozel kartiniz sonucu alisveris tutari : %.2f\n", fiyat);
	}
	else if(kullaniciIstegi == 'n')
		printf("Ozel kart uygulanmadi.\nIndirim gerceklestirilmedi.\n");
	else
		printf("Yanlis giris yaptiniz. Ozel kart uygulanmiyor.\n");
		
	printf("Odeme tutariniz : %.2f\n", fiyat);
	printf("Onayliyor musunuz? (y/n) ");
	fflush(stdin);
	kullaniciIstegi = getchar();
	
	if(kullaniciIstegi == 'y')
		printf("Islemler baslatiliyor...\nBizi tercih ettiginiz icin tesekkur ederiz!");
	else if(kullaniciIstegi == 'n')
		printf("Iyi gunler dileriz.");
	else
		printf("Yanlis tuslama yaptiniz. Lutfen tekrar deneyin!");
		
	printf("\n************************************************\n");
	
	// SORU - 4 : Kullan�c�dan 3 adet ��gen kenar bilgisi al�nacak. Al�nan bu kenar bilgileriyle ��gen olu�turulup olu�turulmad��� tespit edilecek
	// ��gen olma �art� : x => |y-z|<x<y+z 		y => |x-z|<y<x+z 		z => |x-y|<z<x+y 
	printf("SORU - 4\n");
	int x,y,z;
	
	printf("Ucgen sart kontrolu yapilacak kenarlari giriniz: ");
	scanf("%d%d%d",&x,&y,&z);
	
	if(abs(y-z) < x && (y+z) > x)
	{
		if(abs(x-z) < y && (x+z) > y)
		{
			if(abs(x-y) < z && (x+y) > z)
				printf("Girilen kenarlarla bir ucgen olusturulabilir.");
			else
				printf("z kenarindan dolayi bir ucgen olusturulamaz.");
		}
		else
			printf("y kenarinden dolayi bir ucgen olusturulamaz.");
	}
	else
		printf("x kenarindan dolayi bir ucgen olusturulamaz.");
	
	
	return 0;
}
