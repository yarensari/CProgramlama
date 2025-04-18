#include <stdio.h>
#include <stdlib.h>
/*
	dinamik bellek yonetimi:
	bellekte isimize yarayacak kadar alan ayrýlýr ve sonunda da o alan geri verilir.
	int dizi[20]=>kullanýcý belki 10 adet yeri kullandý. o zaman 10 tane yer bosa ayrildi. bosa harcanmis olur
	sizeof ile degiskenin kac byte yer kapladigini ogreniriz.
	adimlar:
	sizeof fonksiyonu kullanilarak ne kadar yer ayrilacagi anlasilir.
	malloc ile istenilen kadar yer ayrilir.
	islemler bittikten sonra ayrilan yerler serbest birakilir. 
	kullanilan bu fonksiyonlar=>stdlib.h kutuphanesinin icerisinde bulunur.
	daha cok malloc kullanilmaktadir.malloc disinda calloc ve realloc fonksiyonlari da bulunmaktadir.gorevleri daha farklidir.
*/
int main()
{
	int dizi[20];
	
	printf("%d\n",sizeof(dizi));
	//memory allocation=malloc=>bu fonksiyon bana baslangic adresi doner ve istedigim kadar yer ayirabilir.bu baslangic adresi bi pointerla tutulacak.
	//malloc ile ayrilan yeri kullandiktan sonra free fonksiyonu ile ayrilan yeri serbest birakiriz.
	
	int *ptr1,*ptr2;	//baslangic adresini tutmak icin
	ptr1=(int *)malloc(sizeof(int));	//baslangic adresi ptr'ye atandi ve bir adet yer ayrildi(int boyutunda).
	
	*ptr1=15;	//ptr su anda malloc ile olusturulan yerin baslangic adresini tutuyor.biz o tutulan yere 15 degerini atadik.
	ptr2=ptr1;	//ptr2 ile ptr1 ayni yeri gosteriyor.
	
	printf("%#X\n",ptr1);
	printf("%d\n",*ptr1);
	printf("%#X\n",ptr2);
	printf("%d\n",*ptr2);
	/*free(ptr2);	//ayrilan adres serbest birakildigi icin o adresi artik kullanamiyoruz.
	printf("%#X\n",ptr1);
	printf("%d\n",*ptr1);
	printf("%#X\n",ptr2);
	printf("%d\n",*ptr2);
	*/
	ptr2=(int *)malloc(sizeof(int));	//sizeof(int)=4 oldugundan hicbir sey degismez.	
	*ptr2=*ptr1;
	puts("yeni yer ayrildi");
	printf("%#X\n",ptr2);
	printf("%d\n",*ptr2);
	free(ptr2);
	printf("%#X\n",ptr1);
	printf("%d\n",*ptr1);
	puts("ptr2 free");
	printf("%#X\n",ptr2);
	printf("%d\n",*ptr2);
	
	return 0;
}
