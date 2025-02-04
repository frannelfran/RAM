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
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include"Lectura/Lectura.h"
#include"UnidadDeControl/UnidadDeControl.h"
#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    //std::cerr << "Error no se han introducido los datos correctamente" << std::endl;  // lo he comentado porque ya en la función recoger_parametro se imprime el error
    return 1;
  }
  try {
    //Creo el objeto de la clase Lectura
    Lectura lectura(fichero_to_vector(datos.ficheroEntrada));
    //Creo el objeto de la clase Maquina
    //Ejecuto la máquina
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return 1;
  }

  return 0;
}