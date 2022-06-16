#include "led_manager.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define TAG "BOARD"

// PINS
#define LED_PARENT_PIN GPIO_NUM_33
#define LED_CHILD_PIN GPIO_NUM_32

struct _led_state led_state[2] = {
    {LED_OFF, LED_PARENT_PIN, "blue"},
    {LED_OFF, LED_CHILD_PIN, "red"}};

/**
 * @brief Turn LED on or off.
 *
 * @param pin
 * @param onoff
 */
void updated_led_state(uint8_t pin, uint8_t onoff)
{

  // 1. Verify pin existence
  for (int i = 0; i < 2; i++)
  {
    if (led_state[i].pin != pin)
    {
      continue;
    }

    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    gpio_set_level(pin, onoff);
    return;
  }

  ESP_LOGE(TAG, "LED was not found");
}

static void led_init(void)
{
  for (int i = 0; i < 2; i++)
  {
    gpio_reset_pin(led_state[i].pin);
    gpio_set_direction(led_state[i].pin, GPIO_MODE_OUTPUT);
  }
}

/**
 * @brief Initializes led  board manager.
 *
 */
void led_manager_init(void)
{
  led_init();
}
