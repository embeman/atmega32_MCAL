#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include <Dio.h>
#include <Dio_Cfg.h>
#include <Keypad_Cfg.h>




void Keypad_Init();
Keypad_KeyCoodeType Keypad_GetKey();
char Keypad_KeyCodeToChar(Keypad_KeyCoodeType);
#endif /* HAL_KEYPAD_KEYPAD_H_ */
