#include <Protocentral_ADS1220.h>
#include <SPI.h>

#define VREF 2.048            // Internal reference of 2.048V
#define FSR (((long int)1<<23)-1)

#define ADS1220_CS_PIN    7
#define ADS1220_DRDY_PIN  6

Protocentral_ADS1220 pc_ads1220;
int32_t adc_data;
int PGA = 1;                 // Programmable Gain = 1
float VFSR = VREF/PGA;

void setup(){
  
}

void loop(){
  
}

int init_adc(){   //Run this inside setup()
    pc_ads1220.begin(ADS1220_CS_PIN,ADS1220_DRDY_PIN);

    pc_ads1220.set_data_rate(DR_1000SPS);
    pc_ads1220.set_pga_gain(PGA_GAIN_1);

    pc_ads1220.set_conv_mode_single_shot(); //Set Single shot mode
}

long read_val_adc(int a){
  if(a > -1 && a < 5){
    if(a == 0){
      return pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH0);
    }
    else if(a==1){
      return pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH1);
    }
    else if(a==2){
      return pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH2);
    }
    else if(a==3){
      return pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH3);
    }
  }
  else{
    return -1;
  }
}

int set_gain(int a){
  PGA = a;
  pc_ads1220.set_pga_gain(PGA);
  return 0;
}
