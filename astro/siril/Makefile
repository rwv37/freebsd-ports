PORTNAME=	siril
DISTVERSION=	1.2.6
CATEGORIES=	astro graphics
MASTER_SITES=	https://free-astro.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Astronomical image processing software
WWW=		https://siril.org/ \
		https://gitlab.com/free-astro/siril

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	undefined reference to '__atomic_load' and '__atomic_compare_exchange'
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libcfitsio.so:astro/cfitsio \
		libconfig.so:devel/libconfig \
		libexiv2.so:graphics/exiv2 \
		libffms2.so:multimedia/ffms2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libgsl.so:math/gsl \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		libopencv_core.so:graphics/opencv \
		libpng.so:graphics/png \
		libraw.so:graphics/libraw \
		librtprocess.so:graphics/librtprocess \
		libtiff.so:graphics/tiff \
		libwcs.so:astro/wcslib
LIB_DEPENDS+=	libopencv_photo.so:graphics/opencv # for some reason, configure fails without opencv, but executable only links to opencv-core

USES=		cmake:indirect compiler:c++11-lang desktop-file-utils gettext \
		gnome meson pkgconfig jpeg shared-mime-info tar:bz2
USE_GNOME=	atk cairo gdkpixbuf gtk30 intltool pango

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		CURL OPENMP
OPTIONS_DEFAULT=	CURL OPENMP

OPENMP_MESON_OFF=	-Dopenmp=false

CURL_MESON_YES=		enable-libcurl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

.include <bsd.port.mk>
