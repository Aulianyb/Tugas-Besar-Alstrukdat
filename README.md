# Tugas-Besar-Alstrukdat
Tugas Besar Alstrukdat 2022

Deskripsi Singkat Program :
BNMO merupakan program permainan berbasis CLI (command-line interface) yang menggunakan bahasa C. Library yang digunakan adalah stdlib.h, stdio.h, time.h, dan math.h. BNMO diprogram dengan mengimplementasikan beberapa struktur data (ADT), yaitu ADT Array, ADT Mesin karakter serta Mesin Kata, dan ADT Queue. Terdapat beberapa fitur yang dimiliki BNMO, yaitu memainkan game, menambahkan game, menghapus game, dan mengurutkan game yang akan dimainkan. Adapun beberapa game yang terdapat pada program BNMO adalah RNG, Dinner Dash, dan ROCK PAPER SCISSOR.

Pada saat pertama kali menjalankan program BNMO, ditampilkan main menu awal yang berisi welcome page dan dua command pilihan, yaitu START yang membaca file konfigurasi dan LOAD <filename> yang membaca <filename>.txt yang diinginkan. Setelah berhasil membaca file .txt, pengguna akan masuk ke menu utama program. Pada menu utama program, pengguna dapat memasukkan beberapa command. Beberapa command yang tersedia adalah CREATE GAME, LIST GAME, DELETE GAME, QUEUE GAME, PLAY GAME, HELP, dan QUIT. Jika pengguna melakukan input di luar command yang tersedia akan diberi pesan bahwa command tidak valid dan pengguna diminta untuk melakukan input ulang.

Pertama, CREATE GAME adalah command untuk menambahkan game baru pada daftar	game. Kedua, LIST GAME untuk menampilkan seluruh daftar game yang tersedia pada sistem. Ketiga, DELETE GAME untuk menghapus game dari daftar game yang tersedia. Keempat, QUEUE GAME untuk memasukkan game ke dalam antrian game yang akan dimainkan. Kelima, PLAY GAME untuk memainkan game pada urutan pertama antrian. Keenam, SKIP GAME <n> untuk melewatkan game pada antrian sebanyak n kali. Ketujuh, QUIT untuk keluar dari program. Terakhir, HELP untuk menampilkan penjelasan mengenai penggunaan command yang ada.

Game yang tersedia pertama adalah RNG. RNG merupakan permainan  dimana pengguna menebak angka yang ditentukan secara acak oleh program. Jika angka tebakan salah, program akan menampilkan bahwa angka tebakan pengguna lebih besar atau lebih kecil dari angka yang telah ditentukan. Program akan terus menerima input hingga tebakan pengguna benar.

Game kedua adalah Diner Dash. Diner Dash merupakan permainan memasak dan mengantar makanan yang terurut berdasarkan prioritasnya. Permainan dimulai dengan 3 pelanggan yang masing-masing hanya dapat memesan satu makanan. Terdapat 3 command yang tersedia pada permainan, yaitu COOK untuk memasak makanan, SERVE untuk menyajikan makanan, dan SKIP untuk menyelesaikan 1 putaran tanpa melakukan apa-apa. Ketika antrian telah melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan permainan akan selesai.

Game ketiga adalah ROCK PAPER SCISSOR yang merupakan permainan suit dimana pengguna memasukkan salah satu dari tiga opsi yang tersedia yakni rock, paper, atau scissor dan kemudian opsi yang dipilih oleh pengguna akan dibandingkan dengan opsi yang dipilih oleh lawan. Siapapun yang menang pada ronde tersebut akan mendapatkan poin 100, kecuali ketika terjadi seri maka kedua pihak tidak akan mendapatkan poin. Permainan akan berhenti ketika permainan sudah mencapai 11 ronde.

Anggota Kelompok :
Aulia Nadhirah Yasmin. B	/ 18221066
Rifqi Syafiq				/ 18221070
Hilmi Baskara Radanto		/ 18221072
Akmal Natha Abirama		/ 18221082
Farhan Algani Putra		/ 18221108

Cara kompilasi program :
gcc src/main.c src/Function/ADT/mesinkata.c src/Function/ADT/mesinkarakter.c src/Function/ADT/array.c src/Function/ADT/queue.c src/Function/Create_Game/Create_Game.c src/Function/List_Game/List_Game.c src/Function/Delete_Game/deletegame.c src/Function/Help/help.c src/Function/Queue_Game/queuegame.c src/Function/Skip_Game/skipgame.c src/Function/Play_Game/playgame.c src/console.c src/Function/RNG/rng.c src/Function/Dinner_dash/Dinner_dash.c src/random_generator.c src/Function/RockPaperScissor/RockPaperScissor.c -o main
