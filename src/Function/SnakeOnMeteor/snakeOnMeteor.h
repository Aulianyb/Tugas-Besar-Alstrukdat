#ifndef __SNAKE_ON_METEOR__
#define __SNAKE_ON_METEOR__

#include "../ADT/listdp.h"
#include "../../random_generator.h"
#include "../ADT/mesinkata.h"

boolean isMoveValid(Word word);
/* Menghasilkan true apabila input merupakan masukan yang valid */

void MoveSnake(List *L, POINT meteor, Word input, char keyword, boolean* valid);
/* Menggerakkan snake sesuai dengan input user.
   I.S. : L terdefinisi
   F.S. : L bergerak sesuai dengan keyword apabila valid, bila tidak maka F.S. = I.S. */

void AddBody(List *L, int abs, int ord, List obstacle, POINT food, POINT meteor, boolean* emptySpace);
/* Menambahkan body snake. 
   I.S. : L, obstacle, food, dan meteor terdefinisi 
   F.S. : L bertambah panjang apabila memakan food, memberikan output apakah disekitar tail
          masih terdapat POINT kosong. */

void spawnObstacle(List *obstacle);
/* Men-generate obstacle. 
   I.S. : Sembarang
   F.S. : Mengenerate obstacle secara random dengan banyaknya obstacle dalam rentang 1-3 */

void spawnFood(List L, List Obs, POINT meteor, POINT *food);
/* Men-generate food.
   I.S. : L, Obs, meteor terdefinisi 
   F.S. : mengenerate food di POINT random yang masih kosong */

void spawnMeteor(List obstacle, POINT food, POINT *meteor, int prevAbs, int prevOrd);
/* Men-generate meteor. 
   I.S. : obstacle, food terdefinisi 
   F.S. : Meteor muncul di POINT yang belum diakusisi oleh obstacle dan food, serta
          bukan di POINT dengan Absis = prevAbs dan Ordinat = prevOrd */

void PrintGrid(List L, List obs, POINT food, POINT meteor);
/* Menampilkan grid/peta permainan saat ini 
   I.S. : L,obs,food,meteor terdefinisi 
   F.S. : peta permainan saat ini muncul
          Contoh :  [  ][  ][H ][1 ][  ]
                    [  ][X ][  ][2 ][  ]
                    [  ][  ][  ][  ][m ]
                    [  ][o ][  ][  ][  ]
                    [  ][  ][X ][  ][  ] */

void SnakeOnMeteor(int *score);
/* Memainkan permainan Snake On Meteor 
   I.S. : Sembarang
   F.S. : Menghasilkan output berupa score yang didapatkan dari panjang badan snake dikali 2 */

#endif