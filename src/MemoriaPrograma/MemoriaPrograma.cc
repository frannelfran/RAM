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

/** ficher_to_line()
  * @brief Lee un fichero y lo convierte en un vector de strings
  * @param string fichero
  * @return vector de strings
  */
vector<string> fichero_to_line(string fichero) {
  ifstream file(fichero);
  string line;
  vector<string> lineas;
  while (getline(file, line)) {
    lineas.push_back(line);
  }
  //imprimo el vector
  for (int i = 0; i < lineas.size(); i++) {
    cout << lineas[i] << endl;
  }
  // compruebo que las instrucciones están correctamente escritas
  // miro si hay lineas vacias
  for (int i = 0; i < lineas.size(); i++) {
    if (lineas[i] == "") {
      lineas.erase(lineas.begin() + i);
    }
  }
  // miro si hay lineas que empiezan con # y en ese caso las elimino

  return lineas;
}


/** MemoriaPrograma::MemoriaPrograma()
  * @brief Crea el objeto de la clase MemoriaPrograma.
  * @param 
  * @return objeto de la clase MemoriaPrograma
  */
MemoriaPrograma::MemoriaPrograma(vector<string> lineas_de_codigo) {
  memoria_programa_ = vector<pair<string,string>>();
  PC_ = 0;
  string instruccion = "";
  string operando = "";
  vector<string> instruccion_auxiliar;
  // hago un bucle para recorrer todas las lineas de codigo
  for (int i = 0; i < lineas_de_codigo.size(); i++) {
    instruccion = "";
    operando = "";
    instruccion_auxiliar = vector<string>();

    // Utilizo istringstream para leer la línea como si fuese un fichero
    istringstream iss(lineas_de_codigo[i]);
    // Recopilo todas las
    while (iss >> instruccion) { 
      instruccion_auxiliar.push_back(instruccion);
    }
    // miro si hay una etiqueta
    if (instruccion_auxiliar.size() == 2) {
      memoria_programa_.push_back(make_pair(instruccion_auxiliar[0], instruccion_auxiliar[1]));
    } else if (instruccion_auxiliar.size() == 3) { // esto significa que hay una etiqueta antes de las instrucciones
      memoria_programa_.push_back(make_pair(instruccion_auxiliar[1], instruccion_auxiliar[2]));
      etiqueta_a_dirección_[instruccion_auxiliar[0]] = i;
    } else {
      cout << "Error en la instrucción" << endl;
    }
  }

}
