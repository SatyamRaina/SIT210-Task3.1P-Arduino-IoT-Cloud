#include <BH1750FVI.h>
#include "thingProperties.h"
// Create the Lightsensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

void setup() 
{
  Serial.begin(115200);
  LightSensor.begin();  

    // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  ArduinoCloud.update();
  uint16_t light_int2 = LightSensor.GetLightIntensity();
  
  
  Serial.print("Light: ");
  Serial.println(light_int2);
  light_int = light_int2;
  delay(300);
}
/*
  Since LedState is READ_WRITE variable, onLedStateChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange()  {
  //led switch on and off based on the led_state vairable
  digitalWrite(LED_BUILTIN,led);
}
