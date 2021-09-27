#include <stdio.h>
#define FILE_NAME "HelloWorld.dat"

typedef struct {
    char id[31];
    char description[101];
    float price;
    short stock;
}Product;

int createFile(const char* fileName) {
    FILE *arch = fopen(fileName, "wb"); // r+b = r(read) +(write too) b(binary file)
    if (!arch) /// if (arch == NULL)
        return 1;
    Product product[6] =
    {
            {"pera", "Pera", 35.98, 23},
            {"manza", "Manzana", 32.03, 98},
            {"banana", "Banana", 43.98, 42},
            {"kiwi", "Kiwi", 45.21, 87},
            {"naranja", "Naranja", 98.99, 32},
            {"melon", "Melon", 321.32, 45}
    };
    fwrite(product, sizeof(product), 1, arch);
    fclose(arch);
    return 0;
}

void printProduct(const Product *product) {
    printf("[ID: %s, Description: %s, Price: %.2f, Stock: %d]\n", product->id, product->description, product->price, product->stock);
}

int showFile(const char* fileName) {
    FILE *arch = fopen(fileName, "rb");
    if (!arch) return 1;
    Product product;
    fread(&product, sizeof(Product), 1, arch);
    while(!feof(arch)) {
        printProduct(&product);
        fread(&product, sizeof(Product), 1, arch);
    }
    fclose(arch);
    return 0;
}

int increasePricesByInflationFILE(const char* fileName, float percentInflation) {
    FILE *arch = fopen(fileName, "r+b");
    if (!arch) return 1;
    Product product;
    fread(&product, sizeof(Product), 1, arch);
    while(!feof(arch)){
        product.price *= percentInflation;
        fseek(arch, -sizeof(Product), SEEK_CUR);
        fwrite(&product, sizeof(Product), 1, arch);
        // We use fseek to move the pointer of the file
        fread(&product, sizeof(Product), 1, arch);
    }
    fclose(arch);
    return 0;
}


int main() {
    int res = createFile(FILE_NAME);
    if (res == 1) {
        printf("The file wasn't create correctly.\n");
        return 1;
    }
    printf("Before Inflation:\n");
    res = showFile(FILE_NAME);
    if (res == 1) {
        printf("The file wasn't read correctly.\n");
        return 1;
    }
    res = increasePricesByInflationFILE(FILE_NAME, 1.1);
    if (res == 1) {
        printf("The file wasn't read correctly.\n");
        return 1;
    }
    printf("After Inflation:\n");
    res = showFile(FILE_NAME);
    if (res == 1) {
        printf("The file wasn't read correctly.\n");
        return 1;
    }

    return 0;
}