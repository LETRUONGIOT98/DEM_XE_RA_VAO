#define tang 3 //Khai báo chân nút nhấn tăng giá trị giới hạn là chân 3
#define giam 2 
#define senvao A0  //Khai báo chân cảm biến đếm xe vào
#define senra A1    //Cảm biến đếm xe ra
#include <Wire.h>    //Thư viện i2C
#include <LiquidCrystal_I2C.h>  //Thư viện màn hình
LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo màn hình
#include <Servo.h>  //Thư viện Servo
Servo myservo;   //Khai báo servo
int i =0,j=0;   //Khai báo biến
void setup() {
lcd.init();  //khởi động LCD
  lcd.backlight(); //Bật đèn LCD
  myservo.attach(4);  //Khai báo chân điều khiển Servo
  myservo.write(0);   //Góc bạn đầu
  pinMode(tang, INPUT_PULLUP);
  pinMode(giam, INPUT_PULLUP);
  pinMode(senvao, INPUT_PULLUP);
  pinMode(senra, INPUT_PULLUP);
}
void loop() {
if(digitalRead(tang) == 0){ //Nếu nhấn nút tăng
  i=i+1;                    //Giá trị tăng lên 1 cho mỗi lần
  delay(200);
}
if(digitalRead(giam) == 0){   //Nếu nhấn nút giảm
  i=i-1;                      //Giá trị i giảm 1 lần 
  delay(200);
  if(i<=0)i=0;
}
if(digitalRead(senvao) == 0){   //Nếu cảm biến đếm vào cso xe đi qua 
  j=j+1;                        //Giá trị j tăng lên 1 lần
  delay(200);
}
if(digitalRead(senra) == 0){   //Nếu cảm biến đếm xe ra có xe đi qua
  j=j-1;                       //Giá trị j giảm đi 1 lần 
  delay(200);
  if(j<=0)j=0;                 //Nếu bé hơn 0 thì j =0;
}
if(j >= i){                     //Nếu giá trị j lớn hơn giá trị i(i là giá trị giới hạn đặt) 
myservo.write(0);               //Thì servo đóng cửa
}
if(j < i){                      //Nếu giá trị j(xe vào) bé hơn giá trị i(giới hạn đặt) thì servo mở cửa cho xe vào
  myservo.write(180);
}
lcd.setCursor(0,0);           //Vị trí con trỏ
lcd.print("GIOI HAN:       "); //In lên màn hình
lcd.setCursor(10,0);
lcd.print(i);
lcd.setCursor(0,1);
lcd.print("XE VAO:         ");
lcd.setCursor(8,1);
lcd.print(j);
}
