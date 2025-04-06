#include <stdio.h>

int main()
{
	int sayiInt = 1234;
	printf("sayiInt 10'luk taban : %d\n", sayiInt);
	printf("sayiInt 16'lik taban : %X\n", sayiInt);		// 4D2  = 16^0*2 + 16^1*13 + 16^2*4 	   = 1234
	printf("sayiInt 8'lik taban  : %o\n", sayiInt);		// 2322 = 8^0*2  + 8^1*2   + 8^2*3 + 8^3*2 = 1234
	
	float sayiFloat = 1.123456;
	printf("sayiFloat normal gosterimi   : %f\n", sayiFloat);
	printf("sayiFloat bilimsel gosterimi : %e\n", sayiFloat);
	
	printf("Merhaba Dunya\n");			// \n alt satýra geçirir
	printf("Merhaba \t Dunya\n");		// \t tab kadar boþluk býrakýr
	printf("Merhaba\bDunya\n");			// \b backspace karakteridir. bir karakter geriye siler.
	printf("Merhaba \\ Dunya\n");		// printf fonksiyonuna özel karakterleri kullanmak için, \ gibi, \ karakteri kullanýlmalýdýr
	printf("\"Merhaba Dunya\"\n");
	printf("Merhaba 5*8 Dunya\n");
	printf("Merhaba 5%%8 Dunya\n");		// mod ifadesi normalde deðiþken eklemek için kullanýldýðýndan bu þekilde kullanýlmalýdýr
	
	return 0;
}
