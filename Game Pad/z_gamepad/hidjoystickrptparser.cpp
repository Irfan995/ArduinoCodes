#include "hidjoystickrptparser.h"

JoystickReportParser::JoystickReportParser(JoystickEvents *evt) :
joyEvents(evt),
oldHat(0xDE),
oldButtons(0) {
  for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++)
    oldPad[i] = 0xD;
}

void JoystickReportParser::Parse(HID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
  bool match = true;

  // Checking if there are changes in report since the method was last called
  for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++)
    if (buf[i] != oldPad[i]) {
      match = false;
      break;
    }

  // Calling Game Pad event handler
  if (!match && joyEvents) {
    joyEvents->OnGamePadChanged((const GamePadEventData*)buf);

    for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++) oldPad[i] = buf[i];
  }

  uint8_t hat = (buf[5] & 0xF);

  // Calling Hat Switch event handler
  if (hat != oldHat && joyEvents) {
    joyEvents->OnHatSwitch(hat);
    oldHat = hat;
  }

  uint16_t buttons = (0x0000 | buf[6]);
  buttons <<= 4;
  buttons |= (buf[5] >> 4);
  uint16_t changes = (buttons ^ oldButtons);

  // Calling Button Event Handler for every button changed
  if (changes) {
    for (uint8_t i = 0; i < 0x0C; i++) {
      uint16_t mask = (0x0001 << i);

      if (((mask & changes) > 0) && joyEvents)
        if ((buttons & mask) > 0)
          joyEvents->OnButtonDn(i + 1);
        else
          joyEvents->OnButtonUp(i + 1);
    }
    oldButtons = buttons;
  }
}

void JoystickEvents::OnGamePadChanged(const GamePadEventData *evt) {

  leftJoyy=int(evt->Z2);
  left_X=int(evt->Z1);
  
  rightJoyy=int(evt->Y);
  right_X=int(evt->X);
  
  Buttonn=int(evt->Rz);

}



void JoystickEvents::OnHatSwitch(uint8_t hat) {
  hatt=int(hat);

}

void JoystickEvents::OnButtonUp(uint8_t but_id) {

 // Buttonn=int(but_id)+100;
}

void JoystickEvents::OnButtonDn(uint8_t but_id) 
{
 // Buttonn=int(but_id);

}

int JoystickEvents::get_hat(){
  return hatt;
}

int JoystickEvents::get_button(){
  return Buttonn;
}

int JoystickEvents::get_left(){
  return leftJoyy;
}

int JoystickEvents::get_left_X(){
  return left_X;
}

int JoystickEvents::get_right(){
  return rightJoyy;
}

int JoystickEvents::get_right_X(){
  return right_X;
}
