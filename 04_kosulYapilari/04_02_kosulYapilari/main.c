#include <stdio.h>

int main()
{
	float kullaniciBakiyesi = 1250.0, kullaniciMiktar, gunlukLimit = 500;
	int islem;
	
	printf("\t Merhabalar, Hosgeldiniz\n");
	printf("\t Para yatirmak icin 1, para cekmek icin 2, hesap bakiyesi goruntulemek icin 3'e basiniz: ");
	scanf("%d", &islem);
	
	if(islem == 1)
	{
		printf("\t Yatirmak istediginiz miktari giriniz: ");
		scanf("%f", &kullaniciMiktar);
		if(kullaniciMiktar == 0)
		{
			printf("\t Lutfen belirtilen surede bir para girisi yapiniz.\n");
			sleep(3);	// 3 saniye boyunca program durur
			printf("\t Yatirmak istediginiz miktari giriniz: ");
			scanf("%f", &kullaniciMiktar);	
		}
		kullaniciBakiyesi += kullaniciMiktar;
		printf("\t Isleminiz basariyla gerceklestirildi. Tesekkur ederiz.\n");
		printf("\t Yeni bakiyeniz : %.2f\n", kullaniciBakiyesi);
	}
	else if(islem == 2)
	{
		printf("\t Cekmek istediginiz miktari giriniz: ");
		scanf("%f", &kullaniciMiktar);
		
		if(kullaniciMiktar > kullaniciBakiyesi)
			printf("\t Yetersiz bakiye. Islem gerceklesemiyor.");
		else if (kullaniciMiktar > gunlukLimit)
			printf("\t Gunluk para cekme limitini astiniz. Islem gerceklesemiyor.");
		else 
		{
			kullaniciBakiyesi -= kullaniciMiktar;
			printf("\t Islem basariyla gerceklesti. Tesekkur ederiz.\n");
			printf("\t Yeni bakiyeniz : %.2f\n", kullaniciBakiyesi);
		}
	}
	else if(islem == 3)
	{
		printf("\t Bakiyeniz : %.2f\n", kullaniciBakiyesi);
	}
	else
		printf("\t Yanlis islem girisi yaptiniz!");
	
	return 0;
}
