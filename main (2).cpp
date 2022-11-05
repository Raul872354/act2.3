//Act 2.3
//Ximena Castañeda, A01742439
//José Raúl Arredondo, A01742153

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "linkedlist.h"

void conversionLong(dato &v){
  while(v.ip.length() < 3) v.ip = '0' + v.ip;
  while(v.ip2.length() < 2) v.ip2 = '0' + v.ip2;
  while(v.ip3.length() < 3) v.ip3 = '0' + v.ip3;
  while(v.ip4.length() < 2) v.ip4 = '0' + v.ip4;; 
  v.ipp = stoi(v.ip + v.ip2 + v.ip3);
  v.ipp = v.ipp*1000000 + stoi(v.ip4 + v.ip5);
}
//complejidad : O(n)

long conversionString(string num, string num2, string num3, string num4, string num5){
  long nume;
  while(num.length()<3) num = '0' + num;
  while(num2.length()<2) num2= '0' + num2;
  while(num3.length()<3) num3 = '0' + num3;
  while(num4.length()<2) num4 = '0' + num4;
  nume = stoi(num + num2 + num3);
  return nume = (nume*1000000 + stoi(num4 + num5));
}
//complejidad : O(n)

long convertir(string numero){
  string num, num2, num3, num4, num5;
  stringstream s(numero);
  getline(s, num, '.');//3
  getline(s,num2,'.');//2
  getline(s,num3,'.');//3
  getline(s,num4,':');//2
  getline(s,num5);//4
  return conversionString(num,num2,num3,num4,num5);
}
//complejidad : O(1)

int main() {
  long n, last, minimo, maximo;
  string mini, maxi, titulo, ss;
  char seguir;
  fstream fin;
  dato registro;
  linkedlist lista;
  fin.open("bitacora.txt",ios::in); 
   
  while(!fin.eof()){
    getline(fin,registro.linea);
    stringstream s(registro.linea);
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,registro.ip, '.');
    getline(s,registro.ip2,'.');
    getline(s,registro.ip3,'.');
    getline(s,registro.ip4,':');
    getline(s,registro.ip5,' ');
    conversionLong(registro);
    lista.addFirst(registro);
  }
  lista.burbuja();
  fin.close();
  
  n = convertir("0");
  last = convertir("9999");
  titulo = "bitacoraOrdenadaIP-Eq6.txt";
  lista.print(n,last,titulo); 
  
  do{
  cout << endl << "Ingresa los valores de búsqueda de ip: ";
  cin >> mini;
  cout << "Ingresa los valores del rango final de ip: ";
  cin >> maxi;
  n = convertir(mini);
  last = convertir(maxi);
  titulo = "salidaN-Eq6.txt";
  lista.print(n,last,titulo); 
  cout << endl << "Desea hacer otra busqueda? : S/N" << endl;
  cin >> (seguir);
  }while((toupper(seguir)) == 'S'); 
  cout << "Ha terminado";
}