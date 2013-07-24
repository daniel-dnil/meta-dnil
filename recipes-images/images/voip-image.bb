DESCRIPTION = "Image for the FOAB voip project"

IMAGE_FEATURES += "ssh-server-dropbear debug-tweaks"

LICENSE = "MIT"

inherit core-image

IMAGE_INSTALL += "linphone-console linphone-utils libbcg729-msplugin \
	          libstdc++ readline libsqlite3 libssl libcrypto \
		  libudev alsa-utils-aplay alsa-utils-amixer \
		  procps linphone xauth \
		  "

