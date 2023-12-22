/*
3.1.1 Händelsestyrning - 1p
Med hjälp av så kallade 'Events' i LabWindows kan man styra vad som ska hända när användaren
gör något speciellt i en grafisk miljö. Skapa ett program där användaren kan mata in en text i ett fält
och sedan skicka den till en textkontroll i en annan panel (se exempel) – antingen genom ’Enter’
eller genom vänstermusklick på en OK-knapp. Innehållet i textkontroll två ska inte kunna ändras av
användaren. 
*/

#include <cvirte.h>		
#include <userint.h>
#include "3_1_1.h"

#define PANEL1_TOP 400
#define PANEL1_LEFT 1000
#define PANEL2_TOP 400
#define PANEL2_LEFT  500

static int panel1, panel2;

int main (int argc, char *argv[])		// control of Panel
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panel1 = LoadPanel (0, "3_1_1.uir", Panel1)) < 0)
		return -1;
	if ((panel2 = LoadPanel (0, "3_1_1.uir", Panel2)) < 0)
		return -1;
	DisplayPanel (panel1);
	SetPanelPos (panel1, PANEL1_TOP, PANEL1_LEFT);
	DisplayPanel (panel2);
	SetPanelPos (panel2, PANEL2_TOP, PANEL2_LEFT);
	RunUserInterface ();
	DiscardPanel (panel1);
	DiscardPanel (panel2);
	return 0;
}


int CVICALLBACK Panel1Callback (int panel, int event, void *callbackData, int eventData1, int eventData2)  // Set the panel to active
{
	int SetActivePanel (int panel1);
	return 0;
}


int CVICALLBACK OkCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)  // Control of OK button
{
	char text[300];
	int textLength;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panel1, Panel1_TEXTMSGIN, text);			 // int GetCtrlVal (int panelHandle, int controlID, void *value);
			if (GetCtrlAttribute(panel, Panel1_TEXTMSGIN, ATTR_STRING_TEXT_LENGTH, &textLength) < 100)
				{
				SetCtrlVal (panel2, Panel2_TEXTMSG, text);
				}
			break;
			
		case Panel1_OKBUTTON:
			GetCtrlVal (panel1, Panel1_TEXTMSGIN, text);			// int GetCtrlVal (int panelHandle, int controlID, void *value);
			SetCtrlVal (panel2, Panel2_TEXTMSG, text);
		break;
			
		case EVENT_LEFT_CLICK:
			SetActiveCtrl(panel1, Panel1_TEXTMSGIN);
			break;
	}
	return 0;
}


int CVICALLBACK QuitCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)		// Control of Quit
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}


int CVICALLBACK TextInCallback (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)		// Control of textbox
{
	switch (event)
	{	
		case EVENT_LEFT_CLICK:
			SetActiveCtrl(panel1, Panel1_OKBUTTON);
			break;
									 
		case EVENT_COMMIT:
			SetActiveCtrl(panel1, Panel1_TEXTMSGIN);	
			break;
				
		case EVENT_CLOSE:
			DeleteTextBoxLines(panel, Panel1_QUITBUTTON, 0, -1);  //delete entire content in textbox when Quit
			QuitUserInterface (0);
			break;
	}
	return 0;
}
