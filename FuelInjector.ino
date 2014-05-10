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
int gModo        = 7;  // Lendo a porta 7 para alternar entre o modo economico e o de performance.
int gModoAtual   = 0;


void setup() {
  Serial.begin(9600);
  pinMode(gBICOINJETOR, OUTPUT); 
  pinMode(gModo, INPUT); 
}

void loop() {
  gRPM = analogRead(gACELERADOR) * 10; // Multiplicando valor por 10 para obter valor próximo aos RPM de um carro

  gModoAtual = digitalRead(gModo);
  
  if (gModoAtual == HIGH) {
    AcionarBicoInjetor(gRPM, 'p');
  } else {
    AcionarBicoInjetor(gRPM, 'e');
  }
  
  
  Serial.println(gRPM);
}

void AcionarBicoInjetor(int aRPM, String aModo) {

  // Modo e = economômico => RPM/180 => Maior intervalo entre as injeções garantindo assim mais economia.
  if (aModo = 'e') {
    aRPM = aRPM/180;
  }

  // Modo p = performance => RPM/120 => Menor intervalo entre as injeções permitindo assim mais performance.
  if (aModo = 'p'){
    aRPM = aRPM/120;
  }

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
