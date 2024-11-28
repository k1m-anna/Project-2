// testing out the servo (Venti 1)

# include <Servo.h>

Servo oneVentiServo;

void setup()
{
  oneVentiServo.attach(9);
  oneVentiServo.write(0);
}

void loop()
{
  //nothing
}