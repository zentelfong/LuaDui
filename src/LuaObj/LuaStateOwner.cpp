#include "LuaStateOwner.h"



void * LuaStateOwner::luaAlloc(void *ud, void *ptr, size_t osize, size_t nsize)
{

	MemPool *memalloc=(MemPool*)ud;

	if (nsize == 0) 
	{
		if(ptr)
			memalloc->free(ptr);
		return NULL;
	}
	else
	{  
		if(ptr)
			return memalloc->realloc(ptr,nsize);
		else
			return memalloc->malloc(nsize);
	}	
}


void LuaStateOwner::error(const char* fmt,...)
{
	char buf[1024]={0};
	va_list argp;
	va_start(argp, fmt);
	vsprintf(buf,fmt,argp);
	va_end(argp);

	if (m_errorHandler)
	{
		m_errorHandler(buf);
	}
	else
	{
		printf(buf);
	}
}

