// Chân 10 của Arduino kết nối với TCS3200

int OutPut= 10;

unsigned int frequency = 0;

#include <LiquidCrystal.h>   

// Khởi tạo thư viện LCD với các số của các chân giao tiếp

LiquidCrystal lcd(8, 9, 7, 11, 12, 13); //RS,EN,D4,D5,D6,D7

void setup()

{

                // Thiết lập số cột và hàng của LCD

                lcd.begin(16, 2);

                // Chân 2, 3, 4, 5 là các chân ngõ ra

                pinMode(2, OUTPUT);

                pinMode(3, OUTPUT);

                pinMode(4, OUTPUT);

                pinMode(5, OUTPUT);

                // Chân 10 là chân ngõ vào

                pinMode(10, INPUT);

               // Thiết lập tỷ lệ tần số là 20%

                digitalWrite(2,HIGH);

                digitalWrite(3,LOW);

}

void loop()

{

                //In ký tự R(red) – màu đỏ

                lcd.print("R=");

                //Thiết lập photodiode lọc màu đỏ

                digitalWrite(4,LOW);

                digitalWrite(5,LOW);

                //Đọc tần số

                frequency = pulseIn(OutPut, LOW);

                //Hiển thị tần số màu đỏ trên LCD

                lcd.print(frequency);

                lcd.print("    ");

                //Di chuyển con trỏ đến vị trí 9

                lcd.setCursor(9, 0);

                delay(100);

               //In ký tự B(blue) – màu xanh dương

               lcd.print("B=");

              //Thiết lập photodiode lọc màu xanh dương

                digitalWrite(4,LOW);

                digitalWrite(5,HIGH);

                //Đọc tần số

                frequency = pulseIn(OutPut, LOW);

               //Hiển thị tần số màu xanh dương lên LCD

                lcd.print(frequency);

                lcd.print("     ");

                lcd.setCursor(0, 1);

                delay(100);

               //In ký tự G(green) – màu xanh lá

               lcd.print("G=");

               //Thiết lập photodiode lọc màu xanh lá

                digitalWrite(4,HIGH);

                digitalWrite(5,HIGH);

                //Đọc tần số

                frequency = pulseIn(OutPut, LOW);

               //Hiển thị tần số màu xanh lá lên LCD

                lcd.print(frequency);

                lcd.print("    ");

                lcd.setCursor(0, 0);

                delay(100);        

}
