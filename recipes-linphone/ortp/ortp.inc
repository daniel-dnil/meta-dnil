DESCRIPTION = "LGPL licensed C library implementing the RTP protocol (rfc3550)"
SECTION = "libs/network"
PR = "r0"

SRC_URI = "git://git.linphone.org/ortp.git;protocol=git;tag=${PV}"

S = "${WORKDIR}/git/"

EXTRA_OECONF = " \
        --disable-strict \
	"

inherit autotools
