cmake_minimum_required(VERSION 2.6)
project(cprojecttemplate)

# Build googletest & and googlemock
add_subdirectory(gmock-1.7.0)

# The actual building happens in here
add_subdirectory(src)


# Unit-tests are in here
add_subdirectory(tests)



