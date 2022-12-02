#include <stdio.h>
#include "help.h"

//parameter state untuk membedakan help yang dipanggil sebelum start dan setelah start
void help() {
/*
I.S. Sembarang
F.S. Menampilkan seluruh command yang dapat dipanggil di dalam sistem.
*/
    printf("======================================= HELP =======================================\n");
    printf("No  | Daftar Command | Keterangan\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("1.  | SAVE <namafile>   | Menyimpan state game pemain saat ini ke dalam save file. Tidak perlu menyertakan .txt\n");
    printf("2.  | CREATE GAME       | Menambahkan game baru pada daftar game\n");
    printf("3.  | LIST GAME         | Menampilkan daftar game yang disediakan oleh sistem\n");
    printf("4.  | START             | Membaca file konfigurasi default\n");
    printf("5.  | DELETE GAME       | Menghapus sebuah game dari daftar game\n");
    printf("6.  | QUEUE GAME        | Mendaftarkan permainan ke dalam list game yang akan dimainkan\n");
    printf("7.  | PLAY GAME         | Memainkan sebuah permainan\n");
    printf("8.  | SKIP GAME X       | Melewatkan permainan sebanyak X\n");
    printf("9.  | QUIT              | Keluar dari program\n");
    printf("10. | HELP              | Menampilkan daftar command yang dapat dipanggil\n");
    printf("11. | SCOREBOARD        | Menampilkan daftar scoreboard pada setiap permainan\n");
    printf("12. | RESET SCOREBOARD  | Menghapus scoreboard pada suatu permainan yang diinginkan\n");
    printf("11. | HISTORY           | Menampilkan daftar riwayat permainan yang dimainkan pemain.\n");
    printf("12. | RESET HISTORY     | Menghapus riwayat permainan yang dimainkan pemain\n");
}