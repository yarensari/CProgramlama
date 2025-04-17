#include <stdio.h>
/*
	fonksiyon i�aret�ileri:
	olu�turulan fonksiyonun adresini tutmak i�in kullan�l�rlar

*/
void merhabaDunya(int);
void sonucHesapla1(int,int);
void sonucHesapla2(int,int);
void sonucHesapla3(int,int);
void hesapla(void (*)(int,int),int,int);	//void (*)(int,int)=>de�er d�necek olan fonksiyon:int,int=>olu�turulan fonksiyonun de�i�kenleri:burada void (*)(int,int) �a�r�lacak olan fonksiyonun protitipidir.

int main()
{
	//TANIMLAMA
	//void (*fPtr)(void);			//fonksiyon i�aret�isi tan�mland�.hi�bir de�er alm�yor ve d�nm�yor
	void (*fPtr)(int);
	//DE�ER ATAMA
	fPtr=merhabaDunya;				//fonksiyon i�aret�isi merhabaDunya fonksiyonunu tutmaktad�r.
	//�A�IRMA
	//(*fPtr)(5);					//bir de�er almad��� i�in parantezler bo� b�rak�l�r. (*fPtr) merhabaDunya'y� ifade eder
	(*fPtr)(5);
	
	//FONKS�YON ��ARET��LER�N� ARRAY �EKL�NDE KULLANMA
	void (*fonkPtr[3])(int,int);	//3 elemanl� fonksiyon pointer tan�mland�
	
	fonkPtr[0]=sonucHesapla1;		//de�er atand�.
	fonkPtr[1]=sonucHesapla2;		//de�er atand�.
	fonkPtr[2]=sonucHesapla3;		//de�er atand�.
	
	(fonkPtr[0])(3,5);				//callbyvalue ile �a�r�ld�.
	(fonkPtr[1])(3,5);				//callbyvalue ile �a�r�ld�.
	(fonkPtr[2])(3,5);				//callbyvalue ile �a�r�ld�.
	
	//FONKS�YONA DE���KEN OLARAK FONKS�YON ��ARET��S� G�NDERME
	hesapla(sonucHesapla1,3,5);
	
	return 0;
}

void merhabaDunya(int a)
{
	printf("merhaba dunya\n");
	printf("%d\n",a);
}

void sonucHesapla1(int a ,int b)
{
	printf("Sonuc:%d\n",a*3+b*2);
}

void sonucHesapla2(int a,int b)
{
	printf("Sonuc:%d\n",(a+3)*(b+2));
}

void sonucHesapla3(int a,int b)
{
	printf("Sonuc:%d\n",a*2+b*3);
}

void hesapla(void (*ptr)(int,int),int a,int b)
{
	ptr(a,b);	//de�i�ken olarak gelen fonksiyonu (ptr) a ve b de�erleriyle �a��r.
}
