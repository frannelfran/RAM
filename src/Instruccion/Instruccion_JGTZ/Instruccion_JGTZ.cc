// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_JGTZ.cc: Implementación de Instruccion_JGTZ
//        En este fichero se implementa las funciones de la clase Instruccion_JGTZ
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_JGTZ.h"

/**
 * @brief Constructor de la clase Instruccion_JGTZ
 * @param registros Conjunto de registros
 * @param etiquetas Conjunto de etiquetas
 * @return Crea el objeto Instruccion_JGTZ
*/

Instruccion_JGTZ::Instruccion_JGTZ(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "JGTZ";
}

/**
 * @brief Método para ejecutar la instrucción JGTZ
 * @details Salta a la etiqueta si el registro RO es mayor que 0
 * @return -1 
*/

int Instruccion_JGTZ::ejecutar() {
  int pos = std::stoi(operando_);
  if (registros_->GetDato(0) > 0) {
    return pos;
  }
  return -1;
}
