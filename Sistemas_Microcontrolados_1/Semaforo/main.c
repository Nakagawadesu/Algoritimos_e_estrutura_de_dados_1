#include <msp430g2553.h>
/*
volatile long INITIAL_DELAY = 0;   // DELAY INICIAL DA VARIAVEL DO CONTADOR
volatile long GREEN_LED = 900000;  // TEMPO QUE O LED VERDE FICA ACESO
volatile long YELLOW_LED = 112500; //TEMPO QUE O LED AMARELO FICA ACESO
volatile long LED_VERIFICATION_DELAY = 50000; // DELAY INICIAL DO PROGRAMA, USADO PARA VERIFICAR TODOS OS LEDS

 */

void INIT_PORTS(void); //DECLARAÇÃO DO PROTÓTIPO DA FUNÇÃO PARA INICIAR AS PORTAS
void SET_PORTS(void);

int STATE = 1 ;
int STATE_CHECK = 0;//variavel global para setar o estado de interupt
int delay_break = 8;
int delay_red = 10;
int delay_yellow = 2;
int delay_green = 8;

int t = 0;

int current_state = 1 ;// O NUMERO CORRESPONDE AO ESTADO 1,2,3 e 4
int INTERRUPT_FLAG = 1;


void check_state(int Next_state, int t ,int stop)
{


    if(STATE_CHECK == 1)// ocorreu interrupção
    {
        Next_state = INTERRUPT_FLAG;
        STATE_CHECK = 0;
        current_state = Next_state;

        t = stop;


    }


}

void main(void) {
    SET_CLOCK();

    __enable_interrupt(); //HABILITA AS REQUISIÇÕES DE INTERRUPÇÃO PARA A CPU
    INIT_PORTS();



    while (1) {
        for (t = 0 ; t <= 20 ; t++)
        {
            __delay_cycles(16000000);
            if(t<=8)
            {
                STATE = 1;
            }
            else if(t > 8 && t <= 10){
                STATE = 2;
            }
            else if(t > 10 && t <= 18){
                STATE = 3;
            }
            else if(t > 18 && t <= 20){
                STATE = 4;
                        }

            switch (STATE) {
            case  1:  //SEMAFORO 1 VERMELHO // SEMAFORO 2 VERDE
            if(STATE_CHECK == 1)
            {
                STATE = 2;
                t = 9;
                STATE_CHECK = 0 ;
            }
            //PRIMEIRO SEMAFORO
            P1OUT |= BIT4; //LIGA O LED VERMELHO EM P1.4

            P1OUT &= ~BIT5; //DESLIGA O LED AMARELO EM P1.5

            P1OUT &= ~BIT6; //DESLIGA O LED VERDE EM P1.6

            //SEGUNDO SEMAFORO
            P2OUT &= ~BIT0; //DESLIGA O LED VERMELHO EM P2.0

            P2OUT &= ~BIT1; //DESLIGA O LED AMARELO EM P2.1

            P2OUT |= BIT2; //LIGA O LED VERDE EM P2.2



            break;

            case 2:  //SEMAFORO 1 VERMELHO, SEMAFORO 2 AMARELO
            if(STATE_CHECK == 1)
            {
                STATE = 2;
                STATE_CHECK = 0 ;
            }
            //PRIMEIRO SEMAFORO
            P1OUT |= BIT4; //LIGA O LED VERMELHO EM P1.4

            P1OUT &= ~BIT5; //DESLIGA O LED AMARELO EM P1.5

            P1OUT &= ~BIT6; //DESLIGA O LED VERDE EM P1.6

            //SEGUNDO SEMAFORO
            P2OUT &= ~BIT0; //DESLIGA O LED VERMELHO EM P2.2

            P2OUT |= BIT1; //LIGA O LED AMARELO EM P2.1

            P2OUT &= ~BIT2; //DESLIGA O LED VERDE EM P2.2




            break;

            case 3: //SEMAFORO 1 VERDE // SEMAFORO 2 VERMELHO
            if(STATE_CHECK == 1)
            {
                STATE = 4;
                t = 19;
                STATE_CHECK = 0 ;
            }

            //PRIMEIRO SEMAFORO
            P1OUT &= ~BIT4; // DESLIGA O LED VERMELHO EM P1.4

            P1OUT &= ~BIT5; //DESLIGA O LED AMARELO EM P1.5

            P1OUT |= BIT6; //LIGA O LED VERDE EM P1.6

            //SEGUNDO SEMAFORO
            P2OUT |= BIT0; //LIGA O LED VERMELHO EM P2.0

            P2OUT &= ~BIT1; //DESLIGA O LED AMARELO EM P2.1

            P2OUT &= ~BIT2; //DESLIGA O LED VERDE EM P2.2




            break;

            case 4:  // SEMAFORO 1 AMARELO // SEMAFORO 2 VERMELHO
            if(STATE_CHECK == 1)
            {

                STATE = 4;
                STATE_CHECK = 0 ;
            }

            //PRIMEIRO SEMAFORO
            P1OUT &= ~BIT4; //DESLIGA O LED VERMELHO EM P1.3

            P1OUT |= BIT5;  //LIGA O LED AMARELO EM P1.5

            P1OUT &= ~BIT6; //DESLIGA O LED VERDE EM P1.6

            //SEGUNDO SEMAFORO
            P2OUT |= BIT0;  // LIGA O LED VERDE DE P2.0

            P2OUT &= ~BIT1; //DESLIGA O LED AMARELO DE P2.1

            P2OUT &= ~BIT2; //DESLIGA O LED VERDE DE P2.2


            if (t == 20)
            {
                t=0;
            }

            break;
            }

        }


    }


}

