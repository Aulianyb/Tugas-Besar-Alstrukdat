#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quit()
{
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

void startGAME(TabGame *listGame, StackHistory *SH, TabScore *TS){
    loadGAME("config", listGame, SH, TS);
}

void loadGAME(char* filename, TabGame *listGame, StackHistory *SH, TabScore *TS)
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

        // Membaca history
        StackHistory temp; CreateEmptyHistory(&temp);
        ADVWORDLOAD();
        int countHistory = wordtoInt(currentWord);
        for (i = 0; i < countHistory; i++){
            ADVWORDLOAD();
            PushHistory(&temp, currentWord);
        }

        SwapStackHistory(temp, SH);

        ADVWORDLOAD();
        
        Map map_temp;
        for (i = IdxMin; i <= countGame; i++)     
        {
            int countScore = wordtoInt(currentWord);
            // printf("%d\n", countScore);
            // Word title = listGame->TI[i]; printf("print game nani: ");
            // PrintKata(title); printf("\n");
            if (countScore == 0)
            {
                ADVLOAD();
                ADVWORDLOAD();
                CreateEmptyMap(&map_temp);
                // printf("Game sekarang: ");
                // Word title = listGame->TI[i];
                // PrintKata(title); printf("\n");
                // printf("skip\n");
            } else {
                CreateEmptyMap(&map_temp);
                //Word title = listGame->TI[i];
                //printf("Game sekarang: ");
                // PrintKata(title);
                // printf("\n");
                
                ADVLOAD();
                for (int j = 0; j < countScore; j++)
                {
                    ADVWORDLOAD();
                    InsertMap(&map_temp, GetKataFirst(currentWord), WordToInt(GetKataSecond(currentWord)));

                    // printf("Isi seharusnya: \n");
                    // PrintKata(GetKataFirst(currentWord)); printf(" ");
                    // PrintKata(GetKataSecond(currentWord)); printf("\n");

                    // printf("Isi map: \n");
                    // PrintKata(map_temp.Elements[j].user);
                    // printf(" %d", map_temp.Elements[j].score);
                    // printf("\n");
                }
                
                ADVWORDLOAD();
            }

            SetElTabScore(TS, i, map_temp);

            // printf("Game sekarang: ");
            // PrintKata(TS->TI[i].GameTitle);
            // printf("\n");

            // for (int j = 0; j < TS->TI[i].Count; j++)
            // {
            //     PrintKata(TS->TI[i].Elements[j].user);
            //     printf(" %d\n", TS->TI[i].Elements[j].score);
            // // }
            // printf("\nCheck game end\n");
        }

        printf("Loading");
        delay(250); printf(".");
        delay(250); printf(".");
        delay(250); printf(".\n");
        printf("File konfigurasi BNMO berhasil dibaca. GLHF!!\n\n");      
    }

}

void saveGAME(char* filename, TabGame listGame, StackHistory SH, TabScore TS)
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

    fptr = fopen(path, "w");

    if (fptr == NULL){
        printf("Tidak berhasil menyimpan file!");
    }
    else
    {
        fprintf(fptr, "%d\n", listGame.Neff);
        int i, j;
        for (i = IdxMin; i <= listGame.Neff-1; i++)
        {
            char *title = wordToString(listGame.TI[i]);
            fprintf(fptr, "%s\n", title);
        }
        char *title = wordToString(listGame.TI[i]);
        fprintf(fptr, "%s\n", title);

        StackHistory temp; CreateEmptyHistory(&temp);
        SwapStackHistory(SH, &temp);
        fprintf(fptr, "%d\n", Top(temp)+1);
        for (i = 0; i < Top(temp); i++){
            char *titlehistory = wordToString(temp.T[i]);
            fprintf(fptr, "%s\n", titlehistory);
        }
        char *titlehistory = wordToString(temp.T[Top(temp)]);
        fprintf(fptr, "%s\n", titlehistory);

        // penulisan scoreboard
        for (i = IdxMin; i <= listGame.Neff-1;i++){
            fprintf(fptr, "%d\n", TS.TI[i].Count);
            for (j = 0; j < TS.TI[i].Count; j++){
                char* name = wordToString(TS.TI[i].Elements[j].user);
                fprintf(fptr, "%s %d\n", name, TS.TI[i].Elements[j].score);
            }
        }
        j = 0;
        fprintf(fptr, "%d", TS.TI[i].Count);
        if (TS.TI[i].Count != 0) fprintf(fptr, "\n");
        while(j < TS.TI[i].Count){
            char* name = wordToString(TS.TI[i].Elements[j].user);
            fprintf(fptr, "%s %d", name, TS.TI[i].Elements[j].score);
            j++;
        }

        fclose(fptr);
        printf("Berhasil melakukan save\n");
    }
}