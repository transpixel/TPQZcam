
# Override default install location for testing this package
# In general default (no command here) will install to /usr/{lib,bin,...}
# - but here, set package to isolated location for easier/safer testing
set (DEB_PACKAGE_ROOT "/usr/local/")
set(CPACK_PACKAGING_INSTALL_PREFIX "${DEB_PACKAGE_ROOT}")

# Set package(Generator) specific characteristics
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Transpixel.org")

set(APT_PACKAGE_DEPLIST
	"libeigen3-dev (>= ${EigenVersion}) \
	"
	)
set(CPACK_DEBIAN_PACKAGE_DEPENDS ${APT_PACKAGE_DEPLIST})

message("###")
message("### DEB_PACKAGE_ROOT: " ${DEB_PACKAGE_ROOT})
message("### APT_PACKAGE_DEPLIST: " ${APT_PACKAGE_DEPLIST})


