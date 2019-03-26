/*
 * Project SIT210-BlinkName
 * Author: Brett T Best
 * Date: March 2019
 */

#include <map>
#include <vector>

static const float sMorseCodeUnit = 0.5;
static const std::map<char, std::vector<int>> sMorseCodeMap = {{'A', {1,3}}, {'B', {3,1,1,1}}, {'C', {3,1,3,1}}, {'D', {3,1,1}}, {'E', {1}}, {'F', {1,1,3,1}}, {'G', {3,3,1}}, {'H', {1,1,1,1}}, {'I', {1,1}}, {'J', {1,3,3,3}}, {'K', {3,1,3}}, {'L', {1,3,1,1}}, {'M', {3,3}}, {'N', {3,1}}, {'O', {3,3,3}}, {'P', {1,3,3,1}}, {'Q', {3,3,1,3}}, {'R', {1,3,1}}, {'S', {1,1,1}}, {'T', {3}}, {'U', {1,1,3}}, {'V', {1,1,1,3}}, {'W', {1,3,3}}, {'X', {3,1,1,3}}, {'Y', {3,1,3,3}}, {'Z', {3,3,1,1}}};

static const int sMorseCodeLED = D7;

void setup()
{
  pinMode(sMorseCodeLED, OUTPUT);
}

void loop()
{

}
