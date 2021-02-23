#include "stdafx.h"
#include "../controls.extend/SAnimator.h"

class MyCtrl : public SButton, public SAnimator, public ITimelineHandler {
	SOUI_CLASS_NAME(MyCtrl, L"myctrl")
public:
	MyCtrl();
	~MyCtrl();

protected:
	virtual void OnAnimatorState(int percent) override;
	virtual void OnFinalRelease() override { delete this; }

	virtual void OnNextFrame();

	void OnMouseMove(UINT nFlags, CPoint pt);
	void OnLButtonUp(UINT nFlags, CPoint pt);
	void OnLButtonDown(UINT nFlags, CPoint pt);
	void OnLButtonDbClick(UINT nFlags, CPoint pt);
	void MoveTo(const CRect& rcEnd);

	int OnCreate(LPVOID);
	void OnDestroy();

	SOUI_MSG_MAP_BEGIN()
		MSG_WM_CREATE(OnCreate)
		MSG_WM_DESTROY(OnDestroy)
		MSG_WM_MOUSEMOVE(OnMouseMove)
		MSG_WM_LBUTTONDOWN(OnLButtonDown)
		MSG_WM_LBUTTONUP(OnLButtonUp)
		MSG_WM_LBUTTONDBLCLK(OnLButtonDbClick)
	SOUI_MSG_MAP_END()

		virtual BOOL InitFromXml(pugi::xml_node xmlNode);
	bool OnCloseBtnHover(EventArgs* pEvtBase);
private:
	CRect m_rcBegin{}, m_rcEnd{};
	CPoint  m_ptDrag;
	bool    m_bDrag = false;
};



