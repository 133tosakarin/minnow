#include <stdexcept>

#include "byte_stream.hh"
#include <iostream>
using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), rd_idx_(0), wt_idx_(0), total_(0) {}

void ByteStream::move()
{
  uint64_t size = wt_idx_ - rd_idx_;
  for( size_t i = 0; i < size; ++i ) {
     stream_[i] = stream_[i + rd_idx_];
  } 
  rd_idx_ = 0;
  wt_idx_ = size;

}
void Writer::push( string data )
{
  // Your code here.
  int remain = std::min(data.size(),available_capacity());
  if( remain <= 0 ) return;
  stream_.push_back(std::move(data.substr(0, remain)));
  peek_queue.emplace_back(stream_.back().c_str(), remain);
  wt_idx_ += remain;
  total_ += remain;
  
}

void Writer::close()
{
  eof_ = true;
}

void Writer::set_error()
{
  error_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return eof_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  int size = capacity_ - wt_idx_;
  return size < 0 ? 0 : size;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return total_;
}

string_view Reader::peek() const
{
  // Your code here.
  //printf("%s,  %ld\n", stream_.data(),  rd_idx_);
  //string s = stream_.data();
  //std::cout << s <<" " << rd_idx_ << std::endl;
  //std::cout.flush();
  if( !peek_queue.empty()) {
    return peek_queue.front();
  }
  return {};
}

bool Reader::is_finished() const
{
  // Your code here.

  return total_ == rd_idx_ && eof_;
}

bool Reader::has_error() const
{
  // Your code here.
  return error_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  /*int size = wt_idx_ - rd_idx_;
  for( int i = 0; i < size; ++i ) {
    stream_[i] = stream_[i + rd_idx_];
  }*/
  while(len) {
    uint64_t sz = peek_queue.front().size();
    if(peek_queue.front().size() > len){
      peek_queue.front().remove_prefix(len);
      wt_idx_ -= len;
      rd_idx_ += len;
      return;

    }
    len -= sz;
    wt_idx_ -= sz;
    rd_idx_ += sz;
    peek_queue.pop_front();
    stream_.pop_front();
    if( peek_queue.empty())
     break;
   
  }
  (void)len;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return wt_idx_;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return rd_idx_;
}
