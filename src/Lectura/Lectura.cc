// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo Lectura.cc: Implementación de Lectura
//        En este fichero se implementa las funciones de la clase Lectura
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"Lectura.h"


/** vector<int> fichero_to_vector(string fichero)
  * @brief Convierte un fichero en un vector de enteros.
  * @param string fichero
  * @return vector<int> un vector con todos los enteros del fichero
  * 
  */
vector<int> fichero_to_vector(string fichero) {
  vector<int> vector_fichero;
  ifstream archivo(fichero); 
  if (archivo.is_open()) {
    string elemento_leido;
    while (archivo >> elemento_leido) { // mientras haya elementos en el fichero
      try {
        vector_fichero.push_back(stoi(elemento_leido)); // metemos la linea en el vector en forma de número
      } catch (const invalid_argument& e) {
        throw invalid_argument("Error: El fichero contiene algo que no es un número"); // si no es un número, lanzamos una excepción
      }
    }
    archivo.close();
  } else { // si no se ha podido abrir el fichero, lanzamos una excepción
    throw ios_base::failure("Error: No se ha podido abrir el fichero"); 
  }
  return vector_fichero;
}

/** Lectura::Lectura()
  * @brief Crea el objeto de la clase Lectura.
  * @param vector<int> fichero_de_lectura
  * @return objeto de la clase Lectura
  */
Lectura::Lectura(vector<int> fichero_de_lectura) : fichero_de_lectura_(fichero_de_lectura) {
  int pos_lectura_= 0;
  // muestro el vector (debug)
  for (long unsigned int i = 0; i < fichero_de_lectura_.size(); i++) {
    cout << fichero_de_lectura[i] << " ";
  }
}



