PORTNAME=	coffeescript
DISTVERSION=	2.7.0
PORTREVISION=	3
CATEGORIES=	lang

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Unfancy JavaScript
WWW=		https://coffeescript.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		nodejs:run
USE_GITHUB=	yes
GH_ACCOUNT=	jashkenas

PORTEXAMPLES=	*.coffee

CONFLICTS_INSTALL=	cake

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cake ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/coffee ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/*.js \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
