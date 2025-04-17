#include <stdio.h>
/*
	fonksiyon iþaretçileri:
	oluþturulan fonksiyonun adresini tutmak için kullanýlýrlar

*/
void merhabaDunya(int);
void sonucHesapla1(int,int);
void sonucHesapla2(int,int);
void sonucHesapla3(int,int);
void hesapla(void (*)(int,int),int,int);	//void (*)(int,int)=>deðer dönecek olan fonksiyon:int,int=>oluþturulan fonksiyonun deðiþkenleri:burada void (*)(int,int) çaðrýlacak olan fonksiyonun protitipidir.

int main()
{
	//TANIMLAMA
	//void (*fPtr)(void);			//fonksiyon iþaretçisi tanýmlandý.hiçbir deðer almýyor ve dönmüyor
	void (*fPtr)(int);
	//DEÐER ATAMA
	fPtr=merhabaDunya;				//fonksiyon iþaretçisi merhabaDunya fonksiyonunu tutmaktadýr.
	//ÇAÐIRMA
	//(*fPtr)(5);					//bir deðer almadýðý için parantezler boþ býrakýlýr. (*fPtr) merhabaDunya'yý ifade eder
	(*fPtr)(5);
	
	//FONKSÝYON ÝÞARETÇÝLERÝNÝ ARRAY ÞEKLÝNDE KULLANMA
	void (*fonkPtr[3])(int,int);	//3 elemanlý fonksiyon pointer tanýmlandý
	
	fonkPtr[0]=sonucHesapla1;		//deðer atandý.
	fonkPtr[1]=sonucHesapla2;		//deðer atandý.
	fonkPtr[2]=sonucHesapla3;		//deðer atandý.
	
	(fonkPtr[0])(3,5);				//callbyvalue ile çaðrýldý.
	(fonkPtr[1])(3,5);				//callbyvalue ile çaðrýldý.
	(fonkPtr[2])(3,5);				//callbyvalue ile çaðrýldý.
	
	//FONKSÝYONA DEÐÝÞKEN OLARAK FONKSÝYON ÝÞARETÇÝSÝ GÖNDERME
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
	ptr(a,b);	//deðiþken olarak gelen fonksiyonu (ptr) a ve b deðerleriyle çaðýr.
}
