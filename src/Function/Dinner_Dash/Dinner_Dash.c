#include "Dinner_Dash.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty_pesanan(Tab *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong */
	T->Neff = 0;
	T->buffer[MaxEl];
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty_pesanan(Tab T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull_pesanan (Tab T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (T.Neff == MaxEl);
}

/* ********** MODIFIKASI TAB ********** */
void Insert_pesanan(Tab *T, int label, int durasi, int ketahanan, int harga){
	Label(T->buffer[Neff(*T)])->TabWord[0] = 'M';
	Label(T->buffer[Neff(*T)])->Length = 1;
	MergeWord(Label(T->buffer[Neff(*T)]), IntToWord(label));
	Durasi(T->buffer[Neff(*T)]) = durasi;
	Ketahanan(T->buffer[Neff(*T)]) = ketahanan;
	Harga(T->buffer[Neff(*T)]) = harga;
	Neff(*T)++;
}
/* Memasukkan suatu pesanan ke dalam Tab */

void Delete_pesanan(Tab *T, int label, Pesanan *val){
	boolean found=false;
	int i=0;
	while (i < Neff(*T) && !found){
		if (WordToInt((GetLabel(Label(*T->buffer[i])))) == label){
			found = true;
		}
		else{
			i++;
		}
	}

	if (found){
		Move(val->label, Label(*T->buffer[i]));
		val->durasi = Durasi(T->buffer[i]);
		val->ketahanan = Ketahanan(T->buffer[i]);
		val->harga = Harga(T->buffer[i]);

		for (int j=i;j<Neff(*T)-1;j++){
		Move(Label(T->buffer[j]), Label(*T->buffer[j+1]));
		Durasi(T->buffer[j]) = Durasi(T->buffer[j+1]);
		Ketahanan(T->buffer[j]) = Ketahanan(T->buffer[j+1]);
		Harga(T->buffer[j]) = Harga(T->buffer[j+1]);
		}
		Neff(*T)--; 
	}
}
/* Menghapus suatu pesanan ke dalam Tab */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi_pesanan(Tab T){
	printf(" Daftar Pesanan\n");
	printf(" Makanan | Durasi memasak | Ketahanan | Harga\n");
	printf("-------------------------------------------------\n");
	if (!(IsEmpty_pesanan(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" ");
			PrintKata(Label(*T.buffer[i]));
			printf("      | %d              | %d         | %d\n", Durasi(T.buffer[i]), Ketahanan(T.buffer[i]), Harga(T.buffer[i]));
		}
	}
	else{
		printf("         |                |           |  \n"); 
	}
}

int Label_int(Pesanan P){
    return WordToInt((GetLabel(Label(*P)))); 
}
//MENGAMBIL NILAI INT LABEL

void enqueue_cook (Tab *T, Pesanan val){
	int i=0;
	boolean found=false;
	if(IsEmpty_pesanan(*T)){
		Insert_pesanan(T, Label_int(val), Durasi(val), Ketahanan(val), Harga(val));
	}
	else{
		while((!found) && (i < Neff(*T))){
			if (Label_int(T->buffer[i]) > Label_int(val)){
				found=true;
			}
			else{
				i++;
			}
		}
		for (int j=Neff(*T);j>i;j--){
			Move(Label(T->buffer[j]), Label(*T->buffer[j-1]));
			Durasi(T->buffer[j]) = Durasi(T->buffer[j-1]);
			Ketahanan(T->buffer[j]) = Ketahanan(T->buffer[j-1]);
			Harga(T->buffer[j]) = Harga(T->buffer[j-1]);
		}

		Move(Label(T->buffer[i]), Label(*val));
		Durasi(T->buffer[i]) = Durasi(val);
		Ketahanan(T->buffer[i]) = Ketahanan(val);
		Harga(T->buffer[i]) = Harga(val);
		Neff(*T)++;
	}
}

void dequeue_cook (Tab *T, Pesanan *val){
	boolean found=false;
	Move(val->label, Label(*T->buffer[0]));
	val->durasi = Durasi(T->buffer[0]);
	val->ketahanan = Ketahanan(T->buffer[0]);
	val->harga = Harga(T->buffer[0]);
	for (int i=0;i<Neff(*T)-1;i++){
		Move(Label(T->buffer[i]), Label(*T->buffer[i+1]));
		Durasi(T->buffer[i]) = Durasi(T->buffer[i+1]);
		Ketahanan(T->buffer[i]) = Ketahanan(T->buffer[i+1]);
		Harga(T->buffer[i]) = Harga(T->buffer[i+1]);
	}
	Neff(*T)--; 
}
/*Menghapus elemen pertama ke dalam Tab*/

void TulisIsi_Cook(Tab T){
	printf(" Daftar Makanan yang sedang dimasak\n");
	printf(" Makanan | Sisa durasi memasak\n");
	printf("--------------------------------\n");
	if (!(IsEmpty_pesanan(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" ");
			PrintKata(Label(*T.buffer[i]));
			printf("      | %d\n", Durasi(T.buffer[i]));
		}
	}
	else{
		printf("         |\n"); 
	}
}
/*Menulis CookTab*/

void TulisIsi_Served(Tab T){
	printf(" Daftar Makanan yang dapat disajikan\n");
	printf(" Makanan | Sisa ketahanan makanan\n");
	printf("--------------------------------\n");
	if (!(IsEmpty_pesanan(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" ");
			PrintKata(Label(*T.buffer[i]));
			printf("      | %d\n", Ketahanan(T.buffer[i]));
		}
	}
	else{
		printf("         |\n"); 
	}
}
/*menuliskan label dan ketahanan makanan*/

void UpdateCook_Tab(Tab *T){
	for (int i=0; i<Neff(*T);i++){
		Durasi(T->buffer[i])--;
	}
}
/*Update seluruh anggota Tab*/

void UpdateServed_Tab(Tab *T){
	for (int i=0; i<Neff(*T);i++){
		Ketahanan(T->buffer[i])--;
	}
}
/*Update seluruh anggota Tab*/

boolean isMember_cook(Tab T, int label){
	boolean found = false;
	int i=0;
	while ((i < Neff(T)) && (!found)){
		if (Label_int(T.buffer[i]) == label){
			found = true; 
		}
		else{
			i++;
		}
	}
	return found;
}

boolean isCook(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "COOK");
}

