#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	// SORU-1: Kullan�c�dan al�nan string ifadedeki b�y�k harfler k���k harfe, k���k harfler de b�y�k harfe d�n��t�r�lecek.
	puts("SORU-1:");
	
	char kullaniciGirisi[50];
	int i=0;
	
	puts("Lutfen buyuk kucuk harf degisimi yapilacak olan kelimeyi giriniz:");
	gets(kullaniciGirisi);
	
	while(kullaniciGirisi[i]!='\0')
	{
		if(isupper(kullaniciGirisi[i]))
			kullaniciGirisi[i]=tolower(kullaniciGirisi[i]);
		else
			kullaniciGirisi[i]=toupper(kullaniciGirisi[i]);
		i++;
	}
	
	puts("Donusturulmus hali:");
	puts(kullaniciGirisi);
	
	puts("----------------------------------------------------------------");
	
	// SORU-2: Kullan�c�dan iki adet string al�nacak. �kinci stringin birinci stringte ge�ip ge�medi�i kontrol edilecek.
	/*
		serkan
		erkan
		kan
		er
	*/
	puts("SORU-2");
	
	char ilkString[50];
	char ikinciString[50];
	int j=0,k=0,karakterSayisi1,karakterSayisi2,uyumluMu=1;
	i=0;
	
	puts("Lutfen birinci stringi giriniz:");
	gets(ilkString);
	puts("Lutfen ikinci stringi giriniz:");
	gets(ikinciString);
	
	karakterSayisi1=strlen(ilkString);
	karakterSayisi2=strlen(ikinciString);
	
	char karsilastirilmisDeger[karakterSayisi2];
	
	for(i=0;i<=karakterSayisi1;i++)
	{
		for(j=0;j<=karakterSayisi2;j++)
		{
			if(ilkString[i+j]==ikinciString[j])
			{
				karsilastirilmisDeger[k]=ikinciString[j];
				karsilastirilmisDeger[k+1]='\0';			// sona null karakter eklenerek string olmas� sa�lan�r.	
				k++;
			}
			else
				break;
		}
		if(strcmp(ikinciString,karsilastirilmisDeger)==0)
		{
			printf("%s stringinin icerisinde %s stringi yer almaktadir.\n",ilkString,ikinciString);
			break;
		}
		else
		{
			k=0;
			karsilastirilmisDeger[k]='\0';				// string ifadenin ilk karakteri '\0' yap�larak bo�alt�lmas� sa�lan�r
		}
	}
	
	puts("----------------------------------------------------------------");
	
	// SORU-2:Kurstaki ��z�m
	puts("SORU-2:Kurstaki cozum");
	
	int sorgu=0,devamEdilecekIndeks=0;
	i=0;
	j=0;
	ilkString[i]='\n';
	ikinciString[i]='\n';
	
	puts("Lutfen ilk stringi giriniz:");
	gets(ilkString);
	puts("Lutfen ikinci stringi giriniz:");
	gets(ikinciString);
	
	while(ilkString[i]!='\0')
	{
		i=devamEdilecekIndeks;
		j=0;
		sorgu=1;
		while(ikinciString[j]!='\0')
		{
			if(ilkString[i]!=ikinciString[j])
			{
				sorgu=0;
				break;
			}
			i++;
			j++;
		}
		if(sorgu)
		{
			printf("%s stringinin icerisinde %s stringi yer almaktadir.\n",ilkString,ikinciString);
			break;		
		}
		devamEdilecekIndeks++;
	}
	
	puts("----------------------------------------------------------------");
	
	// SORU-3: Kullan�c�n�n girdi�i iki stringin birbirinin anagram� olup olmad���n� kontrol et.
	/*
		kalem->kelam : ikisi de ayn� harfleri i�ermekte
	*/
	puts("SORU-3");
	
	int bulunduMu=0;
	i=0;
	j=0;
	ilkString[i]='\0';
	ikinciString[i]='\0';
	
	puts("Lutfen anagram kontrolu yapilacak olan ilk stringi giriniz:");
	gets(ilkString);
	puts("Lutfen anagram kontrolu yapilacak olan ikinci stringi giriniz:");
	gets(ikinciString);
	
	karakterSayisi1=strlen(ilkString);
	karakterSayisi2=strlen(ikinciString);
	
	if(karakterSayisi1==karakterSayisi2)
	{
		for(i=0;i<=karakterSayisi1;i++)
		{	
			bulunduMu=0;
			for(j=0;j<=karakterSayisi2;j++)
			{
				if(ilkString[i]==ikinciString[j])
				{
					bulunduMu=1;
					break;
				}
			}
			if(bulunduMu==0)
			{
				printf("%c harfi %s stringinde yer almamaktadir.\n",ilkString[i],ikinciString);
				break;
			}
		}
	}
	else
		puts("Karakter sayilari uyusmamaktadir.");
	
	if(bulunduMu)
		printf("%s stringi ile %s stringi birbirinin anagramidir.\n",ilkString,ikinciString);
	
	
	puts("----------------------------------------------------------------");
	
	// Kurstaki ��z�m:
	// Kursta karakter dizileri s�ralanarak kontrol edildi.
	puts("SORU-3:Kurstaki cozum");
	
	int eleman;
	sorgu=1;
	ilkString[i]='\0';
	ikinciString[i]='\0';	
	
	puts("Lutfen anagram kontrolu yapilacak olan ilk stringi giriniz:");
	gets(ilkString);
	puts("Lutfen anagram kontrolu yapilacak olan ikinci stringi giriniz:");
	gets(ikinciString);
	
	karakterSayisi1=strlen(ilkString);
	karakterSayisi2=strlen(ikinciString);
	
	if(karakterSayisi1!=karakterSayisi1)
		puts("Anagram degiller.");
	else
	{
		for(i=1;i<karakterSayisi1;i++)
		{
			eleman=ilkString[i];
			for(j=i-1;j>=0 && eleman<=ilkString[j];j--)
			{
				ilkString[j+1]=ilkString[j];
			}
			ilkString[j+1]=eleman;
		}
		for(i=1;i<karakterSayisi2;i++)
		{
			eleman=ikinciString[i];
			for(j=i-1;j>=0 && eleman<=ikinciString[j];j--)
			{
				ikinciString[j+1]=ikinciString[j];
			}
			ikinciString[j+1]=eleman;
		}	
		for(i=0;i<karakterSayisi1;i++)
		{
			if(ilkString[i]!=ikinciString[i])
			{
				sorgu=0;
				break;
			}
		}
		if(sorgu)
			puts("Anagramdir.");
		else
			puts("Anagram degildir.");
	}	
	
	puts("----------------------------------------------------------------");
	
	// SORU-4: Kullan�c�dan al�nan stringin ba� harfleri b�y�k harfe �evrilecek.
	puts("SORU-4:");
	
	i=0;
	j=0;
	kullaniciGirisi[i]='\0';
	char buyukHarfler[10];
	
	puts("Lutfen bas harfleri buyuk harfe cevrilecek olan kelimeyi giriniz:");
	gets(kullaniciGirisi);
	
	// �lk harf al�n�
	kullaniciGirisi[i]=toupper(kullaniciGirisi[i]);	
	buyukHarfler[j]=kullaniciGirisi[i];
	i++;
	j++;
	
	while(kullaniciGirisi[i]!='\0')
	{
		if(kullaniciGirisi[i]==' ')
		{
			kullaniciGirisi[i+1]=toupper(kullaniciGirisi[i+1]);	
			buyukHarfler[j]=kullaniciGirisi[i+1];
			j++;
		}
		i++;
	}
	
	buyukHarfler[j]='\0';
	
	printf("Buyuk harfe donusturulmus hali:");
	puts(kullaniciGirisi);
	printf("Buyuk harflerin ciktisi:");
	puts(buyukHarfler);
	
	return 0;
}
