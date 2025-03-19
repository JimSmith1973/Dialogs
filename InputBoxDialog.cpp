// InputBoxDialog.cpp

#include "InputBoxDialog.h"

// Global variables
static LPTSTR g_lpszInputText;
static LPTSTR g_lpszTitle;

BOOL InputBoxDialogPositionToMouse( HWND hWndDialog )
{
	BOOL bResult = FALSE;

	RECT rcDialog;

	// Get dialog size
	if( GetWindowRect( hWndDialog, &rcDialog ) )
	{
		// Successfully got dialog size
		POINT ptMouse;

		// Get mouse position
		if( GetCursorPos( &ptMouse ) )
		{
			// Successfully got mouse position
			int nDialogWidth;
			int nDialogHeight;
			int nDialogLeft;
			int nDialogTop;

			// Calculate dialog size
			nDialogWidth	= ( rcDialog.right - rcDialog.left );
			nDialogHeight	= ( rcDialog.bottom - rcDialog.top );

			// Calculate cialog position
			nDialogLeft		= ( ptMouse.x - nDialogWidth );
			nDialogTop		= ( ptMouse.y - nDialogHeight );

			// Ensure that left position is ok
			if( nDialogLeft < 0 )
			{
				// Left position is not ok

				// Correct left position
				nDialogLeft = 0;

			} // End of left position is not ok

			// Ensure that top position is ok
			if( nDialogTop < 0 )
			{
				// Top position is not ok

				// Correct top position
				nDialogTop = 0;

			} // End of top position is not ok

			// Move dialog window
			bResult = MoveWindow( hWndDialog, nDialogLeft, nDialogTop, nDialogWidth, nDialogHeight, TRUE );

		} // End of successfully got mouse position

	} // End of successfully got dialog size

	return bResult;

} // End of function InputBoxDialogPositionToMouse

INT_PTR CALLBACK InputBoxDialogProcedure( HWND hWndDialog, UINT uMessage, WPARAM wParam, LPARAM )
{
	BOOL bResult = FALSE;

	// Select message
	switch( uMessage )
	{
		case WM_INITDIALOG:
		{
			// An init dialog message

			// Position template dialog to mouse
			InputBoxDialogPositionToMouse( hWndDialog );

			// Set title
			SetDlgItemText( hWndDialog, IDC_TITLE, g_lpszTitle );

			// Set edit text
			SetDlgItemText( hWndDialog, IDC_EDITTEXT, g_lpszInputText );

			// Select edit text
			SendDlgItemMessage( hWndDialog, IDC_EDITTEXT, EM_SETSEL, ( WPARAM )0, ( LPARAM )-1 );

			// Update return value
			bResult = TRUE;

			// Break out of switch
			break;

		} // End of an init dialog message
		case WM_COMMAND:
		{
			// A command message

			// Select command
			switch( LOWORD( wParam ) )
			{
				case IDOK:
				{
					// An ok command

					// Get edit text
					GetDlgItemText( hWndDialog, IDC_EDITTEXT, g_lpszInputText, STRING_LENGTH );

					// End dialog with ok
					EndDialog( hWndDialog, IDOK );

					// Break out of switch
					break;

				} // End of an ok command
				case IDCANCEL:
				{
					// A cancel command

					// End dialog with cancel
					EndDialog( hWndDialog, IDCANCEL );

					// Break out of switch
					break;

				} // End of a cancel command

			}; // End of selection for command

			// Update return value
			bResult = TRUE;

			// Break out of switch
			break;

		} // End of an init dialog message

	}; // End of selection for message

	return bResult;

} // End of function InputBoxDialogProcedure

BOOL InputBoxDialog( HWND hWndParent, HINSTANCE hInstance, LPTSTR lpszInputText, LPCTSTR lpszTitle )
{
	BOOL bResult = FALSE;

	// Allocate string memory
	g_lpszInputText	= new char[ STRING_LENGTH + sizeof( char ) ];
	g_lpszTitle		= new char[ STRING_LENGTH + sizeof( char ) ];

	// Copy texts into global
	lstrcpy( g_lpszInputText,	lpszInputText );
	lstrcpy( g_lpszTitle,		lpszTitle );

	// Show template dialog
	if( DialogBox( hInstance, MAKEINTRESOURCE( IDD_INPUT_BOX_DIALOG ), hWndParent, InputBoxDialogProcedure ) == IDOK )
	{
		// Dialog box was shown and ok button was pressed

		// Get input text from global
		lstrcpy( lpszInputText, g_lpszInputText );

		// Update return value
		bResult = TRUE;

	} // End of dialog box was shown and ok button was pressed

	// Free string memory
	delete [] g_lpszInputText;
	delete [] g_lpszTitle;

	return bResult;

} // End of function InputBoxDialog
