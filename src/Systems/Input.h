#pragma once

class Input
{
public:
  Input(Input&) = delete;

  static Input& Instance();

  bool isKey(int key);

	const int keyCount() const;

	void keyCountReset();
  void keyPressed(int key);
  void keyReleased(int key);

private:
  Input();

  bool m_keys[257] = {false};

	int m_keyCount = 0;

  // I am using this to get around
  // the 'Unknown' key value in the sf::Keyboard doc.
  int m_offset = 1;
};
