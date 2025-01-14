#include <stdio.h>
#include "pico/stdlib.h"

//Nesse ponto eu fiz as correções dos pinos
#define LED_R_PIN 13 //Define o LED vermelho 
#define LED_G_PIN 11 //Define o LED verde
#define LED_B_PIN 12 //Define o LED azul
#define BTN_A_PIN 5 //Define o botão A
#define BTN_B_PIN 6 //Define o botao B

//aceita três parâmetros booleanos e configura os pinos correspondentes para ligar ou desligar cada LED.
void set_leds(bool red, bool green, bool blue) {
    gpio_put(LED_R_PIN, red);
    gpio_put(LED_G_PIN, green);
    gpio_put(LED_B_PIN, blue);
}


int main()
{
    stdio_init_all();

    //Inicializa os pinos dos LEDs como saída
    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);

    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);

    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);

    //Inicializa os pinos dos botões como entrada
    gpio_init(BTN_A_PIN);
    gpio_set_dir(BTN_A_PIN, GPIO_IN);
    gpio_pull_up(BTN_A_PIN); //como boa pratica, alterei pra pull_up

    gpio_init(BTN_B_PIN);
    gpio_set_dir(BTN_B_PIN, GPIO_IN);
    gpio_pull_up(BTN_B_PIN); //como boa pratica, alterei pra pull_up

    //Loop para verificar estado dos botões e controlar LEDs
    while (true) {
    //Aqui eu alterei como o programa identifica se o botão foi acionado
        if(gpio_get(BTN_A_PIN) == 0 && gpio_get(BTN_B_PIN) == 0 ) { //verifica se botão A e B estão pressionados
            set_leds(1, 1, 1); // Todos os LEDS acesos (branco)
            printf("A e B Pressionado\n");

        } else if(gpio_get(BTN_A_PIN) == 0 ) { // verifica se o apenas o botão A estiver pressionado
            set_leds(1, 0, 0); //LED vermelho acesso
            printf("A Pressionado\n");

        } else if(gpio_get(BTN_B_PIN) == 0) { //verifica se botão B está pressionado
            set_leds(0, 1, 0); //LED verde aceso
            printf("B Pressionado\n");

        } else { // se nenhum botão estiver pressionado
            set_leds(0, 0, 1); //LED azul aceso
        }

        sleep_ms(100);

    }
    return 0;

}