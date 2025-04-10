#include <stdio.h>
#include <string.h>

int main()
{
	// ÖRNEK - 1 : strlen, strcpy, strcat ve strcmp fonksiyonlarýný yazma.
	puts("ORNEK-1 a:");
	
	// strlen fonksiyonu 
	char isim[20];
	int karakterSayisi;
	
	puts("Lutfen isminizi giriniz:");
	gets(isim);
	
	for(karakterSayisi=0;isim[karakterSayisi]!='\0';karakterSayisi++);
	
	printf("%s stringi %d karakterden olusmaktadir.\n",isim,karakterSayisi);
	
	puts("--------------------------------------------");
	
	// strcpy fonksiyonu
	puts("ORNEK-1 b:");
	
	char kopyalananIsim[20];
	int i;
	karakterSayisi=0;
	
	puts("Lutfen kopyalamasi yapilacak olan ismi giriniz:");
	gets(isim);
	
	while(isim[karakterSayisi]!='\0')
		karakterSayisi++;
		
	
	for(i=0;i<=karakterSayisi;i++)			// 0 1 2 3 4 5 <= yaparak NULL karakteri kopyalananIsim char'ýna ekledik. bu sayede bu char dizisi bir string oldu
		kopyalananIsim[i]=isim[i];
	
	printf("Kopyalanma sonucu olusan string:%s\n",kopyalananIsim);
	
	puts("--------------------------------------------");
	
	// strcat fonksiyonu
	puts("ORNEK-1 c:");
	
	char isim1[20];
	char isim2[20];
	int karakterSayisi1,karakterSayisi2;
	
	puts("Lutfen bastaki ismi giriniz:");
	gets(isim1);
	puts("Lutfen ekleme yapmak istediginiz ismi giriniz:");
	gets(isim2);
	
	for(karakterSayisi1=0;isim1[karakterSayisi1]!='\0';karakterSayisi1++);	
	for(karakterSayisi2=0;isim2[karakterSayisi2]!='\0';karakterSayisi2++);
	
	for(i=0;i<=karakterSayisi2;i++)		// <= yapýlarak NULL karakterin de eklenmesi saðlanmýþtýr. bu sayede char dizisi string olmuþtur.
		isim1[karakterSayisi1+i]=isim2[i];
		
	puts(isim1);
	
	puts("--------------------------------------------");
	
	// strcmp fonksiyonu
	puts("ORNEK-1 d:");
	
	int esitlik=1;
	
	puts("Lutfen karsilastirmasi yapilacak ilk ismi giriniz:");
	gets(isim1);
	puts("Lutfen karsilastirmasi yapilacak ikinci ismi giriniz:");
	gets(isim2);
	
	for(karakterSayisi1=0;isim1[karakterSayisi1]!='\0';karakterSayisi1++);
	for(karakterSayisi2=0;isim2[karakterSayisi2]!='\0';karakterSayisi2++);
	
	i=0;
	while(isim1[i]=='\0' || isim2[i]=='\0')
	{
		if(isim1[i]>isim2[i])
		{
			esitlik=0;
			printf("%s stringi %s stringinden alfabetik olarak once gelmektedir.\n",isim2,isim1);
			break;
		}else if(isim1[i]<isim[i])
		{
			esitlik=0;
			printf("%s stringi %s stringinden alfabetik olarak sonra gelmektedir.\n",isim2,isim1);
			break;
		}
	}
	
	if(esitlik=1)
	{
		if(karakterSayisi1==karakterSayisi2)
			printf("Girdiginiz iki string birbirinin aynisidir.\n");
		else if(karakterSayisi1>karakterSayisi2)
			printf("%s stringi %s stringinden alfabetik olarak sonra gelmektedir.\n",isim1,isim2);
		else
			printf("%s stringi %s stringinden alfabetik olarak sonra gelmektedir.\n",isim2,isim1);
			
	}
	
	puts("--------------------------------------------");
	
	// ÖRNEK-2: Kullanýcýnýn girdiði string terse çevrilecek
	puts("ORNEK-2:"); 
	
	char kullaniciGirisi[20];
	char geciciKarakter;
	
	puts("Lutfen terse cevrilecek olan kelimeyi giriniz:");
	gets(kullaniciGirisi);
	
	karakterSayisi=strlen(kullaniciGirisi);
	
	for(i=0;i<karakterSayisi/2;i++)
	{
		geciciKarakter=kullaniciGirisi[i];
		kullaniciGirisi[i]=kullaniciGirisi[karakterSayisi-1-i];		// indeksler 0'dan baþladýðý için 1 çýkartýlmalýdýr ki son karakterin indeksine eriþebilelim
		kullaniciGirisi[karakterSayisi-1-i]=geciciKarakter;
	}
	
	printf("Girdiginiz kelimenin ters hali:%s\n",kullaniciGirisi);
	
	puts("--------------------------------------------");
	
	// ÖRNEK-3: Küçük büyük harf duyarlýlýðý olmayan bir karþýlaþtýrma programý yazýlacak.
	puts("ORNEK-3:");
	
	char ilkString[20],ikinciString[20];
	int karakterSorgusu=1;
	
	puts("Karsilastirmasi yapilacak iki stringi sirasiyla giriniz:");
	gets(ilkString);
	gets(ikinciString);
	
	karakterSayisi1=strlen(ilkString);
	karakterSayisi2=strlen(ikinciString);
	
	if(karakterSayisi1!=karakterSayisi2)
		puts("Girilen stringler birbirinden farklidir.");
	else
	{
		for(i=0;i<karakterSayisi1;i++)
		{
			if(tolower(ilkString[i])!=tolower(ikinciString[i]))
			{
				karakterSorgusu=0;
				break;
			}
		}
		if(karakterSorgusu)
			puts("Girilen stringler birbirinin aynisidir.");
		else
			puts("Girilen stringler birbirinden farklidir.");
	}
	
	puts("--------------------------------------------");
	
	// ÖRNEK-4: Kullanýcýdan alýnan cumlede yer alan kelime ve harf sayýsýný bul.
	puts("ORNEK-4");
	
	int kelimeSayisi=0;		
	char cumle[100];
	
	puts("Lutfen cumlenizi giriniz:");
	gets(cumle);
	
	karakterSayisi=strlen(cumle);
	
	for(i=0;i<karakterSayisi;i++)
	{
		if(cumle[i]==' ')
			kelimeSayisi++;
	}
	
	karakterSayisi-=kelimeSayisi;
	kelimeSayisi++;		// kelimeSayisi=bosluk+1
	
	printf("Girdiginiz metinde %d kelime, %d karakter yer almaktadir.\n",kelimeSayisi,karakterSayisi);
	printf("Girdiginiz metinde bir kelime ortalama olarak %.2f harf icermektedir.\n",(float)karakterSayisi/(float)kelimeSayisi);
	
	puts("--------------------------------------------");
	
	// ÖRNEK-5: Kullanýcýdan alýnan stringte belirli bir harfin kaç kez geçtiði bulunacak. Ayný zaman bu harf baþka bir harfle deðiþtirilecek. Harfler kullanýcýdan alýnacak.
	puts("ORNEK-5");
	
	char arananKarakter, yeniKarakter;
	i=0;
	karakterSayisi=0;
	
	puts("Lutfen stringinizi giriniz:");
	gets(kullaniciGirisi);
	puts("Lutfen aradiginiz harfi giriniz:");
	arananKarakter=getchar();
	puts("Lutfen yerine yazilacak olan karakteri giriniz:");
	fflush(stdin);
	yeniKarakter=getchar();
	
	while(kullaniciGirisi[i]!='\0')
	{
		if(kullaniciGirisi[i]==arananKarakter)
		{
			karakterSayisi++;
			kullaniciGirisi[i]=yeniKarakter;
		}
		i++;
	}
	
	printf("Aradiginiz karakter %d adet bulundu.\n",karakterSayisi);
	printf("%c karakteri %c karakteriyle yer degistirdi.\n",arananKarakter,yeniKarakter);
	printf("Stringin yeni hali:%s",kullaniciGirisi);
	
	puts("\n--------------------------------------------");
	
	// ÖRNEK-6: Palindrom sorgusu yapýlacak.
	/*
		eðer kelimenin tersi yine kendisini veriyorsa o kelime bir palindromdur.
		kabak - ada
	*/
	puts("ORNEK-6");
	
	int palindromSorgu=1;
	
	puts("Lutfen palindrom sorgusu yapilacak olan stringi giriniz:");
	fflush(stdin);
	gets(kullaniciGirisi);
	
	karakterSayisi=strlen(kullaniciGirisi);
	
	for(i=0;i<karakterSayisi/2;i++)
	{
		if(kullaniciGirisi[i]!=kullaniciGirisi[karakterSayisi-1-i])
		{
			palindromSorgu=0;
			break;
		}
	}
	
	if(palindromSorgu)
		printf("Girdiginiz string bir palindromdur.\n");
	else
		printf("Girdiginiz string bir palindrom degildir.\n");
	
	return 0;
}
