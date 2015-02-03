

#include "new.hpp"

#ifdef __cplusplus

// new i new[]
void * operator new(size_t size) {
	return malloc(size);
}

void * operator new[](size_t size) {
	return malloc(size);
}

// delete i delete[]
void operator delete(void* ptr) {
	free(ptr);
}

void operator delete[](void* ptr) {
	free(ptr);
}

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);}
void __cxa_guard_release (__guard *g) {*(char *)g = 1;}
void __cxa_guard_abort (__guard *) {}

void __cxa_pure_virtual(void) {}

#endif // __cplusplus
