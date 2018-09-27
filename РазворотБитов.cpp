#include <iostream>

long ReverseBits(long& value) {
   value = (value & 0x55) << 1 | (value & 0xAA) >> 1;
   value = (value & 0x33) << 2 | (value & 0xCC) >> 2;
   value = (value & 0x0F) << 4 | (value & 0xF0) >> 4;

   return value;
}

int main() {
   long value = 1;
   std::cout << (ReverseBits(value)) << std::endl;

   return 0;
}
