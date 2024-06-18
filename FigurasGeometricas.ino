// motor A
int IN1 = 3;
int IN2 = 4;

// motor B
int IN3 = 5;
int IN4 = 6;

// PWM
int mA = 9;
int mB = 10;

void setup() {
  Serial.begin(9600); // Inicializa el monitor serial para depuración
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(mA, OUTPUT);
  pinMode(mB, OUTPUT);
}

void loop() {
  //int C = Serial.parseInt();
  //realCuadrado();
  realCuadrado();
  delay(4000);
  Parar();
  delay(500);
  realTriangulo();
  delay(4000);
  Parar();
  delay(500);
  CirculoPWM(95); //min: 90, max: 119
  delay(7000);
  Parar();
  delay(500);
  /*Serial.println("Adelante2");
  Adelante2();
  //Circulo2();
  delay(1000);
  Serial.println("Parar");
  Parar();*/

}

// *************** Función para ir hacia delante ************
void Adelante() {
  analogWrite(mA, 80);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, 80);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Adelante2() {
  analogWrite(mA, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, 100);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ************** Función para ir hacia atras ***************
void Atras() {
  analogWrite(mA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  analogWrite(mB, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Circulo2() {
  analogWrite(mA, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ************** Función para parar ***************
void Parar() {
  analogWrite(mA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void GiroDerecha() {
  analogWrite(mA, 70);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void GiroIzquierda() {
  // Actualmente no hace nada.
}

void Cuadrado() {
  Adelante();
  delay(1000);
  GiroDerecha();
  delay(687);
  Adelante();
  delay(1000);
  GiroDerecha();
  delay(687);
  Adelante();
  delay(1000);
  GiroDerecha();
  delay(687);
  Adelante();
  delay(1000);
  GiroDerecha();
  delay(687);
}

void Circulo() {
  analogWrite(mA, 127);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, 63);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void realCuadrado()
{
  Avanza();
  delay(1000);
  giraIzquierda();
  delay(1000);
  //Serial.println("\n\n");
}

void giraIzquierda()
{
  int pwmA = 0;
  int pwmB = 51;
  analogWrite(mA, pwmA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Serial.println(pwmA);
  
  analogWrite(mB, pwmB);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //Serial.println(pwmB);
}

void realTriangulo()
{
  Avanza();
  delay(1000);
  giraDerecha();
  delay(1000);
  //Serial.println("\n\n");
}

void Avanza()
{
  int pwmA = 80;
  int pwmB = 80;
  
  analogWrite(mA, pwmA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Serial.println(pwmA);
  
  analogWrite(mB, pwmB);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  //Serial.println(pwmB);
}

void giraDerecha()
{
  int pwmA = 60;
  int pwmB = 0;
  analogWrite(mA, pwmA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Serial.println(pwmA);
  
  analogWrite(mB, pwmB);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //Serial.println(pwmB);
}

void CirculoPWM(int C)
{
  double radio = calcularRadio(C);
  double radio2 = radio - 9;

  //Obtenemos la circunferencia del radio 2
  double c2 = calcularCircunferencia(radio2);
  //El obtenerPWM nos da el PWM para que la rueda 2 gire C
  double PWM = obtenerPWM(c2);
/*
  // Imprimir etiquetas y valores
  Serial.println("\n\n\n\n\n\n");

  Serial.print("Circunferencia: ");
  Serial.println(C);  
  Serial.print("Radio: ");
  Serial.println(radio);  
  Serial.print("Radio2: ");
  Serial.println(radio2);  
  Serial.print("C2: ");
  Serial.println(c2);  
  Serial.print("PWM: ");
  Serial.println(PWM);
  delay(3000);*/

  analogWrite(mA, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(mB, PWM);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

double obtenerPWM(int C)
{
  double PWM = (C - 14.8) / 0.233;
  if (PWM < 0)
  {
    return 0;
  } else if (PWM > 200)
  {
    return 200;
  }
  return PWM;
}

double calcularCircunferencia(int r)
{
  double C = (2 * PI) * r;
  return C;
}

double calcularRadio(int C)
{
  double r = C / (2 * PI);
  return r;
}

