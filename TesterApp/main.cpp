#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <avr/io.h>


#include "osc.hpp"
#include "fixedpoint/fixed_class.h"

int main(void) {
	auto clock = new ClockConfig;
	clock->OscPLL(16);
	delete clock;

	fixedpoint::fixed_point<16> myPoint;
	fixedpoint::fixed_point<16> mySPoint;

	// konfiguracja przerwañ
	TCC0.INTCTRLA	=	TC_OVFINTLVL_LO_gc;			// przepe³nienie ma generowaæ przerwanie LO
	PMIC.CTRL		=	PMIC_LOLVLEN_bm;			// odblokowanie przerwañ o priorfytecie LO
	sei();											// globalne odblokowanie przerwañ

	// konfiguracja timera
	TCC0.CTRLB		=	TC_WGMODE_NORMAL_gc;		// tryb normalny
//	TCC0.CTRLFSET	=	TC0_DIR_bm;					// liczenie w dó³
	TCC0.CTRLA		=	TC_CLKSEL_DIV1_gc;			// ustawienie preskalera i uruchomienie timera


	while(1){
		myPoint = fixedpoint::fixed_point<16>((int32_t)PORTA_IN);
		myPoint =  myPoint+1;
		mySPoint = myPoint / mySPoint;
		PORTA_DIR = myPoint.intValue & 0xff;
	}
}

