{
  //A32-GDEY0154D67-FP-20221013\GDEY0154D67_Arduino\GDEY0154D67_Arduino.ino
#if 0   
  writecommand(0xFD); // COMMANDLOCK
  writedata(0x12);
  writecommand(0xFD); // COMMANDLOCK
  writedata(0xB1);
  writecommand(0xAE); // DISPLAYOFF
  writecommand(0xB3); // CLOCKDIV
  writedata(0xF1);
  writecommand(0xCA); // MUXRATIO
  writedata(127);
  writecommand(0xA2); // DISPLAYOFFSET
  writedata(0x00);
  writecommand(0xB5); // SETGPIO
  writedata(0x00);
  writecommand(0xAB); // FUNCTIONSELECT
  writedata(0x01);
  writecommand(0xB1); // PRECHARGE
  writedata(0x32);
  writecommand(0xBE); // VCOMH
  writedata(0x05);
  writecommand(0xA6); // NORMALDISPLAY
  writecommand(0xC1); // CONTRASTABC
  writedata(0xC8);
  writedata(0x80);
  writedata(0xC8);
  writecommand(0xC7); // CONTRASTMASTER
  writedata(0x0F);
  writecommand(0xB4); // SETVSL
  writedata(0xA0);
  writedata(0xB5);
  writedata(0x55);
  writecommand(0xB6); // PRECHARGE2
  writedata(0x01);
  writecommand(0xAF); // DISPLAYON
#endif
  int BUSY_Pin = A14; 
  int RES_Pin = A15; 
  int DC_Pin = A16; 
  int CS_Pin = A17;

  #define EPD_W21_CS_0 digitalWrite(CS_Pin,LOW)
  #define EPD_W21_CS_1 digitalWrite(CS_Pin,HIGH)
  #define EPD_W21_DC_0  digitalWrite(DC_Pin,LOW)
  #define EPD_W21_DC_1  digitalWrite(DC_Pin,HIGH)
  #define EPD_W21_RST_0 digitalWrite(RES_Pin,LOW)
  #define EPD_W21_RST_1 digitalWrite(RES_Pin,HIGH)
  #define isEPD_W21_BUSY digitalRead(BUSY_Pin)
#if 0 // EPD_HW_Init()
  writecommand(0x01); //Driver output control      
  writedata(0xC7);
  writedata(0x00);
  writedata(0x00);

  writecommand(0x11); //data entry mode       
  writedata(0x01);

  writecommand(0x44); //set Ram-X address start/end position   
  writedata(0x00);
  writedata(0x18);    //0x0C-->(18+1)*8=200

  writecommand(0x45); //set Ram-Y address start/end position          
  writedata(0xC7);   //0xC7-->(199+1)=200
  writedata(0x00);
  writedata(0x00);
  writedata(0x00); 

  writecommand(0x3C); //BorderWavefrom
  writedata(0x05);  
      
  writecommand(0x18); //Reading temperature sensor
  writedata(0x80);  

  writecommand(0x4E);   // set RAM x address count to 0;
  writedata(0x00);
  writecommand(0x4F);   // set RAM y address count to 0X199;    
  writedata(0xC7);
  writedata(0x00);
#endif
#if 1 // EPD_HW_Init_Fast()
  writecommand(0x12);  //SWRESET
  //Epaper_READBUSY();   
  
  writecommand(0x18); //Read built-in temperature sensor
  writedata(0x80);  
      
  writecommand(0x22); // Load temperature value
  writedata(0xB1);    
  writecommand(0x20); 
  //Epaper_READBUSY();   

  writecommand(0x1A); // Write to temperature register
  writedata(0x64);    
  writedata(0x00);  
            
  writecommand(0x22); // Load temperature value
  writedata(0x91);    
  writecommand(0x20); 
  //Epaper_READBUSY();   
#endif
}
