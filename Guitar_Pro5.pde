import ddf.minim.*;

import processing.serial.*;


Serial port;
Minim minim;

AudioPlayer play1;
AudioPlayer play2;
AudioPlayer play3;
AudioPlayer play4;

AudioPlayer play12;
AudioPlayer play22;
AudioPlayer play32;
AudioPlayer play42;

AudioPlayer play13;
AudioPlayer play23;
AudioPlayer play33;
AudioPlayer play43;

String data;

int val;

String val_str;

void setup()
{
  size(512, 200, P3D);
  minim = new Minim(this);

  play1 = minim.loadFile( "1.wav");
  play2 = minim.loadFile( "2.wav");                         
  play3 = minim.loadFile( "3.wav");
  play4 = minim.loadFile( "4.wav");
 


  play12 = minim.loadFile( "12.wav");
  play22 = minim.loadFile( "22.wav");                         
  play32 = minim.loadFile( "32.wav");
  play42 = minim.loadFile( "42.wav");
 
 
  play13 = minim.loadFile( "13.wav");
  play23 = minim.loadFile( "23.wav");                         
  play33 = minim.loadFile( "33.wav");
  play43 = minim.loadFile( "43.wav");
 

  printArray(Serial.list());
  port = new Serial(this, Serial.list()[3], 9600);
  port.bufferUntil('\n');
}

void draw()
{
}

void serialEvent(Serial port)
{
  while (port.available() > 0)
  {

    val_str = port.readStringUntil('\n');
    val_str = trim(val_str);
    val = parseInt(val_str);

    println(val_str);

    if (val == 1  )
    {
      play1.rewind();
      play1.play();
      //     play1.setGain(realVolume);
    }
    if (val == 2 )
    {
      play2.rewind();
      play2.play();
      //      play2.setGain(realVolume);
    }
    if (val == 3 )
    {
      play3.rewind();
      play3.play();
      //     play3.setGain(realVolume);
    }
    if (val == 4 )
    {
      play4.rewind();
      play4.play();
      //     play4.setGain(realVolume);
    }
    
    if (val == 12 )
    {
      play12.rewind();
      play12.play();
      //play12.setGain(realVolume);
    }
    if (val == 22 )
    {
      play22.rewind();
      play22.play();
      //     play22.setGain(realVolume);
    }
    if (val == 32 )
    {
      play32.rewind();
      play32.play();
      //     play32.setGain(realVolume);
    }
    if (val == 42 )
    {
      play42.rewind();
      play42.play();
      //     play42.setGain(realVolume);
    }
    
    if (val == 13 )
    {
      play13.rewind();
      play13.play();
      //play12.setGain(realVolume);
    }
    if (val == 23 )
    {
      play23.rewind();
      play23.play();
      //     play22.setGain(realVolume);
    }
    if (val == 33 )
    {
      play33.rewind();
      play33.play();
      //     play32.setGain(realVolume);
    }
    if (val == 43 )
    {
      play43.rewind();
      play43.play();
      //     play42.setGain(realVolume);
    }
    
    else {
    }
  }
    //delay(2200);
}