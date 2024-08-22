
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
ClickEncoder *one; 
ClickEncoder *two; 
ClickEncoder *three; 
ClickEncoder *four; 
ClickEncoder *five; 
ClickEncoder *six; 

int16_t last, value;

void timerIsr() {
  encoder->service();
}

void setup() {
  Serial.begin(9600); 
  Consumer.begin(); 
  encoder = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN1); 
  one = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN2); 
  two = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN3); 
  three = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN4); 
  four = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN5); 
  five = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN6); 
  six = new ClickEncoder(ENCODER_DT, ENCODER_CLK, BUTTON_PIN7); 

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

  ClickEncoder::Button c = one->getButton(); 
  if (d != ClickEncoder::Open) { 
    switch (e) {
      case ClickEncoder::Clicked: 
        Consumer.write(MEDIA_PLAY_PAUSE); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(MEDIA_NEXT); 
      break;      
    }
  }

    ClickEncoder::Button b = two->getButton(); 
  if (b != ClickEncoder::Open) { 
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(MEDIA_PLAY_PAUSE); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(MEDIA_NEXT); 
      break;      
    }
  }

    ClickEncoder::Button b = three->getButton(); 
  if (b != ClickEncoder::Open) { 
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(MEDIA_PLAY_PAUSE); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(MEDIA_NEXT); 
      break;      
    }
  }

    ClickEncoder::Button b = tfour->getButton(); 
  if (b != ClickEncoder::Open) { 
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(MEDIA_PLAY_PAUSE); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(MEDIA_NEXT); 
      break;      
    }
  }

    ClickEncoder::Button b = five->getButton(); 
  if (b != ClickEncoder::Open) { 
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(MEDIA_PLAY_PAUSE); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(MEDIA_NEXT); 
      break;      
    }
  }

  delay(10); 
  
}


        
