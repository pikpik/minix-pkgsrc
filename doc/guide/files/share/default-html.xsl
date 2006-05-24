<?xml version='1.0'?>

<!-- $NetBSD: default-html.xsl,v 1.2 2005/05/07 22:40:25 wiz Exp $ -->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

  <xsl:import href="http://www.NetBSD.org/XML/htdocs/share/xsl/netbsd-docbook-html.xsl" />

  <xsl:output method="html" indent="yes" encoding="ISO-8859-1"
	doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN"/>
</xsl:stylesheet>
