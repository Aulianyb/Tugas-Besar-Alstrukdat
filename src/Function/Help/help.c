#include <stdio.h>
#include "help.h"

//parameter state untuk membedakan help yang dipanggil sebelum start dan setelah start
void help(int state) {
/*
I.S. Sembarang
F.S. Menampilkan seluruh command yang dapat dipanggil di dalam sistem
     berdasarkan statenya. Bila state = 0, maka hanya menampilkan START. Bila
     state = 1, menampilkan sisa command yang lain.
*/
    printf("Daftar Command yang dapat dipanggil : \n");
    if (state == 0) {
        printf("==================================== HELP ====================================\n");
        printf("No  | Daftar Command | Keterangan\n");
        printf("------------------------------------------------------------------------------\n");
        printf("1.  | START          | Membaca file konfigurasi default\n");
        printf("2.  | LOAD           | Membaca save file yang berisi list game dan histori\n");
    }
    else {
        printf("======================================= HELP =======================================\n");
        printf("No  | Daftar Command | Keterangan\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("1.  | SAVE           | Menyimpan state game pemain saat ini ke dalam save file\n");
        printf("2.  | CREATE GAME    | Menambahkan game baru pada daftar game\n");
        printf("3.  | LIST GAME      | Menampilkan daftar game yang disediakan oleh sistem\n");
        printf("4.  | START          | Membaca file konfigurasi default\n");
        printf("5.  | DELETE GAME    | Menghapus sebuah game dari daftar game\n");
        printf("6.  | QUEUE GAME     | Mendaftarkan permainan ke dalam list game yang akan dimainkan\n");
        printf("7.  | PLAY GAME      | Memainkan sebuah permainan\n");
        printf("8.  | SKIPGAME X     | Melewatkan permainan sebanyak X\n");
        printf("9.  | QUIT           | Keluar dari program\n");
        printf("10. | HELP           | Menampilkan daftar command yang dapat dipanggil\n");
    }
}