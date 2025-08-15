/* 

            NAU7802 example program
Initializes and sets up basic usage of NAU7802 ADC.
Prints out the voltage measured across the channel 1
inputs of the ADC.

*/

#include <Arduino.h>
#include <NAU7802.h>

NAU7802 adc;


void setup() {
    Serial.begin(9600);

    if(adc.begin() == true) {
        Serial.println("NAU7802 initialized successfully.");
    } else {
        Serial.println("NAU7802 initialization failed.");
    }
    adc.standby(false);
    adc.setAnalogSupply(NAU7802_SUPPLY_4V5);
    adc.setChannel(NAU7802_CHANNEL_1);
    adc.setConversionRate(NAU7802_CONVERSIONRATE_80);
    adc.setLdoMode(NAU7802_LDOMODE_1);
    adc.pgaBypass(true);
    adc.calibrate(NAU7802_CALIBRATE_INTERNAL_OFFSET);
    
}

void loop() {
    float adcVal = adc.read();
    if (adcVal == NAU7802_DATA_NOT_READY) return;

    float voltage = adcVal * 4.5 / pow(2, 24);
    Serial.print("Voltage:");
    Serial.print(voltage, 3);
    Serial.println("V");
}