#define LED_PIN 13
#define LED_ON HIGH
#define LED_OFF LOW
#define ON_INTERVAL 1000   // Duração do LED aceso em milissegundos (1 segundo)
#define OFF_INTERVAL 2000  // Duração do LED apagado em milissegundos (2 segundos)

bool ledState = LED_OFF;
unsigned long elapsedTime = 0;
unsigned long startTime = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, ledState);
    startTime = millis();
}

void loop() {
    unsigned long loopStartTime = millis();
    elapsedTime = loopStartTime - startTime;

    if ((ledState == LED_OFF) && (elapsedTime >= OFF_INTERVAL)) {
        ledState = LED_ON;
        digitalWrite(LED_PIN, ledState);
        startTime = loopStartTime;
    }

    if ((ledState == LED_ON) && (elapsedTime >= ON_INTERVAL)) {
        ledState = LED_OFF;
        digitalWrite(LED_PIN, ledState);
        startTime = loopStartTime;
    }
}
