// dllmain.h : Declaration of module class.

class CPolygonModule : public ATL::CAtlDllModuleT< CPolygonModule >
{
public :
	DECLARE_LIBID(LIBID_PolygonLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_POLYGON, "{CA9B8E3B-7DBF-4725-952E-3F5578623921}")
};

extern class CPolygonModule _AtlModule;
