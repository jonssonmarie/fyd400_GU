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
int CVICALLBACK GenerateData 	(int panel, int controlID, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK Shutdown     	(int panel, int controlID, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK send_panel 		(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK send_panel2 	(int panel2, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK Clearing 		(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);	
int CVICALLBACK Clearing2 		(int panel2, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK color 			(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK color2 			(int panel2, int control, int event, void *callbackData, int eventData1, int eventData2);	


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
	panel = NewPanel(0, "User 1",  VAL_AUTO_CENTER, ATTR_TOP , 500, 600);   //int NewPanel (int parentPanelHandle, char panelTitle[], int panelTop, int panelLeft, int panelHeight, int panelWidth);
	SetPanelAttribute(panel, ATTR_CONFORM_TO_SYSTEM, 1); 				// int SetPanelAttribute (int panelHandle, int panelAttribute, ...);
	SetPanelPos (panel, PANEL_TOP, PANEL_LEFT);
	
	panel2 = NewPanel(0, "User 2",  VAL_AUTO_CENTER, ATTR_LEFT, 500, 600);   
	SetPanelAttribute(panel2, ATTR_CONFORM_TO_SYSTEM, 1); 
	SetPanelPos (panel2, PANEL2_TOP, PANEL2_LEFT);	
	SetActivePanel(panel);
	
	// Create a Quit buttons
    quitButton = NewCtrl (panel, CTRL_SQUARE_COMMAND_BUTTON, "Quit", 100, 50);
    InstallCtrlCallback (panel, quitButton, Shutdown, 0);			//int InstallCtrlCallback (int panelHandle, int controlID, CtrlCallbackPtr eventFunction, void *callbackData);
    SetCtrlAttribute (panel, quitButton, ATTR_CMD_BUTTON_COLOR, VAL_YELLOW);  
    SetCtrlAttribute (panel, quitButton, ATTR_WIDTH, 100);
	SetCtrlAttribute (panel, quitButton, ATTR_LEFT, 450);
	SetCtrlAttribute (panel, quitButton, ATTR_TOP, 400);
	
	quitButton2 = NewCtrl (panel2, CTRL_SQUARE_COMMAND_BUTTON, "Quit", 100, 50);
    InstallCtrlCallback (panel2, quitButton2, Shutdown, 0);			
    SetCtrlAttribute (panel2, quitButton2, ATTR_CMD_BUTTON_COLOR, VAL_YELLOW);  
    SetCtrlAttribute (panel2, quitButton2, ATTR_WIDTH, 100);
	SetCtrlAttribute (panel2, quitButton2, ATTR_LEFT, 450);
	SetCtrlAttribute (panel2, quitButton2, ATTR_TOP, 400);
	
	//The Quit button will receive an EVENT_COMMIT when the panel is closed with the system menu
    SetPanelAttribute (panel, ATTR_CLOSE_CTRL, quitButton);
	SetPanelAttribute (panel2, ATTR_CLOSE_CTRL, quitButton2);
	
	
	//Create a text message and a text box in panels
	textBoxCtrlW1 = NewCtrl (panel, CTRL_TEXT_BOX_LS, "Your Messege", 100, 100);
	SetTextCtrlHeight (panel, textBoxCtrlW1, 200);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_CALLBACK_DATA, textW1);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_MAX_ENTRY_CHARS, 300);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_VISIBLE_LINES, 10);
	SetCtrlAttribute (panel, textBoxCtrlW1, ATTR_ENTER_IS_NEWLINE, 1);
		
	textBoxCtrlW2 = NewCtrl (panel2, CTRL_TEXT_BOX_LS, "Your Messege", 100, 100);
	SetTextCtrlHeight (panel2, textBoxCtrlW2, 200);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_CALLBACK_DATA, textW2);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_MAX_ENTRY_CHARS, 300);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_VISIBLE_LINES, 10);
	SetCtrlAttribute (panel2, textBoxCtrlW2, ATTR_ENTER_IS_NEWLINE, 1);
	
	
	//Create a read text and a text box in panels with no edit
	textBoxCtrlR1 = NewCtrl (panel, CTRL_TEXT_BOX_LS, "Answer", 300, 100);
	SetTextCtrlHeight (panel, textBoxCtrlR1, 200);
	SetCtrlAttribute (panel, textBoxCtrlR1, ATTR_MAX_ENTRY_CHARS, 300);
	SetCtrlAttribute (panel, textBoxCtrlR1, ATTR_NO_EDIT_TEXT, 1);
	SetCtrlAttribute (panel, textBoxCtrlR1, ATTR_VISIBLE_LINES, 10);
	
	textBoxCtrlR2 = NewCtrl (panel2, CTRL_TEXT_BOX_LS, "Answer", 300, 100);
	SetTextCtrlHeight (panel2, textBoxCtrlR2, 200);
	SetCtrlAttribute (panel2, textBoxCtrlR2, ATTR_MAX_ENTRY_CHARS, 300);
	SetCtrlAttribute (panel2, textBoxCtrlR2, ATTR_NO_EDIT_TEXT, 1);
	SetCtrlAttribute (panel2, textBoxCtrlR2, ATTR_VISIBLE_LINES, 10);
		
	
	//Create a Clear buttons
	clear_button = NewCtrl (panel, CTRL_SQUARE_COMMAND_BUTTON, "Clear", 150, 325);
	InstallCtrlCallback (panel, clear_button, Clearing, 0);
	
	clear_button2 = NewCtrl (panel2, CTRL_SQUARE_COMMAND_BUTTON, "Clear", 150, 325);
	InstallCtrlCallback (panel2, clear_button2, Clearing2, 0);

	//int InstallCtrlCallback (int panelHandle, int controlID, CtrlCallbackPtr eventFunction, void *callbackData);
	//Create a send buttons 
	send_button = NewCtrl(panel, CTRL_SQUARE_COMMAND_BUTTON, "Send", 100, 325 );
	InstallCtrlCallback (panel, send_button, send_panel, 0);	
	
	send_button2 = NewCtrl(panel2, CTRL_SQUARE_COMMAND_BUTTON, "Send", 100, 325 );
	InstallCtrlCallback (panel2, send_button2, send_panel2, 0);	
	
	// Create a color buttons
	color_button = NewCtrl(panel, CTRL_COLOR_NUMERIC_LS, "Color", 350, 325);
	InstallCtrlCallback (panel, color_button, color, 0);	
	
	color_button2 = NewCtrl(panel2, CTRL_COLOR_NUMERIC_LS, "Color", 350, 325);
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

