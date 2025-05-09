PORTNAME=	jsonm
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	https://erratique.ch/software/jsonm/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Non-blocking streaming JSON codec for OCaml
WWW=		https://erratique.ch/software/jsonm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam \
		${SA_DIR}/topkg/META:devel/ocaml-topkg \
		${SA_DIR}/uutf/META:devel/ocaml-uutf
RUN_DEPENDS=	${SA_DIR}/uutf/META:devel/ocaml-uutf

USES=		ocaml tar:tbz
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && ocaml pkg/pkg.ml build

do-install:
	cd ${INSTALL_WRKSRC} && opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/jsontrip \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/jsonm/jsonm.cmxs

.include <bsd.port.mk>
