int setbits(int x, const int y, int position, const int n);
int create_rightmost_mask(const int y, const int position, const int n,
                          int* mask);
int clear_bitfield(int* x, const int position, const int n);
int set_rightmost(const int n);
void test(const int x, const int y, const int position, const int count,
          const int hypothesis);
