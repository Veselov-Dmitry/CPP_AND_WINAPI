// dllmain.h : Declaration of module class.

class CLab3_Task_ServerModule : public ATL::CAtlDllModuleT< CLab3_Task_ServerModule >
{
public :
	DECLARE_LIBID(LIBID_Lab3_Task_ServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LAB3_TASK_SERVER, "{C86F05D4-167F-471A-8A52-960150DD4514}")
};

extern class CLab3_Task_ServerModule _AtlModule;
