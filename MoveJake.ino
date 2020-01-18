    #include <Servo.h>
    Servo left_arm;
    Servo right_arm;
    Servo head;

    int la_pos = 0;
    int ra_pos = 0;
    int h_pos = 0;
    int num = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(2,INPUT);
    Serial.begin(9600);
    left_arm.attach(9);
    right_arm.attach(10);
    head.attach(11);
    head.write(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    if(digitalRead(2)==HIGH){
      if (num==0){
    Serial.print("stay ");
    for (la_pos = 0; la_pos <= 180; la_pos += 1) {
    left_arm.write(la_pos);
    delay(10);
    num=1;
      }
    }
    if(num==1) {
      if(digitalRead(2)==HIGH && num==1){
    Serial.print("away ");
    for (ra_pos = 0; ra_pos <= 180; ra_pos += 1) {
    right_arm.write(ra_pos);
    delay(10);
    num=2;
      }
    }
    if (num==2)
      if(digitalRead(2)==HIGH && num==2){
    Serial.print("from ");
    for (h_pos = 50; h_pos >= 1; h_pos -= 1) {
    head.write(h_pos);
    delay(10);
    num=3;
      }
    }
    if (num==3)
      if(digitalRead(2)==HIGH && num==3){
    Serial.print("cookie. ");
    for (h_pos = 1; h_pos <= 50; h_pos += 1) {
    head.write(h_pos);
    delay(10);
    num=0;
      }
    }
  }
}
}
