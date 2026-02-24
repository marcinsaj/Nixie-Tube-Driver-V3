/* Nixie Tube Driver V3 - Example 1: Single Nixie Tube
 *
 * This program drives a single nixie tube connected to the Nixie Tube Driver V3
 * controller board. The controller uses 5 daisy-chained 74HC595D shift registers
 * providing 40 outputs (K01-K40). Data is sent as a 40-bit frame using
 * software bit-banging.
 *
 * Each nixie tube has 10 cathodes (digits 0-9). Only one cathode is active
 * at a time, so only one bit in the 40-bit frame is set to 1.
 *
 * This example cycles through digits 0-9 with a 1 second delay between each.
 */

// ---------------------------------------------------------------------------
// Controller outputs K01-K40 mapped to bit positions in 40-bit frame.
// Bits are counted from 0 to 39.
// The assignment is based on the controller PCB architecture.
// Don't change it.
// ---------------------------------------------------------------------------
static const uint8_t K01 =  7;    static const uint8_t K21 =  0;
static const uint8_t K02 =  6;    static const uint8_t K22 =  9;
static const uint8_t K03 =  5;    static const uint8_t K23 = 10;
static const uint8_t K04 =  4;    static const uint8_t K24 = 11;
static const uint8_t K05 =  3;    static const uint8_t K25 = 12;
static const uint8_t K06 =  2;    static const uint8_t K26 = 13;
static const uint8_t K07 =  1;    static const uint8_t K27 = 14;
static const uint8_t K08 =  8;    static const uint8_t K28 = 15;
static const uint8_t K09 = 16;    static const uint8_t K29 = 17;
static const uint8_t K10 = 31;    static const uint8_t K30 = 18;

static const uint8_t K11 = 30;    static const uint8_t K31 = 19;
static const uint8_t K12 = 29;    static const uint8_t K32 = 20;
static const uint8_t K13 = 28;    static const uint8_t K33 = 21;
static const uint8_t K14 = 27;    static const uint8_t K34 = 22;
static const uint8_t K15 = 26;    static const uint8_t K35 = 23;
static const uint8_t K16 = 25;    static const uint8_t K36 = 24;
static const uint8_t K17 = 32;    static const uint8_t K37 = 33;
static const uint8_t K18 = 39;    static const uint8_t K38 = 34;
static const uint8_t K19 = 38;    static const uint8_t K39 = 35;
static const uint8_t K20 = 37;    static const uint8_t K40 = 36;


// ---------------------------------------------------------------------------
// Example assignment of nixie tube cathodes to the corresponding controller outputs. 
// The first item on the list corresponds to the cathode displaying “0”, 
// the second to cathode “1,” and so on. 
// You can edit the list according to your own nixie tube connection.
// ---------------------------------------------------------------------------
static const uint8_t nixieTube1[10] = 
{
  /*Digit 0*/ K10,
  /*Digit 1*/ K01,
  /*Digit 2*/ K02,
  /*Digit 3*/ K03,
  /*Digit 4*/ K04,
  /*Digit 5*/ K05,
  /*Digit 6*/ K06,
  /*Digit 7*/ K07,
  /*Digit 8*/ K08,
  /*Digit 9*/ K09
};


// ---------------------------------------------------------------------------
// Pin assignment - control inputs
// These can be any digital pins
// ---------------------------------------------------------------------------
const uint8_t DIN_PIN  = 11;  // Serial data input (DIN)
const uint8_t EN_PIN   = 10;  // Enable input pin (EN)
const uint8_t CLK_PIN  = 13;  // Clock input pin (CLK)

// ---------------------------------------------------------------------------
// setup() - configure control pins as outputs
// ---------------------------------------------------------------------------
void setup()
{
  pinMode(DIN_PIN, OUTPUT);
  digitalWrite(DIN_PIN, LOW);  

  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);

  pinMode(CLK_PIN, OUTPUT);  
  digitalWrite(CLK_PIN, LOW);         
}

// ---------------------------------------------------------------------------
// Cycle through digits 0-9, one per second
// ---------------------------------------------------------------------------
void loop()
{
  for (uint8_t digit = 0; digit < 10; digit++)
  {
    nixieDisplay(digit);
    delay(1000);
  }
}

// ---------------------------------------------------------------------------
// nixieDisplay() - display a single digit (0-9) on the nixie tube
//
// Sends a 40-bit frame to the controller shift registers chain. 
// Only one bit is set to 1 (the active cathode), all other 39 bits are 0.
// ---------------------------------------------------------------------------
void nixieDisplay(uint8_t digit)
{
  uint8_t activeBit = nixieTube1[digit];

  digitalWrite(EN_PIN, LOW);

  // Send 40 bits, MSB first (bit 39 first, bit 0 last)
  for (int8_t i = 39; i >= 0; i--)
  {
    digitalWrite(DIN_PIN, (i == activeBit) ? HIGH : LOW);
    digitalWrite(CLK_PIN, HIGH);
    digitalWrite(CLK_PIN, LOW);
  }

  // Latch - transfer data to outputs
  digitalWrite(EN_PIN, HIGH);
}
