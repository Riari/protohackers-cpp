#pragma once

#include <asio.hpp>

#define SESSION_DATA_MAX_LEN 1024

class session
{
public:
    session(asio::io_service&);

    asio::ip::tcp::socket& get_socket();

    void start();
    void stop();
    void handle_receive(const asio::error_code&, size_t bytes_transferred);
    void handle_send(const asio::error_code&);

private:
    bool m_is_stopped{false};
    asio::ip::tcp::socket m_socket;
    char m_data[SESSION_DATA_MAX_LEN];
};
