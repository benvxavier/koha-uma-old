[% USE raw %]
<!-- str/cataloging_additem.inc -->
<script>
    var searchid = '[% searchid | html %]';
    var biblionumber = '[% biblionumber | html %]';
    var frameworkcode = '[% frameworkcode | html %]';
    [% IF popup %]
      var popup = true;
    [% ELSE %]
      var popup = false;
    [% END %]
    var op = '[% op | html %]';
    var LABEL_EDIT_ITEM = _("Editar item");
    var LABEL_DELETE_ITEM = _("Eliminar item");
    var MSG_FORM_NOT_SUBMITTED = _("Formulário não submetido devido ao(s) seguinte(s) problema(s)");
    var MSG_MANDATORY_FIELDS_EMPTY = _("%s campos obrigatórios vazios (realçados)");
    var MSG_IMPORTANT_FIELDS_EMPTY = _("%s campos importantes vazios (realçados)");
    var MSG_ADD_MULTIPLE_ITEMS = _("Você está prestes a adicionar %s exemplares. Continuar?");
    var MSG_ENTER_NUM_ITEMS = _("Por favor insira o número de itens a criar.");
    var MSG_CONFIRM_DELETE_ITEM = _("Tem a certeza que pretende eliminar este exemplar?");
    var MSG_CONFIRM_ADD_ITEM = _("Tem a certeza que pretende adicionar um novo item? Qualquer alteração efetuada nesta página será pedida.");
    var MSG_CONFIRM_SAVE = _("Tem a certeza que pretende guardar?");
    var table_settings = [% TablesSettings.GetTableSettings( 'cataloguing', 'additem', 'itemst', 'json' ) | $raw %];
</script>
<!-- / str/cataloging_additem.inc -->
