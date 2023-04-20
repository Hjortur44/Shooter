#include "Input.h"

Input::Input()
{
  for(int i = 0; i < 257; i++)
    m_keys[i] = false;
}


Input& Input::Instance()
{
  static Input INSTANCE;
  return INSTANCE;
}


bool Input::isKey(int key)
{
  return m_keys[key + m_offset];
}


void Input::keyPressed(int key)
{
  m_keys[key + m_offset] = true;
}


void Input::keyReleased(int key)
{
  m_keys[key + m_offset] = false;
}
