
#include "RefBase.h"
#include <Windows.h>



namespace base
{



int AtomicOps::Increment(int* i) 
{
	return ::InterlockedIncrement(reinterpret_cast<LONG*>(i));
}


int AtomicOps::Decrement(int* i) 
{
	return ::InterlockedDecrement(reinterpret_cast<LONG*>(i));
}


}