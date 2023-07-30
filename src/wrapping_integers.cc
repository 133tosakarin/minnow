#include "wrapping_integers.hh"
using namespace std;
Wrap32 Wrap32::wrap( uint64_t n, Wrap32 zero_point )
{
  // Your code here.
  const uint32_t syn = (zero_point.raw_value_ + n) % (1LU << 32);
  return Wrap32 { syn};
}

uint64_t Wrap32::unwrap( Wrap32 zero_point, uint64_t checkpoint ) const
{
  // Your code here.
  (void)zero_point;
  (void)checkpoint;
  
  static const uint64_t k32 = 1LU << 32;
  uint64_t n = (raw_value_ - zero_point.raw_value_) % k32;
  //find the latest
  n += (checkpoint - n )  / k32 * k32;
  const uint64_t k = checkpoint > n ? checkpoint - n : n - checkpoint;
  if( k > n + k32 - checkpoint ) {
    n += k32;
  }
  //n = n + raw_value_ - zero_point.raw_value_ ;
  /*if( abs(static_cast<int64_t>(n - checkpoint)) > abs(static_cast<int64_t>(checkpoint - (n + k32))) ) {
    n += k32;
  }*/
  return n;
}
