/*
 * Project SIT210-BlinkName
 * Author: Brett T Best
 * Date: March 2019
 */

#include <map>
#include <vector>

static std::string sName = "Brett";
static const int sMorseCodeLED = D7;

static std::map<char, std::vector<int>> sMorseCodeMap = {{'A', {1, 3}}, {'B', {3, 1, 1, 1}}, {'C', {3, 1, 3, 1}}, {'D', {3, 1, 1}}, {'E', {1}}, {'F', {1, 1, 3, 1}}, {'G', {3, 3, 1}}, {'H', {1, 1, 1, 1}}, {'I', {1, 1}}, {'J', {1, 3, 3, 3}}, {'K', {3, 1, 3}}, {'L', {1, 3, 1, 1}}, {'M', {3, 3}}, {'N', {3, 1}}, {'O', {3, 3, 3}}, {'P', {1, 3, 3, 1}}, {'Q', {3, 3, 1, 3}}, {'R', {1, 3, 1}}, {'S', {1, 1, 1}}, {'T', {3}}, {'U', {1, 1, 3}}, {'V', {1, 1, 1, 3}}, {'W', {1, 3, 3}}, {'X', {3, 1, 1, 3}}, {'Y', {3, 1, 3, 3}}, {'Z', {3, 3, 1, 1}}};

class LEDController
{
public:
  LEDController()
  {
    pinMode(sMorseCodeLED, OUTPUT);
    digitalWrite(sMorseCodeLED, LOW);
  }

  void turnOff(double waitDuration)
  {
    Serial.print("OFF: ");
    Serial.print(waitDuration/1000);
    Serial.print("\n");

    digitalWrite(sMorseCodeLED, LOW);
    delay(waitDuration);
  }

  void turnOn(double waitDuration)
  {
    Serial.print("ON: ");
    Serial.print(waitDuration/1000);
    Serial.print("\n");

    digitalWrite(sMorseCodeLED, HIGH);
    delay(waitDuration);
  }
};

class MorseCodeController
{
public:
  double unit = 0.5 * 1000;
  double letterPartsSpace = 1 * unit;
  double lettersSpace = 3 * unit;
  double wordsSpace = 7 * unit;

  LEDController ledController;

  MorseCodeController(LEDController ledController)
  {
    this->ledController = ledController;
  }

  void send(char character)
  {
    Serial.write("Starting Character: ");
    Serial.write(character);
    Serial.write("\n");

    char upperCharacter = toupper(character);

    std::vector<int> sequence = sMorseCodeMap[upperCharacter];
    int counter = 0;

    for (int duration : sequence)
    {
      ledController.turnOn(duration * unit);

      if (counter != sequence.size() - 1)
      {
        ledController.turnOff(letterPartsSpace);
      }
      else
      {
        ledController.turnOff(0);
      }

      counter++;
    }

    Serial.write("Ending Character: ");
    Serial.write(character);
    Serial.write("\n");
  }

  void send(std::string userString)
  {
    Serial.write("Sending String: ");
    Serial.write(userString.c_str());
    Serial.write("\n");

    int counter = 0;

    for (char &character : userString)
    {
      this->send(character);

      if (counter != userString.length() - 1)
      {
        ledController.turnOff(lettersSpace);
      }
      else
      {
        ledController.turnOff(0);
      }

      counter++;
    }

    ledController.turnOff(wordsSpace);

    Serial.write("Ending String: ");
    Serial.write(userString.c_str());
    Serial.write("\n");
  }
};

MorseCodeController morseCodeController = MorseCodeController(LEDController());

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  morseCodeController.send(sName);
}
