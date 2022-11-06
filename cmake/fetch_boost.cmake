FetchContent_Declare(
    boost_core
    GIT_REPOSITORY  https://github.com/boostorg/core.git
    GIT_TAG         boost-1.80.0
    GIT_SHALLOW     ON
)

FetchContent_MakeAvailable(boost_core)

FetchContent_Declare(
    boost_config
    GIT_REPOSITORY  https://github.com/boostorg/config.git
    GIT_TAG         boost-1.80.0
    GIT_SHALLOW     ON
)

FetchContent_MakeAvailable(boost_config)

FetchContent_Declare(
    boost_assert
    GIT_REPOSITORY  https://github.com/boostorg/assert.git
    GIT_TAG         boost-1.80.0
    GIT_SHALLOW     ON
)

FetchContent_MakeAvailable(boost_assert)

FetchContent_Declare(
    boost_static_assert
    GIT_REPOSITORY  https://github.com/boostorg/static_assert.git
    GIT_TAG         boost-1.80.0
    GIT_SHALLOW     ON
)

FetchContent_MakeAvailable(boost_static_assert)

FetchContent_Declare(
    boost_throw_exception
    GIT_REPOSITORY  https://github.com/boostorg/throw_exception.git
    GIT_TAG         boost-1.80.0
    GIT_SHALLOW     ON
)

FetchContent_MakeAvailable(boost_throw_exception)

FetchContent_Declare(
    boost_bind
    GIT_REPOSITORY  https://github.com/boostorg/bind.git
    GIT_TAG         boost-1.80.0
    GIT_SHALLOW     ON
)

FetchContent_MakeAvailable(boost_bind)