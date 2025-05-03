#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//SORU-1 FONKSIYONLAR
char * stringAl(void);
void anagramKontrol(char *,char *);

//SORU-2 FONKSIYONLAR
int ** ikiBoyutluDiziOlustur(int,int);
void ikiBoyutluDiziyiDoldur(int **,int,int);
void ikiBoyutluDiziyiYazdir(int **,int,int);
void ikiBoyutluDiziSimetriKontrol(int **,int,int);
void alaniSerbestBirak(int **,int);

//SORU-3 FONKSIYONLAR --ikiBoyutluDiziOlustur,ikiBoyutluDiziyiYazdir---
void ikiBoyutluDiziyiRandomDoldur(int **,int,int);
void ikiBoyutluDizininNegatifiniAl(int **,int,int);
void matrislerinFarki(int **,int **,int **,int,int);

//SORU-4 FONKSIYONLAR
int * diziyiOlustur(int);
void diziyiDoldur(int *,int);
void diziyiYazdir(int *,int);
void arayaSokmaAlgoritmasi(int *,int);

//SORU-5 FONKSIYONLAR
int ardisilArama(int *,int,int);

int main()
{
	//SORU-1:Kullanicidan 2 adet string dinamik bir sekilde alinacak. Alinan bu stringlerin birbirinin anagrami olup olmadigi harf frekansiyla kontrol edilecek.
	puts("SORU-1:");
	
	char *string1;
    char *string2;

    puts("Ilk stringi giriniz:");
    string1 = stringAl();
    puts("Ikinci stringi giriniz:");
    string2 = stringAl();
    
    anagramKontrol(string1,string2);
    
    free(string1);	//alinan yerleri geri ver
    free(string2);
    
    puts("----------------------------------------------------------------");
    
    //SORU-2:Kullanicidan satir ve sutun sayisi alinacak.Alinan bu degerlerle dinamik bir iki boyutlu dizi olusturulacak.Bu sefer iki boyutlu dizinin degerleri kullanicidan alinacak.Elde edilen iki boyutlu dizinin simetrik olup olmadigi kontrol edilecek.
    puts("SORU-2:");
	
	int satirSayisi,sutunSayisi,**dizi;
	
	puts("Lutfen satir ve sutun sayilarini sirasiyla giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);
	dizi=ikiBoyutluDiziOlustur(satirSayisi,sutunSayisi);
	dizi!=NULL?puts("Iki boyutlu dizi basariyla olusturuldu!"):puts("Iki boyutlu dizi olusturulurken hata olustu.");
	
	ikiBoyutluDiziyiDoldur(dizi,satirSayisi,sutunSayisi);
	puts("Olusturdugunuz matris:");
	ikiBoyutluDiziyiYazdir(dizi,satirSayisi,sutunSayisi);
	
	ikiBoyutluDiziSimetriKontrol(dizi,satirSayisi,sutunSayisi);	//simetri kontrolu yapilir
	
	alaniSerbestBirak(dizi,satirSayisi);	//alan serbest birakilir
	
	puts("----------------------------------------------------------------");
    
    //SORU-3:Kullanicidan alinan satir ve sutun degerlerine gore iki adet iki boyutlu dinamik matris olusturulacak.olusturulan bu matrislerin degerleri random bir sekilde atanacak.sonrasinda ikinci matrisin - ile carpimi saglanacak ve bu iki matrisin farki alinacak
	puts("SORU-3:");
	
	int **matris1,**matris2,**toplamMatris;
	
	puts("Lutfen satir ve sutun sayilarini sirasiyla giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);
	
	//matrisler ikiBoyutluDiziOlustur fonksiyonuyla olusturulur
	matris1=ikiBoyutluDiziOlustur(satirSayisi,sutunSayisi);    
    matris2=ikiBoyutluDiziOlustur(satirSayisi,sutunSayisi); 
    toplamMatris=ikiBoyutluDiziOlustur(satirSayisi,sutunSayisi);
    //matrisler doldurulur(random)
	ikiBoyutluDiziyiRandomDoldur(matris1,satirSayisi,sutunSayisi);
    ikiBoyutluDiziyiRandomDoldur(matris2,satirSayisi,sutunSayisi);
    //matrisler yazdirilir
	puts("Olusturulan birinci matris:");
    ikiBoyutluDiziyiYazdir(matris1,satirSayisi,sutunSayisi);
    puts("Olusturulan ikinci matris:");
    ikiBoyutluDiziyiYazdir(matris2,satirSayisi,sutunSayisi);
    //matrisleri topla ve yazdir
    matrislerinFarki(matris1,matris2,toplamMatris,satirSayisi,sutunSayisi);
    puts("Matrislerin farki:");
    ikiBoyutluDiziyiYazdir(toplamMatris,satirSayisi,sutunSayisi);
    
    alaniSerbestBirak(matris1,satirSayisi);
    alaniSerbestBirak(matris2,satirSayisi);
    alaniSerbestBirak(toplamMatris,satirSayisi);
    
    puts("----------------------------------------------------------------");
    
    //SORU-4:Kullanicidan alinan eleman sayisina gore random bir sekilde dizi olusturulacak.Olusturulan bu dizide araya sokma algoritmasi uygulanacak ve dizi tekrardan yazdirilacak.Araya sokma algoritmasi sadece pointer kullanilarak yapilacak.
	puts("SORU-4:");
	
	int elemanSayisi,*array;
	
	puts("Lutfen olusturulacak olan dizinin eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	//diziyi olustur,doldur ve yazdir
	array=diziyiOlustur(elemanSayisi);
	array!=NULL?puts("Dizi basariyla olusturuldu."):puts("Dizi olusturulamadi.");
	diziyiDoldur(array,elemanSayisi);
	puts("Olusturulan dizi:");
	diziyiYazdir(array,elemanSayisi);
	arayaSokmaAlgoritmasi(array,elemanSayisi);
	puts("\nSirali dizi:");
	diziyiYazdir(array,elemanSayisi);
	
	puts("\n----------------------------------------------------------------");
    
    //SORU-5:Soru-4'te siralanmis olan diziye ardisil arama uygulanacak.
    puts("SORU-5:");
    
	int arananDeger;
    
    puts("Lutfen aranacak olan degeri giriniz:");
    scanf("%d",&arananDeger);
    
    if(ardisilArama(array,elemanSayisi,arananDeger))
    	puts("Aranan deger bulundu!");
    else
    	puts("Aranan deger bulunamadi.");
    
    free(array);
    
	return 0;
}

char * stringAl(void)
{
	char *str=NULL;					//baslangic adresi null
	char karakter;					//kullanicidan gelen karakterleri tut
	int boyut=0;					//hic karakter gelmemis gibi davran
	
	while((karakter=getchar())!='\n')
	{
		str=realloc(str,boyut+2);	//1tanesi karakter,1tanesi '\0' +2tamamdir cunku char 1byte.var olan boyut degeri+yeniKarakter+stringSonu
		str[boyut++]=karakter;		//karakter degerini o anki boyut noktasina yazdik ve sonrasinda da boyut degerini 1 arttirdik.
	}
	
	str[boyut]='\0';
	
	return str;
}

void anagramKontrol(char *str1,char *str2)
{
	int *harfFrekansi1,*harfFrekansi2,karakterSayisi1,karakterSayisi2,anagramKontrol=1,i;
	char *ptr1,*ptr2;
	ptr1=str1;
	ptr2=str2;
	
	harfFrekansi1=(int *)calloc(26,sizeof(int));	//hepsine ilk basta 0 atanir ve baslangic degeri donulur
	harfFrekansi2=(int *)calloc(26,sizeof(int));
	
	karakterSayisi1=strlen(str1);	//karakter sayilari alinir ve eger farkliysa direkt anagram olmadigina karar verilir
	karakterSayisi2=strlen(str2);
	
	if(karakterSayisi1!=karakterSayisi2)
		anagramKontrol=0;
	else
	{
		while(*ptr1!='\0')
		{
			if(*ptr1>='a' && *ptr1<='z')
				harfFrekansi1[*ptr1-'a']+=1;
			if(*ptr2>='a' && *ptr2<='z')
				harfFrekansi2[*ptr2-'a']+=1;
			ptr1++;
			ptr2++;
		}
		for(i=0;i<26;i++)
		{
			if(harfFrekansi1[i]!=harfFrekansi2[i])	//degeri arttirilan yerleri karsilastir
			{
				anagramKontrol=0;
				break;
			}
		}
	}
	
	if(anagramKontrol==0)
		puts("Girilen stringler birbirlerinin anagrami degildir.");
	else
		puts("Girilen stringler birbirlerinin anagramidir.");		
}

int ** ikiBoyutluDiziOlustur(int satirSayisi,int sutunSayisi)
{
	int i;
	int **dizi=(int **)malloc(sizeof(int *)*satirSayisi);	//satir sayisi kadar yer ayrilir
	
	for(i=0;i<satirSayisi;i++)
		dizi[i]=(int *)malloc(sizeof(int)*sutunSayisi);	//her satir icin belirlenen sutun sayisi kadar yer ayrilir
		
	return dizi;	//olusturulan iki boyutlu dizi return edilir
}

void ikiBoyutluDiziyiDoldur(int **dizi,int satirSayisi,int sutunSayisi)
{
	int i,j;
	
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
		{
			printf("Lutfen [%d][%d] degeri giriniz:",i+1,j+1);
			scanf("%d",&dizi[i][j]);	//!!!&dizi[i][j] iki boyutlu dizinin o noktadaki adresini verir!!! dizi[i][j] ise o adresteki degeri verir
		}
		printf("\n");
	}
}

void ikiBoyutluDiziyiYazdir(int **dizi,int satirSayisi,int sutunSayisi)
{
	int i,j;
	
	for(i=0;i<satirSayisi;i++)
	{
		for(j=0;j<sutunSayisi;j++)
			printf("%d ",dizi[i][j]);	//!!!dizi[i][j] iki boyutlu dizinin o noktadaki degerini verir!!!
		printf("\n");
	}
}

void ikiBoyutluDiziSimetriKontrol(int **matris,int satir,int sutun)
{
	int i,j,simetriMi=1;
	
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
		{
			if(matris[i][j] != matris[j][i])
			{
				simetriMi=0;
				break;
			}
		}
	}
	
	if(simetriMi)
		printf("Girdiginiz matris simetriktir.\n");
	else
		printf("Girdiginiz matris simetrik degildir.\n");
}

void alaniSerbestBirak(int **dizi,int satirSayisi)
{
	int i;
	//once satirlar icin ayrilan yerler temizlenir
	for(i=0;i<satirSayisi;i++)
		free(dizi[i]);
	free(dizi);
}

void ikiBoyutluDiziyiRandomDoldur(int **matris,int satir,int sutun)
{
	int i,j;
	srand(time(NULL));
	
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
			matris[i][j]=rand()%10;
	}
}

