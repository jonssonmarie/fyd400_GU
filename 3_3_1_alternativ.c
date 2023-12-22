#include <cvirte.h>		
#include <userint.h>
#include <ansi_c.h>
#include <color_picker.h>

#define PANEL_TOP 400
#define PANEL_LEFT 1000
#define PANEL2_TOP 400
#define PANEL2_LEFT  300

// function prototypes                                              
void BuildGUI(void);
int CVICALLBACK GenerateData 	(int panelHandle, int controlID, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK Shutdown     	(int panelHandle, int controlID, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK Clearing 		(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);	
int CVICALLBACK send_panel 		(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK color 			(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


int panel, panel2, quitButton, quitButton2, send_button, send_button2, color_button, color_button2;
int textBoxCtrlW1, textBoxCtrlW2, textBoxCtrlR1, textBoxCtrlR2, clear_button, clear_button2;
char textW1[300], textW2[300];


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
        return -1;
    
    // Build, display and runs the GUI 
    BuildGUI();
    DisplayPanel(panel);
	DisplayPanel(panel2);
    RunUserInterface();

    // Free resources and return
    DiscardPanel(panel);
	DiscardPanel(panel2);
    CloseCVIRTE();
    return 0;
}


void BuildGUI(void)
{
	// Create a new panels and set positions
	panel = NewPanel(0, "Write",  VAL_AUTO_CENTER, ATTR_TOP , 500, 600);   //int NewPanel (int parentPanelHandle, char panelTitle[], int panelTop, int panelLeft, int panelHeight, int panelWidth);
	SetPanelAttribute(panel, ATTR_CONFORM_TO_SYSTEM, 1); 				// int SetPanelAttribute (int panelHandle, int panelAttribute, ...);
	SetPanelPos (panel, PANEL_TOP, PANEL_LEFT);
	
	panel2 = NewPanel(0, "Read",  VAL_AUTO_CENTER, ATTR_LEFT, 500, 600);   
	SetPanelAttribute(panel2, ATTR_CONFORM_TO_SYSTEM, 1); 
	SetPanelPos (panel2, PANEL2_TOP, PANEL2_LEFT);	
	
	
	// Create a Quit buttons
    quitButton = NewCtrl (panel, CTRL_SQUARE_COMMAND_BUTTON, "Quit", 100, 50);
    InstallCtrlCallback (panel, quitButton, Shutdown, 0);			//int InstallCtrlCallback (int panelHandle, int controlID, CtrlCallbackPtr eventFunction, void *callbackData);
    SetCtrlAttribute (panel, quitButton, ATTR_CMD_BUTTON_COLOR, VAL_YELLOW);  
    SetCtrlAttribute (panel, quitButton, ATTR_WIDTH, 100);
	SetCtrlAttribute (panel, quitButton, ATTR_LEFT, 400);
	SetCtrlAttribute (panel, quitButton, ATTR_TOP, 300);
	
	
	//The Quit button will receive an EVENT_COMMIT when the panel is closed with the system menu
    SetPanelAttribute (panel, ATTR_CLOSE_CTRL, quitButton);
	
	
	//Create a text message and a text box in panels
	textBoxCtrlW1 = NewCtrl (panel, CTRL_TEXT_BOX_LS, "Your Text", 100, 100);
	SetTextCtrlHeight (panel, textBoxCtrlW1, 200);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_CALLBACK_DATA, textW1);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_MAX_ENTRY_CHARS, 300);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_ENTER_IS_NEWLINE, 1);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_VISIBLE_LINES, 15);
		
	textBoxCtrlW2 = NewCtrl (panel2, CTRL_TEXT_BOX_LS, "Received text", 100, 100);
	SetTextCtrlHeight (panel2, textBoxCtrlW2, 200);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_CALLBACK_DATA, textW2);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_MAX_ENTRY_CHARS, 300);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_NO_EDIT_TEXT, 1);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_VISIBLE_LINES, 15);
	

	//Create a Clear buttons
	clear_button = NewCtrl (panel, CTRL_SQUARE_COMMAND_BUTTON, "Clear", 150, 325);
	InstallCtrlCallback (panel, clear_button, Clearing, 0);
	//int InstallCtrlCallback (int panelHandle, int controlID, CtrlCallbackPtr eventFunction, void *callbackData);
	
	
	//Create a send buttons 
	send_button = NewCtrl(panel, CTRL_SQUARE_COMMAND_BUTTON, "Send", 100, 325 );
	InstallCtrlCallback (panel, send_button, send_panel, 0);	
	
	
	// Create a color button
	color_button2 = NewCtrl(panel2, CTRL_COLOR_NUMERIC_LS, "Color", 150, 325);
	InstallCtrlCallback (panel2, color_button2, color, 0);	
}


int CVICALLBACK Shutdown (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
    if (event == EVENT_COMMIT)
        QuitUserInterface(0);
    return 0;
}


int CVICALLBACK Clearing (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	if (event == EVENT_COMMIT)
	{
	//delete entire content in textbox when Quit and reset
	DeleteTextBoxLines(panel, textBoxCtrlW1, 0, -1);
	ResetTextBox(panel, textBoxCtrlW1, " ");
	}
	return 0;
}


int CVICALLBACK send_panel (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{	
	 
	if (event == EVENT_COMMIT)
		{
		GetCtrlVal(panel, textBoxCtrlW1, textW1);			 // int GetCtrlVal (int panelHandle, int controlID, void *value);
		SetCtrlVal(panel2, textBoxCtrlW2, textW1);			// int SetCtrlVal (int panelHandle, int controlID, ...);
		}
	return 0;
}


// Control of the color of the text
int CVICALLBACK color (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int val;
	if (event == EVENT_COMMIT)
		{
		GetCtrlVal(panel2, color_button2, &val);
		SetCtrlAttribute(panel2, textBoxCtrlW2 ,ATTR_TEXT_COLOR, val);
		}
	return 0;
}

