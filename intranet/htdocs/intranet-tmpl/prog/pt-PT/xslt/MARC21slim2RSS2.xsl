<?xml version="1.0" encoding="UTF-8"?>

<!DOCTYPE stylesheet>

<xsl:stylesheet version="1.0" xmlns:marc="http://www.loc.gov/MARC21/slim" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" exclude-result-prefixes="marc">
 <xsl:import href="MARC21slimUtils2.xsl"/>
 <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
 
 <!--Added ISBN and deleted attributes 6/04 jer-->
 
 <xsl:template match="/">
 <xsl:apply-templates/>
 </xsl:template>

 <xsl:template match="marc:record">
 <xsl:variable name="leader" select="marc:leader"/>
 <xsl:variable name="leader6" select="substring($leader,7,1)"/>
 <xsl:variable name="leader7" select="substring($leader,8,1)"/>
 <xsl:variable name="controlField008" select="marc:controlfield[@tag=008]"/>

 <item>
 <xsl:for-each select="marc:datafield[@tag=245]">
 <title>
 <xsl:call-template name="subfieldSelect"> <xsl:with-param name="codes">abfghk</xsl:with-param> </xsl:call-template> </title>
 </xsl:for-each>

 
 <xsl:for-each select="marc:datafield[@tag=100]">
 <author>
 <xsl:value-of select="."/>
 </author>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=110]|marc:datafield[@tag=111]|marc:datafield[@tag=700]|marc:datafield[@tag=710]|marc:datafield[@tag=711]|marc:datafield[@tag=720]">
 <dc:creator>
 <xsl:value-of select="."/>
 </dc:creator>
 </xsl:for-each>

 <dc:type> 
 <xsl:if test="$leader7='c'">
 <xsl:text>coleção</xsl:text>
 <!--Removed attributes 6/04 jer-->
 <!--<xsl:attribute name="collection">yes</xsl:attribute>-->
 </xsl:if>

 <xsl:if test="$leader6='d' or $leader6='f' or $leader6='p' or $leader6='t'">
 <!--Removed attributes 6/04 jer-->
 
 <!--<xsl:attribute name="manuscript">yes</xsl:attribute>-->
 <xsl:text>manuscrito</xsl:text>
 </xsl:if>

 <xsl:choose>
 <xsl:when test="$leader6='a' or $leader6='t'">texto</xsl:when>
 <xsl:when test="$leader6='e' or $leader6='f'">cartográfico</xsl:when>
 <xsl:when test="$leader6='c' or $leader6='d'">música anotada</xsl:when>
 <xsl:when test="$leader6='i' or $leader6='j'">gravação de som</xsl:when>
 <xsl:when test="$leader6='k'">imagem estática</xsl:when>
 <xsl:when test="$leader6='g'">imagem em movimento</xsl:when>
 <xsl:when test="$leader6='r'">objecto tridimensional</xsl:when>
 <xsl:when test="$leader6='m'">software, multimédia</xsl:when>
 <xsl:when test="$leader6='p'">material misto</xsl:when>
 </xsl:choose>
 </dc:type>

 <xsl:for-each select="marc:datafield[@tag=655]">
 <category>
 <xsl:value-of select="."/>
 </category>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=260]">
 <dc:publisher>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ab</xsl:with-param>
 </xsl:call-template>
 </dc:publisher>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=260]/marc:subfield[@code='c']">
 <pubDate>
 <xsl:value-of select="."/>
 </pubDate> 
 </xsl:for-each>

 <dc:language>
 <xsl:value-of select="substring($controlField008,36,3)"/>
 </dc:language>

 <xsl:for-each select="marc:datafield[@tag=856]/marc:subfield[@code='q']">
 <dc:format>
 <xsl:value-of select="."/>
 </dc:format>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[500&lt;@tag][@tag&lt;=599][not(@tag=506 or @tag=530 or @tag=540 or @tag=546)]">
 <description>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </description>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=600]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=610]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=611]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>
 
 <xsl:for-each select="marc:datafield[@tag=630]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=650]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=653]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=752]">
 <dc:coverage>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcd</xsl:with-param>
 </xsl:call-template>
 </dc:coverage>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=530]">
 <dc:relation type="original">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdu</xsl:with-param>
 </xsl:call-template>
 </dc:relation> 
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=760]|marc:datafield[@tag=762]|marc:datafield[@tag=765]|marc:datafield[@tag=767]|marc:datafield[@tag=770]|marc:datafield[@tag=772]|marc:datafield[@tag=773]|marc:datafield[@tag=774]|marc:datafield[@tag=775]|marc:datafield[@tag=776]|marc:datafield[@tag=777]|marc:datafield[@tag=780]|marc:datafield[@tag=785]|marc:datafield[@tag=786]|marc:datafield[@tag=787]">
 <dc:relation>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ot</xsl:with-param>
 </xsl:call-template>
 </dc:relation> 
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=856]">
 <dc:identifier>
 <xsl:value-of select="marc:subfield[@code='u']"/>
 </dc:identifier>
 </xsl:for-each>
 
 <xsl:for-each select="marc:datafield[@tag=020]">
 <dc:identifier>
 <xsl:text>URN:ISBN:</xsl:text>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:identifier>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=506]">
 <dc:rights>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:rights>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=540]">
 <dc:rights>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:rights>
 </xsl:for-each>
 </item>
 </xsl:template>
</xsl:stylesheet><!-- Stylus Studio meta-information - (c)1998-2003 Copyright Sonic Software Corporation. All rights reserved.
<metaInformation>
<scenarios ><scenario default="yes" name="RDF" userelativepaths="yes" externalpreview="no" url="marcxmlfile.xml" htmlbaseurl="" outputurl="" processortype="internal" commandline="" additionalpath="" additionalclasspath="" postprocessortype="none" postprocesscommandline="" postprocessadditionalpath="" postprocessgeneratedext=""/></scenarios><MapperInfo srcSchemaPath="" srcSchemaRoot="" srcSchemaPathIsRelative="yes" srcSchemaInterpretAsXML="no" destSchemaPath="" destSchemaRoot="" destSchemaPathIsRelative="yes" destSchemaInterpretAsXML="no"/>
</metaInformation>
-->