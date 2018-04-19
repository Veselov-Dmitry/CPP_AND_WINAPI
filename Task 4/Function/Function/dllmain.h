// dllmain.h : Declaration of module class.

class CFunctionModule : public ATL::CAtlDllModuleT< CFunctionModule >
{
public :
	DECLARE_LIBID(LIBID_FunctionLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FUNCTION, "{00C1E212-76A3-4EEB-9154-82B438F33FA9}")
};

extern class CFunctionModule _AtlModule;
