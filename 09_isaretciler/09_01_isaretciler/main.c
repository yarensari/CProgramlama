#include <stdio.h>
/*
	pointerlar bir deðiþkenin adresini tutmak için kullanýlan özel veri tipleridir.
	tanýmlama yapýlýrken kullanýlan * iþareti pointer anlamýna gelmektedir.
 	* iþareti deðiþkenin atamasý yapýldýktan sonra kullanýmýnda ise o adresteki deðeri verir.
*/
int main()
{
	int sayi=5;			// buradaki sayi deðiþkeni o deðiþkenin tutulduðu bellek adresine verdiðimiz isimdir. direkt eriþim:deðiþken ismiyle eriþim.
						// pointerla olan eriþim dolaylý eriþimdir çünkü bu sefer adresiyle eriþim saðlýyoruz. bu adresler pointerlarda tutulur. 
	//int *ptr=&sayi;		// direkt tanýmlama yapýlýp atama da yapýlabilir.
	int *ptr;			// önce tanýmlama yapýlýp
	ptr=&sayi;			// sonra atama yapýlabilir.&:adres
	
	int *p1,*p2;
	p1=&sayi;
	p2=&sayi;			// p1 ve p2 sayi deðiþkeninin adresini tutuyor. adresteki iki pointerdan biri deðiþiklik yaptýðý zaman direkt adres üzerinde deðiþiklik olduðunda sayi deðiþkeninin deðeri deðiþir
	*p2=8;				// artýk sayi deðiþkeni 8 deðerini tutuyor. direkt adres üzerinden deðiþiklik yapýldý. dolayýsýyla sayi deðiþkeni deðiþti. 
	*p1=12;
	printf("Pointer kullanarak sayi degiskeninin adresi:%#X\n",p1);			// sayi deðiþkeninin bellekte bulunduðu adresi pointer aracýlýðýyla yazdýrdýk.
	printf("Pointer kullanmayarak sayi degiskeninin adresi:%#X\n",&sayi);	// # iþareti yazdýrmada baþa 0X gelmesini saðlar
	
	printf("Pointer kullanmadan sayi degiskeninin degeri:%d\n",sayi);
	printf("Pointer kullanarak sayi degiskeninin degeri:%d\n",*p1);			// * iþareti adresteki deðeri okuyabilmemizi saðlar
	
	
	return 0;
}
