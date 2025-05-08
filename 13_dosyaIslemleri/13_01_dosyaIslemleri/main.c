#include <stdio.h>

/*
	bu bolumde:
	- bilgiler dosyadan nasil okunabilir
	- bilgiler dosyaya nasil kaydedilebilir
	bu bize verileri kalici bir sekilde saklamamizi saglayacak
	
	Dosya Tipleri
	1-Metin Dosyalar:ASCII tabloya gore saklanirlar yani 0 ile 255 arasindadirlar.Kac adet karakter varsa o kadar byte yer kaplayacak bunun sebebi karakterlerin 1 byte olmasidir.Satir bazinda ekleme yapilabilir.Yani geriye donup 8.satira ekleme yapilamaz.
	2-Ikili Dosyalar(Binary File):0-1 bit karsiligina gore tutulurlar.Geriye donuk ekleme yapilabiliyor.Ozel editorle goruntulenebiliyor. ".bin",".dat"
	Ikili dosyalarin metin dosyalarina gore en buyuk avantaji geriye donuk ekleme yapilabilmesidir.
	Kodlarda metin dosyalari kullanilacak.
*/

int main()
{
	/*
		dosya modlari: **metin dosyalari icin**
		1-yazma --w-- ile kullanilabilmektedir.bu mod ile dosya acildigi zaman icerisinde yer alan butun veriler silinir.	
		2-okuma --r-- ile kullanilabilmektedir.bu modun kullanilabilmesi icin dosyanin var olmasi gerekmektedir.var olmayan bir dosyayi okumaya calisirsan hata alirsin!!!
		3-yazma ancak sona ekleme seklinde.yani var olanlari silmeden eklenecek. --a-- dosya var ise sonundan ekleme yapmakta, yok ise de dosyayi olusturmaktadir.
		read modundayken dosya olusturma islemi yapmaz!!!
		write modundayken eger dosya yoksa olusturma islemini yapar.
		write ama sona eklemeli moddayken eger dosya yoksa olusturma islemini yapar.
	
		**ikili dosyalar icin**
		->wb, metin dosyalariyla ayni islevlere sahiptir.
		->rb, metin dosyalariyla ayni islevlere sahiptir.
		->ab, metin dosyalariyla ayni islevlere sahiptir.
		
		**temel modlar disinda var olan modlar**
		r+ : hem okuma hem de yazma islemine olanak saglar.bu modun kullanilabilmesi icin dosyanin daha onceden olusturulmus olmasi gerekmektedir.yazma isleminde metnin kaldigi yerden itibaren yazarsan icerigi kurtarabilirsin.eger kaldigin yerden yazmazsan overwrite olur.
		w+ : hem okuma hem de yazma islemine olanak saglar.bu mod kullanildigi zaman eger ilgili dosya yoksa mod sayesinde olusturulur.yazma isleminde dosyada yer alan veriler SILINIR.
		a+ : hem okuma hem de yazma islemine olanak saglar.bu mod kullanildigi zaman eger ilgili dosya yoksa mod sayesinde olusturulur.yazma isleminde dosyada yer alan veriler SILINMEZ.
	
		**ikili dosyalar icin**
		->rb+ : metin dosyalariyla ayni isleve sahiptir.
		->wb+ : metin dosyalariyla ayni isleve sahiptir.
		->ab+ : metin dosyalariyla ayni isleve sahiptir.
	*/
	//dosya burada FILE turunde bir pointerdir.Dolayisiyla adres tutmaktadir.Olusturulan veya acilan dosyanin adresini tutmaktadir.
	FILE *dosya=fopen("deneme1.txt","r");//FILE pointer.dosya bizim dosyayla olan iletisimimizi saglar.fopen ile dosya acma islemi yapilir.Ilk bekledigi dosyanin acilacagi yerin adresidir."deneme.txt" diyerek c kaynak kodunun bulundugu dosyaya acilir.Ikinci bekledigi dosyanin acilma modudur.
	//dosya olusturulurken herhangi bir hata meydana geldiyse dosyaya NULL karakteri atanacak
	if(dosya!=NULL)
		printf("Dosyaniz basariyla olusturuldu.");
	else
		printf("Dosya olusturulma sirasinda hata meydana geldi.");
	
	int kapandiMi;//dosyanin kapanip kapanmadigini tutacak
	
	kapandiMi=fclose(dosya);//dosya pointeri burada dosyanin ADRESINI tutmaktadir.dolayýsýyla derleyiciye diyorum ki dosya adresinde yer alan dosyayi kapat. -bu bir silme islemi degildir- 
	//eger dosya kapandiysa 0 degerini donuyor,kapanmadiysa 0'dan farkli bir deger donuyor!!!
	if(kapandiMi==0)
		printf("\nDosya basarili bir sekilde kapanmistir.");
	else
		printf("\nDosya kapatilma sirasinda bir hata meydana geldi.");
	
	return 0;
}
