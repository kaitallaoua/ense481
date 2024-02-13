/**
 *
 * DESCRIPTION:
 * main file for inplementings CLI for led on/off with window functionality
 *
 * AUTHOR: Karim Ait-Allaoua 200406520
 *
 **/

#include "CLI.h"
#include "io_control.h"
#include "measurement.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "timer.h"
#include "usart.h"

int main() {
    turn_on_clocks();
    configure_io();
    serial_open();
    timer_init();

		
	
    extern char input_buff[INPUT_BUFF_LEN];

    refresh_screen(1);
    CLI_transmit(prompt, strlen(prompt));

    while (1) {
        // blocks untill entire command is present
        CLI_receive();

        if (input_buff[0] != '\r') {
            if (strcmp(input_buff, time_cmd) == 0) {
                print_time();
            } else if (strcmp(input_buff, help_cmd) == 0) {
                CLI_transmit(help, strlen(help));

            } else {
                CLI_transmit(invalid_cmd, strlen(invalid_cmd));
                CLI_transmit(input_buff, strlen(input_buff));
            }
        }

        CLI_transmit(prompt, strlen(prompt));

        // screen is only refreshed after command is entered.
        // which is fine for this since led can't update otherwise
        // since this main loop blocks untill the entire command
        // is present. Fix this by making the refresh screen
        // use systick to refresh at regular intervals regardless of
        // what the main loop is doing
        refresh_screen(0);

        flush_buff(input_buff, INPUT_BUFF_LEN);

        // need to reable usart interrupt again to be receivering data
        USART2->CR1 |= USART_CR1_RXNEIE;
    }
}
