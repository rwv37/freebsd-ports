PORTNAME=	ccdoc
PORTVERSION=	0.8r41
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	http://ccdoc.sourceforge.net/downloads/
DISTNAME=	src
DIST_SUBDIR=	ccdoc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracting comments from C++ source and generating HTML
WWW=		https://ccdoc.sourceforge.net/

LICENSE=	MIT

DEPRECATED=	Obsolete utility
EXPIRATION_DATE=2025-04-30

USES=		perl5

WRKSRC=		${WRKDIR}/${PORTNAME}v${PORTVERSION:S/.//g}/src
MAKEFILE=	mkopt_gcc.mk
ALL_TARGET=	bld
PLIST_FILES=	bin/ccdoc \
		share/man/man1/ccdoc.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

do-configure:
	@${REINPLACE_CMD} -e "s:%%PERL%%:${PERL}:" \
		-e "s:%%CXX%%:${CXX}:" \
		-e "s:%%CXXFLAGS%%:${CXXFLAGS}:" \
		-e "s:-pedantic::" \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin_opt_gcc_/ccdoc.exe \
		${STAGEDIR}${PREFIX}/bin/ccdoc
	${INSTALL_MAN} ${WRKSRC}/../doc/htdocs/ccdoc.man \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
