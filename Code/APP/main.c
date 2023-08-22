#include "APP_Includes.h"


int main(){
	DIO_voidInit();
	LCD_init();
	KPD_voidInit();
	Stepper_Init();
	
	u8 keyPressed, c = 0, count = 0, r = 0, n = 0, tries = 2;
	u8 InPassword[20];
	u8 Password[10]	= {'1', '2', '3', '4'};
	
	LCD_GoToXY(0, 0);
	LCD_displayString("Enter Password");
	
	LCD_GoToXY(1, 0);
	
	while(1){
		KPD_u8GetKeyState(&keyPressed);
		if (keyPressed != KPD_UnPressed) {
			if ((keyPressed >= '0') && (keyPressed <= '9')) {
				LCD_displayCharacter(keyPressed);
				
				InPassword[c++] = keyPressed;
			}
			
			if(keyPressed == '='){
				for(u8 i = 0; i < 4; i++){
					if(InPassword[i] == Password[i]){
						count++;
					}
					else{
						r++;
					}
				}
				
				if(count == 4){
					LCD_ClearScreen();
					LCD_displayString("Welcome Home");
					SelectStepAngle(180, 0);
				}
				if(r > 0){
					LCD_ClearScreen();
					LCD_displayString("Wrong Password");
				}
			}
			
			if(keyPressed == 'C'){
				if(tries > 0){
					count = 0;
					r = 0;
					c = 0;
					tries--;
					
					LCD_ClearScreen();
					LCD_GoToXY(0, 0);
					LCD_displayString("Enter Password");
					
					LCD_GoToXY(1, 0);
				}
				
				else{
					LCD_ClearScreen();
					LCD_displayString("Close System And");
					
					LCD_GoToXY(1, 0);
					LCD_displayString("Try Again");
				}
			}
		}
		
	}
	return 0;
}
