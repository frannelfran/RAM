// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo Escritura.h : Declaración de la clase Escritura
//        En este fichero se declara la clase Escritura
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_Escritura_H
#define C_Escritura_H
#include <vector>
#include <fstream>

using namespace std;

/**
 * @class Clase para representar el conjunto de escritura
*/

class Escritura {
 public:
  Escritura() {}

  void VolcarEnFichero(ofstream& file);
  void Escribir(int dato);

 private:
  vector<int> cinta_escritura;
};

#endif