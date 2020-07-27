#include <16f877.h>
#fuses xt,nowrt,nowdt,nobrownout,nolvp,nocpd,nodebug,noprotect,noput
#use delay(clock=4M)
#use rs232 (baud=600, xmit=pin_C6, rcv=pin_C7, parity=N, stop=1)
#use fast_io(b)

char e;

#int_rda

void int_rda_kesmesi()
{
   disable_interrupts(int_rda);
   
    if(getch()=='X')
    {
      delay_ms(5);
      e=getch();


       if(e=='W')  //ileri
       {
        output_high(pin_b0);
        output_low(pin_b1);
        output_high(pin_b2);
        output_low(pin_b3);
       }
        if(e=='S')  //geri
       {
        output_low(pin_b0);
        output_high(pin_b1);
        output_low(pin_b2);
        output_high(pin_b3);
        }
        if(e=='D') //saga don
        {
         output_high(pin_b0);
         output_low(pin_b1);
         output_low(pin_b2);
         output_high(pin_b3);
        }
        if(e=='A')  //sola don
        {
         output_low(pin_b0);
         output_high(pin_b1);
         output_high(pin_b2);
         output_low(pin_b3);
        }
        if(e=='C')  //DUR
        {
         output_low(pin_b0);
         output_low(pin_b1);
         output_low(pin_b2);
         output_low(pin_b3);
        }
         if(e=='R')  //gövde saga dön
        {
         output_high(pin_b4);
         output_low(pin_b5);
        }
        if(e=='L')  //gövde SOLA dön
        {
         output_low(pin_b4);
         output_high(pin_b5);
        }
         if(e=='F')  //atesleme
        {
         output_high(pin_b6);
         delay_ms(1000);
         output_low(pin_b6);
        }
     }
}

void main()

{

   setup_psp(PSP_DISABLED);        // PSP birimi devre dýþý
   setup_timer_2(T2_DISABLED,0,1); // T2 zamanlayýcýsý devre dýþý
   setup_adc_ports(NO_ANALOGS);    // ANALOG giriþ yok
   setup_adc(ADC_OFF);             // ADC birimi devre dýþý
   setup_CCP1(CCP_OFF);            // CCP1 birimi devre dýþý
   setup_CCP2(CCP_OFF);           // CCP2 birimi devre dýþý 
   setup_timer_1(T1_DISABLED); // Timer1 ayarlarý yapýlýyor

   set_tris_b(0x00);
   output_b(0x00);
   enable_interrupts(GLOBAL);
   
    while(1)
    {
     enable_interrupts(int_rda); // int_rda kesmesi aktif
    }
}

