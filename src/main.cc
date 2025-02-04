// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo main.cc: Implementación del programa cliente
//        En este fichero se implementa la función del main
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include<iostream>

int main(int argc, char *argv[]) {
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    std::cerr << "Error no se han introducido los datos correctamente" << std::endl;
    return 1;
  }

  return 0;
}