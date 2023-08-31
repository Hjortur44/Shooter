#pragma once

class CBoundingBox
{
public:
  CBoundingBox();
  CBoundingBox(bool activate);

  bool isActive = false;
};