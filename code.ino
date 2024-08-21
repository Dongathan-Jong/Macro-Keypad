
#include <ClickEncoder.h>
#include <TimerOne.h>
#include <HID-Project.h>

#define ENCODER_CLK A0
#define ENCODER_SW A2
#define ENCODER_DT A1

#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7

ClickEncoder *encoder; 

int16_t last, value;

void timerIsr() {
  encoder->service();
}

void setup() {
  Serial.begin(9600); 
  Consumer.begin(); 

} 

void loop() {  
  value += encoder->getValue();
  
  if (value != last) { 

    if(last<value)
      Consumer.write(MEDIA_VOLUME_UP);
      else
      Consumer.write(MEDIA_VOLUME_DOWN);
    last = value; 
    Serial.print("Encoder Value: ");
    Serial.println(value);
  }

  delay(10); 
  
}


        
