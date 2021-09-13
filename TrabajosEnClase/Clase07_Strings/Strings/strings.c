#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

int stringLength(const char *string) {
    char *theString = (char *) string;
    int length = 0;

    while (*theString)
    {
        theString++;
        length++;
    }
        
    
    return length;

}

int isTheSameString(const char *string, const char *subString, const char *firstChar, const char *lastChar, int length) {
    return 
    (
        (length == stringLength(subString))
        && (*firstChar == string[0] || *(firstChar - 1) == ' ')
        && (!*lastChar || *lastChar == ' ')
    );
}

char* findString(const char *string, const char *subString) {
    char *i = (char*)string;
    char *j = (char*)subString;
    while (*i) {
        // While *i != '\0'
        while ((*i) && (*i != *j))
            i++;
        
        if (!*i) return NULL; // *i == '\0'

        // If we are here, that means a match
        char *indexI = i;
        char *indexJ = j;
        int length = 0;
        while ((*indexI) && (*indexI == *indexJ))
        {
            indexI++;
            indexJ++;
            length++;
        }

        if (isTheSameString(string, subString, i, indexI, length)) 
            return i;

        i++;
    }
    return NULL;
}

void removeChar(char *string, int i) {
    int length = stringLength(string);
    // h(ola
    // length = 5
    // for (i < 4)
    // i = 1 : ho(la
    // i = 2 : hol(a
    // i = 3 : hola(
    for (i; i < (length - 1); i++) {
        char aux = string[i];
        string[i] = string[i + 1];
        string[i + 1] = aux;
    }
    string[i] = '\0';
}

void formatterString(char *string) {
    int length = stringLength(string);
    int charRemove = 0;
    int i = 0;
    while (i < length) {
        // While string != '\0'
        charRemove = 0;
        if (! ((string[i] == 0) || (string[i] == 32) || ((string[i] >= 65) && (string[i] <= 90)) || ((string[i] >= 97) && (string[i] <= 122)) ) )
        {
            removeChar(string, i);
            charRemove = 1;
        }

        if ((i == 0) || (string[i - 1] == ' '))
            string[i] = toupper(string[i]);

        if ((i != 0) && (string[i - 1] != ' '))
            string[i] = tolower(string[i]);

        if (charRemove == 0)
            i++;
    }
}