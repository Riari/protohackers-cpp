#include <iostream>
#include <asio.hpp>
#include "session.h"
#include "server.h"

int main(int argc, char** argv)
{
    try
    {
        asio::io_service io_service;
        server s(io_service, 1313);

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
