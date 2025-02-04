// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo Escritura.cc: Implementación de Escritura
//        En este fichero se implementa las funciones de la clase Escritura
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"Escritura.h"

/**
 * @brief Función para volcar en el fichero de salida
 * @param file Fichero de salida
*/

void Escritura::VolcarEnFichero(ofstream& file) {
  // Recorro la cinta de escritura
  for (int digito : cinta_escritura) {
    file << digito;
  }
}