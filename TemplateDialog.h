// TemplateDialog.h

#pragma once

#include <windows.h>

#include "..\Common\Ascii.h"
#include "..\Common\Common.h"

#ifndef IDC_STATIC
#define IDC_STATIC																-1
#endif

#define IDD_TEMPLATE_DIALOG														9000
#define IDC_TITLE																9001
#define IDC_EDITTEXT															9002

#define TEMPLATE_DIALOG_DEFAULT_TITLE											"Input Some Text"

BOOL TemplateDialog( HWND hWndParent, HINSTANCE hInstance, LPTSTR lpszInputText, LPCTSTR lpszTitle = TEMPLATE_DIALOG_DEFAULT_TITLE );
