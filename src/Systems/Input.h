#pragma once

class Input
{
  bool m_keys[256] = {false};

  // I am using this to get around
  // the 'Unknown' key value in the sf::Keyboard doc.
  int m_offset = 1;

  Input();

public:
  Input(Input&) = delete;

  static Input& Instance();

  bool isKey(int key);

  void keyReleased(int key);
  void keyPressed(int key);
};
