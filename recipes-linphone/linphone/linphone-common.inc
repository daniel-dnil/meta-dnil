inherit autotools pkgconfig gettext

SECTION = "x11/network"
SECTION_liblinphone = "libs/network"
SECTION_linphonec =  "console/network"

# Default is to include video and GTK UI support if the distro supports X11.
PACKAGECONFIG ??= "${@base_contains('DISTRO_FEATURES', 'x11', 'video gtkui', '', d)}"
PACKAGECONFIG[video] = "--enable-video,--disable-video,libxv ffmpeg libv4l"
PACKAGECONFIG[gtkui] = "--enable-gtk_ui=yes,--enable-gtk_ui=no,gtk+"

DEPENDS = "intltool readline libosip2 libexosip2 speex alsa-lib ortp mediastreamer2"

PROVIDES = "linphonec liblinphone ${@base_contains('PACKAGECONFIG', 'gtkui', 'linphone', '', d)}"

do_install_append(){
	install -d ${D}${bindir}
	install -m 0755 ${S}/coreapi/.libs/test_ecc ${D}${bindir}/test_ecc
	install -m 0755 ${S}/coreapi/.libs/test_lsd ${D}${bindir}/test_lsd
}

EXTRA_OECONF = " \
        --enable-alsa \
        --disable-manual \
        --disable-strict \
	--enable-console_ui=yes \
        --enable-external-mediastreamer \
        --enable-external-ortp \
	--with-realprefix=/usr \
	"

PACKAGES = "${PN} ${PN}-console linphone-rings liblinphone ${PN}-utils ${PN}-dbg ${PN}-dev ${PN}-doc"

FILES_${PN} = " \ 
	    ${bindir}/linphone \
            ${datadir}/linphone \
 	    ${datadir}/pixmaps \
	    ${datadir}/applications \
	    ${datadir}/gnome/apps \
	    ${datadir}/sounds/linphone/hello8000.wav \
	    ${datadir}/sounds/linphone/hello16000.wav \
	    ${datadir}/images/nowebcamCIF.jpg \
	    "

FILES_${PN}-console = "${bindir}/linphonec ${bindir}/linphonecsh ${bindir}/sipomatic ${datadir}/sounds/linphone/ringback.wav"
FILES_${PN}-rings = "${datadir}/sounds/linphone/rings"
FILES_liblinphone = "${libdir}/lib*.so.*"
FILES_${PN}-dev += "${libdir}/*.a ${libdir}/*.la ${libdir}/pkgconfig ${includedir}"
FILES_${PN}-utils = "${bindir}/test_ecc ${bindir}/test_lsd ${bindir}/xml2lpc_test ${bindir}/lpc2xml_test"
