#include"IFN_12.h"
#include"IVer.h"

// global variable counter Objects 
extern long g_lObjs; 
// global variable counter Factories
extern long g_lLocks;
// HMODULE DLL
static HMODULE g_hModule;

class CFN_12 : public IFN_12, public IVer {
	protected:
		// Reference counter
		long m_lRef;
	public: 
		CFN_12();
		~CFN_12();
	public:
		// IUnknown
		STDMETHOD(QueryInterface( REFIID, void** ));
		STDMETHOD_(ULONG, AddRef());
		STDMETHOD_(ULONG, Release());
		// IFN_12
		STDMETHOD(Fun121 (double, double, int*));
		STDMETHOD(Fun122 (int, int, int, float*)); 
		STDMETHOD(Fun123 (int, int* ));
		// IVer
		STDMETHOD(GetAutor(wchar_t **));
};

class FN_12ClassFactory : public IClassFactory
{
protected:
   long       m_lRef;
 
public:
   FN_12ClassFactory();
   ~FN_12ClassFactory();
 
   // IUnknown
   STDMETHOD( QueryInterface(REFIID, void** ));
   STDMETHOD_(ULONG, AddRef());
   STDMETHOD_(ULONG, Release());
 
   // IClassFactory
   STDMETHOD( CreateInstance(LPUNKNOWN, REFIID, void**));
   STDMETHOD( LockServer(BOOL));
};