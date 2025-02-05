// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo MemoriaPrograma.cc: Implementación de MemoriaPrograma
//        En este fichero se implementa las funciones de la clase MemoriaPrograma
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"MemoriaPrograma.h"
/**
  * @brief Función utilitaria para trim de cadenas (para quitarles los espacios en blanco)
  * @param string s
  * @return string 
  */
string trim(const string& s) {
  auto start = s.begin();
  while (start != s.end() && isspace(*start)) ++start;
  
  auto end = s.end();
  do { --end; } while (distance(start, end) > 0 && isspace(*end));
  
  return string(start, end + 1);
}

/** ficher_to_line()
  * @brief Lee un fichero y lo convierte en un vector de strings
  * @param string fichero
  * @return vector de strings
  */
vector<string> fichero_to_line(string fichero) {
  ifstream file(fichero);
  string line;
  vector<string> lineas;
  for (string line; getline(file, line);) { // mientras haya lineas en el fichero
    line = trim(line);
      
    if (!line.empty() && line[0] != '#') {
      lineas.emplace_back(move(line));
    }
  }
  return lineas;
}


/** MemoriaPrograma::MemoriaPrograma()
  * @brief Crea el objeto de la clase MemoriaPrograma.
  * @param 
  * @return objeto de la clase MemoriaPrograma
  */
MemoriaPrograma::MemoriaPrograma(vector<string> lineas_de_codigo) {
  memoria_programa_ = vector<pair<string,string>>();
  string instruccion = "";
  string operando = "";
  vector<string> instruccion_auxiliar;
  // hago un bucle para recorrer todas las lineas de codigo
  for (long unsigned int i = 0; i < lineas_de_codigo.size(); i++) {
    instruccion = "";
    operando = "";
    instruccion_auxiliar = vector<string>();
    // Utilizo istringstream para leer la línea como si fuese un fichero
    istringstream iss(lineas_de_codigo[i]);
    // Recopilo todas las palabras en un vector
    while (iss >> instruccion) { 
      std::transform(instruccion.begin(), instruccion.end(), instruccion.begin(), ::toupper); // paso todas las instrucciones a mayúsculas
      instruccion_auxiliar.push_back(instruccion); 
    }
    // miro si hay una etiqueta
    if (instruccion_auxiliar.size() == 2) {
      if (instruccion_auxiliar[1] == "HALT") {
        memoria_programa_.push_back(make_pair(instruccion_auxiliar[1], "-1"));
        // le quito los dos puntos a la etiqueta
        string etiqueta = instruccion_auxiliar[0];
        etiqueta = etiqueta.substr(0, etiqueta.size() - 1);
        etiqueta_a_dirección_[etiqueta] = i;
      } else {
        memoria_programa_.push_back(make_pair(instruccion_auxiliar[0], instruccion_auxiliar[1]));
      }
    } else if (instruccion_auxiliar.size() == 3) { // esto significa que hay una etiqueta antes de las instrucciones
      memoria_programa_.push_back(make_pair(instruccion_auxiliar[1], instruccion_auxiliar[2]));
      // le quito los dos puntos a la etiqueta
      string etiqueta = instruccion_auxiliar[0];
      etiqueta = etiqueta.substr(0, etiqueta.size() - 1);
      etiqueta_a_dirección_[etiqueta] = i;
    } else if (instruccion_auxiliar.size() == 1 || instruccion_auxiliar[0] == "HALT") { // esto significa que hay una instrucción sin operando
       memoria_programa_.push_back(make_pair(instruccion_auxiliar[0], "-1")); // le pongo un -1 porque no debería de usarse
    } else {
      throw invalid_argument("Error: La instrucción no tiene el formato correcto");
    }
  }
}

/**
 * @brief Función para leer la instrucción en la dirección dada
 * @param direccion Dirección de la instrucción
 * @return pair<string, string> Instrucción y operando
*/

pair<string, string> MemoriaPrograma::Leer_instruccion(int direccion) {
  if (static_cast<long unsigned int>(direccion) >= memoria_programa_.size()) {
    throw out_of_range("Error: Se ha intentado leer más allá de la memoria de programa");
  }
  return memoria_programa_[direccion];
}


/**
 * @brief Función para imprimir la memoria de programa
 * @param os ostream
 * @param memoria MemoriaPrograma
 * @return ostream
*/

ostream& operator<<(ostream& os, const MemoriaPrograma& memoria) {
    for (long unsigned int i = 0; i < memoria.memoria_programa_.size(); i++) {
      os << i << " -> " << memoria.memoria_programa_[i].first << " " << memoria.memoria_programa_[i].second << endl;
    }
    for (auto etiqueta : memoria.etiqueta_a_dirección_) {
      os << etiqueta.first << " -> " << etiqueta.second << endl;
    }
    return os;
  }
