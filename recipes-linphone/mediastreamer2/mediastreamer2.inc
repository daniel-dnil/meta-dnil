DESCRIPTION = "a modular sound and video processing and streaming"
SECTION = "libs/network"
PR = "r0"

DEPENDS = "ortp speex alsa-lib"

SRC_URI = "git://git.linphone.org/mediastreamer2.git;protocol=git;tag=${PV}"

S = "${WORKDIR}/git/"

# Default is to include video and GTK UI support if the distro supports X11.
PACKAGECONFIG ??= "${@base_contains('DISTRO_FEATURES', 'x11', 'video', '', d)}"
PACKAGECONFIG[video] = "--enable-video,--disable-video, glew"

EXTRA_OECONF = " \
        --enable-alsa \
        --disable-pulse \
        --disable-upnp \
        --disable-manual \
        --disable-strict \
	"

FILES_${PN} += "${datadir}/images/nowebcamCIF.jpg"

inherit autotools gettext
