/*
 * Automated Load Switch for vacumm control with ACS712 sensor
 * https://youtu.be/dfmcjT2cFxc
 * 
 * This code is written by Blagojce Kolicoski
 * for the Taste The Code YouTube Channel
 * https://www.youtube.com/tastethecode
 */

#define ITERATIONS 300    //Number of itterations to measure for current
#define inputPin A2       //ACS712 analog input pin
#define relayPin 7        //Control relay output pin
#define sensorType 20     //Specifies the A that the sensor is rated for

float highPeak,lowPeak,sensorPrecision;
float value_PeakToPeak, value_RMS;

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

//Turn off delay after tool stops 1000 = 1 second
const long interval = 5000;

void setup() 
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  //calculate the sensor precision per step
  sensorPrecision = 1024.0 / (sensorType * 1000.0);
}

void loop() 
{
  measure();
  value_RMS = value_PeakToPeak * 0.3536 * sensorPrecision;     

  Serial.print(sensorPrecision);
  Serial.print("\t");
  Serial.print(value_RMS);
  Serial.print("\t");
  Serial.println(value_PeakToPeak);
  if (value_RMS > 0.2) {
    digitalWrite(relayPin, LOW);
    previousMillis = millis();
  } else {
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digitalWrite(relayPin, HIGH);
    }
  }
  delay(200);
}

void measure()
{     
  int cnt;
  //We first assume that our high peak is equal to 0 and low peak is 1024, yes inverted
  highPeak = 0;
  lowPeak = 1024;

  //determine values for loww and high peak
  for (cnt = 0; cnt < ITERATIONS; cnt++) {          
    float sensorValue = analogRead(inputPin); 
    if(sensorValue > highPeak){               
      highPeak = sensorValue;            
    } else if(sensorValue < lowPeak) {
      lowPeak = sensorValue;
    }
  }
  //get the difference from peak to peak
  value_PeakToPeak = highPeak - lowPeak;
}
