PR = "r0"

LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"

inherit autotools pkgconfig

SRC_URI[md5sum] = "45e127a9a309aff94d3262d97b5aeab0"
SRC_URI[sha256sum] = "6f80f9820f081fbd8b3f97b7bdc9c584bd54ba4558fa714130f8a53b154509ac"

require libbcg729.inc
