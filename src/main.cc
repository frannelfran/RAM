// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo main.cc: Implementación del programa cliente
//        En este fichero se implementa la función del main
//
// Usage: ./Máquina_RAM data/entrada.txt data/salida.txt data/test2.ram 
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include"Lectura/Lectura.h"
#include"UnidadDeControl/UnidadDeControl.h"
#include"MemoriaPrograma/MemoriaPrograma.h"
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<regex>

using namespace std;

// void test(UnidadDeControl &UDC) {
//   UDC.EjecutarInstruccion("LOAD", "=5");
//   cout << UDC << endl;
//   UDC.EjecutarInstruccion("STORE", "10");
//   //.EjecutarInstruccion("STORE", "=11");
//   cout << UDC << endl;
//   UDC.EjecutarInstruccion("STORE", "5");
//   UDC.EjecutarInstruccion("LOAD", "=20");
//   UDC.EjecutarInstruccion("STORE", "*5");
// 
//   
//   cout << UDC << endl;
// 
// }

int main(int argc, char *argv[]) {
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    //std::cerr << "Error no se han introducido los datos correctamente" << std::endl;  // lo he comentado porque ya en la función recoger_parametro se imprime el error
    return 1;
  }

  UnidadDeControl UDC;

  try {

    // Inicializo la cinta de lectura
    Lectura* cinta_lectura = new Lectura(fichero_to_vector(datos.ficheroEntrada));
    // Inicializo la cinta de escritura
    Escritura* cinta_escritura = new Escritura(datos.ficheroSalida);
    // Inicializo la memoria de datos
    MemoriaDatos* registros = new MemoriaDatos();
    // Inicializo la memoria de programa
    MemoriaPrograma* programa = new MemoriaPrograma(datos.ficheroPrograma);
    // Inicializo la unidad de control
    UDC.Inicializar(registros, programa, cinta_lectura, cinta_escritura);
  } catch (const exception& e) {
    cerr << "Error inicializando el programa: " << e.what() << endl;
    return 1;
  }

  try {
    //Ejecuto el programa
    UDC.EjecutarPrograma();
  } catch (const exception& e) {
    cerr << "Error en la ejecución del programa: " << e.what() << endl;
    return 1;
  }
  return 0;
}
