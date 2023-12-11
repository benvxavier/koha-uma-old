<div id="editor-widget-templates" style="display:none">
 <div id="widget-leader">
 Leader:&nbsp;<span title="Tamanho do registo (auto-gerado)">#####</span>
 <select name="f5" title="Estado do registo">
 <option value="a">a - Aumento do nível de codificação</option>
 <option value="c">c - Corrigido ou revisto</option>
 <option value="d">d - Eliminado</option>
 <option value="n">n - Novo</option>
 <option value="p">p - Aumento do nível de codificação de pré-publicação</option>
 </select>
 <select name="f6" title="Tipo de registo. Controla o tipo por omissão do campo 008.">
 <option value="a">a - Material de idioma</option>
 <option value="c">c - Música anotada</option>
 <option value="d">d - Manuscrito de música anotada</option>
 <option value="e">e - Material cartográfico</option>
 <option value="f">f - Manuscrito de material cartográfico</option>
 <option value="g">g - Meio de projecção</option>
 <option value="i">i - Gravação de som não-musical</option>
 <option value="j">j - Gravação de som musical</option>
 <option value="k">k - Gráfico não-projectado 2D</option>
 <option value="m">m - Ficheiro informático</option>
 <option value="o">o - Kit</option>
 <option value="p">p - Materiais mistos</option>
 <option value="r">r - Artefacto tridimensional ou objecto natural</option>
 <option value="t">t- Material de idioma manuscrito</option>
 </select>
 <select name="f7" title="Nível bibliográfico">
 <option value="a">a - Parte componente monográfico</option>
 <option value="b">b - Parte componente de periódico</option>
 <option value="c">c - Coleção</option>
 <option value="d">d - Sub-unidade</option>
 <option value="i">i - Recurso integrado</option>
 <option value="m">m - Monografia</option>
 <option value="s">s - Periódico</option>
 </select>
 <select name="f8" title="Tipo de controlo">
 <option value=" ">_ - Nenhum tipo específico</option>
 <option value="a">a - Arquivo</option>
 </select>
 <span title="Codificação (Unicode forçado)">a</span>
 <span title="Tamanhos de indicador/subcampo">22</span>
 <span title="Endereço da base de dados (auto-gerado)">#####</span>
 <select name="f17" title="Nível de codificação">
 <option value=" ">_ - Nível completo</option>
 <option value="1">1- Nível completo, documento não examinado</option>
 <option value="2">2 - Nível incompleto, material não examinado</option>
 <option value="3">3 - Nível abreviado</option>
 <option value="4">4 - Nível central</option>
 <option value="5">5 - Nível parcial (preliminar)</option>
 <option value="7">7 - Nível mínimo</option>
 <option value="8">8 - Nível de pré-publicação</option>
 [% IF Koha.Preference('UseOCLCEncodingLevels') %]
 <option value="I">I- Nível completo de entrada por participantes OCLC</option>
 <option value="J">J- Registo eliminado</option>
 <option value="K">I- Nível incompleto de entrada por participantes OCLC</option>
 <option value="M">M- Adicionado por um processo em lote</option>
 [% END %]
 <option value="u">u - Desconhecido</option>
 <option value="z">z - Não aplicável</option>
 </select>
 <select name="f18" title="Forma descritiva de catalogação">
 <option value=" ">_ - Non-ISBD</option>
 <option value="a">a - AACR 2</option>
 <option value="c">c - Pontuação ISBD omitida</option>
 <option value="i">i - Pontuação ISBD incluída</option>
 <option value="n">n - Pontuação não-ISBD omitida</option>
 <option value="u">u - Desconhecido</option>
 </select>
 <select name="f19" title="Nível de registo de recurso multiparte">
 <option value=" ">_ - Não especificado ou aplicável</option>
 <option value="a">a - Conjunto</option>
 <option value="b">b - Parte com título independente</option>
 <option value="c">c - Parte com título independente</option>
 </select>
 <span title="Tamanho dos elementos de produção">4500</span>
 </div>
