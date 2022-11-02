#include "array_pesanan.h"

#ifndef QUEUE_H
#define QUEUE_H

void dequeue (Tab *T, Pesanan *val);
/*Memasukkan elemen ke dalam Tab*/

void TulisIsi_Cook(Tab T);
/*menuliskan label dan durasi pesanan*/

void TulisIsi_Served(Tab T);
/*menuliskan label dan ketahanan makanan*/

void UpdateCook_Tab(Tab *T);
/*Update seluruh anggota Tab*/

void UpdateServed_Tab(Tab *T);
/*Update seluruh anggota Tab*/

#endif

