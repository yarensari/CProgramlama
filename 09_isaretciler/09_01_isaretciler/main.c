#include <stdio.h>
/*
	pointerlar bir de�i�kenin adresini tutmak i�in kullan�lan �zel veri tipleridir.
	tan�mlama yap�l�rken kullan�lan * i�areti pointer anlam�na gelmektedir.
 	* i�areti de�i�kenin atamas� yap�ld�ktan sonra kullan�m�nda ise o adresteki de�eri verir.
*/
int main()
{
	int sayi=5;			// buradaki sayi de�i�keni o de�i�kenin tutuldu�u bellek adresine verdi�imiz isimdir. direkt eri�im:de�i�ken ismiyle eri�im.
						// pointerla olan eri�im dolayl� eri�imdir ��nk� bu sefer adresiyle eri�im sa�l�yoruz. bu adresler pointerlarda tutulur. 
	//int *ptr=&sayi;		// direkt tan�mlama yap�l�p atama da yap�labilir.
	int *ptr;			// �nce tan�mlama yap�l�p
	ptr=&sayi;			// sonra atama yap�labilir.&:adres
	
	int *p1,*p2;
	p1=&sayi;
	p2=&sayi;			// p1 ve p2 sayi de�i�keninin adresini tutuyor. adresteki iki pointerdan biri de�i�iklik yapt��� zaman direkt adres �zerinde de�i�iklik oldu�unda sayi de�i�keninin de�eri de�i�ir
	*p2=8;				// art�k sayi de�i�keni 8 de�erini tutuyor. direkt adres �zerinden de�i�iklik yap�ld�. dolay�s�yla sayi de�i�keni de�i�ti. 
	*p1=12;
	printf("Pointer kullanarak sayi degiskeninin adresi:%#X\n",p1);			// sayi de�i�keninin bellekte bulundu�u adresi pointer arac�l���yla yazd�rd�k.
	printf("Pointer kullanmayarak sayi degiskeninin adresi:%#X\n",&sayi);	// # i�areti yazd�rmada ba�a 0X gelmesini sa�lar
	
	printf("Pointer kullanmadan sayi degiskeninin degeri:%d\n",sayi);
	printf("Pointer kullanarak sayi degiskeninin degeri:%d\n",*p1);			// * i�areti adresteki de�eri okuyabilmemizi sa�lar
	
	
	return 0;
}