void INIT_PORTS(void) { //FUNÇÃO PARA INICIALIZAÇÃO DAS PORTAS

    P1DIR &= ~BIT3; // DEFINE P1.3 COMO ENTRADA
    P1IE |= BIT3; // HABILITA A INTERRUPÇÃO EM P1.3
    P1IES &= ~BIT3; //CONFIGURA A INTERRUPÇÃO COMO BORDA DE SUBIDA EM P1.3
    P1IFG &= ~BIT3; // LIMPA A FLAG DE INTERRUPÇÃO EM P1.3
    P1REN = BIT3;
    P1OUT = BIT3;

    P1DIR |= BIT4;  //CONFIGURA A DIREÇÃO DE P1.4    //    LED VERMELHO SEMAFORO 1
    P1OUT |= BIT4;

    P1DIR |= BIT5;  //CONFIGURA A DIREÇÃO DE P2.5    //    LED AMARELO SEMAFORO 1
    P1OUT |= BIT5;

    P1DIR |= BIT6;  //CONFIGURA A DIREÇÃO DE P2.6    //    LED VERDE SEMAFORO 1
    P1OUT |= BIT6;

    P2DIR |= BIT0;  //CONFIGURA A DIREÇÃO DE P2.0    //    LED VERMELHO SEMAFORO 2
    P2OUT |= BIT0;

    P2DIR |= BIT1;  //CONFIGURA A DIREÇÃO DE P2.1    //    LED AMARELO SEMAFORO 2
    P2OUT |= BIT1;

    P2DIR |= BIT2;  //CONFIGURA A DIREÇÃO DE P2.2    //    LED VERDE SEMAFORO 2
    P2OUT |= BIT2;


}

void SET_CLOCK(){
    WDTCTL = WDTPW | WDTHOLD; // Para o contador do watchdog timer
    // Configuracoes do BCS
    // MCLK = DCOCLK ~ 16 MHz
    // ACLK = LFXT1CLK = 32768 Hz
    // SMCLK = DCOCLK / 8 ~ 2 MHz
    DCOCTL = CALDCO_16MHZ; // Freq. Calibrada de 16 MHz
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1; // Fator divisao = 8 para SMCLK
    BCSCTL3 = XCAP0 + XCAP1; // Capacitor do cristal ~12.5 pF
    while(BCSCTL3 & LFXT1OF);
}


#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
    P1IFG &= ~BIT3; // LIMPA A FLAG DE INTERRUPÇÃO DE P1.3

    STATE_CHECK  = 1;  // PULA PARA O ESTADO 2



}
