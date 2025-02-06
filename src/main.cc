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


using namespace std;

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
    MemoriaPrograma* programa = new MemoriaPrograma(fichero_to_line(datos.ficheroPrograma));
    // Inicializo la unidad de 
    UDC.Inicializar(registros, programa, cinta_lectura, cinta_escritura);
    //Ejecuto la máquina
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return 1;
  }

  UDC.EjecutarInstruccion("LOAD", "10");
  UDC.EjecutarInstruccion("STORE", "5");
  UDC.EjecutarInstruccion("ADD", "5");
  UDC.EjecutarInstruccion("SUB", "5");
  UDC.EjecutarInstruccion("MUL", "5");
  UDC.EjecutarInstruccion("DIV", "5");
  UDC.EjecutarInstruccion("READ", "5");
  UDC.EjecutarInstruccion("READ", "7");
  UDC.EjecutarInstruccion("WRITE", "5");
  UDC.EjecutarInstruccion("JUMP", "fin:");
  UDC.EjecutarInstruccion("JGTZ", "fin:");
  UDC.EjecutarInstruccion("LOAD", "0");
  UDC.EjecutarInstruccion("JZERO", "fin:");

  
  cout << UDC << endl;




  return 0;
}