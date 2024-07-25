Mains #include <xc.h>
// Configuration bits
#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits
#pragma config WDTE = OFF		// Watchdog Timer Enable bit 
#pragma config PWRTE = OFF			// Power-up Timer Enable bit 
#pragma config MCLRE = ON		 // RE3/MCLR pin function select bit
#pragma config CP = OFF	// Code Protection bit
#pragma config CPD = OFF	// Data Code Protection bit 
#pragma config BOREN = ON		// Brown Out Reset Selection bits
#pragma config IESO = OFF	// Internal External Switchover bit
#pragma config FCMEN = OFF		// Fail-Safe Clock Monitor Enable bit
#pragma config LVP = OFF	// Low Voltage Programming Enable bit
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit
#pragma config WRT = OFF	// Flash Program Memory Self Write Enable bits

#define _XTAL_FREQ 4000000		// Define crystal frequency #define VOLTAGE_PIN 0	// Analog input pin (AN0)


#define _XTAL_FREQ 4000000		// Define crystal frequency #define VOLTAGE_PIN 0	// Analog input pin (AN0)

// Function prototypes void initADC(); unsigned int readADC();
float calculateVoltage(unsigned int adcValue);

// Main function void main(void) {
unsigned int adcValue; float voltage;

// Initialize ADC initADC();

// Infinite loop while (1) {
// Read ADC value adcValue = readADC();
// Calculate voltage
voltage = calculateVoltage(adcValue);
// Add your display or logging code here
// For example, send the voltage value to UART (assuming UART is initialized)
// printf("Voltage: %.2fV\n", voltage);

  delay_ms(1000); // Delay 1 second
}
}

// Initialize ADC void initADC() {
ADCON0 = 0x41; // Turn on ADC and set clock
ADCON1 = 0x80; // Right justify result, use VDD and VSS as reference
}
// Read ADC value unsigned int readADC() {
ADCON0 |= 0x02; // Start conversion
while (ADCON0 & 0x02); // Wait for conversion to complete return ((ADRESH << 8) + ADRESL); // Return 10-bit ADC value
}

// Calculate voltage from ADC value
float calculateVoltage(unsigned int adcValue) { float voltage;
voltage = adcValue * (5.0 / 1023.0); // Convert ADC value to voltage
// Adjust according to your voltage divider voltage = voltage * ((R1 + R2) / R2); return voltage;
}
