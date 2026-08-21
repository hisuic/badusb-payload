#include "Keyboard.h"

// Delay between each character (ms)
const unsigned long CHAR_DELAY = 50;

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
  delay(50);
}

void typeString(const char* str)
{
  while (*str)
  {
    Keyboard.write(*str);
    delay(CHAR_DELAY);
    str++;
  }
}

/* Init function */
void setup()
{
  // Beginning the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // Hello World
  delay(2000);

  // Win + R
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();

  delay(2000);

  // Type notepad.exe with 50ms delay between characters
  typeString("notepad.exe");

  typeKey(KEY_RETURN);

  delay(2000);

  // Type text with 50ms delay between characters
  typeString(
    "Curiosity is often considered a trait reserved for children, who naturally question the world around them. "
    "However, maintaining a sense of wonder throughout adulthood is one of the most effective ways to ensure a "
    "fulfilling and dynamic life. As an AI, I don't \"feel\" curiosity in the human sense, but my entire existence "
    "is built on the pursuit and synthesis of information - a digital echo of human inquisitiveness."
  );

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

void loop() {}