</div>
<!-- cateditor-widgets-marc21.inc -->
<script>

/**
 * Each widget should provide one to three methods:
 *   init( text ): Returns the DOM node for this widget.
 *   postCreate( node, mark ): Optional, called once the mark has been created
 *                             and the node shown. Bind event handlers here.
 *   makeTemplate(): Optional, should return some sane default contents for a
 *                   newly created field/subfield. '<empty>' will be used if this
 *                   method is unset.
 *
 * Following the Koha convention, control fields are defined as tags with a
 * single subfield, '@'.
 */

require( [ 'koha-backend', 'widget', 'text-marc' ], function( KohaBackend, Widget, TextMarc ) {
    Widget.Register( '000@', {
        makeTemplate: function() {
            return '     nam a22     7a 4500';
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget"></span>' );

            return $result[0];
        },
        postCreate: function() {
            // Clear the length and directory start fields; these are unnecessary for MARCXML and will be filled in upon USMARC export
            this.setFixed( 0, 5, '     ' );
            this.setFixed( 9, 17, 'a22     ' );
            this.setFixed( 20, 24, '4500' );

            this.insertTemplate( '#widget-leader' );

            this.bindFixed( '[name=f5]', 5, 6 );
            this.bindFixed( '[name=f6]', 6, 7 );
            this.bindFixed( '[name=f7]', 7, 8 );
            this.bindFixed( '[name=f8]', 8, 9 );
            this.bindFixed( '[name=f17]', 17, 18 );
            this.bindFixed( '[name=f18]', 18, 19 );
            this.bindFixed( '[name=f19]', 19, 20 );
        },
    } );

    /* Check to see if there are any Control Number entries
     *  in the authorised values table.
     * If not, let's not show the widget
     */
    var reg001 = KohaBackend.GetAuthorisedValues( 'CONTROL_NUM_SEQUENCE');
    if(reg001) {

        Widget.Register( '001@', {
            init: function() {
                var $result = $(
                    '<span class="subfield-widget">'
                    + _("Número de control: ")
                    + '<span class="control-number-widget-contents"></span>'
                    + '<button class="control-number-widget-assign">' + _("Atribuir o próximo") + '</button>'
                    + '<select class="control-number-widget-sequence"></select>'
                    + '<button class="control-number-widget-override">' + _("Sobrepor") + '</button>'
                    + '</span>'
                );

                return $result[0];
            },
            setControlNumber: function( text ) {
                if ( text ) this.setText( text );
                $( this.node ).find('.control-number-widget-contents')
                    .html( text == '<empty>' ? ( '<span class="hint">' + _("limpar") + '</span>' ) : text );
                this.mark.changed();
            },
            postCreate: function( node, mark ) {
                var widget = this;
                this.setControlNumber( this.text );
                $( this.node )
                    .find('.control-number-widget-assign').click( function() {
                        var sequence = $( widget.node ).find('.control-number-widget-sequence').val();
                        $.post(
                            '/cgi-bin/koha/svc/cataloguing/control_num_sequences/' + sequence
                        ).done( function( result ) {
                            if ( result.next_value ) widget.setControlNumber( result.next_value );
                        } );
                    } ).end()
                    .find('.control-number-widget-override').click( function() {
                        var result = prompt( _("Definir novo número de control") );

                        if ( result ) widget.setControlNumber( result );
                    } ).end();

                var sequence_list = $.map( reg001 , function( authval ) {
                    return authval.lib;
                } );
                sequence_list.sort();

                $.each( sequence_list, function( undef, sequence ) {
                    $( widget.node ).find('.control-number-widget-sequence').append( '<option>' + sequence + '</option>' );
                } );

                // TODO: Make Enter on select click "Assign"
            }
        } );
        };

    Widget.Register( '005@', {
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Atualizado: ") + '</span>' );

            return $result[0];
        },
        postCreate: function( node, mark ) {
            var parts = this.text.match( /(\d{4})(\d{2})(\d{2})(\d{2})(\d{2})(\d{2})\.(\d)/ );

            if ( parts ) {
                var dateVal = new Date(
                    parseInt( parts[1] ), // Year
                    parseInt( parts[2] ) - 1, // Month (0-11)
                    parseInt( parts[3] ), // Day
                    parseInt( parts[4] ), // Hour
                    parseInt( parts[5] ), // Minute
                    parseInt( parts[6] ), // Second
                    parseInt( parts[7] ) * 100 // Millisecond
                );

                $( this.node ).append( dateVal.toLocaleString() );
            } else {
                $( this.node ).append( '<span class="hint">' + _("limpar") + '</span>' );
            }
        }
    } );

    Widget.Register( '006@', {
        makeTemplate: function() {
            return "a                 ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Dados fixos:") + '<span class="hint widget-loading">' + _("Em carregamento...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: 'BKS',
            c: 'MU',
            d: 'MU',
            e: 'MPS',
            f: 'MPS',
            g: 'VM',
            i: 'MU',
            j: 'MU',
            k: 'VM',
            m: 'CF',
            o: 'VM',
            p: 'MX',
            r: 'VM',
            s: 'CR',
            t: 'BKS',
        },
        getMaterial: function () {
            return this.materialTypeMapping[this.text.substring(0, 1)];
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/006' );
        }
    } );

    Widget.Register( '007@', {
        makeTemplate: function() {
            return "a       ";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Dados fixos:") + '<span class="hint widget-loading">' + _("Em carregamento...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: 'MPS',
            c: 'ER',
            d: 'GL',
            f: 'TM',
            g: 'PG',
            h: 'MF',
            k: 'NG',
            m: 'MP',
            o: 'KT',
            q: 'NM',
            r: 'RI',
            s: 'SR',
            t: 'TC',
            v: 'VR',
            z: 'UN'
        },
        getMaterial: function () {
            return this.materialTypeMapping[this.text.substring(0, 1)];
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/007' ).then(() => {
                $(this.node).find('.material-select').on('change', (e) => {
                    const keys = Object.keys(this.materialTypeMapping);
                    const k = keys.filter(k => this.materialTypeMapping[k] === $(e.target).val());
                    this.setFixed(0, 1, k, '+input');

                    // FIXME There must be a better way to update display
                    const n = $(this.node).find('[name="f00"]');
                    n.triggerHandler('focus');
                    n.triggerHandler('blur');
                });
            });
        }
    } );

    Widget.Register( '008@', {
        makeTemplate: function() {
            var now = new Date();
            return Widget.PadNum( now.getYear() % 100, 2 ) + Widget.PadNum( now.getMonth() + 1, 2 ) + Widget.PadNum( now.getDate(), 2 ) + "b        [% DefaultCountryField008 | html %]||||| |||| 00| 0 [% DefaultLanguageField008 | html %] d";
        },
        init: function() {
            var $result = $( '<span class="subfield-widget fixed-widget">' + _("Dados fixos:") + '<span class="hint widget-loading">' + _("Em carregamento...") + '</span></span>' );

            return $result[0];
        },
        materialTypeMapping: {
            a: {
                a: 'BKS', c: 'BKS', d: 'BKS', m: 'BKS',
                b: 'CR', i: 'CR', s: 'CR',
            },
            t: 'BKS',
            c: 'MU', d: 'MU', i: 'MU', j: 'MU',
            e: 'MP', f: 'MP',
            g: 'VM', k: 'VM', o: 'VM', r: 'VM',
            m: 'CF',
            p: 'MX',
        },
        getMaterial: function () {
            const record = TextMarc.TextToRecord(this.editor.cm.getValue());

            const leader = record.leader();
            const leader6 = leader.substring(6, 7);
            let materialType = this.materialTypeMapping[leader6];
            if (typeof materialType === 'object') {
                const leader7 = leader.substring(7, 8);
                materialType = materialType[leader7];
            }

            return materialType;
        },
        postCreate: function( node, mark ) {
            this.createFromXML( 'marc21/xml/008' );
        }
    } );
} );

</script>
<!-- / cateditor-widgets-marc21.inc -->
