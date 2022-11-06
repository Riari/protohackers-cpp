FetchContent_Declare(
    asio
    GIT_REPOSITORY  https://github.com/chriskohlhoff/asio.git
    GIT_TAG         asio-1-24-0
    GIT_SHALLOW     ON
)

FetchContent_GetProperties(asio)
if(NOT asio_POPULATED)
  FetchContent_Populate(asio)
endif()

add_library(asio INTERFACE)
target_compile_definitions(asio INTERFACE ASIO_HAS_BOOST_BIND)
target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
