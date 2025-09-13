#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigA = 25;
const int echoA = 26;

const int trigB = 19;
const int echoB = 18;

const int botaoAnulaGol = 15;

int placarA = 0;
int placarB = 0;

char ultimoTimeGol = ' ';

long medirDistancia(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duracao = pulseIn(echoPin, HIGH, 20000); 
  long distancia = duracao * 0.034 / 2; 
    return distancia;
}

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();

    pinMode(trigA, OUTPUT);
    pinMode(echoA, INPUT);
    pinMode(trigB, OUTPUT);
    pinMode(echoB, INPUT);
    pinMode(botaoAnulaGol, INPUT_PULLUP);

    lcd.setCursor(0, 0);
    lcd.print("Placar Iniciado");
    delay(2000);
    lcd.clear();

    atualizarPlacar();
}

void loop() {
    long distanciaA = medirDistancia(trigA, echoA);
    long distanciaB = medirDistancia(trigB, echoB);

    if (distanciaA > 0 && distanciaA < 10) {
    placarA++;
    ultimoTimeGol = 'A';
    atualizarPlacar();
    delay(1000);
}

    if (distanciaB > 0 && distanciaB < 10) {
    placarB++;
    ultimoTimeGol = 'B';
    atualizarPlacar();
    delay(1000);
}

    anulaGol();
}

void atualizarPlacar() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time A: ");
    lcd.print(placarA);
    lcd.setCursor(0, 1);
    lcd.print("Time B: ");
    lcd.print(placarB);
}

void anulaGol() {
    if (digitalRead(botaoAnulaGol) == LOW) { 
    if (ultimoTimeGol == 'A' && placarA > 0) {
        placarA--;
        atualizarPlacar();
        delay(500);
    } else if (ultimoTimeGol == 'B' && placarB > 0) {
        placarB--;
        atualizarPlacar();
    delay(500);
    }
    ultimoTimeGol = ' ';
    }
}
