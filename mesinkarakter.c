#include <stdio.h>
#include "mesinkarakter.h"

char cc;
boolean eop;


static FILE *pita;
static int retval;

void START(){
	pita = stdin;
	ADV();

}

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV(){
	retval = fscanf(pita, "%c", &cc);
	eop = (cc == MARK);
	if (eop){
		fclose(pita);
	}
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC(){
	return cc;
}
/* Mengirimkan currentChar */

boolean IsEOP(){
	return (cc == MARK);
}
/* Mengirimkan true jika currentChar = MARK */