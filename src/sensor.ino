//
// simple pump              - CeC 7/15/17
// add moisture sensor      - CeC 7/23/17
//

// behavior configuration
//
#define runTime 900000      // ms to run (15min = 900,000)
#define brief   300000      // for a brief run (5 min = 300,000)
// bone dry is about 4000 ; soaked is about 1200
#define DRY     2400        // kinda dry

// hardware configuration
//
#define pumpPin D4          // put pump (relay) control on D4 

// water sensor using A pins for power/ground to turn on/off only 
// when needed (otherwise the probes and soil act like a battery and they erode)
#define h2oGND  A0          // GND on pin A0
#define h2oVCC  A1          // VCC on pin A1
#define h2oDAT  A2          // Analog data on pin A2

// Other Vars and setup
//
int state       = 0;        // pump state
int howLong     = 0;        // int to hold the ad hoc request to run for xxx ms
int msPump      = 0;        // how much time have we been pumping, roughly, updated every 10s
int moisture    = 0;
bool thirsty    = TRUE;     // is it dry? checked every minute in housekeep

// Timers
//
Timer pumpTimer(runTime, finito);   // turn it off after runTime (#defined above) ms
Timer hkeeper(20000, housekeep);    // housekeeping stuff every 20s

// Setup
//
void setup() {
    Particle.function("parse", parse);
    Particle.variable("state", state);          //NOTE - if you use a cellular-connected
    Particle.variable("msPump", msPump);        // Particle Electron don't use variables
    Particle.variable("moisture", moisture);    // because they burn through your data ($$)
    Particle.variable("thirsty", thirsty);
    pinMode(pumpPin, OUTPUT);
    pinMode(h2oGND, OUTPUT);
    pinMode(h2oVCC, OUTPUT);
    pinMode(h2oDAT, INPUT);
    digitalWrite(h2oGND, LOW);      // GND for h2o sensor
    hkeeper.start();                // start the houskeeping task running every minute
    delay (5000);                   // give the moisture sensor time to fire up
    moisture = analogRead(h2oDAT);
}

void loop() {
    // everything is interrupt- or timer-driven
}

// parse is called via IFTTT
//
int parse(String cmd) {
    cmd.trim();
    cmd.toUpperCase();
    
    if (cmd.startsWith("ON") && thirsty) { // turn the relay ON if soil is dry
        digitalWrite(pumpPin, HIGH);
        state = 1;
        pumpTimer.start();
        msPump = 0;
    }
    
    if (cmd.startsWith("OF")) { // "OFF" - turn the relay OFF
        finito();
    }

    if (cmd.startsWith("FO")) { // "FORCE" - turn the relay on, ignoring moisture sensor
        digitalWrite(pumpPin, HIGH);
        state = 1;
        pumpTimer.start();
        msPump = 0;
    }
}

void finito() {
    digitalWrite(pumpPin, LOW);
    msPump = 0;
    state = 0;
}

void housekeep() {
    
    // monitor moisture
    // turn on the sensor (keep it off most of the time 
	// as it aspires to be a battery and will erode the probes)
    digitalWrite(h2oVCC, HIGH);     // VCC for h2o sensor
    delay(1000);
    moisture = analogRead(h2oDAT);
    digitalWrite(h2oVCC, LOW);      // turn off VCC while not in use
    
    thirsty = (moisture > DRY);

    // keep track of how long we have run so we can report for the curious
    if (state) {
        msPump++;
    } else {
        msPump = 0;
    }
}
