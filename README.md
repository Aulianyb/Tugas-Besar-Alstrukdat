# Tugas-Besar-Alstrukdat
Tugas Besar Alstrukdat 2022

**DESKRIPSI SINGKAT PROGRAM :**

BNMO merupakan program permainan berbasis CLI (command-line interface) yang menggunakan bahasa C. Library yang digunakan adalah stdlib.h, stdio.h, time.h, dan math.h. BNMO diprogram dengan mengimplementasikan beberapa struktur data (ADT), yaitu ADT Array, ADT Mesin karakter serta Mesin Kata, dan ADT Queue. Terdapat beberapa fitur yang dimiliki BNMO, yaitu memainkan game, menambahkan game, menghapus game, dan mengurutkan game yang akan dimainkan. Adapun beberapa game yang terdapat pada program BNMO adalah RNG, Dinner Dash, dan ROCK PAPER SCISSOR.

Pada saat pertama kali menjalankan program BNMO, ditampilkan main menu awal yang berisi welcome page dan dua command pilihan, yaitu START yang membaca file konfigurasi dan LOAD <filename> yang membaca <filename>.txt yang diinginkan. Setelah berhasil membaca file .txt, pengguna akan masuk ke menu utama program. Pada menu utama program, pengguna dapat memasukkan beberapa command. Jika pengguna melakukan input di luar command yang tersedia akan diberi pesan bahwa command tidak valid dan pengguna diminta untuk melakukan input ulang. Berikut merupakan daftar command yang tersedia:

    1. CREATE GAME adalah command untuk menambahkan game baru pada daftar	game.
    2. LIST GAME untuk menampilkan seluruh daftar game yang tersedia pada sistem.
    3. DELETE GAME untuk menghapus game dari daftar game yang tersedia.
    4. QUEUE GAME untuk memasukkan game ke dalam antrian game yang akan dimainkan.
    5. PLAY GAME untuk memainkan game pada urutan pertama antrian.
    6. SKIP GAME <n> untuk melewatkan game pada antrian sebanyak n kali.
    7. QUIT untuk keluar dari program.
    8. HELP untuk menampilkan penjelasan mengenai penggunaan command yang ada.
    9. SCOREBOARD untuk menampilkan daftar scoreboard pada setiap permainan
    10. RESET SCOREBOARD untuk menghapus scoreboard pada suatu permainan yang diinginkan.
    11. HISTORY untuk menampilkan daftar riwayat permainan yang dimainkan pemain.
    12. RESET HISTORY untuk menghapus riwayat permainan yang dimainkan pemain.
    
