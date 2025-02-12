// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_HALT.cc: Implementación de Instruccion_HALT
//        En este fichero se implementa las funciones de la clase Instruccion_HALT
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_HALT.h"

/**
 * @brief Constructor de la clase Instruccion_HALT
 * @param registros Conjunto de registros
 * @param cinta_escritura Cinta de escritura
 * @return Crea el objeto Instruccion_HALT
 */

Instruccion_HALT::Instruccion_HALT(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "HALT";
}

/**
 * @brief Método para ejecutar la instrucción HALT
 * @details Escribe en la cinta de escritura el registro que se le pasa
 * @return -2  Int para parar el programa 
*/

int Instruccion_HALT::ejecutar() {
  return -2; // -2 para parar el programa
}
