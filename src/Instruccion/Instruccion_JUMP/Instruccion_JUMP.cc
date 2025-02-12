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
 * @brief Constructor de la clase Instruccion_JUMP
 * @param registros Conjunto de registros
 * @param etiquetas Conjunto de etiquetas
 * @return Crea el objeto Instruccion_JUMP
*/

Instruccion_JUMP::Instruccion_JUMP(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "JUMP";
}

/**
 * @brief Método para ejecutar la instrucción JUMP
 * @details Salta a la etiqueta
 * @return -1 
*/

int Instruccion_JUMP::ejecutar() {
  return stoi(operando_);
}
