#include <cvirte.h>		
#include <userint.h>
#include "3_2_1.h"
#include <color_picker.h>
#include <toolbox.h>

static int panelHandle;

// control of memory, load, display, discard panel and run GUI
int main (int argc, char *argv[])				
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "3_2_1.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

// Control of active panel
int CVICALLBACK Panel (int panel, int event, void *callbackData,				
					   int eventData1, int eventData2)
{
	SetActivePanel (panelHandle);
	return 0;
}

// Control of Quit
int CVICALLBACK Avsluta (int panel, int control, int event, void *callbackData, int eventData1, int eventData2) 		
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}


// Move the text to the right a few pixels.
int CVICALLBACK Right (int panel, int control, int event, void *callbackData, int eventData1, int eventData2) 
{
	int error =0, val;
	switch (event)
	{
		case EVENT_COMMIT:
			errChk(GetCtrlAttribute(panel, PANEL_TEXTMSG, ATTR_LEFT, &val))
			if (val < 170)
				{
			  	val += 10;
				errChk(SetCtrlAttribute(panel, PANEL_TEXTMSG, ATTR_LEFT, val));
				}
			break;
	}
	Error:
	return error;
}


// Move the text to the left a few pixels.
int CVICALLBACK Left (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int error = 0, val;
	switch (event)
	{
		case EVENT_COMMIT:		
			errChk(GetCtrlAttribute (panel, PANEL_TEXTMSG, ATTR_LEFT, &val));
			if (val > -80) 
				{
				val -=10;
				errChk(SetCtrlAttribute (panel, PANEL_TEXTMSG, ATTR_LEFT, val));
				}
			break;
	}
	Error:
	return error;
}


//   Move the text up a few pixels.
int CVICALLBACK Up (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int error = 0, val;
	switch (event)
	{
		case EVENT_COMMIT:
			errChk(GetCtrlAttribute (panel, PANEL_TEXTMSG, ATTR_TOP, &val));
			if (val > 20)
				{
				val -= 10; 
				errChk(SetCtrlAttribute (panel, PANEL_TEXTMSG, ATTR_TOP, val));
				}
			break;
	}
	Error:
	return error;
}


//   Move the text down a few pixels.
int CVICALLBACK Down (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int error = 0, val;
	switch (event)
	{
		case EVENT_COMMIT:
			errChk(GetCtrlAttribute (panel, PANEL_TEXTMSG, ATTR_TOP, &val));
			if(val < 150)
				{
				val += 10;
				errChk(SetCtrlAttribute (panel, PANEL_TEXTMSG, ATTR_TOP, val));
				}
			break;
	}
	Error:
	return error;
}

// Control of the color of the text
int CVICALLBACK color (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int val; 
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel, PANEL_COLORNUM, &val);
			SetCtrlAttribute(panel, PANEL_TEXTMSG ,ATTR_TEXT_COLOR, val );
			break;
	}
	return 0;
}
