#include <Wire.h>
#include <Adafruit_ADS1015.h>

float Multiplier = 0.1875;

Adafruit_ADS1115 ads;
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////REMEMBER THIS. CAUTION ADVICED./////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

int init_adc()
{
  ads.begin();
}

long read_val_adc(int a) // If a = 1, gives V_(01) else if a = 2, gives V_(23)
{
  if(a == 1)
  {
    return ads.readADC_Differential_0_1();
  }
  else if(a == 2)
  {
    return ads.readADC_Differential_2_3();
  }
  else
  {
    return -1;
  }
}

int set_gain(int a)
{
  //                                            Maximum Voltage              Least Count / Multiplier
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V        a = 1      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V        a = 2      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V        a = 3      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V        a = 4      0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V        a = 5      0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V        a = 6      0.0078125mV

  if(a == 1){
    ads.setGain(GAIN_TWOTHIRDS);
    Multiplier = 0.1875;
  }
  else if(a == 2){
    ads.setGain(GAIN_ONE);
    Multiplier = 0.125;
  }
  else if(a == 3){
    ads.setGain(GAIN_TWO);
    Multiplier = 0.0625;
  }
  else if(a == 4){
    ads.setGain(GAIN_FOUR);
    Multiplier = 0.03125;
  }
  else if(a == 5){
    ads.setGain(GAIN_EIGHT);
    Multiplier = 0.015625;
  }
  else if(a == 6){
    ads.setGain(GAIN_SIXTEEN);
    Multiplier = 0.0078125;
  }
  else{
    return -1;
  }
  return 0;
}

void setup(void)
{
}

void loop(void)
{
}
