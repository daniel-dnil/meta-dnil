FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://ntp.conf"

PRINC := "${@int(PRINC) + 1}"

