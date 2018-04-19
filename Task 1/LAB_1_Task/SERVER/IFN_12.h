#include "stdafx.h"
// {C3FD39FA-0D5F-4835-9CC3-A6B40AED1F79}
/*static */const GUID CLSID_FN_12 = {0xc3fd39fa, 0xd5f, 0x4835, 0x9c, 0xc3, 0xa6, 0xb4, 0xa, 0xed, 0x1f, 0x79};

// {1EBF7700-4779-41F2-9AD2-59CB46AB6F58}
/*static */const GUID IID_IFN_12 = {0x1ebf7700, 0x4779, 0x41f2, 0x9a, 0xd2, 0x59, 0xcb, 0x46, 0xab, 0x6f, 0x58};

class IFN_12 : public IUnknown {
	public:
		STDMETHOD(Fun121 (double, double,int*))PURE;
		STDMETHOD(Fun122 (int, int, int, float*))PURE; 
		STDMETHOD(Fun123 (int, int*))PURE;
};
