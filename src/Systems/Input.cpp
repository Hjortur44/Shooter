#include "Input.h"

Input& Input::Instance()
{
  static Input INSTANCE;
  return INSTANCE;
}


bool Input::isKey(int key)
{
  return m_keys[key + m_offset];
}

const int Input::keyCount() const
{
	return m_keyCount;
}


void Input::keyCountReset()
{
	m_keyCount = 0;
}


void Input::keyPressed(int key)
{
	if(!m_keys[key + m_offset])
		m_keyCount++;

  m_keys[key + m_offset] = true;
}


void Input::keyReleased(int key)
{
	if(m_keys[key + m_offset])
		m_keyCount--;

  m_keys[key + m_offset] = false;
}


// private
Input::Input()
{
  for(int i = 0; i < 257; i++)
    m_keys[i] = false;
}