#include "nRF24L01.h" // nRF24L01 kütüphanesini ekledik
#include "RF24.h" / /RF24 kütüphanesini ekledik   
#include "SPI.h" // SPI kütüphanesini ekledik

#define led 5 // ledimizin pinini tanımladık

int ReceivedMessage[1] = {000}; // alınan mesaj adında bir değişken oluşturduk ve değerini 000 olarak tanımladık

RF24 radio(9,10); // nRF24L01 'in kullandığı pinleri tanımladık 9. pin CE, 10. pin CSN

const uint64_t pipe = 0xE6E6E6E6E6E6; // nRF24L01'lerin arasında haberleşmesi için kanal oluşturduk


void setup(){
pinMode(led,OUTPUT); // ledimizin çıkış olduğunu bildirdik
radio.begin(); // nRF24L01'i başlattık
radio.openReadingPipe(1,pipe); // nRF24L012'i haberleşmeye hazır duruma getirdik
radio.startListening(); // veri almak için dinleme(ortamdaki kablosuz radyo sinyallerini algılama)yapması gerektiğini söyledik
}

void loop(){

while (radio.available()) // bağlantının müsait olduğunu zaman boyunca
{
radio.read(ReceivedMessage, 1); // diğer nFR24L01'den bilgileri al

if (ReceivedMessage[0] == 222) // eğer alınan mesaj değişkeni 111 ise
{
  digitalWrite(led,HIGH); // ledi yak

}
else // eğer alınan mesaj değişkeni 111 değilse 
{
  digitalWrite(led,LOW); // ledi söndür
}
}
}
