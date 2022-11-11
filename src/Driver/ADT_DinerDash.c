#include "../Function/Dinner_Dash/Dinner_Dash.h"
#include <stdio.h>


/*DRIVER INI BERISI SELURUH ADT YANG DIPAKAI DALAM GAME DINER DASH*/

int main(){
	printf("========= DRIVER ADT PADA GAME DINER DASH =========");
	//KAMUS
	Tab T;
	Pesanan temp;


	//KONSTRUKTOR
	printf("\n=== MakeEmpty_Pesanan ===\n");
	MakeEmpty_pesanan(&T);
	//OUTPUT
	printf("Membuat suatu Array Pesanan Kosong\n");
	TulisIsi_pesanan(T);
	printf("\n");


	//TEST KOSONG
	printf("\n=== IsEmpty_pesanan ===\n");
	printf("Cek apakah Array Pesanan kosong atau tidak\n");
	//OUTPUT
	printf("HASIL RETURN : %d\n", IsEmpty_pesanan(T));
	printf("\n");


	//TEST PENUH
	printf("\n=== IsFull_pesanan ===\n");
	printf("Dilakukan pengisian Tab T sebanyak 20 elemen\n\n");
	for (int i=0; i < 20; i++){
		buat_pesanan(&T, i);
	}
	//OUTPUT
	TulisIsi_pesanan(T);
	printf("\nNOTES : KARENA RANDOM GENERATOR MENGGUNAKAN TIME.H DAN \nKAMI TIDAK INGIN MEMPERLAMBAT PROSES LOADING FILE DRIVER\nDENGAN DELAY, MAKA OUTPUT SEMUA NILAI AKAN SAMA\nINI BERLAKU UNTUK SEMUA RANDOMLY GENERATED VALUES\n");
	printf("HASIL RETURN : %d\n", IsFull_pesanan(T));
	printf("\n");


	//INSERT
	printf("\n=== Insert_pesanan ===\n");
	printf("Memasukkan suatu pesanan spesifik ke akhir Array Pesanan\n");
	printf("Tab T akan direset kembali menjadi kosong\n\n");
	MakeEmpty_pesanan(&T);
	TulisIsi_pesanan(T);
	printf("Memasukkan pesanan dengan Insert_pesanan\n");
	printf("MISAL : Memasukkan pesanan label 0, durasi 5, ketahanan 5 dan harga 10000\n\n");
	Insert_pesanan(&T, 0, 5, 5, 10000);
	//OUTPUT
	TulisIsi_pesanan(T);
	printf("\n");
	printf("MISAL : Memasukkan pesanan label 1, durasi 2, ketahanan 3 dan harga 4\n\n");
	Insert_pesanan(&T, 1, 2, 3, 4);
	TulisIsi_pesanan(T);
	printf("\n");
	

	//DELETE
	printf("\n=== Delete_pesanan ===\n");
	printf("Menghapus suatu pesanan dengan label sesuai dengan label\ndan menyimpannya dalam output val\n");
	printf("MISAL : Menghapus pesanan label 1\n\n");
	Delete_pesanan(&T, 1, &temp);
	//OUTPUT
	TulisIsi_pesanan(T);
	printf("\n");
	printf("NILAI OUTPUT VAL : \n");
	printf("LABEL VAL : %d\n", Label_int(temp));
	printf("DURASI VAL : %d\n", Durasi(temp));
	printf("KETAHANAN VAL : %d\n", Ketahanan(temp));
	printf("HARGA VAL : %d\n", Harga(temp));

	//TULIS ISI PESANAN
	printf("\n=== TulisIsi_pesanan ===\n");
	printf("Menuliskan semua isi Pesanan\n");
	printf("MISAL : Kita akan memasukkan 5 Pesanan dummy pada Tab\n");
	for (int i=1; i < 6; i++){
		buat_pesanan(&T, i);
	}
	//OUTPUT
	TulisIsi_pesanan(T);
	printf("\nDiatas adalah penulisan isi dari data dummy di T\n");

	//LABEL_INT
	printf("\n=== Label_Int ===\n");
	printf("Mengembalikan Label suatu pesanan dalam tipe data integer\n");
	printf("MISAL : Kita mengambil pesanan dengan label 5\n");
	Delete_pesanan(&T, 5, &temp);
	//OUTPUT
	printf("Kita dapat menuliskan label dalam tipe data int : %d\n\n", Label_int(temp));
	TulisIsi_pesanan(T);

	//ENQUEUE COOK
	printf("\n=== enqueue_cook ===\n");
	printf("Memasukkan pesanan ke dalam queue cook, sesuai dengan prioritas label\n");
	printf("MISAL : Kita enqueue pesanan dengan label 2, durasi 2, ketahanan 2 dan harga 2\n\n");
	Label(temp)->TabWord[0] = 'M';
	Label(temp)->Length = 1;
	MergeWord(Label(temp), IntToWord(2));
	Durasi(temp) = 2;
	Ketahanan(temp) = 2;
	Harga(temp) = 2;

	enqueue_cook(&T, temp);
	TulisIsi_pesanan(T);
	printf("\n");

	//DEQUEUE COOK
	printf("\n=== dequeue_cook ===\n");
	printf("Menghapus urutan pertama dalam queue dan menyimpannya dalam val\n");
	printf("MISAL : Kita melakukan dequeue terhadap T\n\n");
	dequeue_cook(&T, &temp);
	//OUTPUT
	TulisIsi_pesanan(T);
	printf("\n");
	printf("NILAI OUTPUT VAL : \n");
	printf("LABEL VAL : %d\n", Label_int(temp));
	printf("DURASI VAL : %d\n", Durasi(temp));
	printf("KETAHANAN VAL : %d\n", Ketahanan(temp));
	printf("HARGA VAL : %d\n", Harga(temp));
	printf("\n");

	//TULISISI_COOK
	printf("\n=== TulisIsi_cook ===\n");
	printf("Fungsi ini hanya menuliskan Label dan Durasi dari Pesanan\n");
	printf("MISAL : Menggunakan Tulis Isi Cook untuk T\n\n");
	//OUTPUT
	TulisIsi_Cook(T);
	printf("\n");

	//TULISISI_SERVED
	printf("\n=== TulisIsi_Served ===\n");
	printf("Fungsi ini hanya menuliskan Label dan Ketahanan dari Pesanan\n");
	printf("MISAL : Menggunakan Tulis Isi Served untuk T\n\n");
	//OUTPUT
	TulisIsi_Served(T);
	printf("\n");

	//UPDATE COOK_TAB
	printf("\n=== UpdateCook_Tab ===\n");
	printf("Fungsi ini akan melakukan update kepada Makanan yang sedang dimasak\n");
	printf("Durasi makanan akan dikurangi satu\n");
	//OUTPUT
	UpdateCook_Tab(&T);
	TulisIsi_Cook(T);
	printf("\n");

	//UPDATE SERVED_TAB
	printf("\n=== UpdateServed_Tab ===\n");
	printf("Fungsi ini akan melakukan update kepada Makanan yang dapat disajikan\n");
	printf("Ketahanan makanan akan dikurangi satu\n");
	//OUTPUT
	UpdateServed_Tab(&T);
	TulisIsi_Served(T);
	printf("\n");

	//ISMEMBER_COOK
	printf("\n=== isMember_cook ===\n");
	printf("Fungsi ini akan bernilai true jika pesanan dengan label yang\ndimasukkan pengguna ada dalam Queue\n");
	printf("TEST : APAKAH LABEL 20 ADA DALAM T?\n");
	printf("HASIL RETURN : %d\n", isMember_cook(T, 20));
	printf("TEST : APAKAH LABEL 3 ADA DALAM T?\n");
	printf("HASIL RETURN : %d\n", isMember_cook(T, 3));
	printf("\n");


	//isCook, isServe, isSkip	
	printf("\n=== isCook, isServe, isSkip ===\n");
	printf("isCook : bernilai true bila kata pertama yang dimasukkan adalah COOK\n");
	printf("isServe : bernilai true bila kata pertama yang dimasukkan adalah SERVE\n");
	printf("isCook : bernilai true bila kata yang dimasukkan adalah SKIP\n");
	
	printf("\n== TEST 1 : COOK M0 ==\n");
	currentWord.TabWord[0] = 'C';
	currentWord.TabWord[1] = 'O';	
	currentWord.TabWord[2] = 'O';
	currentWord.TabWord[3] = 'K';
	currentWord.TabWord[4] = ' ';
	currentWord.TabWord[5] = 'M';
	currentWord.TabWord[6] = '0';
	currentWord.Length = 7; 

	printf("Hasil IsCook : %d\n", isCook(currentWord));
	printf("Hasil IsServe : %d\n", isServe(currentWord));
	printf("Hasil IsSkip : %d\n", isSkip(currentWord));

	printf("\n== TEST 2 : SERVE M0 ==\n");
	currentWord.TabWord[0] = 'S';
	currentWord.TabWord[1] = 'E';	
	currentWord.TabWord[2] = 'R';
	currentWord.TabWord[3] = 'V';
	currentWord.TabWord[4] = 'E';
	currentWord.TabWord[5] = ' ';
	currentWord.TabWord[6] = 'M';
	currentWord.TabWord[7] = '0';

	currentWord.Length = 8; 

	printf("Hasil IsCook : %d\n", isCook(currentWord));
	printf("Hasil IsServe : %d\n", isServe(currentWord));
	printf("Hasil IsSkip : %d\n", isSkip(currentWord));

	printf("\n== TEST 3 : SKIP ==\n");
	currentWord.TabWord[0] = 'S';
	currentWord.TabWord[1] = 'K';	
	currentWord.TabWord[2] = 'I';
	currentWord.TabWord[3] = 'P';

	currentWord.Length = 4; 

	printf("Hasil IsCook : %d\n", isCook(currentWord));
	printf("Hasil IsServe : %d\n", isServe(currentWord));
	printf("Hasil IsSkip : %d\n", isSkip(currentWord));

	printf("\n== TEST 3 : GOOFY AH ==\n");
	currentWord.TabWord[0] = 'G';
	currentWord.TabWord[1] = 'O';	
	currentWord.TabWord[2] = 'O';
	currentWord.TabWord[3] = 'F';
	currentWord.TabWord[4] = 'Y';
	currentWord.TabWord[5] = ' ';
	currentWord.TabWord[6] = 'A';
	currentWord.TabWord[7] = 'H';

	currentWord.Length = 8; 

	printf("Hasil IsCook : %d\n", isCook(currentWord));
	printf("Hasil IsServe : %d\n", isServe(currentWord));
	printf("Hasil IsSkip : %d\n", isSkip(currentWord));
}