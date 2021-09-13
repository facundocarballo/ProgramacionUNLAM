#include <stdio.h>
#include <stdlib.h>
#include "./Strings/strings.c"

int main() {
    char string[] = "Hola Facu Facundo como estas";
    char subString[50];
    printf("Enter a word that you want to find in the text: ");
    scanf("%s", subString);
    fflush(stdin);

    printf("String: %s\n", string);
    printf("SubString: %s\n", subString);
    char* finded = findString(string, subString);

    if (finded == NULL)
        printf("The subString doesn't exist.\n");
    else
        printf("The subString exists.\n");

    char unFormattedString[] = "hoLA {}*(&) toDO BieN";
    formatterString(unFormattedString);

    return 0;
}