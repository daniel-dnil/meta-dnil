DESCRIPTION = "oSIP is an implementation of SIP."
LICENSE = "GPLv2"
LICENSE_FLAGS = "commercial"

SRC_URI = "http://download-mirror.savannah.gnu.org/releases/linphone/plugins/sources/bcg729-${PV}.tar.gz"
S = "${WORKDIR}/bcg729-${PV}"

PACKAGES += "${PN}-msplugin ${PN}-msplugin-dbg"

DEPENDS = "ortp mediastreamer2 speex"

FILES_${PN}-msplugin = "${libdir}/mediastreamer/plugins/libms*.so"
FILES_${PN}-msplugin-dbg = "${libdir}/mediastreamer/plugins/.debug"

do_install_append() {
    rm ${D}${libdir}/mediastreamer/plugins/libmsbcg729.a
    rm ${D}${libdir}/mediastreamer/plugins/libmsbcg729.la
    rm ${D}${libdir}/mediastreamer/plugins/libmsbcg729.so
    rm ${D}${libdir}/mediastreamer/plugins/libmsbcg729.so.0
    mv ${D}${libdir}/mediastreamer/plugins/libmsbcg729.so.0.0.0 \
       ${D}${libdir}/mediastreamer/plugins/libmsbcg729.so
}
