FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

PRINC := "${@int(PRINC) + 1}"

SRC_URI += "file://pulseaudio"


do_install_append() {
	# Change resampling method
	sed -i -e s:\;\ resample-method\ =\ speex-float-3:resample-method\ =\ src-sinc-medium-quality: ${D}${sysconfdir}/pulse/daemon.conf

	# Load the needed modules
	echo "load-module module-native-protocol-tcp auth-ip-acl=127.0.0.1;192.168.0.0/16" >> ${D}${sysconfdir}/pulse/system.pa
	echo "load-module module-rtp-recv" >> ${D}${sysconfdir}/pulse/system.pa

	# Install the startup script
	# ${D} is effectively the root directory of the target system.
	# ${D}${sysconfdir} is where system configuration files are to be stored (e.g. /etc).
	#
	install -d ${D}${sysconfdir}/init.d
	install -m 0755 ${WORKDIR}/pulseaudio ${D}${sysconfdir}/init.d/

	install -d ${D}${sysconfdir}/rc0.d
	install -d ${D}${sysconfdir}/rc1.d
	install -d ${D}${sysconfdir}/rc2.d
	install -d ${D}${sysconfdir}/rc3.d
	install -d ${D}${sysconfdir}/rc4.d
	install -d ${D}${sysconfdir}/rc5.d
	install -d ${D}${sysconfdir}/rc6.d

	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc0.d/K10pulseaudio
	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc1.d/K10pulseaudio
	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc6.d/K10pulseaudio
	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc2.d/S50pulseaudio
	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc3.d/S50pulseaudio
	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc4.d/S50pulseaudio
	ln -sf ../init.d/pulseaudio      ${D}${sysconfdir}/rc5.d/S50pulseaudio
}

