#ifndef QUEUECOOK_H
#define QUEUECOOK_H

#include "array_pesanan.h"
#include "../../random_generator.h"

void enqueue_cook(Tab *T, Pesanan val);
/*Memasukkan elemen ke dalam Queue dalam urutan Prioritas*/

void dequeue_cook (Tab *T, Pesanan *val);
/*Memasukkan elemen ke dalam Tab*/

void TulisIsi_Cook(Tab T);
/*menuliskan label dan durasi pesanan*/

void TulisIsi_Served(Tab T);
/*menuliskan label dan ketahanan makanan*/

void UpdateCook_Tab(Tab *T);
/*Update seluruh anggota Tab*/

void UpdateServed_Tab(Tab *T);
/*Update seluruh anggota Tab*/

boolean isMember_cook(Tab T, int label);
/*Cek apakah pesanan dengan label yang dimasukkan pengguna ada di dalam Queue/Array atau tidak*/

#endif