int CVICALLBACK Clearing2 (int panel2, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	if (event == EVENT_COMMIT)
	{
	//delete entire content in textbox when Quit and reset 
	DeleteTextBoxLines(panel2, textBoxCtrlW2, 0, -1);
	ResetTextBox(panel2, textBoxCtrlW2, " ");
	}
	return 0;
}


int CVICALLBACK send_panel (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{	
	 
	if (event == EVENT_COMMIT)
		{
		GetCtrlVal(panel, textBoxCtrlW1, textW1);			 // int GetCtrlVal (int panelHandle, int controlID, void *value);
		SetCtrlVal(panel2, textBoxCtrlR2, textW1);			// int SetCtrlVal (int panelHandle, int controlID, ...);
		}
	return 0;
}


int CVICALLBACK send_panel2 (int panel2, int control, int event, void *callbackData, int eventData1, int eventData2)
{	
	
	SetActiveCtrl(panel2, textBoxCtrlW2);
	if (event == EVENT_COMMIT)
		{
		GetCtrlVal(panel2, textBoxCtrlW2, textW2);			 // int GetCtrlVal (int panelHandle, int controlID, void *value);
		SetCtrlVal(panel, textBoxCtrlR1, textW2);	
		}
	return 0;
}


// Control of the color of the text
int CVICALLBACK color (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int val;
	if (event == EVENT_COMMIT)
		{
		GetCtrlVal(panel, color_button, &val);
		SetCtrlAttribute(panel, textBoxCtrlR1 ,ATTR_TEXT_COLOR, val);
		}
	return 0;
}


// Control of the color of the text
int CVICALLBACK color2 (int panel2, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int val;
	if (event == EVENT_COMMIT)
		{
		GetCtrlVal(panel2, color_button2, &val);
		SetCtrlAttribute(panel2, textBoxCtrlR2 ,ATTR_TEXT_COLOR, val);
		}
	return 0;
}


