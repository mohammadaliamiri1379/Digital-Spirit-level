#include <Wire.h>
int ADXL345 = 0x53;
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;

LedControl lc=LedControl(DIN,CLK,CS,0);

float x, y;  // Outputs
#define z_  10
Adafruit_ADXL345_Unified accel (54321);
byte ok[8]=  {0x00,0x09,0xFA,0x9C,0x9C,0xFA,0x09,0x00,};

 byte f1[8]=  {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,};
 byte f2[8]=  {0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00,};  
 byte f3[8]=  {0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,};  
 byte f4[8]=  {0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x18,};  
 byte f5[8]=  {0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,};  
 byte f6[8]=  {0x00,0x00,0x00,0x1E,0x1E,0x00,0x00,0x00,};  
 byte f7[8]=  {0x00,0x00,0x00,0x1F,0x1F,0x00,0x00,0x00,};  
 byte f8[8]=  {0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00,};  
 byte f9[8]=  {0x00,0x18,0x18,0x18,0x18,0x00,0x00,0x00,};  
 byte f10[8]=  {0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00,};  
 
 byte f11[8]=  {0x00,0x00,0x00,0x38,0x38,0x00,0x00,0x00,};  
 byte f12[8]=  {0x00,0x00,0x00,0x78,0x78,0x00,0x00,0x00,};  
 byte f13[8]=  {0x00,0x00,0x00,0xF8,0xF8,0x00,0x00,0x00,};  
 
 byte f23[8]=  {0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00,};  
 byte f24[8]=  {0x00,0x1C,0x1C,0x1C,0x1C,0x00,0x00,0x00,};  
 byte f25[8]=  {0x1C,0x1C,0x1C,0x1C,0x1C,0x00,0x00,0x00,};  
 
 byte f26[8]=  {0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00,0x00,};  
 byte f27[8]=  {0x00,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,};  
 byte f28[8]=  {0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,};  
 
 byte f29[8]=  {0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,0x00,};  
 byte f30[8]=  {0x00,0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,};  
 byte f31[8]=  {0x1F,0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,};  
 //
 byte f14[8]=  {0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,};  
 byte f15[8]=  {0x00,0x00,0x00,0x1C,0x1C,0x1C,0x1C,0x00,};  
 byte f16[8]=  {0x00,0x00,0x00,0x1C,0x1C,0x1C,0x1C,0x1C,};  
 
 byte f17[8]=  {0x00,0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00,};  
 byte f18[8]=  {0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x00,};  
 byte f19[8]=  {0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x1E,};  
 
 byte f20[8]=  {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,};  
 byte f21[8]=  {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x00,};  
 byte f22[8]=  {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,};  
 //
 byte f41[8]=  {0x00,0x00,0x00,0x38,0x38,0x38,0x00,0x00,};  
 byte f42[8]=  {0x00,0x00,0x00,0x38,0x38,0x38,0x38,0x00,};  
 byte f43[8]=  {0x00,0x00,0x00,0x38,0x38,0x38,0x38,0x38,};
   
 byte f44[8]=  {0x00,0x00,0x00,0x78,0x78,0x78,0x00,0x00,};  
 byte f45[8]=  {0x00,0x00,0x00,0x78,0x78,0x78,0x78,0x00,};  
 byte f46[8]=  {0x00,0x00,0x00,0x78,0x78,0x78,0x78,0x78,};  
 
 byte f47[8]=  {0x00,0x00,0x00,0xF8,0xF8,0xF8,0x00,0x00,};  
 byte f48[8]=  {0x00,0x00,0x00,0xF8,0xF8,0xF8,0xF8,0x00,};  
 byte f49[8]=  {0x00,0x00,0x00,0xF8,0xF8,0xF8,0xF8,0xF8,};  
 ///
 byte f32[8]=  {0x00,0x00,0x38,0x38,0x38,0x00,0x00,0x00,};  
 byte f33[8]=  {0x00,0x38,0x38,0x38,0x38,0x00,0x00,0x00,};  
 byte f34[8]=  {0x38,0x38,0x38,0x38,0x38,0x00,0x00,0x00,};  
 
 byte f35[8]=  {0x00,0x00,0x78,0x78,0x78,0x00,0x00,0x00,};  
 byte f36[8]=  {0x00,0x78,0x78,0x78,0x78,0x00,0x00,0x00,};  
 byte f37[8]=  {0x78,0x78,0x78,0x78,0x78,0x00,0x00,0x00,};  
 
 byte f38[8]=  {0x00,0x00,0xF8,0xF8,0xF8,0x00,0x00,0x00,};  
 byte f39[8]=  {0x00,0xF8,0xF8,0xF8,0xF8,0x00,0x00,0x00,};  
 byte f40[8]=  {0xF8,0xF8,0xF8,0xF8,0xF8,0x00,0x00,0x00,};  
