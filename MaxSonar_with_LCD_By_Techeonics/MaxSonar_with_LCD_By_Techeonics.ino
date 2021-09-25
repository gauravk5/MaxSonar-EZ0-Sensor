/*...........................................................
Techeonics

MaxSonar PWM Code ( With LCD )
Created 15-2-2021
 
By Gaurav Kumar (Techeonics) 
<thetecheonics@gmail.com>

See <http://www.techeonics.com> for details.

*/
#include <LiquidCrystal_I2C.h> // Library for LCD
#include "SonarEZ0pw.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

SonarEZ0pw Sonar(7); // pin D7
float cm_dis=0.00;
float Inch_dis=0.00;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
lcd.init(); // initialize the lcd
lcd.backlight();
}

void loop() {
// put your main code here, to run repeatedly:
cm_dis= Sonar.Distance(cm); // To calculate the distance in cm
Inch_dis=Sonar.Distance(inch);// To calculate the distance in Inch
Serial.println("Distance " );
//Serial.print(Inch_dis);
//Serial.println(" inch ");
Serial.print(cm_dis);
Serial.println(" cm ");
delay(500);

lcd.setCursor(0, 0);
  lcd.print("Distance: "); 
  lcd.print(cm_dis);
  lcd.setCursor(3, 1);
  lcd.print("Techeonics"); 
}
