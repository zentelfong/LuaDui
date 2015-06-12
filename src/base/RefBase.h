#pragma once

namespace base
{

//记数基类
class RefCountedBase
{
public:
	virtual int AddRef()=0;
	virtual int Release()=0;
	virtual int GetRefCt() =0;
protected:
	virtual ~RefCountedBase(){}
};



template <class T>
class RefCountedPtr
{
public:
	RefCountedPtr() : m_ptr(NULL)
	{
	}

	RefCountedPtr(T* p) : m_ptr(p) 
	{
		if (m_ptr)m_ptr->AddRef();
	}

	RefCountedPtr(const RefCountedPtr<T>& r) : m_ptr(r.m_ptr) 
	{
		if (m_ptr)m_ptr->AddRef();
	}

	template <typename U>
	RefCountedPtr(const RefCountedPtr<U>& r) : m_ptr(r.get())
	{
		if (m_ptr) m_ptr->AddRef();
	}

	~RefCountedPtr()
	{
		if (m_ptr) m_ptr->Release();
	}

	T* get() const { return m_ptr; }
	operator T*() const { return m_ptr; }
	T* operator->() const { return m_ptr; }

	// Release a pointer.
	// The return value is the current pointer held by this object.
	// If this object holds a NULL pointer, the return value is NULL.
	// After this operation, this object will hold a NULL pointer,
	// and will not own the object any more.
	T* release() 
	{
		T* retVal = m_ptr;
		m_ptr = NULL;
		return retVal;
	}

	RefCountedPtr<T>& operator=(T* p) 
	{
		// AddRef first so that self assignment should work
		if (p) p->AddRef();
		if (m_ptr) m_ptr ->Release();
		m_ptr = p;
		return *this;
	}

	RefCountedPtr<T>& operator=(const RefCountedPtr<T>& r)
	{
		return *this = r.m_ptr;
	}

	template <typename U>
	RefCountedPtr<T>& operator=(const RefCountedPtr<U>& r)
	{
		return *this = r.get();
	}

	void swap(T** pp)
	{
		T* p = m_ptr;
		m_ptr = *pp;
		*pp = p;
	}

	void swap(RefCountedPtr<T>& r)
	{
		swap(&r.m_ptr);
	}

	int count()
	{
		if (m_ptr)
		{
			return m_ptr->GetRefCt();
		}
		return 0;
	}
protected:
	T* m_ptr;
};

class AtomicOps {
public:
#ifdef WIN32
	// Assumes sizeof(int) == sizeof(LONG), which it is on Win32 and Win64.
	static int Increment(int* i);
	static int Decrement(int* i);
#else
	static int Increment(int* i) {
		return __sync_add_and_fetch(i, 1);
	}
	static int Decrement(int* i) {
		return __sync_sub_and_fetch(i, 1);
	}
#endif
};


template <class T>
class RefCountedObject : public T 
{
public:
	RefCountedObject() : m_count(0) 
	{
	}

	template<typename P>
	explicit RefCountedObject(P p) : T(p), m_count(0) 
	{
	}

	template<typename P1, typename P2>
	RefCountedObject(P1 p1, P2 p2) : T(p1, p2), m_count(0) 
	{
	}

	template<typename P1, typename P2, typename P3>
	RefCountedObject(P1 p1, P2 p2, P3 p3) : T(p1, p2, p3), m_count(0) 
	{
	}

	template<typename P1, typename P2, typename P3, typename P4>
	RefCountedObject(P1 p1, P2 p2, P3 p3, P4 p4)
		: T(p1, p2, p3, p4), m_count(0) 
	{
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5>
	RefCountedObject(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
		: T(p1, p2, p3, p4, p5), m_count(0) 
	{
	}

	virtual int AddRef() 
	{
		return AtomicOps::Increment(&m_count);
	}

	virtual int Release() 
	{
		int count = AtomicOps::Decrement(&m_count);
		if (!count) 
		{
			delete this;
		}
		return count;
	}

	virtual int GetRefCt()
	{
		return m_count;
	}
protected:
	virtual ~RefCountedObject() {
	}

	int m_count;
};



class RefCount {
public:
	RefCount() : refct_(1) {}

	///
	// Atomic reference increment.
	///
	int AddRef() {
		return AtomicOps::Increment(&refct_);
	}

	///
	// Atomic reference decrement. Delete the object when no references remain.
	///
	int Release() {
		return AtomicOps::Decrement(&refct_);
	}
	int GetRefCt(){
		return refct_;
	}
private:
	int refct_;  // NOLINT(runtime/int)
};

#define IMPLEMENT_REFCOUNTING(ClassName)            \
  public:                                           \
    int AddRef() { return refct_.AddRef(); }        \
    int Release() {                                 \
      int retval = refct_.Release();                \
      if (retval == 0)                              \
        delete this;                                \
      return retval;                                \
    }                                               \
	virtual int GetRefCt(){							\
		return refct_.GetRefCt();					\
	}												\
  private:                                          \
    base::RefCount refct_;




/*************************************************************

class Test
{
public:
	void test(){}
};


RefCountedPtr<Test> test=new RefCountedObject<Test>()
test->test();


************************************************************/



}//namespace


//导出以下类
using base::RefCountedBase;
using base::RefCountedPtr;
using base::RefCountedObject;