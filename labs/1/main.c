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
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "usart.h"
#include "timer.h"
#include "measurement.h"

int main() {
    turn_on_clocks();
    configure_io();
    serial_open();
		timer_init();
	
		while (1) {
			
			print_time();
			
		}
		
}
