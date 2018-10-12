int steps_x = 2;       //Posición del pin contador de pasos eje x
int direccion_x = 5;    //Posición del pin dirección eje x
int enable = 8;       //Posición enable
int pasos = 200;     //Pasos de mi motor
 
void setup() {               
  // Con esto me diferencia si el valor que he metido anteriormente pertenece a un pin o pertenece a un valor dado 
  pinMode(steps_x, OUTPUT);
  pinMode(direccion_x, OUTPUT);
  pinMode(enable, OUTPUT);
  
}
 
// La rutina que se repite cíclicamente
void loop() {
 digitalWrite(enable,LOW); //el enable tiene lógica inversa, cuando está en LOW está activado

  
  digitalWrite(direccion_x, HIGH);  
  //Se repite un bucle hasta final de carril.
  for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
  {
    digitalWrite(steps_x, HIGH); // This LOW to HIGH change is what creates the
    delay(1);
    digitalWrite(steps_x, LOW);// al A4988 de avanzar una vez por cada pulso de energia. 
    delay(1);
    
  } 
  

  digitalWrite(direccion_x, LOW);
  delay(1000);
  for (int i = 0; i<pasos; i++)       //Equivale al numero de vueltas (200 es 360º grados) o micropasos
  {  
    digitalWrite(steps_x, LOW);// LOW to HIGH hace que el motor avance ya que da la orden
    delay(1);
    digitalWrite(steps_x, HIGH); // al A4988 de avanzar una vez por cada pulso de energia.
    delay(1);
    
  }
}
