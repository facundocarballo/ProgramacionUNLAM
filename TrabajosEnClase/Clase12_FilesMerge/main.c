#include <stdio.h>
#include <string.h>

#define ERR_FILE 1
#define WRITE_FILE "writeFile.dat"

typedef struct
{
    char id[31];
    char description[101];
    float price;
    short stock;
} Product;



/// If the file name is correct, will return 0 otherwise 1.
int checkFileName(char *fileName) {
    if ((strcmp(fileName, "") == 0) || (strstr(fileName, ".") != NULL))
        return 1;
    else
        return 0;
}


void writeProductOfActualFile(Product *product, FILE* writeFile, FILE* actualFile) {
    fwrite(product, sizeof(Product), 1, writeFile);
    fread(product, sizeof(Product), 1, actualFile);
}

void writeProductOfUpdateFile(Product *newProduct, Product* updateProduct, FILE* writeFile, FILE* updateFile) {
    newProduct = updateProduct;
    fread(updateProduct, sizeof(Product), 1, updateFile);
    while (!feof(updateFile) && (strcmp(newProduct->id, updateProduct->id) == 0))
    {
        newProduct->stock += updateProduct->stock;
        fread(updateProduct, sizeof(Product), 1, updateFile);
    }
    fwrite(newProduct, sizeof(Product), 1, writeFile);
}

void getFilesNames(char* actualFile, char* updateFile) {
    puts("\nPlease, now you have to deliver us the file names without the extensions.");
    puts("For example: If the file is: 'product.dat' you have to write just 'product'.\n\n");
    char condition = 1;
    while(condition) {
        printf("Actual File: ");
        fflush(stdin);
        scanf("%s", actualFile);
        printf("Update file: ");
        fflush(stdin);
        scanf("%s", updateFile);
        
        if (checkFileName(actualFile) || checkFileName(updateFile))
            puts("Please enter a valid file name.");
        else{
            strcat(actualFile, ".dat");
            strcat(updateFile, ".dat");
            condition = 0;
        }
        

        
    }
}

char update(const char* actualFile, const char* updateFile) {
    FILE* fActualFile = fopen(actualFile, "rb");
    FILE* fUpdateFile = fopen(updateFile, "rb");
    FILE* fWriteFile  = fopen(WRITE_FILE, "wb");

    if ( !fActualFile || !fWriteFile || !fUpdateFile ) {
        fclose(fActualFile);
        fclose(fWriteFile);
        fclose(fUpdateFile);
        return ERR_FILE;
    }

    Product product, updateProduct, newProduct;
    char comp;

    fread(&product, sizeof(Product), 1, fActualFile);
    fread(&updateProduct, sizeof(Product), 1, fUpdateFile);

    while(!feof(fActualFile) && !feof(fUpdateFile)){
        // Runs until one of the files come to the end.
        comp = strcmp(product.id, updateProduct.id);
        if (comp == 0) {
            product.stock += updateProduct.stock;
            fread(&updateProduct, sizeof(Product), 1, fUpdateFile);
        }
        if (comp < 0)
            writeProductOfActualFile(&product, fWriteFile, fActualFile);
        // Like the fActualFile is ordered
        // shows that the updateProduct has to be written in the future, but not now.
            
        
        if (comp > 0)
            writeProductOfUpdateFile(&newProduct, &updateProduct, fWriteFile, fUpdateFile);
        // The updateProduct has to be written NOW
            
    }

    // If one of the files wasn't read it all, we will continue reading the file here.

    while (!feof(fActualFile)) 
        writeProductOfActualFile(&product, fWriteFile, fActualFile);
    
    while (!feof(fUpdateFile)) 
        writeProductOfUpdateFile(&newProduct, &updateProduct, fWriteFile, fUpdateFile);
    

    fclose(fActualFile);
    fclose(fUpdateFile);
    fclose(fWriteFile);

    remove(actualFile);
    rename(WRITE_FILE, actualFile); // Update the writeFile with the name of the original file.

    return 0;
}

int main() {
    puts("\nWELCOME TO FILE UPDATER!");
    char actualFile[50], updateFile[50];
    getFilesNames(actualFile, updateFile);
    char res = update(actualFile, updateFile);
    if (res == ERR_FILE) {
        puts("\nOne of the files couldn't be read.");
        return ERR_FILE;
    }
    puts("\nThe file was successfully updated.");
    return 0;
}