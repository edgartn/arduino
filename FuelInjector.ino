/*
  1) O Potenciômetro irá simular o acelerador de um carro, seus valores variam de 0 a 1023.
     Para isso iremos multiplicar o valor por 10, para simular as rotações (RPM).

  2) Cada bico injetor é acionado 1 vez a cada 2 voltas (RPM).
     Um motor em estado inicial fica 1500 RPM
     A troca de marcha ideal é em torno de 3000 RPM a 4000 RPM
     
     Então a conta fica assim: RPM/120 => 120 pois é uma injeção a cada 120 segundos.

*/

int gACELERADOR  = 0; 
int gBICOINJETOR = 6;
int gRPM         = 85; // Ao dar a "partida" se inicia com 1000 RPM (1000/120 = 85,25)

void setup() {
  Serial.begin(9600);
  pinMode(gBICOINJETOR, OUTPUT); 
}

void loop() {
  gRPM = analogRead(gACELERADOR) * 10; // Multiplicando valor por 10 para obter valor próximo aos RPM de um carro
  
  AcionarBicoInjetor(gRPM/120); // RPM/120 => Pois é uma injeção a cada 120 segundos.
  
  Serial.println(gRPM);
}

void AcionarBicoInjetor(int aRPM) {

  // Fixando em 20 o menor delay pois abaixo deste valor a "piscada" do led não é visível ao olho humano.
  if (aRPM < 20) {
    aRPM = 20;
  }
  
  // Os valores são "invertidos" pois quanto menor o valor mais rápido o bico irá injetar combustível.  
  analogWrite(gBICOINJETOR, HIGH);
  delay(aRPM);
  analogWrite(gBICOINJETOR, LOW); 
  delay(aRPM);
}