void setup() {
   lc.shutdown(0,false);
 lc.setIntensity(0,13);
 lc.clearDisplay(0);
  Serial.begin(9600); 
  Serial.println("Accelerometer Test"); Serial.println("");
  pinMode(z_ , 1);
  if (!accel.begin())
  {
    Serial.println(" no ADXL345 detected ... Check your wiring!");
    while (1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
  accel.setDataRate(ADXL345_DATARATE_25_HZ);
  Wire.begin();
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  delay(10);
}
void loop() {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);
  x = ( Wire.read()| Wire.read() << 8); // X-axis value
  x = x*70/256;
  y = ( Wire.read()| Wire.read() << 8); // Y-axis value
  y = y*70/256;
  
  Serial.print("Xa= ");
  Serial.print(x);
  Serial.print("   Ya= ");
  Serial.println(y);

    if ( x<3 && x>-3 && y <=3 && y>-3)
    {
      printByte(ok);
    }
     else if ( x<10 && x>-10 && y <=10 && y>-10)
    {
      printByte(f1);
    }
    
if ( x<10 && x>-10 && y >10 && y<30 )
    {
         printByte(f2) ;
    }
if ( x<10 && x>-10 && y >30 && y<50 )
    {
         printByte(f3) ;
    }
if ( x<10 && x>-10 && y >50 && y<70 )
    {
         printByte(f4) ;
    }
if ( x<-10 && x>-30 && y >-10 && y<10 )
    {
         printByte(f5) ;
    }
    if ( x<-30 && x>-50 && y >-10 && y<10 )
    {
         printByte(f6) ;
    }
    if ( x<-50 && x>-70 && y >-10 && y<10 )
    {
         printByte(f7) ;
    }
    if ( x<10 && x>-10 && y >-30 && y<-10 )
    {
         printByte(f8) ;
    }
   if ( x<10 && x>-10 && y >-50 && y<-30 )
    {
         printByte(f9) ;
    }
    if ( x<10 && x>-10 && y >-50 && y<-70 )
    {
         printByte(f10) ;
    }
 if ( x<30 && x>10 && y >-10 && y<10 )
    {
         printByte(f11) ;
    }
    if ( x<50 && x>30 && y >-10 && y<10 )
    {
         printByte(f12) ;
    }
    if ( x<70 && x>50 && y >-10 && y<10 )
    {
         printByte(f13) ;
    }  
    ///////
    if ( x<-10 && x>-30 && y >10 && y<30 )
    {
         printByte(f14) ;
    }
    if ( x<-10 && x>-30 && y >30 && y<50 )
    {
         printByte(f15) ;
    }
    if ( x<-10 && x>-30 && y >50 && y<70 )
    {
         printByte(f16) ;
    }
    
    if ( x<-30 && x>-50 && y >10 && y<30 )
    {
         printByte(f17) ;
    }
     if ( x<-30 && x>-50 && y >30 && y<50 )
    {
         printByte(f18) ;
    }
     if ( x<-30 && x>-50 && y >50 && y<70 )
    {
         printByte(f19) ;
    }
     
     if ( x<-50 && x>-70 && y >10 && y<30 )
    {
         printByte(f20) ;
    }
     if ( x<-50 && x>-70 && y >30 && y<50 )
    {
         printByte(f21) ;
    }
     if ( x<-50 && x>-70 && y >50 && y<70 )
    {
         printByte(f22) ;
    }
    //////
   if ( x<-10 && x>-30 && y >-30 && y<-10 )
    {
         printByte(f23) ;
    }
      if ( x<-10 && x>-30 && y >-50 && y<-30 )
    {
         printByte(f24) ;
    }
      if ( x<-10 && x>-30 && y >-70 && y<-50 )
    {
         printByte(f25) ;
    }

      if ( x<-30 && x>-50 && y >-30 && y<-10 )
    {
         printByte(f26) ;
    }
     if ( x<-30 && x>-50 && y >-50 && y<-30 )
    {
         printByte(f27) ;
    }
     if ( x<-30 && x>-50 && y >-70 && y<-50 )
    {
         printByte(f28) ;
    }
     if ( x<-50 && x>-70 && y >-30 && y<-10 )
    {
         printByte(f29) ;
    }
     if ( x<-50 && x>-70 && y >-50 && y<-30 )
    {
         printByte(f30) ;
    }
     if ( x<-50 && x>-70 && y >-70 && y<-50 )
    {
         printByte(f31) ;
    }
    /////////////
    
     if ( x<30 && x>10 && y >-30 && y<-10 )
    {
         printByte(f32) ;
    }
     if ( x<30 && x>10 && y >-50 && y<-30 )
    {
         printByte(f33) ;
    }
     if ( x<30 && x>10 && y >-70 && y<-50 )
    {
         printByte(f34) ;
    }
     if ( x<50 && x>30 && y >-30 && y<-10 )
    {
         printByte(f35) ;
    }
    if ( x<50 && x>30 && y >-50 && y<-30 )
    {
         printByte(f36) ;
    }
    if ( x<50 && x>30 && y >-70 && y<-50 )
    {
         printByte(f37) ;
    }
    if ( x<70 && x>50 && y >-30 && y<-10 )
    {
         printByte(f38) ;
    }
     if ( x<70 && x>50 && y >-50 && y<-30 )
    {
         printByte(f39) ;
    }
     if ( x<70 && x>50 && y >-70 && y<-50 )
    {
         printByte(f40) ;
    }
    /////////
    if ( x<30 && x>10 && y >10 && y<30 )
    {
         printByte(f41) ;
    }
    if ( x<30 && x>10 && y >30 && y<50 )
    {
         printByte(f42) ;
    }
    if ( x<30 && x>10 && y >50 && y<70 )
    {
         printByte(f43) ;
    }
    if ( x<50 && x>30 && y >10 && y<30 )
    {
         printByte(f44) ;
    }
    if ( x<50 && x>30 && y >30 && y<50 )
    {
         printByte(f45) ;
    }
    if ( x<50 && x>30 && y >50 && y<70 )
    {
         printByte(f46) ;
    }
    if ( x<70 && x>50 && y >10 && y<30 )
    {
         printByte(f47) ;
    }
    if ( x<70 && x>50 && y >30 && y<50 )
    {
         printByte(f48) ;
    }
    if ( x<70 && x>50 && y >50 && y<70 )
    {
         printByte(f49) ;
    }

    // finish 
}

  void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
    
  }
}
