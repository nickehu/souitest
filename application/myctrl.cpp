#include "stdafx.h"
#include "myctrl.h"

MyCtrl::MyCtrl() {
}

MyCtrl::~MyCtrl() {
}

int MyCtrl::OnCreate(LPVOID) {
    int nRet = __super::OnCreate(NULL);
    if (nRet == 0)
        GetContainer()->RegisterTimelineHandler(this);
    return nRet;
}

void MyCtrl::OnDestroy() {
    GetContainer()->UnregisterTimelineHandler(this);
    __super::OnDestroy();
}

void MyCtrl::OnNextFrame() {
	Update();
}

void MyCtrl::OnAnimatorState(int percent) {
    CRect rcTemp;
    rcTemp.left = m_rcBegin.left + (m_rcEnd.left - m_rcBegin.left) * percent / 100;
    rcTemp.top = m_rcBegin.top + (m_rcEnd.top - m_rcBegin.top) * percent / 100;
    rcTemp.right = m_rcBegin.right + (m_rcEnd.right - m_rcBegin.right) * percent / 100;
    rcTemp.bottom = m_rcBegin.bottom + (m_rcEnd.bottom - m_rcBegin.bottom) * percent / 100;
    Move(rcTemp);
}

void MyCtrl::MoveTo(const CRect& rcEnd) {
    m_rcBegin = GetWindowRect();
    m_rcEnd = rcEnd;
    Stop();
    Start(200);
}

void MyCtrl::OnMouseMove(UINT nFlags, CPoint pt) {
	if ((nFlags & MK_LBUTTON))
	{
		CRect rcWnd = GetWindowRect();
		rcWnd.OffsetRect(pt.x - m_ptDrag.x, 0);
		Move(rcWnd);
		m_ptDrag = pt;
	}
}

void MyCtrl::OnLButtonUp(UINT nFlags, CPoint pt) {
	SWindow::OnLButtonUp(nFlags, pt);
	
	m_bDrag = false;
	MoveTo(m_rcEnd);
}

void MyCtrl::OnLButtonDown(UINT nFlags, CPoint pt) {
	SWindow::OnLButtonDown(nFlags, pt);
	
	BringWindowToTop();

	if (!m_bDrag) {
		m_rcEnd = GetWindowRect();
	}
	m_ptDrag = pt;
	m_bDrag = true;
}

void MyCtrl::OnLButtonDbClick(UINT nFlags, CPoint pt) {
}

bool MyCtrl::OnCloseBtnHover(EventArgs* pEvtBase) {
	SSendMessage(WM_MOUSEHOVER);
	return true;
}

BOOL MyCtrl::InitFromXml(pugi::xml_node xmlNode) {
	auto result = __super::InitFromXml(xmlNode);
	
	auto close = FindChildByName(L"close_btn");

	close->GetEventSet()->subscribeEvent(EventSwndMouseHover::EventID, Subscriber(&MyCtrl::OnCloseBtnHover, this));


	return result;
}
