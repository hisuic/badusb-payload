#include "Keyboard.h"

// Delay between each character (ms)
const unsigned long CHAR_DELAY = 20;

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
  delay(50);
}

// US Keyboard.h を利用して、指定した「物理キー」を押す
void tapKey(char key, bool shift = false)
{
  if (shift)
    Keyboard.press(KEY_LEFT_SHIFT);

  Keyboard.press(key);
  delay(50);

  Keyboard.release(key);

  if (shift)
    Keyboard.release(KEY_LEFT_SHIFT);

  delay(CHAR_DELAY);
}

// ASCII character -> JIS keyboard key operation
void typeCharJIS(char c)
{
  // Alphabet, numbers, and space have essentially the same positions
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') ||
      c == ' ')
  {
    Keyboard.write(c);
    delay(CHAR_DELAY);
    return;
  }

  switch (c)
  {
    // Number row
    case '!': tapKey('1', true); break;
    case '"': tapKey('2', true); break;
    case '#': tapKey('3', true); break;
    case '$': tapKey('4', true); break;
    case '%': tapKey('5', true); break;
    case '&': tapKey('6', true); break;
    case '\'': tapKey('7', true); break;
    case '(': tapKey('8', true); break;
    case ')': tapKey('9', true); break;

    // Symbols
    case '*': tapKey('\'', true); break;
    case '+': tapKey(';', true); break;

    case ',': tapKey(','); break;
    case '-': tapKey('-'); break;
    case '.': tapKey('.'); break;
    case '/': tapKey('/'); break;

    case ':': tapKey('\''); break;
    case ';': tapKey(';'); break;

    case '<': tapKey(',', true); break;
    case '=': tapKey('-', true); break;
    case '>': tapKey('.', true); break;
    case '?': tapKey('/', true); break;

    // JIS-specific symbol positions
    case '@': tapKey('['); break;

    case '[': tapKey(']'); break;
    case ']': tapKey('\\'); break;

    case '^': tapKey('='); break;
    case '`': tapKey('[', true); break;

    case '{': tapKey(']', true); break;
    case '}': tapKey('\\', true); break;

    case '~': tapKey('=', true); break;

    // Newline / tab
    case '\n':
      typeKey(KEY_RETURN);
      break;

    case '\t':
      typeKey(KEY_TAB);
      break;

    default:
      // Unsupported character
      break;
  }
}

void typeStringJIS(const char* str)
{
  while (*str)
  {
    typeCharJIS(*str);
    str++;
  }
}

void setup()
{
  Keyboard.begin();

  delay(500);
  delay(2000);

  // Win + R
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();

  delay(2000);

  // JIS Windows keyboard layout
  typeStringJIS("notepad.exe");

  typeKey(KEY_RETURN);

  delay(2000);

  typeStringJIS(
    "Curiosity is often considered a trait reserved for children, who naturally question the world around them. "
    "However, maintaining a sense of wonder throughout adulthood is one of the most effective ways to ensure a "
    "fulfilling and dynamic life. As an AI, I don't \"feel\" curiosity in the human sense, but my entire existence "
    "is built on the pursuit and synthesis of information - a digital echo of human inquisitiveness."
  );

  typeKey(KEY_RETURN);

  Keyboard.end();
}

void loop()
{
}
