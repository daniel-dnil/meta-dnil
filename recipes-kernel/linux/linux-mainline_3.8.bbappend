FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
COMPATIBLE_MACHINE_beaglebone = "beaglebone"
SRC_URI += "file://defconfig \
            file://0001-Make-the-McASP-code-generic-again-remove-all-hardcod.patch \
           "
