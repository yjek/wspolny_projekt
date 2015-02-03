/*
 * osc.hpp
 *
 *  Created on: 29 sty 2015
 *      Author: zawisza
 */

#pragma once

#include "new.hpp"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

class ClockConfig
{
public:
	void Osc2MHz(void) {
		OSC.CTRL		=	OSC_RC2MEN_bm;					// włączenie oscylatora 2MHz
		while(!(OSC.STATUS & OSC_RC2MRDY_bm));				// czekanie na ustabilizowanie siê generatora
		CPU_CCP			=	CCP_IOREG_gc;					// odblokowanie zmiany źródła sygnału zegarowego
		CLK.CTRL		=	CLK_SCLKSEL_RC2M_gc;			// zmiana żródła sygnału zegarowego na RC 2MHz
	}

	void Osc32MHz(void) {
		OSC.CTRL		=	OSC_RC32MEN_bm;					// włączenie oscylatora 32MHz
		while(!(OSC.STATUS & OSC_RC32MRDY_bm));				// czekanie na ustabilizowanie się generatora
		CPU_CCP			=	CCP_IOREG_gc;					// odblokowanie zmiany źródła sygnału zegarowego
		CLK.CTRL		=	CLK_SCLKSEL_RC32M_gc;			// zmiana źródła sygnału zegarowego na RC 32MHz
	}

	void OscXtal(void) {

		// konfiguracja generatora kwarcowego
		OSC.XOSCCTRL	=	OSC_FRQRANGE_12TO16_gc |		// wybór kwarcu od 12 do 16 MHZ
				OSC_XOSCSEL_XTAL_16KCLK_gc;					// czas na uruchomienie generatora
		OSC.CTRL		=	OSC_XOSCEN_bm;					// uruchomienie generatora kwarcowego

		// czekanie na ustabilizowanie siê generatora
		for(uint8_t i=0; i<255; i++) {
			if(OSC.STATUS & OSC_XOSCRDY_bm) {
				CPU_CCP			=	CCP_IOREG_gc;			// odblokowanie zmiany źródła sygnału zegarowego
				CLK.CTRL		=	CLK_SCLKSEL_XOSC_gc;	// wybór źródła sygnału zegarowego na XTAL 16MHz

				// uk³ad nadzoruj¹cy kwarc
				CPU_CCP			=	CCP_IOREG_gc;			// odblokowanie modyfikacji wa¿nych rejestrów
				OSC.XOSCFAIL	=	OSC_XOSCFDEN_bm;		// w³¹czenie uk³adu detekcji b³êdu sygna³u zegarowego
				return;										// wyjcie z funkcji jeli generator siê uruchomi³
			}
			_delay_us(10);
		}

	}

	void OscPLL(uint8_t pllfactor) {
		// uruchomienie generatora 2MHz i ustawienie go jako ród³a zegara
		OSC.CTRL		=	OSC_RC2MEN_bm;					// w³¹czenie oscylatora 2MHz
		while(!(OSC.STATUS & OSC_RC2MRDY_bm));				// czekanie na ustabilizowanie siê generatora
		CPU_CCP			=	CCP_IOREG_gc;					// odblokowanie zmiany ród³a sygna³u zegarowego
		CLK.CTRL		=	CLK_SCLKSEL_RC2M_gc;			// zmiana ród³a sygna³u zegarowego na RC 2MHz

		// wy³¹czenie PLL
		OSC.CTRL		&= ~OSC_PLLEN_bm;

		// konfiguracja PLL
		OSC.PLLCTRL		=	OSC_PLLSRC_RC2M_gc |			// wybór RC 2MHz jako ród³o sygna³u dla PLL
				pllfactor;									// mnożnik czêstotliwości (od 1 do 31)

		// uruchomienie PLL
		OSC.CTRL		=	OSC_PLLEN_bm;					// włączenie układu PLL

		// czekanie na ustabilizowanie siê generatora
		while(!(OSC.STATUS & OSC_PLLRDY_bm));

		// prze³¹czenie ród³a sygna³u zegarowego
		CPU_CCP			=	CCP_IOREG_gc;					// odblokowanie zmiany ród³a sygna³u zegarowego
		CLK.CTRL		=	CLK_SCLKSEL_PLL_gc;				// wybór ród³a sygna³u zegarowego PLL

		// uk³ad nadzoruj¹cy PLL
		CPU_CCP			=	CCP_IOREG_gc;					// odblokowanie modyfikacji wa¿nych rejestrów
		OSC.XOSCFAIL	|=  1<<3;							// w³¹czenie uk³adu detekcji b³êdu sygna³u zegarowego
	}
};

ISR(OSC_XOSCF_vect) {									// przerwanie w razie awarii oscylatora
	OSC.XOSCFAIL	|=	OSC_XOSCFDIF_bm;				// kasowanie flagi przerwania
}
