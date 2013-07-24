meta-dnil
=========

DNIL Electronics Yocto compatible layers

This README file contains information on the contents of the
dnil layer.

Please see the corresponding sections below for details.

Dependencies
============

This layer depends on:

  URI: https://github.com/beagleboard/
  layers: meta-beagleboard
  branch: master
  
  URI: git://git.openembedded.org/meta-openembedded
  layers: meta-oe, meta-networking
  branch: dylan

  URI: git://git.yoctoproject.org/poky
  layers: meta, meta-yocto, meta-yocto-bsp
  branch: dylan


Patches
=======

Please submit any patches against the dnil layer to the maintainer:

Maintainer: Daniel Nilsson <daniel@dnil.se>

Table of Contents
=================

  I. Adding the dnil layer to your build

I. Adding the dnil layer to your build
=================================================

In order to use this layer, you need to make the build system aware of
it.

Assuming the dnil layer exists at the top-level of your
yocto build tree, you can add it to the build system by adding the
location of the dnil layer to bblayers.conf, along with any
other layers needed. e.g.:

  BBLAYERS ?= " \
    /path/to/yocto/meta \
    /path/to/yocto/meta-yocto \
    /path/to/yocto/meta-yocto-bsp \
    /path/to/yocto/meta-beagleboard/common-bsp \
    /path/to/yocto/meta-openembedded/meta-oe \
    /path/to/yocto/meta-openembedded/meta-networking \
    /path/to/yocto/meta-dnil \
    "
