PORTNAME=	robocode
PORTVERSION=	0.9.2
PORTREVISION=	2
DISTVERSIONSUFFIX=	-setup
CATEGORIES=	games education java
MASTER_SITES=	SF/${PORTNAME}/naval-robocode/${PORTVERSION}
PKGNAMESUFFIX=	-naval
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	java

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Game for learning Java[tm] programming language
WWW=		https://robo-code.blogspot.com.br

LICENSE=	EPL

PORTSCOUT=	limit:^\d+\.\d+\.\d+$$

USES=		cpe dos2unix java:extract,run zip
CPE_VENDOR=	${PORTNAME}_project
DOS2UNIX_GLOB=	*.css *.team *.properties package-list MANIFEST.MF

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}${PKGNAMESUFFIX}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SUB_FILES=	${PORTNAME}-NavalRobocode pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-NavalRobocode \
		${STAGEDIR}${PREFIX}/bin/

.for d in battles compilers javadoc libs license roborumble robots \
	templates theme
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

.for f in *.ico *.sh ReadMe.* naval-robocode-versions.md
	@(${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_DATA} ${WRKSRC}/desktop/robocodeRobocode.desktop \
		${STAGEDIR}${DESKTOPDIR}/robocodeNavalRobocode.desktop
	${INSTALL_DATA} ${WRKSRC}/desktop/robocode.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/robocode-naval.png

	@${MKDIR} ${STAGEDIR}${DATADIR}/config

.include <bsd.port.mk>
