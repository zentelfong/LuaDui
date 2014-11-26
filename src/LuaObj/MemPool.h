#pragma once
#include "malloc/dlmalloc.h"

class MemPool
{
public:
	MemPool(size_t defSize,bool useLock)
	{
		m_pool=create_mspace(defSize,useLock);
	}

	~MemPool(void)
	{
		destroy_mspace(m_pool);
	}


	inline void* malloc(size_t bytes)
	{
		return mspace_malloc(m_pool,bytes);
	}

	inline void free(void* mem)
	{
		mspace_free(m_pool,mem);
	}

	inline void* realloc(void* mem, size_t newsize)
	{
		return mspace_realloc(m_pool,mem,newsize);
	}

	inline void* calloc(size_t n_elements, size_t elem_size)
	{
		return mspace_calloc(m_pool,n_elements,elem_size);
	}

	inline mallinfo mallinfo()
	{
		return mspace_mallinfo(m_pool);
	}
private:
	mspace m_pool;
};

