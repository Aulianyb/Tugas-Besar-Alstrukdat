#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void quit(){
    printf("Terima kasih telah memainkam game BNMO ini!\n");
    printf("Good Game, Well Played\n");
    exit(0);
}

void startLOAD(char* filename)
{
    fptr = fopen(filename, "r");
    ADVLOAD();
}

void IgnoreFILEMARK()
{
    while (currentChar == FILEMARK){
        ADVLOAD();
    }
}

void ADVWORDLOAD()
{
    IgnoreFILEMARK();
    if (retval < 0) EndWord = true;
    else CopyWORDLOAD();
}

void CopyWORDLOAD()
{
    int i = 0;
    while ((currentChar != FILEMARK) && i < NMax && !EOP) {
        currentWord.TabWord[i] = currentChar; 
        ADVLOAD();
        i++;
    }
    currentWord.Length = i;
}

void ADVLOAD()
{
	retval = fscanf(fptr, "%c", &currentChar);
	EOP = (retval < 0);
	if (EOP) {
        fclose(fptr);
 	}
}

char* wordToString(Word word)
{
  char *str = (char *)malloc(sizeof(char) * word.Length);
  int i;
  for (i = 0; i < word.Length; i++)
  {
    str[i] = word.TabWord[i];
  }
  str[i] = '\0';
  return str;
}

int wordtoInt(Word word)
{
  int result = 0;
  for (int i = 0; i < word.Length; i++){
      result = result*10 + (word.TabWord[i] - '0');
      i++;
  }
  return result;
}

void startGAME(TabGame *listGame){
    loadGAME("data/config.txt", listGame);
    printf("File konfigurasi BNMO berhasil dibaca. GLHF!!\n");
}

void loadGAME(char* filename, TabGame *listGame)
{
    startLOAD(filename);
    if (fptr == NULL) printf("file tidak ditemukan!\n");
    else {
        ADVWORDLOAD();
        int countGame = wordtoInt(currentWord);

        ADVLOAD();
        char* title;
        int i;
        for ( i = IdxMin; i <= countGame; i++)
        {
            ADVWORDLOAD();
            title = wordToString(currentWord);
            SetEl(listGame, i, title);
        }
        listGame->Neff = countGame;
        fclose(fptr);        
    }

}

void saveGAME(char* filename, TabGame listGame){
    char path[100] = "data/";
    int i = 5;
    while (*filename != '\0')
    {
        path[i] = *filename;
        i++;
        *filename++;
    }
    path[i] = '.'; i++;
    path[i] = 't'; i++;
    path[i] = 'x'; i++;
    path[i] = 't'; i++;

    fptr = fopen(path, "w");

    if (fptr == NULL){
        printf("Tidak berhasil menyimpan file!");
    }
    else
    {
        fprintf(fptr, "%d\n", listGame.Neff);
        for (int i = IdxMin; i <= listGame.Neff-1; i++)
        {
            fprintf(fptr, "%s\n", listGame.TI[i]);   
        }
        fprintf(fptr, "%s", listGame.TI[listGame.Neff]);
        fclose(fptr);
        printf("Berhasil melakukan save\n");
    }
}