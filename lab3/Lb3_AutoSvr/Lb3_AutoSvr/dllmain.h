// dllmain.h : Declaration of module class.

class CLb3_AutoSvrModule : public ATL::CAtlDllModuleT< CLb3_AutoSvrModule >
{
public :
	DECLARE_LIBID(LIBID_Lb3_AutoSvrLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LB3_AUTOSVR, "{06EF60CB-1D78-4EE4-ABD6-C668CFDBFDCA}")
};

extern class CLb3_AutoSvrModule _AtlModule;
