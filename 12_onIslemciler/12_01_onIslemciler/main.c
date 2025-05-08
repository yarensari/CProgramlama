#include <stdio.h>
#include <stdlib.h>

/*
	on islem asamasi:
	kodun derlenmeden onceki asamasidir.
	neden yapilir? kodu derlemeye hazir hale getirmek icin.
	
	asamalar(sirasi yoktur):
	- koda dahil edilen kutuphaneler ve header dosyalari koda entegre edilir.
	- yorum satirlari kaldiriliyor
	- #define ile yapilan makro tanimlamalari ve sabit sayi tanimlamalarinin koda entegre edilmesi

	on islemci komutu olan define komutu:
	bu komut ile sabit ve makro tanimlamasi yapilabiliyor.
	
	makro tanimlamalarda if-else yapisinin kisaltmasi kullanilir.
	makrolarin en buyuk avantaji her tip calismasidir.
	
	sartli duruma gore calisip calismama durumu:
*/

//SABIT TANIMLAMALAR
#define ELEMAN_SAYISI 15 //1=>#define ; 2=>sabit ifadenin ismi --bu ikisi mecburi-- 3=>sabit ifadenin degeri --3.su mecburi degil--.BU TANIMLAMA SABITTIR!
#define TOPLA + //sadece int degerler #define edilecek diye bir kural yoktur. bu sekilde de tanimlama yapilabilir. !!!TOPLA GORDUGU YERE + OPERATORUNU YERLESTIRIYOR!!!
#define CARPMA *
//MAKRO TANIMLAMALAR ---en buyuk avantaji:makroda degisken tipi belirtmene gerek yoktur. yani int,double,float degisken tipleri icin kullanilabilir---
#define SAYI_KARSILASTIR(sayi1,sayi2) (sayi1)<(sayi2)?(sayi1):(sayi2) //SAYI_KARSILASTIR makrosu sayi1 ve sayi2 olarak iki deger alir ve kucuk olan degeri doner.
#define KARE_HESAPLA(sayi) (sayi)*(sayi) //eger sayi ifadesini paranter icerisine almazsak islem onceligi devreye girer. yani ben KARE_AL makrosuna 3+4 ifadesi gonderirsem (parantez yok)=>1+3*1+3=1+3+3=7. () !!!UNUTMA!!!

#define TURKCE //deger atamasi yapilmadan sadece tanimlamasi yapilacak
#define INGILIZCE

int main()
{
	int *dizi,i,x=15,y=20;
	
	printf("Dizinin elemen sayisi:%d\n",ELEMAN_SAYISI);
	
	dizi=(int*)malloc(sizeof(int)*ELEMAN_SAYISI);
	for(i=0;i<ELEMAN_SAYISI;i++)
	{
		dizi[i]=i*i;
		printf("%d ",dizi[i]);
	}
	
	free(dizi);
	
	printf("\nSonuc:%d\n",12 TOPLA 8);//12+8=20 sonucunu verir cunku TOPLA + operatoruna karsilik gelmektedir.
	printf("Sonuc:%d\n",12 CARPMA 8);
	
	//if-else yapisinin kisaltmasi:
	if(x<y)
		printf("%d",x);
	else
		printf("%d",y);
	//------kisa hali-----	
	printf("\n%d",(x)<(y)?(x):(y));//x y'den kucuk mu (?) kucuk ise x degil ise (:) y'yi don
	
	printf("\nKucuk olan sayi:%d",SAYI_KARSILASTIR(45,52));
	
	printf("\n%.1f sayisinin karesi:%.1f",8.12,KARE_HESAPLA(8.12));
	printf("\n%d sayisnin karesi:%d",1+3,KARE_HESAPLA(1+3));
	
	//sartli kontrol:
	#ifdef TURKCE //if defined
		printf("\nTurkce tanimlanmistir.");
	#else
		printf("\nTurkce tanimlanmamistir.");
	#endif
	
	//sartli kontrolun bir diger yolu:
	#ifndef TURKCE	//if not defined
		printf("\nTurkce tanimlanmamistir.");
	#else
		printf("\nTurkce tanimlanmistir.");
	#endif
	
	//sartli kontrolun bir diger yolu:
	#if defined(TURKCE)
		printf("\nTurkce tanimlanmistir.");
	#else
		printf("\nTurkce tanimlanmamistir.");
	#endif	
		
	//sartli kontrolun bir diger yolu:
	#if !defined(TURKCE)
		printf("\nTurkce tanimlanmamistir.");
	#else
		printf("\nTurkce tanimlanmistir.");
	#endif
		
	//sartli kontrolun if-elseif-else.. kullanimi
	#if defined(TURKCE)
		printf("\nTurkce tanimlanmistir.");
	#elif defined(INGILIZCE)
		printf("\nIngilizce tanimlanmistir.");
	#else
		printf("\nTurkce ve Ingilizce tanimlanmamistir.");
	#endif
	
	//undef kavrami:
	//undef kavrami daha onceden define edilen ifadenin silinmesini saglar.
	#undef TURKCE
	
	#if defined(TURKCE)
		printf("\nTurkce tanimlanmistir.");
	#elif defined(INGILIZCE)
		printf("\nIngilizce tanimlanmistir.");
	#else
		printf("\nTurkce ve Ingilizce tanimlanmamistir.");
	#endif	
	
	return 0;
}
