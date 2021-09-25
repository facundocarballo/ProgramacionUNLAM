#include "./cadena.h"

int digitCount(int i) {
    int digit = 1;
    while (i >= 10) {
        digit++;
        i /= 10;
    }
    return digit;
}

Cadena::Cadena() {
    this->cad = new char[1];
    this->cad = '\0';
}

Cadena::Cadena(const char *cad) {
    this->cad = new char[strlen(cad) + 1];
    strcpy(this->cad, cad);
}

Cadena::Cadena(char *cad) {
    this->cad = cad;
}

Cadena::Cadena(char c) {
    this->cad = new char[2];
    this->cad[0] = c;
    this->cad[1] = '\0';
}

Cadena::Cadena(int i) {
    this->cad = new char[digitCount(i) + 1];
    sprintf(this->cad, "%d", i);
}

Cadena::~Cadena() {
    delete [] this->cad;
}

Cadena operator+(const Cadena &cad1, const Cadena &cad2)
{
    char *newCad = new char[strlen(cad1.cad) + strlen(cad2.cad) + 1];
    strcpy(newCad, cad1.cad);
    strcat(newCad, cad2.cad);
    Cadena cadenaConcat = Cadena(newCad);
    return cadenaConcat;
}

ostream &operator<<(ostream &salida, const Cadena &cadena)
{
    // This function is needed to print 'Cadena'.
    return salida << cadena.cad;
}