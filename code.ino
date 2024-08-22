
#include <ClickEncoder.h>
#include <TimerOne.h>
#include <HID-Project.h>

#define ENCODER_CLK A0
#define ENCODER_SW A2
#define ENCODER_DT A1

#define button1 2
#define button2 3
#define button3 4
#define button4 5
#define button5 6
#define button6 7

ClickEncoder *encoder; 

int16_t last, value;

void timerIsr() {
  encoder->service();
}

void setup() {
  Serial.begin(9600); 
  Consumer.begin(); 
  encoder = new ClickEncoder(ENCODER_DT, ENCODER_CLK, ENCODER_SW); 
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  pinMode(BUTTON_PIN6, INPUT_PULLUP);
  
  Timer1.initialize(1000); 
  Timer1.attachInterrupt(timerIsr); 
  last = -1;
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

  //main encoder
  ClickEncoder::Button b = encoder->getButton(); 
  if (b != ClickEncoder::Open) { 
Serial.print("Button: "); 
    #define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(CONSUMER_SLEEP); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(CONSUMER_SLEEP); 
      break;      
    }
  }

  ClickEncoder::Button b = one->getButton(); 
  if (b != ClickEncoder::Open) { 
Serial.print("Button: "); 
    #define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(CONSUMER_SLEEP); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(CONSUMER_SLEEP); 
      break;      
    }
  }

  ClickEncoder::Button b = two->getButton(); 
  if (b != ClickEncoder::Open) { 
Serial.print("Button: "); 
    #define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      case ClickEncoder::Clicked: 
        Consumer.write(CONSUMER_SLEEP); 
      break;      
      
      case ClickEncoder::DoubleClicked: 
         Consumer.write(CONSUMER_SLEEP); 
      break;      
    }
  }

  if(digitalRead(button1) == LOW)
  {
    Consumer.write(MEDIA_PREV); 
    delay(200);
  }

  if(digitalRead(button2) == LOW)
  {
    Consumer.write(CONSUMER_CALCULATOR); 
    delay(200);
  }

  if(digitalRead(button3) == LOW)
  {
    Consumer.write(MEDIA_VOLUME_MUTE); 
    delay(200);
  }

  if(digitalRead(button4) == LOW)
  {
    Consumer.write(MEDIA_PREV); 
    delay(200);
  }

  if(digitalRead(button5) == LOW)
  {
    Consumer.write(MEDIA_PLAY_PAUSE); 
    delay(200);
  }

  if(digitalRead(button6) == LOW)
  {
    Consumer.write(MEDIA_NEXT); 
    delay(200);
  }
  
  delay(10); 
  
}


        
