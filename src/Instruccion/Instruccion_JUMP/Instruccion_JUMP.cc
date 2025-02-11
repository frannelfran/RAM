// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_JUMP.cc: Implementación de Instruccion_JUMP
//        En este fichero se implementa las funciones de la clase Instruccion_JUMP
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_JUMP.h"

/**
 * @brief Método para ejecutar la instrucción JUMP
 * @details Salta a la etiqueta
 * @param operando Etiqueta a la que saltar
 * @return -1 
*/

int Instruccion_JUMP::ejecutar(const string& operando) {
  auto posicion = etiquetas_.find(operando);
  if (posicion == etiquetas_.end()) {
    throw invalid_argument("Error: No se ha encontrado la etiqueta: " + operando);
  }
  return posicion->second;
}
