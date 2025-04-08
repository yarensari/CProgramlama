#include <stdio.h>

/*
	�ki Boyutlu Diziler:
	Sat�r ve s�tunlardan olu�ur. [sat�r][s�tun]
	A00 A01 A02 A03 A04 ... A09
	A10 A11 A12 A13 A14 ... A19
	A20 A21 A22 A23 A24 ... A29
	...
	A90 A91 A92 A93 A94 ... A99
	tan�mlama yaparken sat�r say�n� bo� ge�ebilirken s�tun say�s�n� bo� b�rakamay�z (direkt atama s�z konusu oldu�unda)
*/

int main()
{
	int ikiBoyutluDizi[10][10]={{0,1,2},{3,4,5},{6,7,8}};				// genel parantezin i�erisinde yer alan parantezler sat�rlar� temsil etmektedir.
	int i,j;
	printf("Dizi hafizada %d byte yer kaplamaktadir.\n", sizeof(ikiBoyutluDizi));
	
	// Diziyi olu�turma ve yazd�rma
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d ", ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			ikiBoyutluDizi[i][j]=0;
	}
	
	printf("--------------------------------------------\n");
	
	// �arp�m tablosu
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			ikiBoyutluDizi[i][j]=i*j;
			printf("%d\t",ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	
	printf("--------------------------------------------\n");
	
	/*
		1 0 0 0 0 0 0 0 0 0
		0 1 0 0 0 0 0 0 0 0
		0 0 1 0 0 0 0 0 0 0
		0 0 0 1 0 0 0 0 0 0
		0 0 0 0 1 0 0 0 0 0
		0 0 0 0 0 1 0 0 0 0 
		0 0 0 0 0 0 1 0 0 0
		0 0 0 0 0 0 0 1 0 0
		0 0 0 0 0 0 0 0 1 0
		0 0 0 0 0 0 0 0 0 1
	*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(i==j)
				ikiBoyutluDizi[i][j]=1;
			else
				ikiBoyutluDizi[i][j]=0;
		}
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d ",ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	
	printf("--------------------------------------------\n");
	
	/*
		1 1 1 1 1 1 1 1 1 1			00 01 02 03 04 05 06 07 08 09
		0 1 1 1 1 1 1 1 1 1			10 11 12 13 14 15 16 17 18 19
		0 0 1 1 1 1 1 1 1 1			20 21 22 23 24 25 26 27 28 29
		0 0 0 1 1 1 1 1 1 1
		0 0 0 0 1 1 1 1 1 1
		0 0 0 0 0 1 1 1 1 1 
		0 0 0 0 0 0 1 1 1 1
		0 0 0 0 0 0 0 1 1 1
		0 0 0 0 0 0 0 0 1 1
		0 0 0 0 0 0 0 0 0 1
	*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(i<=j)
				ikiBoyutluDizi[i][j]=1;
			else
				ikiBoyutluDizi[i][j]=0;
		}
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("%d ",ikiBoyutluDizi[i][j]);
		printf("\n");
	}
	
	printf("--------------------------------------------\n");
	
	/*
		0 1 0 1 0 1 0 1 0 1			00 01 02 03 04 05 06 07 08 09
		0 1 0 1 0 1 0 1 0 1			10 11 12 13 14 15 16 17 18 19
		0 1 0 1 0 1 0 1 0 1			20 21 22 23 24 25 26 27 28 29
		0 1 0 1 0 1 0 1 0 1
		0 1 0 1 0 1 0 1 0 1
		0 1 0 1 0 1 0 1 0 1 
		0 1 0 1 0 1 0 1 0 1
		0 1 0 1 0 1 0 1 0 1
		0 1 0 1 0 1 0 0 0 1
		0 1 0 1 0 1 0 0 0 1
	*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(j%2==0)
				ikiBoyutluDizi[i][j]=0;
			else
				ikiBoyutluDizi[i][j]=1;
		}
	}
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("%d ",ikiBoyutluDizi[i][j]);
		printf("\n");
	}
	
	return 0;
}
