#include <stdio.h>
#include <stdlib.h>
/*
	calloc:clear and allocation=>yine yer ayirma islemi yapiliyor fakat bu sefer ayrilan yerlerin hepsine 0 degeri ataniyor.istenirse bu deger degistirilebilir.
	realloc:reallocation=>daha onceden,calloc veya malloc ile, ayrilan yerin degerini arttirmayi saglar.
	
*/
int main()
{
	int elemanSayisi;
	int *dizi,*ptr;
	//CALLOC
	puts("Lutfen eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	dizi=(int *)calloc(elemanSayisi,sizeof(int));
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
	{
		*ptr=10;
		printf("%d ",*ptr);
	}
	//REALLOC
	puts("\nEleman sayisini kaca yukselteceksiniz:");
	scanf("%d",&elemanSayisi);
	
	dizi=realloc(dizi,elemanSayisi*sizeof(int));	//elemanSayisi yukseltildi.artan elemanSayisi degerinden sonra artik o elemanlarin yerine garbage value'lar geldi
	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
	{
		*ptr=20;	//garbage value olmasin diye
		printf("%d ",*ptr);
	}
	
	free(dizi);
	
	return 0;
}
