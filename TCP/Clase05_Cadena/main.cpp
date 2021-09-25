#include "./Cadena/cadena.cpp"
#include <iostream>
using namespace std;

int main()
{
    Cadena cadena1 = Cadena("JAJAJAJA");
    Cadena cadena2 = Cadena("Hola como estas?");
    Cadena newCadena = cadena2 + cadena1 + " HOLA AMIGOOOO " + 564;
    /*
        Now appears the operator function +
        In the first call, takes cadena2 and cadena1.
        In the second call, takes the return of the first call
        and the string literal that we pass ('HOLA AMIGOOOO').
        The compiler will try to convert all the data that we pass
        on Class Cadena. So the compiler will call Cadena(const char *cad)
        to construct a Cadena, and them with the return value of these constructor
        will call the operator function +.
        The same way for the last parameter, who is an integer.

        ----------------------------------------------------------------

        Aca se ejecuta la funcion (operator +) que toma como parametros dos Cadena
        La primera invocacion toma a la cadena2 y la cadena1
        La segunda invocacion toma al resultado que devolvio la primera invocacion
        y a la cadena formada por la cadena de texto escrita 'HOLA AMIGOOOO'.
        El compilador al ver que no esta recibiendo un dato del tipo Cadena, intentara
        crear uno con lo que sea que reciba como dato. Asi que en este caso, ejecutara 
        Cadena(const char *cad) pasandole como parametro la cadena 'HOLA AMIGOOOO' y a 
        ese dato de tipo cadena que obtenga lo tomara como parametro para la funcion 
        llamada con el operador +.
    */

    cout << newCadena << endl;
}