#include "stdafx.h"

// {8176E1D1-42AF-470D-B048-EDF149E4166E}
static const GUID IID_IVER = 
{ 0x8176e1d1, 0x42af, 0x470d, { 0xb0, 0x48, 0xed, 0xf1, 0x49, 0xe4, 0x16, 0x6e } };

class IVer : public IUnknown {
	public:
		STDMETHOD(GetAutor(wchar_t**))PURE;
};
