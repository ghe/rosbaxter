#include "rosbaxter.h"

int main(int argc, char *argv[])
{
  RosBaxter baxter("rosbaxtertest");

  while(baxter.ok())
  {
    baxter.update();
  }

  return 0;
}
