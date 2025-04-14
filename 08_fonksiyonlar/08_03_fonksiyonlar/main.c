#include <stdio.h>

int sayiYazdir(int);
int faktoriyelHesapla(int);

int main()
{
	int faktoriyelSonuc;
	
	sayiYazdir(5);
	
	puts("\n------------------------------");
	
	faktoriyelSonuc=faktoriyelHesapla(5);
	printf("Faktoriyel=%d\n",faktoriyelSonuc);
	
	return 0;
}

int sayiYazdir(int sayi)
{
	if(sayi==0)
		return 0;
	
	printf("%d ",sayi);		
	sayiYazdir(--sayi);
}

int faktoriyelHesapla(int sayi)
{	
	if(sayi==1 || sayi==0)
		return 1;

	int faktoriyelSonuc=sayi*faktoriyelHesapla(sayi-1);
	
	return faktoriyelSonuc;
	// ilk gelen:5
	// faktoriyelSonuc=5*faktoriyelHesapla(4)
	// faktoriyelSonuc=5*4*faktoriyelHesapla(3)
	// faktoriyelSonuc=5*4*3*faktoriyelHesapla(2)
	// faktoriyelSonuc=5*4*3*2*faktoriyelHesapla(1)
	// faktoriyelSonuc=return 1 döndü ve faktoriyelSonuc=120 oldu
}
