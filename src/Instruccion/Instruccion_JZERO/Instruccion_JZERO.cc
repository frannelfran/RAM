// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_JZERO.cc: Implementación de Instruccion_JZERO
//        En este fichero se implementa las funciones de la clase Instruccion_JZERO
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_JZERO.h"

/**
 * @brief Constructor de la clase Instruccion_JZERO
 * @param registros Conjunto de registros
 * @param etiquetas Mapa de etiquetas
 * @return Crea el objeto Instruccion_JZERO
 */

Instruccion_JZERO::Instruccion_JZERO(MemoriaDatos* registros, map<string, int> etiquetas) : Instruccion(registros) {
  instruccion_ = "JZERO";
  etiquetas_ = etiquetas;
}

/**
 * @brief Método para ejecutar la instrucción JZERO
 * @details Salta a la etiqueta si el registro RO es igual a 0
 * @param operando Etiqueta a la que saltar
 * @return -1
*/ 

int Instruccion_JZERO::ejecutar(const string& operando) {
  if (registros_->GetDato(0) == 0) {
    auto posicion = etiquetas_.find(operando);
    if (posicion == etiquetas_.end()) {
      throw invalid_argument("Error: No se ha encontrado la etiqueta: " + operando);
    }
    return posicion->second;
  }
  return -1;
}
