#include "tcp_receiver.hh"

using namespace std;

void TCPReceiver::receive( TCPSenderMessage message, Reassembler& reassembler, Writer& inbound_stream )
{
  // Your code here.
  (void)message;
  (void)reassembler;
  (void)inbound_stream;
  //it is the begining of bytesstream, generate a syn and back to a ack
  /*if( message.SYN ) {
    isn_ = message.seqno;
  }
  //recv data and put into stream
  auto absolute_syn = message.seqno.unwrap(isn_.value(), inbound_stream.bytes_pushed() + 1);
  auto first_index = message.SYN ? 0 : absolute_syn - 1;
  reassembler.insert(first_index, message.payload.release(), message.FIN,inbound_stream);*/
  


}

TCPReceiverMessage TCPReceiver::send( const Writer& inbound_stream ) const
{
  // Your code here.
  (void)inbound_stream;
  TCPReceiverMessage msg{};
  /*uint16_t win_size = inbound_stream.available_capacity();
  msg.window_size = win_size < UINT16_MAX ? win_size : UINT16_MAX;
  if( isn_.has_value() ) {

    msg.ackno = {Wrap32::wrap(inbound_stream.bytes_pushed() + 1, isn_.value())}; 
  }*/
  
  return msg;
}
