#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include </home/vincent/libjade-release-2023.05-1/ext/randombytes/randombytes.h>

extern void get_random_byte_sequence(const uint8_t *a);
extern void get_hashed_byte_sequence(const uint8_t *skp, const uint8_t* hp);
extern void get_encoded_point(const uint8_t * xp, const uint8_t * yp, const uint8_t * zp, const uint8_t * rp);
extern void get_decoded_point(const uint8_t * up, const uint8_t * rp1, const uint8_t * rp2, const uint8_t * rp3, const uint8_t * rp4);
extern void test_addition(const uint8_t * up, const uint8_t * kp, const uint8_t * rp1, const uint8_t * rp2, const uint8_t * rp3);
extern void point_mul(const uint8_t* kp, const uint8_t* up, const uint8_t* rp);

int main(void)
{
  uint64_t u[4] = {0x946f324e7264ae7c5, 0xd20a000a8052d626, 0xa53e667886fd2c0d, 0x8c22a62fef144d5};
  uint64_t k[4] = {0x123456789abcde03, 0x6666666666666666, 0x6666666666666666, 0x8666666666666666};
  
  uint64_t r[4], x[4], y[4], z[4]; 
  
  point_mul(k, u, r);
  
  printf("r: %lx%lx%lx%lx\n", r[3], r[2], r[1], r[0]);

  return 0;
}

