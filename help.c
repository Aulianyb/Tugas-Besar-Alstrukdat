#include <stdio.h>

//parameter state untuk membedakan help yang dipanggil sebelum start dan setelah start
void help(int state) {
    printf("Daftar Command yang dapat dipanggil : \n");
    if (state == 0) {
        printf("================== HELP ===================\n");
        printf("1. START - Membaca file konfigurasi default\n");
    }
    else {
        printf("==================================== HELP ====================================\n");
        printf("1. LOAD - Membaca save file yang berisi list game dan histori\n");
        printf("2. SAVE - Menyimpan state game pemain saat ini ke dalam save file\n");
        printf("3. CREATE GAME - Menambahkan game baru pada daftar game\n");
        printf("4. LIST GAME - Menampilkan daftar game yang disediakan oleh sistem\n");
        printf("5. START - Membaca file konfigurasi default\n");
        printf("6. DELETE GAME - Menghapus sebuah game dari daftar game\n");
        printf("7. QUEUE GAME - Mendaftarkan permainan ke dalam list game yang akan dimainkan\n");
        printf("8. PLAY GAME - Memainkan sebuah permainan\n");
        printf("9. SKIPGAME X - Melewatkan permainan sebanyak X\n");
        printf("10. QUIT - Keluar dari program\n");
        printf("11. HELP - Menampilkan daftar command yang dapat dipanggil\n");
    }
}