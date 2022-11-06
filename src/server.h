#pragma once

#include <asio.hpp>
#include "session.h"

class server
{
public:
    server(asio::io_service&, short);

    void handle_accept(session*, const asio::error_code&);
    session* create_new_session();

private:
    asio::io_service& m_io_service;
    asio::ip::tcp::acceptor m_acceptor;
};
