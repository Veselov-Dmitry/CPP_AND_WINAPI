//#include<Windows.h>



// {A0BCA4CF-F622-49E3-AE63-EC25DD6E0E9F}
DEFINE_GUID(CLSID_Math,
0xa0bca4cf, 0xf622, 0x49e3, 0xae, 0x63, 0xec, 0x25, 0xdd, 0x6e, 0xe, 0x9f);


// {EC351FDF-97B8-48A9-B2CD-478ADD8CD215}
DEFINE_GUID(IID_IMath, 
0xec351fdf, 0x97b8, 0x48a9, 0xb2, 0xcd, 0x47, 0x8a, 0xdd, 0x8c, 0xd2, 0x15);


class IMath : public IUnknown
{
public:
   STDMETHOD( Add( long, long, long* ))      PURE;
   STDMETHOD( Subtract( long, long, long* )) PURE;
   STDMETHOD( Multiply( long, long, long* )) PURE;
   STDMETHOD( Divide( long, long, long* ))   PURE;
};



