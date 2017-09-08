#pragma once
#include "D2Widget.hpp"

class D2Widget_Button : public D2Widget
{
private:
	bool bDisabled;
	bool bDown;
	bool bHasText;

	char16_t buttonTextBuffer[64]{ 0 };
	
	tex_handle texture_up;
	tex_handle texture_down;
	tex_handle texture_disabled;
public:
	D2Widget_Button(int x, int y, char* szDC6Path, char* szButtonType,
		DWORD dwStartEnabled, DWORD dwEndEnabled,
		DWORD dwStartDown, DWORD dwEndDown, 
		DWORD dwStartDisabled, DWORD dwEndDisabled);
	~D2Widget_Button();

	void AttachText(char16_t* text);
	void DetachText();

	void Disable() { bDisabled = true; }
	void Enable() { bDisabled = false; }

	virtual void Draw();
	virtual bool HandleMouseDown(DWORD dwX, DWORD dwY);
	virtual bool HandleMouseClick(DWORD dwX, DWORD dwY);

	tex_handle texture;
};