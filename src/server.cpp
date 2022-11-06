#include <boost/bind.hpp>
#include "server.h"

server::server(asio::io_service& io_service, short port)
    : m_io_service(io_service),
      m_acceptor(io_service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
    create_new_session();
}

void server::handle_accept(session* p_session, const asio::error_code& error)
{
    if (error)
    {
        delete p_session;
        return;
    }

    p_session->start();
    create_new_session();
}

session* server::create_new_session()
{
    session* p_session = new session(m_io_service);

    m_acceptor.async_accept(
        p_session->get_socket(),
        boost::bind(&server::handle_accept, this, p_session, asio::placeholders::error));

    return p_session;
}
