#include <boost/bind.hpp>
#include "session.h"

session::session(asio::io_service& io_service) : m_socket(io_service)
{
}

asio::ip::tcp::socket& session::get_socket()
{
    return m_socket;
}

void session::start()
{
    m_socket.async_read_some(
        asio::buffer(m_data, SESSION_DATA_MAX_LEN),
        boost::bind(&session::handle_receive, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

void session::stop()
{
    m_is_stopped = true;
    m_socket.shutdown(asio::ip::tcp::socket::shutdown_both);
    m_socket.close();
}

void session::handle_receive(const asio::error_code& error, size_t bytes_transferred)
{
    if (error)
    {
        delete this;
        return;
    }

    asio::async_write(
        m_socket,
        asio::buffer(m_data, bytes_transferred),
        boost::bind(&session::handle_send, this, asio::placeholders::error));
}

void session::handle_send(const asio::error_code& error)
{
    if (error)
    {
        delete this;
        return;
    }

    m_socket.async_read_some(
        asio::buffer(m_data, SESSION_DATA_MAX_LEN),
        boost::bind(&session::handle_receive, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}
