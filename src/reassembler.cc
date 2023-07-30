#include "reassembler.hh"
#include <string_view>
using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring, Writer& output )
{
  // Your code here.
  // has remain data can't write, since full or out of order
  if( data.empty() ){
    if( is_last_substring)
      output.close();
    return;
  }
  if (is_last_substring )
    eof_ = true;
  if( output.available_capacity() == 0 ) return;
  auto end_idx = first_index + data.size();
  auto first_unacceptable = first_unassembled_ + output.available_capacity();
  if( end_idx <= first_unassembled_ || first_index >= first_unacceptable ) return;
  //string_view str{data};
  if( end_idx > first_unacceptable ) {
    data = data.substr(0, first_unacceptable - first_index);
    eof_ = false;
    //str.remove_suffix(end_idx - first_unacceptable);
  }
  if( first_index > first_unassembled_ ){
    pushto_buffer(first_index, std::move(data));
    return;
  }

  if( first_index < first_unassembled_) {
    data = data.substr(first_unassembled_ - first_index);
  }
  first_unassembled_ += data.size();
  output.push(std::move(data));
  if( eof_ ) {
    output.close();
  }

  if( buffer_.size() && buffer_.begin()->first <= first_unassembled_ ) {
    popfrom_buffer(output);
  }
}
void Reassembler::pushto_buffer(uint64_t first_index, string data)
{
  auto begin_index = first_index;
  auto end_idx = first_index + data.size();
  for(auto it = buffer_.begin(); it != buffer_.end() && begin_index < end_idx; ) {
    
    if( it->first <= begin_index ) {
      begin_index = std::max(begin_index, it->first + it->second.size());
      it++;
      continue;
    }
    if(first_index == begin_index && end_idx <= it->first ) {
      bytes_pending_ += data.size();
      buffer_.emplace(it, first_index, std::move(data));
      //buffer_.emplace( first_index, std::move(data));
      return;
    }
    auto right_index = std::min(it->first, end_idx);
    auto len = right_index - begin_index;
    it = buffer_.emplace(it, begin_index, data.substr(begin_index - first_index, len));
    bytes_pending_ += len;
    begin_index = right_index;
    //it++;

  }
  if( begin_index < end_idx ) {
    bytes_pending_ += end_idx - begin_index;
    buffer_.emplace_back(begin_index, data.substr(begin_index - first_index));
  }
}
void Reassembler::popfrom_buffer(Writer& output)
{
  //auto end = buffer_.upper_bound(first_unassembled_);
  for(auto it = buffer_.begin(); it != buffer_.end(); ) {
    if( it->first > first_unassembled_ ) {
      break;
    }
    auto first_index = it->first;
    auto end_index = first_index + it->second.size();
    if( end_index < first_unassembled_ ) {
      bytes_pending_ -= it->second.size();
    } else {
      auto data = std::move(it->second);
      bytes_pending_ -= data.size();
      if( first_index < first_unassembled_ )
        data = data.substr(first_unassembled_ - first_index);
      first_unassembled_ += data.size();
      output.push(std::move(data));
     
    }
    it = buffer_.erase(it);
  }
  if( eof_ && !buffer_.size())
    output.close();
}
uint64_t Reassembler::bytes_pending() const
{
  // Your code here.
  return bytes_pending_;
}