Kemudian, tersedia pula beberapa game pada BNMO ini, di antaranya:

    1. RNG 
       merupakan permainan  dimana pengguna menebak angka yang ditentukan secara acak oleh program. Jika angka tebakan salah, program akan menampilkan bahwa angka tebakan pengguna lebih besar atau lebih kecil dari angka yang telah ditentukan. Program akan terus menerima input hingga tebakan pengguna benar.
    2. Diner Dash 
       merupakan permainan memasak dan mengantar makanan yang terurut berdasarkan prioritasnya. Permainan dimulai dengan 3 pelanggan yang masing-masing hanya dapat memesan satu makanan. Terdapat 3 command yang tersedia pada permainan, yaitu COOK untuk memasak makanan, SERVE untuk menyajikan makanan, dan SKIP untuk menyelesaikan 1 putaran tanpa melakukan apa-apa. Ketika antrian telah melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan permainan akan selesai.
    3. ROCK PAPER SCISSOR 
       yang merupakan permainan suit dimana pengguna memasukkan salah satu dari tiga opsi yang tersedia yakni rock, paper, atau scissor dan kemudian opsi yang dipilih oleh pengguna akan dibandingkan dengan opsi yang dipilih oleh lawan. Siapapun yang menang pada ronde tersebut akan mendapatkan poin 100, kecuali ketika terjadi seri maka kedua pihak tidak akan mendapatkan poin. Permainan akan berhenti ketika permainan sudah mencapai 11 ronde.
    4. Hangman
       Hangman adalah permainan tebak kata yang memiliki beberapa spesifikasi. Pada awal permainan, Program akan menentukan satu kata dan pemain memiliki 10 kesempatan untuk menebak huruf yang tidak ada di dalam kata tersebut. Jika huruf ada di dalam kata, maka huruf yang tertebak akan ditampilkan. Jika salah, kesempatan pemain berkurang satu. Pemain tidak boleh menebak huruf yang sudah ditebak sebelumnya pada kata yang sama. Jika seluruh huruf pada satu kata telah lengkap ditebak, maka akan diberikan poin dan pemain terus berlanjut hingga pemain kehabisan kesempatan.
    5. Tower Of Hanoi
       Tower of Hanoi adalah permainan yang terdiri dari 3 tiang, yaitu tiang A, B, dan C. Pada awal permainan, pemain akan diminta untuk memasukkan banyaknya piringan untuk dimainkan. Kemudian, seluruh piringan akan tertumpuk di tiang A dari yang paling besar di bawah hingga yang paling kecil di atas. Pemain diminta untuk memindahkan seluruh piringan tersebut dengan urutan yang sama dengan tiang A awal pada tiang C. Terdapat beberapa peraturan yang ada: piringan yang berada di atas tidak boleh lebih besar dibandingkan yang ada di bawah, skor yang didapat pemain bergantung dari seberapa banyak langkah yang dibutuhkan untuk menyusun piringan.
    6. Snake On Meteor
       Snake on Meteor merupakan game yang seperti snake pada konsol lama tetapi ditambah dengan fitur meteor. Permainan dimulai dengan ular dengan tanda H yang berarti kepala dan dilanjutkan dengan angka berurut dari 1 sebagai badan ular. Permainan berlanjut hingga seluruh komponen snake terkena meteor hingga panjang snake adalah 0 atau kepala snake terkena meteor atau ekor baru tidak dapat dispawn karena tidak ada area di kiri, atas, bawah, atau kanan ekor lama.
    7. Slay the Dragon

**ANGGOTA KELOMPOK :**  
Aulia Nadhirah Yasmin. B	(18221066)
Rifqi Syafiq				(18221070)
Hilmi Baskara Radanto		(18221072)
Akmal Natha Abirama		(18221082)
Farhan Algani Putra		(18221108)

**CARA KOMPILASI PROGRAM :**  
Directory ke file tempat menyimpan program, kemudian masukkan command di bawah ini, lalu run main.

```
gcc src/main.c src/Function/ADT/mesinkata.c src/Function/ADT/mesinkarakter.c src/Function/ADT/array.c src/Function/ADT/queue.c src/Function/Create_Game/Create_Game.c src/Function/List_Game/List_Game.c src/Function/Delete_Game/deletegame.c src/Function/Help/help.c src/Function/Queue_Game/queuegame.c src/Function/Skip_Game/skipgame.c src/Function/Play_Game/playgame.c src/console.c src/Function/RNG/rng.c src/Function/Dinner_dash/Dinner_dash.c src/random_generator.c src/Function/RockPaperScissor/RockPaperScissor.c src/Function/ADT/Stack.c src/Function/Hanoi/Hanoi.c src/Function/resetscoreboard/resetscoreboard.c src/Function/resethistory/resethistory.c src/Function/history/history.c src/Function/ADT/arrayofmap/arrayofmap.c src/Function/ADT/map/map.c src/Function/ADT/stackhistory/stackhistory.c src/Function/scoreboard/scoreboard.c src/Function/hangman/hangman.c src/Function/SnakeOnMeteor/snakeOnMeteor.c src/Function/ADT/point.c src/Function/ADT/listdp.c src/Function/Tree_Game/Tree_Game.c src/Function/ADT/tree/tree.c -o main
```
