#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

void escribirArchivo(ofstream& ,string);
mutex mtx;

int main(){
    string nombre = "file.txt";
    string texto = "";

    ofstream file ("file.txt", ios::app);

    if(file.is_open()){

        thread h1(escribirArchivo,ref(file), "Hola este es el 1");
        h1.join();
        thread h2(escribirArchivo,ref(file), "Hola este es el 2");
        h2.join();
        thread h3(escribirArchivo,ref(file), "Hola este es el 3");
        h3.join();
        thread h4(escribirArchivo,ref(file), "Hola este es el 4");
        h4.join();
        thread h5(escribirArchivo,ref(file), "Hola este es el 5");
        h5.join();
        file.close();
    }

    else{
        cout << "No se pudo abrir el archivo";
    }

    return 0;
}

void escribirArchivo(ofstream& archivo, string texto){
    mtx.lock();
   if (archivo.is_open()) {
        archivo << texto << endl;
        archivo.flush(); 
    }
    mtx.unlock();
}