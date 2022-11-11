#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quit(){
    printf("Terima kasih telah memainkam game BNMO ini!\n");
    printf("Good Game, Well Played\n");
    delay(2000);
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
    loadGAME("config", listGame);
}

void loadGAME(char* filename, TabGame *listGame)
{
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

    startLOAD(path);
    if (fptr == NULL){
        listGame->Neff = -1;
        printf("file tidak ditemukan!\n");
    }
    else {
        ADVWORDLOAD();
        int countGame = wordtoInt(currentWord);

        ADVLOAD();
        char* title;
        int i;
        for ( i = IdxMin; i <= countGame; i++)
        {
            ADVWORDLOAD();
            SetEl(listGame, i, currentWord);
        }
        listGame->Neff = countGame;
        printf("Loading");
        delay(250); printf(".");
        delay(250); printf(".");
        delay(250); printf(".\n");
        printf("File konfigurasi BNMO berhasil dibaca. GLHF!!\n");      
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
        int i;
        for (i = IdxMin; i <= listGame.Neff-1; i++)
        {
            char *title = wordToString(listGame.TI[i]);
            fprintf(fptr, "%s\n", title);
        }
        char *title = wordToString(listGame.TI[i]);
        fprintf(fptr, "%s", title);
        fclose(fptr);
        printf("Berhasil melakukan save\n");
    }
}