boolean isServe(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "SERVE");
}

boolean isSkip(Word Kata){
	return isWordEqual(Kata, "SKIP");	
}

void buat_pesanan(Tab *T, int label){
	Insert_pesanan(T, label, GenRand(1,5,5), (GenRand(1,5,5) % 5) + 1, GenRand(10,50,50) * 1000);
}

void Dinner_Dash(int *saldo){
	*saldo = 0;
	boolean play = true;
	char command[8];
	int order_ctr=3, cook_ctr=0, served_ctr=0, made_ctr=2; 
	Tab Orders, Cook, Served, Data;
	Pesanan temp; 
	boolean valid=false; 
	MakeEmpty_pesanan(&Orders);
	MakeEmpty_pesanan(&Cook);
	MakeEmpty_pesanan(&Served);
	MakeEmpty_pesanan(&Data);

	for (int i = 0;i<3;i++){
		delay(700);
		buat_pesanan(&Orders, i);
		Insert_pesanan(&Data, i, Durasi(Orders.buffer[i]), Ketahanan(Orders.buffer[i]), Harga(Orders.buffer[i]));
	}

	printf("\n");
	printf(" ===================== Selamat Datang di ... =====================\n");
	printf("  ____  _____ _____ _____ _____    ____  _____ _____ _____ \n");
	printf(" |    \\|     |   | |   __| __  |  |    \\|  _  |   __|  |  |\n");
	printf(" |  |  |-   -| | | |   __|    -|  |  |  |     |__   |     |\n");
	printf(" |____/|_____|_|___|_____|__|__|  |____/|__|__|_____|__|__|\n\n");
	printf(" ==================================================================\n\n");
	while (play){

		printf(" saldo : %d\n\n", *saldo);

		TulisIsi_pesanan(Orders);

		printf("\n\n");
		
		TulisIsi_Cook(Cook);
		printf("\n\n");

		TulisIsi_Served(Served);
		printf("\n\n");

		valid=false; 
		//VALIDASI INPUT
		while (!valid){
			printf(" MASUKKAN COMMAND: ");
			STARTFILE();
			if (((isCook(currentWord) || isServe(currentWord)) && GetKataSecond(currentWord).TabWord[0] == 'M') || (isSkip(currentWord))){
				if (isCook(currentWord)){
					if (made_ctr >= CommandInt(currentWord)){
						if (cook_ctr < 5){
							valid=true;
						}
						else{
							printf("Jumlah Maksimal Yang dapat dimasak adalah 5 Pesanan!\n");
						}
					}
					else{
						printf(" Belum ada yang memesan M%d!\n", CommandInt(currentWord));
					}
				}
				else if(isServe(currentWord)){
					if (isMember_cook(Served, CommandInt(currentWord))){
						if (served_ctr >= CommandInt(currentWord)){
							valid=true;
						}
						else{
							printf(" Pesanan M%d belum dapat disajikan karena antrian sebelumnya belum disajikan!\n", CommandInt(currentWord));
						}
					}
					else{
						printf(" Pesanan M%d belum selesai dimasak!\n", CommandInt(currentWord));
					}
				}
				else{
					valid=true; 
				}
			}
			else{
				printf(" UH OH, INPUT TIDAK VALID !\n");
			}
		}

		//UPDATE TABLE
		UpdateCook_Tab(&Cook);
		UpdateServed_Tab(&Served);
		int ctr = 0;
		while ((ctr < Neff(Cook)) && !(IsEmpty_pesanan(Cook))){
			// printf("CEK M%d = %d\n", Label_int(Cook.buffer[ctr]), (Durasi(Cook.buffer[ctr]))); //-> CHECKER
			if (Durasi(Cook.buffer[ctr]) < 1){
				Delete_pesanan(&Cook, Label_int(Cook.buffer[ctr]), &temp);
				enqueue_cook(&Served, temp);
				cook_ctr--;
			}
			else{
				ctr++;
			}
		}

		//ALGORITMA UTAMA
		if (isCook(currentWord)) {
			order_ctr--;
			Delete_pesanan(&Orders, CommandInt(currentWord), &temp);
			temp = Data.buffer[CommandInt(currentWord)];
			enqueue_cook(&Cook, temp);
			cook_ctr++; 
			printf(" Berhasil Memasak M%d\n", CommandInt(currentWord));
		}

		else if(isServe(currentWord)){
			dequeue_cook(&Served, &temp);
			*saldo += Harga(temp);
			served_ctr++;
			printf(" Berhasil Menyajikan M%d\n", CommandInt(currentWord));
		}

		//UPDATE PESANAN
		made_ctr++;
		buat_pesanan(&Orders, made_ctr);
		order_ctr++; 
		Insert_pesanan(&Data, made_ctr, Durasi(Orders.buffer[Neff(Orders)-1]), Ketahanan(Orders.buffer[Neff(Orders)-1]), Harga(Orders.buffer[Neff(Orders)-1]));

		for (int i=0; i < Neff(Served);i++){
			if (Ketahanan(Served.buffer[i]) == 0){
				printf(" PESANAN M%d HANGUS! PESANAN HARUS DIMASAK ULANG!\n", Label_int(Served.buffer[i]));
				temp = Data.buffer[Label_int(Served.buffer[i])];
				enqueue_cook(&Orders, temp);
				Delete_pesanan(&Served, Label_int(Served.buffer[i]), &temp);
				order_ctr++;
			}
		}



		printf("\n =====================================================\n");
		if (served_ctr == 15 || order_ctr > 7){
			play=false;
		}
	}
	printf("  _____ _____ _____ _____    _____ _____ _____ _____ \n");
	printf(" |   __|  _  |     |   __|  |     |  |  |   __| __  |\n");
	printf(" |  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n");
	printf(" |_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n");
	printf(" SCORE AKHIR : %d\n", *saldo);         
	printf(" Served Meals : %d\n", served_ctr);                                                       
}