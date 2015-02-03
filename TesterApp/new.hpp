/*
 * new.hpp
 *
 *  Created on: 29 sty 2015
 *      Author: zawisza
 */

#pragma once
//
// avr-libc nie dostarcza operatorów new i delete.
// Ma także problemy z definicją obsługi dziedziczenia i dziedziczenia
// wirtualnego. Plik poprawia te problemy.
//

#include <stdlib.h>

#ifdef __cplusplus

// Operatory new, new[]
extern void * operator new(size_t size);
extern void * operator new[](size_t size);

// Operatory delete i delete[]
extern void operator delete(void *ptr);
extern void operator delete[](void *ptr);

// Obsługa dziedziczeń i dziedziczeń wirtualnych...
__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);

extern "C" void __cxa_pure_virtual(void);

#endif // __cplusplus
