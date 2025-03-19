// InputBoxDialog.h

#pragma once

#include <windows.h>

#include "..\Common\Ascii.h"
#include "..\Common\Common.h"

#ifndef IDC_STATIC
#define IDC_STATIC																-1
#endif

#define IDD_INPUT_BOX_DIALOG													9000
#define IDC_TITLE																9001
#define IDC_EDITTEXT															9002

#define INPUT_BOX_DIALOG_DEFAULT_TITLE											"Input Some Text"

BOOL InputBoxDialog( HWND hWndParent, HINSTANCE hInstance, LPTSTR lpszInputText, LPCTSTR lpszTitle = INPUT_BOX_DIALOG_DEFAULT_TITLE );
