#include "StdAfx.h"


namespace DuiLib {

CDialogBuilder::CDialogBuilder(CPaintManagerUI* mgr) : m_pCallback(NULL), m_pstrtype(NULL),m_pMgr(mgr)
{

}

bool CDialogBuilder::LoadFile(LPCTSTR file)
{
	return m_xml.LoadFromFile(file);
}


bool CDialogBuilder::LoadString(LPCWSTR strXml)
{
    return m_xml.Load(strXml);
}

bool CDialogBuilder::LoadString(LPCSTR strXml)
{
    return m_xml.LoadFromMem((BYTE*)strXml,strlen(strXml)+1,XMLFILE_ENCODING_UTF8);
}

CControlUI* CDialogBuilder::Create(STRINGorID xml, LPCTSTR type, IDialogBuilderCallback* pCallback,  CControlUI* pParent)
{
    if( HIWORD(xml.m_lpstr) != NULL ) {
        if( *(xml.m_lpstr) == _T('<') ) {
            if( !m_xml.Load(xml.m_lpstr) ) return NULL;
        }
        else {
            if( !m_xml.LoadFromFile(xml.m_lpstr) ) return NULL;
        }
    }
    else {
        HRSRC hResource = ::FindResource(CPaintManagerUI::GetResourceDll(), xml.m_lpstr, type);
        if( hResource == NULL ) return NULL;
        HGLOBAL hGlobal = ::LoadResource(CPaintManagerUI::GetResourceDll(), hResource);
        if( hGlobal == NULL ) {
            FreeResource(hResource);
            return NULL;
        }

        m_pCallback = pCallback;
        if( !m_xml.LoadFromMem((BYTE*)::LockResource(hGlobal), ::SizeofResource(CPaintManagerUI::GetResourceDll(), hResource) )) 
		{
			::FreeResource(hResource);
			return NULL;
		}
        ::FreeResource(hResource);
        m_pstrtype = type;
    }

    return Create(pCallback, pParent);
}

CControlUI* CDialogBuilder::Create(IDialogBuilderCallback* pCallback,CControlUI* pParent)
{
    m_pCallback = pCallback;
    XmlNode root = m_xml.GetRoot().first_child();
    if( !root ) return NULL;
	CPaintManagerUI* pManager=m_pMgr;
    if( pManager ) {
        LPCTSTR pstrClass = NULL;
        int nAttributes = 0;
        LPCTSTR pstrName = NULL;
        LPCTSTR pstrValue = NULL;
        LPTSTR pstr = NULL;

        for( pugi::xml_node node = root.first_child(); node; node =node.next_sibling()) 
		{
            pstrClass = node.name();
            if( _tcscmp(pstrClass, _T("Image")) == 0 ) 
			{
                LPCTSTR pImageName = NULL;
                LPCTSTR pImageResType = NULL;
                DWORD mask = 0;
                for(XmlAttr attr=node.first_attribute();attr;attr=attr.next_attribute()) 
				{
                    pstrName = attr.name();
                    pstrValue = attr.value();
                    if( _tcscmp(pstrName, _T("name")) == 0 ) {
                        pImageName = pstrValue;
                    }
                    else if( _tcscmp(pstrName, _T("restype")) == 0 ) {
                        pImageResType = pstrValue;
                    }
                    else if( _tcscmp(pstrName, _T("mask")) == 0 ) {
                        if( *pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
                        mask = _tcstoul(pstrValue, &pstr, 16);
                    }
                }
                if( pImageName ) pManager->AddImage(pImageName, pImageResType, mask);
            }
            else if( _tcscmp(pstrClass, _T("Font")) == 0 ) 
			{
                LPCTSTR pFontName = NULL;
                int size = 12;
                bool bold = false;
                bool underline = false;
                bool italic = false;
                bool defaultfont = false;
                for(XmlAttr attr=node.first_attribute();attr;attr=attr.next_attribute())
				{
                    pstrName = attr.name();
                    pstrValue = attr.value();
                    if( _tcscmp(pstrName, _T("name")) == 0 ) {
                        pFontName = pstrValue;
                    }
                    else if( _tcscmp(pstrName, _T("size")) == 0 ) {
                        size = _tcstol(pstrValue, &pstr, 10);
                    }
                    else if( _tcscmp(pstrName, _T("bold")) == 0 ) {
                        bold = (_tcscmp(pstrValue, _T("true")) == 0);
                    }
                    else if( _tcscmp(pstrName, _T("underline")) == 0 ) {
                        underline = (_tcscmp(pstrValue, _T("true")) == 0);
                    }
                    else if( _tcscmp(pstrName, _T("italic")) == 0 ) {
                        italic = (_tcscmp(pstrValue, _T("true")) == 0);
                    }
                    else if( _tcscmp(pstrName, _T("default")) == 0 ) {
                        defaultfont = (_tcscmp(pstrValue, _T("true")) == 0);
                    }
                }
                if( pFontName ) {
                    pManager->AddFont(pFontName, size, bold, underline, italic);
                    if( defaultfont ) pManager->SetDefaultFont(pFontName, size, bold, underline, italic);
                }
            }
            else if( _tcscmp(pstrClass, _T("Default")) == 0 ) 
			{
                LPCTSTR pControlName = NULL;
                LPCTSTR pControlValue = NULL;
                for(XmlAttr attr=node.first_attribute();attr;attr=attr.next_attribute()) 
				{
                    pstrName = attr.name();
                    pstrValue = attr.value();
                    if( _tcscmp(pstrName, _T("name")) == 0 ) {
                        pControlName = pstrValue;
                    }
                    else if( _tcscmp(pstrName, _T("value")) == 0 ) {
                        pControlValue = pstrValue;
                    }
                }
                if( pControlName ) {
                    pManager->AddDefaultAttributeList(pControlName, pControlValue);
                }
            }
        }

        pstrClass = root.name();
        if( _tcscmp(pstrClass, _T("Window")) == 0 ) 
		{
            if( pManager->GetPaintWindow() ) 
			{
				LPCTSTR pControlName = NULL;
				LPCTSTR pControlValue = NULL;
				for(XmlAttr attr=root.first_attribute();attr;attr=attr.next_attribute()) 
				{
                    pstrName = attr.name();
                    pstrValue = attr.value();
                    if( _tcscmp(pstrName, _T("size")) == 0 ) {
                        LPTSTR pstr = NULL;
                        int cx = _tcstol(pstrValue, &pstr, 10);  ASSERT(pstr);    
                        int cy = _tcstol(pstr + 1, &pstr, 10);    ASSERT(pstr); 
                        pManager->SetInitSize(cx, cy);
                    } 
                    else if( _tcscmp(pstrName, _T("sizebox")) == 0 ) {
                        RECT rcSizeBox = { 0 };
                        LPTSTR pstr = NULL;
                        rcSizeBox.left = _tcstol(pstrValue, &pstr, 10);  ASSERT(pstr);    
                        rcSizeBox.top = _tcstol(pstr + 1, &pstr, 10);    ASSERT(pstr);    
                        rcSizeBox.right = _tcstol(pstr + 1, &pstr, 10);  ASSERT(pstr);    
                        rcSizeBox.bottom = _tcstol(pstr + 1, &pstr, 10); ASSERT(pstr);    
                        pManager->SetSizeBox(rcSizeBox);
                    }
                    else if( _tcscmp(pstrName, _T("caption")) == 0 ) {
                        RECT rcCaption = { 0 };
                        LPTSTR pstr = NULL;
                        rcCaption.left = _tcstol(pstrValue, &pstr, 10);  ASSERT(pstr);    
                        rcCaption.top = _tcstol(pstr + 1, &pstr, 10);    ASSERT(pstr);    
                        rcCaption.right = _tcstol(pstr + 1, &pstr, 10);  ASSERT(pstr);    
                        rcCaption.bottom = _tcstol(pstr + 1, &pstr, 10); ASSERT(pstr);    
                        pManager->SetCaptionRect(rcCaption);
                    }
                    else if( _tcscmp(pstrName, _T("roundcorner")) == 0 ) {
                        LPTSTR pstr = NULL;
                        int cx = _tcstol(pstrValue, &pstr, 10);  ASSERT(pstr);    
                        int cy = _tcstol(pstr + 1, &pstr, 10);    ASSERT(pstr); 
                        pManager->SetRoundCorner(cx, cy);
                    } 
                    else if( _tcscmp(pstrName, _T("mininfo")) == 0 ) {
                        LPTSTR pstr = NULL;
                        int cx = _tcstol(pstrValue, &pstr, 10);  ASSERT(pstr);    
                        int cy = _tcstol(pstr + 1, &pstr, 10);    ASSERT(pstr); 
                        pManager->SetMinInfo(cx, cy);
                    }
                    else if( _tcscmp(pstrName, _T("maxinfo")) == 0 ) {
                        LPTSTR pstr = NULL;
                        int cx = _tcstol(pstrValue, &pstr, 10);  ASSERT(pstr);    
                        int cy = _tcstol(pstr + 1, &pstr, 10);    ASSERT(pstr); 
                        pManager->SetMaxInfo(cx, cy);
                    }
                    else if( _tcscmp(pstrName, _T("showdirty")) == 0 ) {
                        pManager->SetShowUpdateRect(_tcscmp(pstrValue, _T("true")) == 0);
                    } 
                    else if( _tcscmp(pstrName, _T("alpha")) == 0 ) {
                        pManager->SetTransparent(_ttoi(pstrValue));
                    } 
                    else if( _tcscmp(pstrName, _T("bktrans")) == 0 ) {
                        pManager->SetBackgroundTransparent(_tcscmp(pstrValue, _T("true")) == 0);
                    } 
                    else if( _tcscmp(pstrName, _T("disabledfontcolor")) == 0 ) {
                        if( *pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
                        LPTSTR pstr = NULL;
                        DWORD clrColor = _tcstoul(pstrValue, &pstr, 16);
                        pManager->SetDefaultDisabledColor(clrColor);
                    } 
                    else if( _tcscmp(pstrName, _T("defaultfontcolor")) == 0 ) {
                        if( *pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
                        LPTSTR pstr = NULL;
                        DWORD clrColor = _tcstoul(pstrValue, &pstr, 16);
                        pManager->SetDefaultFontColor(clrColor);
                    }
                    else if( _tcscmp(pstrName, _T("linkfontcolor")) == 0 ) {
                        if( *pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
                        LPTSTR pstr = NULL;
                        DWORD clrColor = _tcstoul(pstrValue, &pstr, 16);
                        pManager->SetDefaultLinkFontColor(clrColor);
                    } 
                    else if( _tcscmp(pstrName, _T("linkhoverfontcolor")) == 0 ) {
                        if( *pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
                        LPTSTR pstr = NULL;
                        DWORD clrColor = _tcstoul(pstrValue, &pstr, 16);
                        pManager->SetDefaultLinkHoverFontColor(clrColor);
                    } 
                    else if( _tcscmp(pstrName, _T("selectedcolor")) == 0 ) {
                        if( *pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
                        LPTSTR pstr = NULL;
                        DWORD clrColor = _tcstoul(pstrValue, &pstr, 16);
                        pManager->SetDefaultSelectedBkColor(clrColor);
                    } 
                }
            }
        }
    }
    return _Parse(root, pParent);
}

CMarkup* CDialogBuilder::GetMarkup()
{
    return &m_xml;
}



CControlUI* CDialogBuilder::_Parse(XmlNode pRoot, CControlUI* pParent)
{
    IContainerUI* pContainer = NULL;
    CControlUI* pReturn = NULL;
	CPaintManagerUI* pManager=m_pMgr;
    for( XmlNode node = pRoot.first_child() ; node; node = node.next_sibling() ) 
	{
        LPCTSTR pstrClass = node.name();
        if( _tcscmp(pstrClass, _T("Image")) == 0 || _tcscmp(pstrClass, _T("Font")) == 0 \
            || _tcscmp(pstrClass, _T("Default")) == 0 ) continue;

        CControlUI* pControl = NULL;
        if( _tcscmp(pstrClass, _T("Include")) == 0 ) 
		{
            if( !node.first_attribute() ) continue;
            int count = 1;
            LPTSTR pstr = NULL;
			XmlAttr attr=node.attribute(_T("count"));
            if ( attr)
                count = _tcstol(attr.value(), &pstr, 10);

			attr=node.attribute(_T("source"));
            if ( !attr ) continue;
            for ( int i = 0; i < count; i++ ) 
			{
                CDialogBuilder builder(m_pMgr);
                if( m_pstrtype != NULL ) { // 使用资源dll，从资源中读取
                    WORD id = (WORD)_tcstol(attr.value(), &pstr, 10); 
                    pControl = builder.Create((UINT)id, m_pstrtype, m_pCallback, pParent);
                }
                else {
                    pControl = builder.Create((LPCTSTR)attr.value(), (UINT)0, m_pCallback, pParent);
                }
            }
            continue;
        }
        else {
            SIZE_T cchLen = _tcslen(pstrClass);
            switch( cchLen ) {
            case 4:
                if( _tcscmp(pstrClass, _T("Edit")) == 0 )                   pControl = new CEditUI;
                else if( _tcscmp(pstrClass, _T("List")) == 0 )              pControl = new CListUI;
                else if( _tcscmp(pstrClass, _T("Text")) == 0 )              pControl = new CTextUI;
                break;
            case 5:
                if( _tcscmp(pstrClass, _T("Combo")) == 0 )                  pControl = new CComboUI;
                else if( _tcscmp(pstrClass, _T("Label")) == 0 )             pControl = new CLabelUI;
                break;
            case 6:
                if( _tcscmp(pstrClass, _T("Button")) == 0 )                 pControl = new CButtonUI;
                else if( _tcscmp(pstrClass, _T("Option")) == 0 )            pControl = new COptionUI;
                else if( _tcscmp(pstrClass, _T("Slider")) == 0 )            pControl = new CSliderUI;
                break;
            case 7:
                if( _tcscmp(pstrClass, _T("Control")) == 0 )                pControl = new CControlUI;
                else if( _tcscmp(pstrClass, _T("ActiveX")) == 0 )           pControl = new CActiveXUI;
                break;
            case 8:
                if( _tcscmp(pstrClass, _T("Progress")) == 0 )               pControl = new CProgressUI;
                else if(  _tcscmp(pstrClass, _T("RichEdit")) == 0 )         pControl = new CRichEditUI;
                break;
            case 9:
                if( _tcscmp(pstrClass, _T("Container")) == 0 )              pControl = new CContainerUI;
                else if( _tcscmp(pstrClass, _T("TabLayout")) == 0 )         pControl = new CTabLayoutUI;
                else if( _tcscmp(pstrClass, _T("ScrollBar")) == 0 )         pControl = new CScrollBarUI; 
                break;
            case 10:
                if( _tcscmp(pstrClass, _T("ListHeader")) == 0 )             pControl = new CListHeaderUI;
                else if( _tcscmp(pstrClass, _T("TileLayout")) == 0 )        pControl = new CTileLayoutUI;
                break;
            case 14:
                if( _tcscmp(pstrClass, _T("VerticalLayout")) == 0 )         pControl = new CVerticalLayoutUI;
                else if( _tcscmp(pstrClass, _T("ListHeaderItem")) == 0 )    pControl = new CListHeaderItemUI;
                break;
            case 15:
                if( _tcscmp(pstrClass, _T("ListTextElement")) == 0 )        pControl = new CListTextElementUI;
                break;
            case 16:
                if( _tcscmp(pstrClass, _T("HorizontalLayout")) == 0 )       pControl = new CHorizontalLayoutUI;
                else if( _tcscmp(pstrClass, _T("ListLabelElement")) == 0 )  pControl = new CListLabelElementUI;
                break;
            case 20:
                if( _tcscmp(pstrClass, _T("ListContainerElement")) == 0 )   pControl = new CListContainerElementUI;
                break;
            }
            // User-supplied control factory
            if( pControl == NULL ) {
                CStdPtrArray* pPlugins = CPaintManagerUI::GetPlugins();
                LPCREATECONTROL lpCreateControl = NULL;
                for( int i = 0; i < pPlugins->GetSize(); ++i ) {
                    lpCreateControl = (LPCREATECONTROL)pPlugins->GetAt(i);
                    if( lpCreateControl != NULL ) {
                        pControl = lpCreateControl(pstrClass);
                        if( pControl != NULL ) break;
                    }
                }
            }
            if( pControl == NULL && m_pCallback != NULL ) {
                pControl = m_pCallback->CreateControl(pstrClass);
            }
        }

        ASSERT(pControl);
        if( pControl == NULL ) continue;


        // Add children
		XmlNode child=node.first_child();

        if( child ) 
		{
			if (_tcscmp(child.name(), _T("Event")) == 0)
			{
				//<Event setFocus="ClickEvent.click">
				//	<click>print("按钮点击")</click>
				//</Event>
				pControl->SetManager(pManager, NULL, false);
				char nameBuf[128];
				char valueBuf[128];

				LuaEngine* L=LuaManager::instance()->current();
				if(L)
				{
					for (XmlAttr attr=child.first_attribute();attr;attr=attr.next_attribute())
					{
						UTF16To8(nameBuf,(unsigned short*)attr.name(),sizeof(nameBuf));
						UTF16To8(valueBuf,(unsigned short*)attr.value(),sizeof(valueBuf));
						
						char* val="";
						for (int i=strlen(valueBuf)-1;i>=0;--i)
						{
							if (valueBuf[i]=='.')
							{
								valueBuf[i]='\0';
								val=&valueBuf[i+1];
							}
						}

						LuaTable tab=L->require(valueBuf);
						if (tab.isValid())
						{
							pControl->BindLuaEvent(nameBuf,tab.getTable(val));
						}
						
					}

					for( XmlNode evNode = child.first_child() ; evNode; evNode = evNode.next_sibling() )
					{
						UTF16To8(nameBuf,(unsigned short*)evNode.name(),sizeof(nameBuf));
						int len=UTF16To8(NULL,(unsigned short*)evNode.text().as_string(),0);
						char* buf=(char*)dlmalloc(len+1);
						UTF16To8(buf,(unsigned short*)evNode.text().as_string(),len+1);
						pControl->BindLuaEvent(nameBuf,buf);
						dlfree(buf);
					}
				}

			}
			else
				_Parse(node, pControl);
        }
        // Attach to parent
        // 因为某些属性和父窗口相关，比如selected，必须先Add到父窗口
        if( pParent != NULL ) {
            if( pContainer == NULL ) pContainer = static_cast<IContainerUI*>(pParent->GetInterface(_T("IContainer")));
            ASSERT(pContainer);
            if( pContainer == NULL ) return NULL;
            if( !pContainer->Add(pControl) ) {
                delete pControl;
                continue;
            }
        }
        // Init default attributes
        if( pManager ) {
            pControl->SetManager(pManager, NULL, false);
            LPCTSTR pDefaultAttributes = pManager->GetDefaultAttributeList(pstrClass);
            if( pDefaultAttributes ) {
                pControl->ApplyAttributeList(pDefaultAttributes);
            }
        }
        // Process attributes
        if( node.first_attribute() ) {
            for(XmlAttr attr=node.first_attribute();attr;attr=attr.next_attribute() ) {
                pControl->SetAttribute(attr.name(),attr.value());
            }
        }
        if( pManager ) {
            pControl->SetManager(NULL, NULL, false);
        }

		
        // Return first item
        if( pReturn == NULL ) pReturn = pControl;
    }//for
    return pReturn;
}

} // namespace DuiLib
