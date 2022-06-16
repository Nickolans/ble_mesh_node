#ifndef _LED_MANAGER_
#define _LED_MANAGER_

#define LED_ON 1
#define LED_OFF 0

struct _led_state
{
  uint8_t current;
  uint8_t pin;
  char *name;
};

void updated_led_state(uint8_t pin, uint8_t onoff);
void board_init(void);

#endif
