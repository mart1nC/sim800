 #include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); //RX y TX
//SoftwareSerial mySerial(2, 3); //RX y TX

String url="http://preemar.mx/php/registrar.php?di=";
String datos="P21SA0318&tem=79&sal=240&ph=6&ni=477&ox=5&tu=3.0";

void setup() {
 /* Serial.begin(9600);  //Iniciamos la comunicacion serie
  mySerial.begin(9600); //Iniciamps a segunda comunicacion serie */
  Serial.begin(115200);  //Iniciamos la comunicacion serie
  mySerial.begin(57600); //Iniciamps a segunda comunicacion serie 
  pinMode(4 ,OUTPUT);  
  digitalWrite(4,LOW);//le mandamos un bajo en reset 
  delay(800);//Detenemos 0.8 segundos 
  digitalWrite(4,HIGH); //Activamos reset 
  delay(5000);
  mySerial.println("AT+CPOF");
  delay(1000);
  mySerial.println("AT+CGATT?");
  delay(1000);
  mySerial.println("AT+CGATT=1");
  delay(1000);
  digitalWrite(4,LOW);//le mandamos un bajo en reset 
  delay(800);//Detenemos 0.8 segundos 
  digitalWrite(4,HIGH); //Activamos reset 
  delay(5000);
}

void loop() {
  if (mySerial.available()){     
     Serial.write(mySerial.read());
  }
  if (Serial.available()){
     while(Serial.available()) {
        mySerial.write(Serial.read());
     }
     mySerial.println();
  }
}

 
