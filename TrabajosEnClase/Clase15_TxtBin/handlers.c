#include "handlers.h"
#include <stdio.h>
#include <string.h>

#define SIZE_OF_FAMILIAR 60

int createTXTFile(char* fn) {
    char fileName[50];
    strcpy(fileName, fn);
    strncat(fileName, ".txt", 4);

    FILE * fp;
    fp = fopen(fileName, "wt");

    fprintf(fp, "Facundo Nicolas Carballo|21|42774931|M\n");
    fprintf(fp, "Gonzalo Matias Carballo|17|46774931|M\n");
    fprintf(fp, "Maria Lucila Carballo|17|46774931|F\n");
    fprintf(fp, "Diego Damian Carballo|48|22774931|M\n");
    fprintf(fp, "Maria Andrea Sain|47|23774931|F\n");

    fclose(fp);
    return 1;
}

int createBINFile(char* fn) {
    char fileName[50];
    strcpy(fileName, fn);
    strncat(fileName, ".dat", 4);

    char info[]  = "Facundo Nicolas Carballo|21|42774931|M\n";
    char info2[] = "Gonzalo Matias Carballo|17|46774931|M\n";
    char info3[] = "Maria Lucila Carballo|17|46774931|F\n";
    char info4[] = "Maria Andrea Sain|47|23774931|F\n";
    char info5[] = "Diego Damian Carballo|48|22774931|M\n";

    FILE * fp;
    fp = fopen(fileName, "wb");

    fwrite(info, sizeof(info), 1, fp);
    fwrite(info2, sizeof(info2), 1, fp);
    fwrite(info3, sizeof(info3), 1, fp);
    fwrite(info4, sizeof(info4), 1, fp);
    fwrite(info5, sizeof(info5), 1, fp);
    
    fclose(fp);
    return 1;
}

char* findWordWithSeparator(const char* data, const char separator) {
    char i = 0;
    char word[50];
    while(data[i] != separator && (data[i] != '\n' || data[i] != '\0')) {
        word[i] = data[i];
        i++;
    }
    return &word;
}

int TxtTOBin(const char* fnTxt, const char* fnBin) {
    char fileNameTXT[50], fileNameBIN[50];
    strcpy(fileNameTXT, fnTxt);
    strcpy(fileNameBIN, fnBin);
    strncat(fileNameTXT, ".txt", 4);
    strncat(fileNameBIN, ".dat", 4);

    FILE * txtFilePointer = fopen(fileNameTXT, "rb");
    FILE * binFilePointer = fopen(fileNameBIN, "wb");
    char data[100];

    while(fgets(&data, SIZE_OF_FAMILIAR, txtFilePointer)) {
        Familiar familiar;
        sscanf(data, "%s|%d|%ld|%c", &familiar.name, &familiar.age, &familiar.id, &familiar.gender);
        fwrite(&familiar, sizeof(familiar), 1, binFilePointer);
    }

    fclose(binFilePointer);
    fclose(txtFilePointer);

    return 1;
}

int binToTXT(char* fnBin, char* fnTxt) {
    char fileNameTXT[50], fileNameBIN[50];
    strcpy(fileNameTXT, fnTxt);
    strcpy(fileNameBIN, fnBin);
    strncat(fileNameTXT, ".txt", 4);
    strncat(fileNameBIN, ".dat", 4);

    FILE *txtFilePointer = fopen(fileNameTXT, "wb");
    FILE *binFilePointer = fopen(fileNameBIN, "rb");

    Familiar familiar;
    fread(&familiar, sizeof(familiar), 1, binFilePointer);
    while(!feof(binFilePointer)) {
        fread(&familiar, sizeof(familiar), 1, binFilePointer);
        fprintf(txtFilePointer, "%s|%d|%ld|%c", &familiar.name, &familiar.age, &familiar.id, &familiar.gender);
    }

    fclose(binFilePointer);
    fclose(txtFilePointer);

    return 1;
    
}

