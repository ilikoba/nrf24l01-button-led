
#include "nRF24L01.h" // nRF24L01 kütüphanesini ekledik
#include "RF24.h" / /RF24 kütüphanesini ekledik   
#include "SPI.h" // SPI kütüphanesini ekledik

#define buton 7 // butonumuzun pinini tanımladık
int SentMessage[1] = {000}; // gönderilen mesaj adında bir deişken oluşturduk ve değerini 000 olarak tanımladık

RF24 radio(9,10); // nRF24L01 'in kullandığı pinleri tanımladık 9. pin CE, 10. pin CSN

const uint64_t pipe = 0xE6E6E6E6E6E6; // nRF24L01'lerin arasında haberleşmesi için kanal oluşturduk


void setup(){
pinMode(buton, INPUT_PULLUP); // butonumuzun giriş olduğunu bildirdik
digitalWrite(buton,HIGH); // butonumuzun basılı olmamasını sağladık
radio.begin(); // nRF24L01'i başlattık
radio.openWritingPipe(pipe); // nRF24L012'i haberleşmeye hazır duruma getirdik
}

void loop(){

if (digitalRead(buton) == LOW){ // eğer butona basılırda
SentMessage[0] = 111; // mesaj değişkeninin değerini 111 olarak tanımladık
radio.write(SentMessage, 1); // 111 yaptığımız mesaj değişkenini diğer nRF24L01'in alması için gönderdik
}
else // eğer butona basılmazsa
{
  SentMessage[0] = 000; // mesaj değişkeni 000 olarak kalddın
  radio.write(SentMessage, 1); // 000 yaptığımız mesaj değişkenini diğer nRF24L01'in alması için gönderdik
}

}
