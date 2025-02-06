// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo Lectura.h : Declaración de la clase Lectura
//        En este fichero se declara la clase Lectura
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_Lectura_H
#define C_Lectura_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<int> fichero_to_vector(string fichero);

/** Clase Lectura
  * @brief Clase que se encarga de leer los elementos de entrada.
  */
class Lectura {
 public:
  Lectura(vector<int> fichero_de_lectura);
  int leer();
  friend ostream& operator<<(ostream& os, const Lectura& lectura);
 private:
  vector<int> fichero_de_lectura_;
  int pos_lectura_ = 0;
};


#endif