/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // Hello World
  delay(2000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(2000);

  Keyboard.print("notepad.exe");

  typeKey(KEY_RETURN);

  delay(2000);

  Keyboard.print("Curiosity is often considered a trait reserved for children, who naturally question the world around them. However, maintaining a sense of wonder throughout adulthood is one of the most effective ways to ensure a fulfilling and dynamic life. As an AI, I d");
  Keyboard.print("on't \"feel\" curiosity in the human sense, but my entire existence is built on the pursuit and synthesis of information—a digital echo of human inquisitiveness.");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
