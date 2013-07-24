DESCRIPTION = "Image for the audio player"

IMAGE_FEATURES += "ssh-server-dropbear debug-tweaks"

LICENSE = "MIT"

inherit core-image

IMAGE_INSTALL += "pulseaudio-server pulseaudio-module-rtp-recv \
	          pulseaudio-module-native-protocol-tcp \
		  procps ntp ntp-utils \
		  "
