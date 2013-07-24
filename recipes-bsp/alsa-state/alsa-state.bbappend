FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/${MACHINE}:"
PRINC := "${@int(PRINC) + 1}"
