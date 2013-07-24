DESCRIPTION = "Audio/video SIP-based IP phone"
HOMEPAGE = "http://www.linphone.org/?lang=us"
LICENSE = "GPLv2"
PR="r0"

LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"

SRC_URI = "git://git.linphone.org/linphone.git;protocol=git;tag=${PV} \
           file://external_libs.patch \
          "

S = "${WORKDIR}/git"

require linphone-common.inc
