<?xml version="1.0" encoding="UTF-8"?>

<!DOCTYPE stylesheet>

<xsl:stylesheet version="1.0"
  xmlns:marc="http://www.loc.gov/MARC21/slim"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:str="http://exslt.org/strings"
  exclude-result-prefixes="marc str">

<xsl:import href="UNIMARCslimUtils.xsl"/>
<xsl:output method = "html" indent="yes" omit-xml-declaration = "yes" encoding="UTF-8"/>
<xsl:template match="/">
 <xsl:apply-templates/>
</xsl:template>

<xsl:template match="marc:record">
 <xsl:variable name="leader" select="marc:leader"/>
 <xsl:variable name="leader6" select="substring($leader,7,1)"/>
 <xsl:variable name="leader7" select="substring($leader,8,1)"/>
 <xsl:variable name="biblionumber" select="marc:controlfield[@tag=001]"/>
 <xsl:variable name="DisplayOPACiconsXSLT" select="marc:sysprefs/marc:syspref[@name='DisplayOPACiconsXSLT']"/>
 <xsl:variable name="OPACURLOpenInNewWindow" select="marc:sysprefs/marc:syspref[@name='OPACURLOpenInNewWindow']"/>
 <xsl:variable name="URLLinkText" select="marc:sysprefs/marc:syspref[@name='URLLinkText']"/>

 <xsl:if test="marc:datafield[@tag=200]">
 <xsl:for-each select="marc:datafield[@tag=200]">
 <h2 class="title">
 <xsl:call-template name="addClassRtl" />
 <xsl:for-each select="marc:subfield">
 <xsl:choose>
 <xsl:when test="@code='a'">
 <xsl:variable name="title" select="."/>
 <xsl:variable name="ntitle"
               select="translate($title, '&#x0088;&#x0089;&#x0098;&#x009C;','')"/>
 <xsl:value-of select="$ntitle" />
 </xsl:when>
 <xsl:when test="@code='b'">
 <xsl:text> [</xsl:text>
 <xsl:value-of select="."/>
 <xsl:text>]</xsl:text>
 </xsl:when>
 <xsl:when test="@code='d'">
 <xsl:text> = </xsl:text>
 <xsl:value-of select="."/>
 </xsl:when>
 <xsl:when test="@code='e'">
 <xsl:text> : </xsl:text>
 <xsl:value-of select="."/>
 </xsl:when>
 <xsl:when test="@code='f'">
 <xsl:text> / </xsl:text>
 <xsl:value-of select="."/>
 </xsl:when>
 <xsl:when test="@code='g'">
 <xsl:text> ; </xsl:text>
 <xsl:value-of select="."/>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>, </xsl:text>
 <xsl:value-of select="."/>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </h2>
 </xsl:for-each>
 </xsl:if>

 <xsl:call-template name="tag_title">
 <xsl:with-param name="tag">454</xsl:with-param>
 <xsl:with-param name="label">Tradução de</xsl:with-param>
 <xsl:with-param name="spanclass">original_title</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_title">
 <xsl:with-param name="tag">461</xsl:with-param>
 <xsl:with-param name="label">Nível de conjunto</xsl:with-param>
 <xsl:with-param name="spanclass">set_level</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_title">
 <xsl:with-param name="tag">464</xsl:with-param>
 <xsl:with-param name="label">Nível de parte analítica</xsl:with-param>
 <xsl:with-param name="spanclass">piece_analytic_level</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_7xx">
 <xsl:with-param name="tag">700</xsl:with-param>
 <xsl:with-param name="label">Autor principal</xsl:with-param>
 <xsl:with-param name="spanclass">main_author</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_7xx">
 <xsl:with-param name="tag">710</xsl:with-param>
 <xsl:with-param name="label">Colectividade-autor (principal)</xsl:with-param>
 <xsl:with-param name="spanclass">corporate_main_author</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_7xx">
 <xsl:with-param name="tag">701</xsl:with-param>
 <xsl:with-param name="label">Co-autor</xsl:with-param>
 <xsl:with-param name="spanclass">co-autor</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_7xx">
 <xsl:with-param name="tag">702</xsl:with-param>
 <xsl:with-param name="label">Autor secundário</xsl:with-param>
 <xsl:with-param name="spanclass">secondary_author</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_7xx">
 <xsl:with-param name="tag">711</xsl:with-param>
 <xsl:with-param name="label">Colectividade-autor (co-autora)</xsl:with-param>
 <xsl:with-param name="spanclass">corporate_coauthor</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_7xx">
 <xsl:with-param name="tag">712</xsl:with-param>
 <xsl:with-param name="label">Colectividade-autor (secundária)</xsl:with-param>
 <xsl:with-param name="spanclass">corporate_secondary_author</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_title">
 <xsl:with-param name="tag">500</xsl:with-param>
 <xsl:with-param name="label">Título uniforme</xsl:with-param>
 <xsl:with-param name="spanclass">uniform_title</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_title">
 <xsl:with-param name="tag">503</xsl:with-param>
 <xsl:with-param name="label">Cabeçalho convencional uniforme</xsl:with-param>
 <xsl:with-param name="spanclass">uniform_conventional_heading</xsl:with-param>
 </xsl:call-template>

 <xsl:if test="marc:datafield[@tag=101]">
 <span class="results_summary language">
 <span class="label">Idioma: </span>
 <xsl:for-each select="marc:datafield[@tag=101]">
 <xsl:for-each select="marc:subfield">
 <xsl:choose>
 <xsl:when test="@code='b'">do texto intermédio, </xsl:when>
 <xsl:when test="@code='c'">da obra original, </xsl:when>
 <xsl:when test="@code='d'">do sumário, </xsl:when>
 <xsl:when test="@code='e'">da página de conteúdo, </xsl:when>
 <xsl:when test="@code='f'">da página de título, </xsl:when>
 <xsl:when test="@code='g'">do título próprio, </xsl:when>
 <xsl:when test="@code='h'">do libreto, </xsl:when>
 <xsl:when test="@code='i'">do material acompanhante, </xsl:when>
 <xsl:when test="@code='j'">das legendas, </xsl:when>
 </xsl:choose>
 <xsl:value-of select="text()"/>
 <xsl:choose>
 <xsl:when test="position()=last()">
 <xsl:text>.</xsl:text>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text> ; </xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=102]">
 <span class="results_summary country">
 <span class="label">País: </span>
 <xsl:for-each select="marc:datafield[@tag=102]">
 <xsl:for-each select="marc:subfield">
 <xsl:value-of select="text()"/>
 <xsl:choose>
 <xsl:when test="position()=last()">
 <xsl:text>.</xsl:text>
 </xsl:when>
 <xsl:otherwise><xsl:text>, </xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:call-template name="tag_comma">
 <xsl:with-param name="tag">205</xsl:with-param>
 <xsl:with-param name="label">Menção da edição</xsl:with-param>
 <xsl:with-param name="spanclass">edição</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_210-214" />

 <xsl:call-template name="tag_215" />

 <!-- Build ISBN -->
 <xsl:if test="marc:datafield[@tag=010]/marc:subfield[@code='a']">
 <span class="results_summary isbn">
 <span class="label">ISBN: </span>
 <xsl:for-each select="marc:datafield[@tag=010]/marc:subfield[@code='a']">
 <span property="isbn">
 <xsl:value-of select="."/>
 <xsl:choose>
 <xsl:when test="position()=last()">
 <xsl:text>.</xsl:text>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>; </xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </span>
 </xsl:for-each>
 </span>
 </xsl:if>

 <!-- Build ISSN -->
 <xsl:if test="marc:datafield[@tag=011]/marc:subfield[@code='a']">
 <span class="results_summary issn">
 <span class="label">ISSN: </span>
 <xsl:for-each select="marc:datafield[@tag=011]/marc:subfield[@code='a']">
 <span property="issn">
 <xsl:value-of select="."/>
 <xsl:choose>
 <xsl:when test="position()=last()">
 <xsl:text>.</xsl:text>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>; </xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </span>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:call-template name="tag_title">
 <xsl:with-param name="tag">225</xsl:with-param>
 <xsl:with-param name="label">Coleção</xsl:with-param>
 <xsl:with-param name="spanclass">coleção</xsl:with-param>
 </xsl:call-template>

 <xsl:if test="marc:datafield[@tag=676]">
 <span class="results_summary dewey">
 <span class="label">Classificação Decimal de Dewey (CDD):</span>
 <xsl:for-each select="marc:datafield[@tag=676]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 <xsl:if test="marc:subfield[@code='v']">
 <xsl:text>, </xsl:text>
 <xsl:value-of select="marc:subfield[@code='v']"/>
 </xsl:if>
 <xsl:if test="marc:subfield[@code='z']">
 <xsl:text>, </xsl:text>
 <xsl:value-of select="marc:subfield[@code='z']"/>
 </xsl:if>
 <xsl:if test="not (position()=last())">
 <xsl:text> ; </xsl:text>
 </xsl:if>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=686]">
 <span class="results_summary classification">
 <span class="label">Classificação: </span>
 <xsl:for-each select="marc:datafield[@tag=686]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 <xsl:if test="marc:subfield[@code='b']">
 <xsl:text>, </xsl:text>
 <xsl:value-of select="marc:subfield[@code='b']"/>
 </xsl:if>
 <xsl:if test="marc:subfield[@code='c']">
 <xsl:text>, </xsl:text>
 <xsl:value-of select="marc:subfield[@code='c']"/>
 </xsl:if>
 <xsl:if test="not (position()=last())"><xsl:text> ; </xsl:text></xsl:if>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=327]">
 <span class="results_summary contents">
 <span class="label">Nota de conteúdo: </span>
 <xsl:for-each select="marc:datafield[@tag=327]">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdjpvxyz</xsl:with-param>
 <xsl:with-param name="subdivCodes">jpxyz</xsl:with-param>
 <xsl:with-param name="subdivDelimiter">-- </xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=330]">
 <span class="results_summary abstract">
 <span class="label">Resumo: </span>
 <xsl:for-each select="marc:datafield[@tag=330]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 <xsl:choose>
 <xsl:when test="position()=last()">
 <xsl:text>.</xsl:text>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>; </xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=317]">
 <span class="results_summary provenance">
 <span class="label">Nota de proveniência: </span>
 <xsl:for-each select="marc:datafield[@tag=317]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=320]">
 <span class="results_summary bibliography">
 <span class="label">Bibliografia: </span>
 <xsl:for-each select="marc:datafield[@tag=320]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><xsl:text>; </xsl:text></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=328]">
 <span class="results_summary thesis">
 <span class="label">Nota de dissertação ou tese: </span>
 <xsl:for-each select="marc:datafield[@tag=328]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><xsl:text>; </xsl:text></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=333]">
 <span class="results_summary audience">
 <span class="label">Audiência: </span>
 <xsl:for-each select="marc:datafield[@tag=333]">
 <xsl:value-of select="marc:subfield[@code='a']"/>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><xsl:text>; </xsl:text></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:if test="marc:datafield[@tag=955]">
 <span class="results_summary sudoc_serial_history">
 <span class="label">Histórico SUDOC do periódico: </span>
 <xsl:for-each select="marc:datafield[@tag=955]">
 <xsl:value-of select="marc:subfield[@code='9']"/>:
 <xsl:value-of select="marc:subfield[@code='r']"/>
 <xsl:choose><xsl:when test="position()=last()"><xsl:text>.</xsl:text></xsl:when><xsl:otherwise><xsl:text>; </xsl:text></xsl:otherwise></xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">600</xsl:with-param>
 <xsl:with-param name="label">Assunto - Nome de pessoa</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">601</xsl:with-param>
 <xsl:with-param name="label">Assunto - Nome de colectividade</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">602</xsl:with-param>
 <xsl:with-param name="label">Assunto - Nome de família</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">604</xsl:with-param>
 <xsl:with-param name="label">Assunto - Autor/Título</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">606</xsl:with-param>
 <xsl:with-param name="label">Assunto - Nome comum</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">607</xsl:with-param>
 <xsl:with-param name="label">Assunto - Nome geográfico</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">608</xsl:with-param>
 <xsl:with-param name="label">Assunto - Forma</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">610</xsl:with-param>
 <xsl:with-param name="label">Assunto</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">615</xsl:with-param>
 <xsl:with-param name="label">Categoria de assunto</xsl:with-param>
 </xsl:call-template>

 <xsl:call-template name="tag_subject">
 <xsl:with-param name="tag">616</xsl:with-param>
 <xsl:with-param name="label">Marca registada</xsl:with-param>
 </xsl:call-template>

 <xsl:if test="marc:datafield[@tag=856]">
 <span class="results_summary online_resources">
 <span class="label">Recursos em linha:</span>
 <xsl:for-each select="marc:datafield[@tag=856]">
 <a>
 <xsl:attribute name="href">
 <xsl:value-of select="marc:subfield[@code='u']"/>
 </xsl:attribute>
 <xsl:if test="$OPACURLOpenInNewWindow='1'">
 <xsl:attribute name="target">_blank</xsl:attribute>
 </xsl:if>
 <xsl:choose>
 <xsl:when test="marc:subfield[@code='y' or @code='3' or @code='z']">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">y3z</xsl:with-param>
 </xsl:call-template>
 </xsl:when>
 <xsl:when test="not(marc:subfield[@code='y']) and not(marc:subfield[@code='3']) and not(marc:subfield[@code='z'])">
 <xsl:choose>
 <xsl:when test="$URLLinkText!=''">
 <xsl:value-of select="$URLLinkText"/>
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>Clicar aqui para aceder online</xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:when>
 </xsl:choose>
 </a>
 <xsl:choose>
 <xsl:when test="position()=last()"></xsl:when>
 <xsl:otherwise> | </xsl:otherwise>
 </xsl:choose>
 </xsl:for-each>
 </span>
 </xsl:if>

 <!-- OpenURL -->
 <xsl:variable name="OPACShowOpenURL" select="marc:sysprefs/marc:syspref[@name='OPACShowOpenURL']" />
 <xsl:variable name="OpenURLImageLocation" select="marc:sysprefs/marc:syspref[@name='OpenURLImageLocation']" />
 <xsl:variable name="OpenURLText" select="marc:sysprefs/marc:syspref[@name='OpenURLText']" />
 <xsl:variable name="OpenURLResolverURL" select="marc:variables/marc:variable[@name='OpenURLResolverURL']" />

 <xsl:if test="$OPACShowOpenURL = 1 and $OpenURLResolverURL != ''">
 <xsl:variable name="openurltext">
 <xsl:choose>
 <xsl:when test="$OpenURLText != ''">
 <xsl:value-of select="$OpenURLText" />
 </xsl:when>
 <xsl:otherwise>
 <xsl:text>OpenURL</xsl:text>
 </xsl:otherwise>
 </xsl:choose>
 </xsl:variable>

 <span class="results_summary"><a>
 <xsl:attribute name="href">
 <xsl:value-of select="$OpenURLResolverURL" />
 </xsl:attribute>
 <xsl:attribute name="title">
 <xsl:value-of select="$openurltext" />
 </xsl:attribute>
 <xsl:attribute name="class">
 <xsl:text>OpenURL</xsl:text>
 </xsl:attribute>
 <xsl:if test="$OPACURLOpenInNewWindow='1'">
 <xsl:attribute name="target">
 <xsl:text>_blank</xsl:text>
 </xsl:attribute>
 </xsl:if>
 <xsl:choose>
 <xsl:when test="$OpenURLImageLocation != ''">
 <img>
 <xsl:attribute name="src">
 <xsl:value-of select="$OpenURLImageLocation" />
 </xsl:attribute>
 </img>
 </xsl:when>
 <xsl:otherwise>
 <xsl:value-of select="$openurltext" />
 </xsl:otherwise>
 </xsl:choose>
 </a></span>
 </xsl:if>
 <!-- End of OpenURL -->

 <xsl:variable name="OPACShowMusicalInscripts" select="marc:sysprefs/marc:syspref[@name='OPACShowMusicalInscripts']" />
 <xsl:variable name="OPACPlayMusicalInscripts" select="marc:sysprefs/marc:syspref[@name='OPACPlayMusicalInscripts']" />

 <xsl:if test="$OPACShowMusicalInscripts and marc:datafield[@tag=036]">
 <xsl:for-each select="marc:datafield[@tag=031]">

 <span class="results_summary musical_inscripts">
 <xsl:if test="marc:subfield[@code='u']">
 <span class="uri">
 <a>
 <xsl:attribute name="href">
 <xsl:value-of select="marc:subfield[@code='u']"/>
 </xsl:attribute>
 <xsl:text>Ficheiro áudio</xsl:text>
 </a>
 </span>
 </xsl:if>
 <xsl:if test="marc:subfield[@code='2'] and marc:subfield[@code='2']/text() = 'pe' and marc:subfield[@code='g'] and marc:subfield[@code='n'] and marc:subfield[@code='o'] and marc:subfield[@code='p']">
 <div class="inscript" data-system="pae">
 <xsl:attribute name="data-clef">
 <xsl:value-of select="marc:subfield[@code='g']"/>
 </xsl:attribute>
 <xsl:attribute name="data-keysig">
 <xsl:value-of select="marc:subfield[@code='n']"/>
 </xsl:attribute>
 <xsl:attribute name="data-timesig">
 <xsl:value-of select="marc:subfield[@code='o']"/>
 </xsl:attribute>
 <xsl:attribute name="data-notation">
 <xsl:value-of select="marc:subfield[@code='p']"/>
 </xsl:attribute>
 </div>
 <xsl:if test="$OPACPlayMusicalInscripts = 1">
 <div class="audio_controls">
 <button class="btn play_btn">
 <i id="carticon" class="fa fa-play"></i>
 <xsl:text> Reproduzir esta amostra</xsl:text>
 </button>
 </div>
 </xsl:if>
 </xsl:if>
 </span>
 </xsl:for-each>
 <xsl:if test="$OPACPlayMusicalInscripts = 1">
 <div class="results_summary">
 <span class="inscript_audio hide"></span>
 </div>
 </xsl:if>
 </xsl:if>

