//
//  TLSSocket.hpp
//  smtp
//
//  Created by JASPER on 28/03/2023.
//

#ifndef TLSSocket_hpp
#define TLSSocket_hpp

#include <concepts>
#include <string>
#include <tls.h>

#include "Socket.hpp"
#include "SocketAddress.hpp"


//template<typename T>
//concept ByteReader = requires (T c) {
//    typename T::value_type;
//    { c.size() } -> std::convertible_to<std::size_t>;
//    { c.capacity() } -> std::convertible_to<std::size_t>;
//    { c.begin() } -> std::same_as<typename T::iterator>;
//    { c.end() } -> std::same_as<typename T::iterator>;
//};


class TLSSocket{
    
public:
    explicit TLSSocket();
    explicit TLSSocket(const std::string&, int);
    explicit TLSSocket(Socket&);
    ~TLSSocket();
    void bind(SocketAddress&);
    void connect(SocketAddress&);
    void connect(SocketAddress&, int);
    void disconnect();
//    SocketAddress getAddress() const noexcept{return address;};
//    inline int getFd() const noexcept{return fd;};
    inline bool isConnected() const noexcept{return connected;};
    template<ByteReader T> int read(T&);
    void setSoTimeout(int);
    int write(const std::string&&);
private:
    void init();
    void upgrade(Socket&);
//    SocketAddress address;
//    int fd = -1;
    bool connected = false;
    struct tls *ctx = nullptr;
    struct tls_config *config = nullptr;
};

#endif /* TLSSocket_hpp */