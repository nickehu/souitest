//stamp:09321b91cc4f71fb
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
			}
			const TCHAR * XML_MAINWND;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMGX{
			public:
			_IMGX(){
				png_small_icons = _T("IMGX:png_small_icons");
			}
			const TCHAR * png_small_icons;
		}IMGX;
		class _SMENU{
			public:
			_SMENU(){
				menu_test = _T("SMENU:menu_test");
			}
			const TCHAR * menu_test;
		}SMENU;
		class _IMG{
			public:
			_IMG(){
			}
		}IMG;
		class _BMP{
			public:
			_BMP(){
				skin_btn_close = _T("BMP:skin_btn_close");
			}
			const TCHAR * skin_btn_close;
		}BMP;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_close",65536},
		{L"btn_max",65537},
		{L"btn_menu",65540},
		{L"btn_min",65539},
		{L"btn_restore",65538},
		{L"calcsum",65541},
		{L"content_view",65542},
		{L"modify",65543}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_close = namedXmlID[1].strName;
			btn_max = namedXmlID[2].strName;
			btn_menu = namedXmlID[3].strName;
			btn_min = namedXmlID[4].strName;
			btn_restore = namedXmlID[5].strName;
			calcsum = namedXmlID[6].strName;
			content_view = namedXmlID[7].strName;
			modify = namedXmlID[8].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_close;
		 const wchar_t * btn_max;
		 const wchar_t * btn_menu;
		 const wchar_t * btn_min;
		 const wchar_t * btn_restore;
		 const wchar_t * calcsum;
		 const wchar_t * content_view;
		 const wchar_t * modify;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_close	=	65536;
		const static int btn_max	=	65537;
		const static int btn_menu	=	65540;
		const static int btn_min	=	65539;
		const static int btn_restore	=	65538;
		const static int calcsum	=	65541;
		const static int content_view	=	65542;
		const static int modify	=	65543;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