</xsl:template>

 <xsl:template name="nameABCDQ">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">aq</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 <xsl:with-param name="punctuation">
 <xsl:text>:,;/ </xsl:text>
 </xsl:with-param>
 </xsl:call-template>
 <xsl:call-template name="termsOfAddress"/>
 </xsl:template>

 <xsl:template name="nameABCDN">
 <xsl:for-each select="marc:subfield[@code='a']">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString" select="."/>
 </xsl:call-template>
 </xsl:for-each>
 <xsl:for-each select="marc:subfield[@code='b']">
 <xsl:value-of select="."/>
 </xsl:for-each>
 <xsl:if test="marc:subfield[@code='c'] or marc:subfield[@code='d'] or marc:subfield[@code='n']">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">cdn</xsl:with-param>
 </xsl:call-template>
 </xsl:if>
 </xsl:template>

 <xsl:template name="nameACDEQ">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">acdeq</xsl:with-param>
 </xsl:call-template>
 </xsl:template>
 <xsl:template name="termsOfAddress">
 <xsl:if test="marc:subfield[@code='b' or @code='c']">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">bc</xsl:with-param>
 </xsl:call-template>
 </xsl:with-param>
 </xsl:call-template>
 </xsl:if>
 </xsl:template>

 <xsl:template name="part">
 <xsl:variable name="partNumber">
 <xsl:call-template name="specialSubfieldSelect">
 <xsl:with-param name="axis">n</xsl:with-param>
 <xsl:with-param name="anyCodes">n</xsl:with-param>
 <xsl:with-param name="afterCodes">fghkdlmor</xsl:with-param>
 </xsl:call-template>
 </xsl:variable>
 <xsl:variable name="partName">
 <xsl:call-template name="specialSubfieldSelect">
 <xsl:with-param name="axis">p</xsl:with-param>
 <xsl:with-param name="anyCodes">p</xsl:with-param>
 <xsl:with-param name="afterCodes">fghkdlmor</xsl:with-param>
 </xsl:call-template>
 </xsl:variable>
 <xsl:if test="string-length(normalize-space($partNumber))">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString" select="$partNumber"/>
 </xsl:call-template>
 </xsl:if>
 <xsl:if test="string-length(normalize-space($partName))">
 <xsl:call-template name="chopPunctuation">
 <xsl:with-param name="chopString" select="$partName"/>
 </xsl:call-template>
 </xsl:if>
 </xsl:template>

 <xsl:template name="specialSubfieldSelect">
 <xsl:param name="anyCodes"/>
 <xsl:param name="axis"/>
 <xsl:param name="beforeCodes"/>
 <xsl:param name="afterCodes"/>
 <xsl:variable name="str">
 <xsl:for-each select="marc:subfield">
 <xsl:if test="contains($anyCodes, @code)      or (contains($beforeCodes,@code) and following-sibling::marc:subfield[@code=$axis])      or (contains($afterCodes,@code) and preceding-sibling::marc:subfield[@code=$axis])">
 <xsl:value-of select="text()"/>
 <xsl:text> </xsl:text>
 </xsl:if>
 </xsl:for-each>
 </xsl:variable>
 <xsl:value-of select="substring($str,1,string-length($str)-1)"/>
 </xsl:template>

</xsl:stylesheet>
