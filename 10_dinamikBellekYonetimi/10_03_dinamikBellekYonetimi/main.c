#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	pointerToPointer:
	bir isaretcinin adresini baska bir isaretcide tutmaya yarar.
	bu kavram sayesinde adres tutan degiskenin, yani pointer'ýn, adresini tutabiliriz.
	dinamik bellek yonetimi -iki boyutlu diziler-
*/
int main()
{
	int kullaniciSayisi=123;
	int *ptr=&kullaniciSayisi;
	int **ptr2ptr=&ptr;	//pointer'ýn adresini tutar.*ptr2ptr yaparsak pointerin tuttuðu degeri döner. yani kullaniciSayisi'nin adresini. eger **ptr2ptr yaparsak=>*(ptr'in tuttugu adres)'in degerini, yani kullaniciSayisi'nin degerine erisiriz.
	
	puts("ADRESLER:");
	printf("kullaniciSayisi:%#X\n",&kullaniciSayisi);	//kullanici sayisinin adresi
	printf("kullaniciSayisi-ptr:%#X\n",ptr);			//kullanicinin sayisinin adresini tutan pointerýn deðeri-yani kullaniciSayisi'nin adres deger
	printf("kullaniciSayisi-ptr2ptr:%#X\n",*ptr2ptr);	//ptr2ptr degerinin icerisinde yer alan adresin degerini yazdirdik.ptr'nin icerisinde kullaniciSayisi degiskeninin adresi var.
	
	printf("ptr:%#X\n",&ptr);				//pointerin adresi
	printf("ptr-ptr2ptr:%#X\n",ptr2ptr);	//pointerin adresini tutan pointerin içerisindeki deger
	
	printf("ptr2ptr:%#X\n",&ptr2ptr);	//pointerin adresini tutan pointerin adresi
	
	puts("DEGERLER");
	printf("kullaniciSayisi=%d\n",kullaniciSayisi);		//kullaniciSayisi degiskeninden direkt eriþim
	printf("kullaniciSayisi-ptr=%d\n",*ptr);			//kullaniciSayisi degiskeninin adresini tutan pointer'dan degere erisim
	printf("kullaniciSayisi-ptr2ptr=%d\n",**ptr2ptr);	//pointer adresini tutan degisken uzerinden pointerin icerisinde yer alan adresin degerine erisim
	
	//IKI BOYUTLU POINTER-DIZI-
	/*
	matris->1 2 3 4 5 
	matris->6 7 8 9 10
	matris->11 12 13 14 15
	bu matrislerin hepsi adres tutuyor. bu adresleri gosterecek baska bir adres tutucuða ihtiyac var 
	*/
	//dinamik bir sekilde yapilacagi icin kullanicidan satir ve sutun degerleri alinmalidir.
	int **ikiBoyutluDizi;
	int satirSayisi,sutunSayisi,i,j;
	srand(time(NULL));
	
	puts("Lutfen satir sayisini giriniz:");
	scanf("%d",&satirSayisi);
	puts("Lutfen sutun sayisini giriniz:");
	scanf("%d",&sutunSayisi);
	
	ikiBoyutluDizi=(int **)malloc(sizeof(int *)*satirSayisi);	//adres olarak donecegi tip malloc(yer ayiracagin byte degeri). su an sadece satirlari iceren bir dizi olusturuldu. sizeof olarak pointer integer*satirSayisi kadar yer ayrildi
	/*
		1.satir=1 2 3 4 5 			
		2.satir=6 7 8 9 10
		3.satir=11 12 13 14 15
		su an tek boyutlu bir dizinin icerisinde sadece satir degerleri kadar yer ayrildi.sutunlar kendi icerisinde donguyla olusturulacak
	*/
	//her satirda yer alacak sutun sayilari olusturma
	for(i=0;i<satirSayisi;i++)
	{
		ikiBoyutluDizi[i]=(int *)malloc(sizeof(int)*sutunSayisi);	//burada her satirin baslangic yerinden itibaren sizeof int*sutunSayisi kadar yer ayrildi.
	}
	///dinamik bir sekilde dizi olusturma bitti
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
		{
			ikiBoyutluDizi[i][j]=rand()%100;
			printf("%d ",ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	
	/*
		yapilan islem 5x5'lik matris:
		ptr1->- - - - -	//ilk once ptrx'ler olusturuldu. sonrasinda da o adreslerin uzerine sutun degerleri eklendi.
		ptr2->- - - - -
		ptr3->- - - - -
		ptr4->- - - - -
		ptr5->- - - - -
		pointer2pointer=adres tutabilecek bir degiskenin adresini tutuyor.
		eger adresin adresine erisemezsek o adresten ileriye dogru gidemeyiz.
		adres tutabilecek bir adres yeri olusturuldu.yani satirSayisi degeriyle adreslerin tutulabilecegi bir adres tutan dizi olusturuldu
		sutunSayisi sayesinde belirlenen o adresten ileriye dogru gidildi
	*/
	
	//free
	//her satir icin birden fazla sutun olusturuldugundan satir-satir silme islemi yapilmali.en son olarak da satir icin olusturulan dizi silindi
	for(i=0;i<satirSayisi;i++)
		free(ikiBoyutluDizi[i]);
	free(ikiBoyutluDizi);
	
	return 0;
}
