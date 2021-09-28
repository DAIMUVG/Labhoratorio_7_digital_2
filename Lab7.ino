//Dylan Ixcayau 18486
//Laboratorio #6: Carrera con TIVA C
//Fecha de creacion: 24 de septiembre del 2021
//Ultima fecha de modificacion: 24 de septiembre del 2021
/*Incluimos las librerias del SPI y para el manejo de la SD
*/
#include <SPI.h>
#include <SD.h>

//Definimos variables
char get;
File myFile;
File root;

void setup()
{
  //Le decimos en que modulo de SPI lo pondremos
  SPI.setModule(0);
  //Iniciamos la comunicacion serial
  Serial.begin(9600);
  while (!Serial) {
    
  }

  //Observamos si se puede niciar la tarjeta SD
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);

  //si la inicializacion falla
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  //Inicializacion acabada
  Serial.println("initialization done.");

  //Le decimos a donde ir
  root = SD.open("/");

  //Nos lleva a una funcion donde nos deja ver los archivos dentro de la SD
  Directorio(root, 0);

  //Texto para usuario
  Serial.println("Ingrese el numero según las opciones numeradas");
  Serial.println("Envie 1) si quiere mostrar val.TXT");
  Serial.println("Envie 2) si quiere mostrar Pringles.TXT");
  Serial.println("Envie 3) si quiere mostrar Nike.TXT");
  Serial.println("Envie 4) si quiere mostrar Carita.TXT");
  Serial.println("Envie 5) si quiere mostrar los archivos en la SD");
}

void loop() {
  //Abrimos de nuevo el archivo para leerlo
  get = Serial.read();

  //Tomamos lo que ingresa el usuario
  char  a = (get, DEC);

  //Por medio de un Switch case ira mostrando los archivos dentro de la SD dependiendo de lo que el usuario indique
  switch (get) {
    case '1':
      myFile = SD.open("val.txt");
      if (myFile) {
        while (myFile.available()) {
          Serial.write(myFile.read());
        }
        myFile.close();
      } else {
        Serial.println("error opening test.txt");
      }
      Serial.println("Ingrese el numero según las opciones numeradas");
      Serial.println("Envie 1) si quiere mostrar val.TXT");
      Serial.println("Envie 2) si quiere mostrar Pringles.TXT");
      Serial.println("Envie 3) si quiere mostrar Nike.TXT");
      Serial.println("Envie 4) si quiere mostrar Carita.TXT");
      Serial.println("Envie 5) si quiere mostrar los archivos en la SD");
      break;

    case '2':
      myFile = SD.open("Pringles.txt");
      if (myFile) {
        while (myFile.available()) {
          Serial.write(myFile.read());
        }
        
        myFile.close();
      } else {
        
        Serial.println("error opening test.txt");
      }
      Serial.println("Ingrese el numero según las opciones numeradas");
      Serial.println("Envie 1) si quiere mostrar val.TXT");
      Serial.println("Envie 2) si quiere mostrar Pringles.TXT");
      Serial.println("Envie 3) si quiere mostrar Nike.TXT");
      Serial.println("Envie 4) si quiere mostrar Carita.TXT");
      Serial.println("Envie 5) si quiere mostrar los archivos en la SD");
      break;

    case '3':
      myFile = SD.open("Nike.txt");
      if (myFile) {
        ;

        
        while (myFile.available()) {
          Serial.write(myFile.read());
        }
        
        myFile.close();
      } else {
        
        Serial.println("error opening test.txt");
      }
      Serial.println("Ingrese el numero según las opciones numeradas");
      Serial.println("Envie 1) si quiere mostrar val.TXT");
      Serial.println("Envie 2) si quiere mostrar Pringles.TXT");
      Serial.println("Envie 3) si quiere mostrar Nike.TXT");
      Serial.println("Envie 4) si quiere mostrar Carita.TXT");
      Serial.println("Envie 5) si quiere mostrar los archivos en la SD");
      break;

    case '4':
      myFile = SD.open("Carita.txt");
      if (myFile) {
        while (myFile.available()) {
          Serial.write(myFile.read());
        }
        myFile.close();
      } else {
        Serial.println("error opening test.txt");
      }
      Serial.println("Ingrese el numero según las opciones numeradas");
      Serial.println("Envie 1) si quiere mostrar val.TXT");
      Serial.println("Envie 2) si quiere mostrar Pringles.TXT");
      Serial.println("Envie 3) si quiere mostrar Nike.TXT");
      Serial.println("Envie 4) si quiere mostrar Carita.TXT");
      Serial.println("Envie 5) si quiere mostrar los archivos en la SD");
      break;

    case '5':
      root = SD.open("/");
      Directorio(root, 0);

      //USUARIO
      Serial.println("Ingrese el numero según las opciones numeradas");
      Serial.println("Envie 1) si quiere mostrar val.TXT");
      Serial.println("Envie 2) si quiere mostrar Pringles.TXT");
      Serial.println("Envie 3) si quiere mostrar Nike.TXT");
      Serial.println("Envie 4) si quiere mostrar Carita.TXT");
      Serial.println("Envie 5) si quiere mostrar los archivos en la SD");
  }

}

void Directorio(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      Directorio(entry, numTabs + 1);
    } else {
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
