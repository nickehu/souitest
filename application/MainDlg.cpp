// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
#include "helper/SMenu.h"

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	auto xx = FindChildByName(L"modify");
	xx->GetEventSet()->subscribeEvent(EventSwndMouseHover::EventID, Subscriber(&CMainDlg::OnCloseBtnHover, this));

	return 0;
}

void CMainDlg::OnActivate(UINT nState, BOOL bMinimized, HWND wndOther) {
	//__super::OnActivate(nState, bMinimized, wndOther);
	if (nState == WA_INACTIVE) {
		GetRoot()->SetAttribute(L"skin", L"main_bg1");
	}
	else {
		GetRoot()->SetAttribute(L"skin", L"main_bg");
	}
}

//TODO:消息映射
void CMainDlg::OnClose()
{
	CSimpleWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnMenu() {
	CPoint pt;
	GetCursorPos(&pt);

	//使用自绘菜单
	SMenu menu;
	menu.LoadMenu(_T("menu_test"), _T("SMENU"));
	menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);

}

void CMainDlg::OnModify(EventArgs* pEvt) {
	 auto self = (SWindow*)pEvt->sender;
	 static bool is_checked = FALSE;
	 is_checked = !is_checked;
	 if (is_checked) {
		 self->SetWindowTextW(L"checked");
	 }
	 else {
		 self->SetWindowTextW(L"free");
	 }
	 //self->ModifyState(0, WndState_Check, TRUE);
	 self->SetCheck(is_checked);

	 
}

bool CMainDlg::OnCloseBtnHover(EventArgs* pEvt) {
	return true;
}

void CMainDlg::OnCalcSum() {
	auto content_view = FindChildByName(L"content_view");
	static int num = 6;
	auto button = content_view->CreateChildren(SStringW().Format(LR"(<button size="-1,-1" extend_left="10" text="New %02d"/>)",num++));
	content_view->UpdateChildrenPosition();
	SStringW str;

	//SWindow* pChild = content_view->GetWindow(GSW_FIRSTCHILD);
	//while (pChild) {

	//	auto rect = pChild->GetWindowRect();

	//	auto child_text = pChild->GetWindowTextW();
	//	str.Append(SStringW().Format(L"name:%s width:%d |", child_text, rect.right - rect.left));

	//	pChild = pChild->GetWindow(GSW_NEXTSIBLING);
	//}

	for (SWindow* pChild = content_view->GetWindow(GSW_FIRSTCHILD); 
		pChild; 
		pChild = pChild->GetWindow(GSW_NEXTSIBLING)) {

		auto rect = pChild->GetWindowRect();
		auto child_text = pChild->GetWindowTextW();
		str.Append(SStringW().Format(L"name:%s width:%d |", child_text, rect.right - rect.left));
	}

	auto content_view_rect = content_view->GetWindowRect();
	content_view->SetWindowTextW(SStringW().Format(L"[width=%d] [%s]", content_view_rect.right - content_view_rect.left, str));


	for (SWindow* pChild = content_view->GetWindow(GSW_FIRSTCHILD); pChild; ) {

		auto temp = pChild->GetWindow(GSW_NEXTSIBLING);
		content_view->DestroyChild(pChild);
		pChild = temp;
	}
}

//演示如何响应菜单事件
void CMainDlg::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl) {
	if (uNotifyCode == 0) {
		if (nID == 7) {
		}
	}
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

