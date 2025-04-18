#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	dinamik bellek yonetimi -tek boyutlu dizi-
	diziler bir butun icerisinde sirali bir sekilde giden degiskenlerdir.

*/
int main()
{
	srand(time(NULL));
	int dizi1[10];
	char dizi2[20];
	float dizi3[10];
	double dizi4[10];
	
	printf("int:%d char:%d float:%d double:%d\n",sizeof(dizi1),sizeof(dizi2),sizeof(dizi3),sizeof(dizi4));
	//[] bizlere adres icerisinde gezmede kolaylik saglar=>a[i]=*(a + i) kisaltmasidir.
	int *dizi;
	int elemanSayisi,i;
	
	puts("Lutfen kac adet eleman gireceginizi giriniz:");
	scanf("%d",&elemanSayisi);
	
	dizi=(int*)malloc(elemanSayisi*sizeof(int));
	for(i=0;i<elemanSayisi;i++)
		dizi[i]=i;
	for(i=0;i<elemanSayisi;i++)
		printf("%d ",dizi[i]);
	
	printf("\n");
	
	//pointerlar kullanarak hafýzadaki yeri kullanma
	/*
		1000=>0
		1002=>1
		1004=>2
		1006=>3
		1008=>4
		1010=>5
	*/
	int *ptr=dizi;
	for(;ptr<dizi+elemanSayisi;ptr++)
		*ptr=rand()%10;
	puts("Duz hali:");
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++)
		printf("%d ",*ptr);	
	puts("\nTersten hali:");
	for(ptr=dizi+elemanSayisi-1;ptr>=dizi;ptr--)
		printf("%d ",*ptr);
		
	free(dizi);
	
	return 0;
}
