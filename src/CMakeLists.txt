#

# Project-wide library
set(local_LIBTARGET "TPQZcam")
add_library(${local_LIBTARGET} STATIC)

# TPQZ basic libraries
add_subdirectory(libsys)
add_subdirectory(libio)
add_subdirectory(libdat)

# TPQZ math related libs
add_subdirectory(libmath)
add_subdirectory(libprob)
add_subdirectory(libga)
# add_subdirectory(libla)
add_subdirectory(libgeo)

# TPQZ photogrammetry
add_subdirectory(libcam)