void ikiBoyutluDizininNegatifiniAl(int **matris,int satir,int sutun)
{
	int i,j;
	
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
			matris[i][j]*=-1;
	}
}

void matrislerinFarki(int **matris1,int **matris2,int **toplamMatris,int satir,int sutun)
{
	int i,j;
	ikiBoyutluDizininNegatifiniAl(matris2,satir,sutun);
	
	for(i=0;i<satir;i++)
	{
		for(j=0;j<sutun;j++)
			toplamMatris[i][j]=matris1[i][j]+matris2[i][j];
	}	
}

int * diziyiOlustur(int elemanSayisi)
{
	int *dizi;
	
	dizi=(int *)malloc(sizeof(int)*elemanSayisi);
	
	return dizi;
}

void diziyiDoldur(int *dizi,int elemanSayisi)
{
	srand(time(NULL));
	int i,*ptr;	//*ptr dizinin baslangic adresinde sonuna kadar gider. bunun yapilmasinin sebebi baslangic adresini kaybetmemektir
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		*ptr=rand()%100;
}

void diziyiYazdir(int *dizi,int elemanSayisi)
{
	int i,*ptr;
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		printf("%d ",*ptr);
}

//kontrol edilen degerin soldaki degerlerle karsilastirilmasi yapilir.buyuk olan degerler saga dogru kaydirilir.
void arayaSokmaAlgoritmasi(int *dizi,int elemanSayisi)
{
	int *ptr1,*ptr2,arayaSokulacakEleman;
	
	for(ptr1=dizi+1;ptr1<dizi+elemanSayisi;ptr1++)
	{
		arayaSokulacakEleman=*ptr1;
		for(ptr2=ptr1-1;ptr2>=dizi && arayaSokulacakEleman<=*ptr2;ptr2--)	//araya sokulacak olan eleman karsilastirilan elemandan buyukse devam etmeye gerek yok.direkt dongu sarti saglanmadigi icin dongu sonlanir.
			*(ptr2+1)=*ptr2;	
		*(ptr2+1)=arayaSokulacakEleman;
	}
}

int ardisilArama(int *dizi,int elemanSayisi,int arananDeger)
{
	int *ptr;
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
	{
		if(*ptr==arananDeger)
			return 1;
	}
	
	return 0;
}
