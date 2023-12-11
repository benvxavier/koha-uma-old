[% USE raw %]
[% USE Asset %]
[% Asset.js("lib/jquery/plugins/jquery.dataTables.min.js") | $raw %]
[% Asset.js("lib/jquery/plugins/dataTables.responsive.min.js") | $raw %]
<script>
    var MSG_DT_FIRST = _("Primeiro");
    var MSG_DT_LAST = _("Último");
    var MSG_DT_NEXT = _("Seguinte");
    var MSG_DT_PREVIOUS = _("Anterior");
    var MSG_DT_EMPTY_TABLE = _("Sem dados disponíveis na tabela");
    var MSG_DT_INFO = _("A ver _START_ até _END_ de _TOTAL_");
    var MSG_DT_INFO_EMPTY = _("Sem entradas para mostrar");
    var MSG_DT_INFO_FILTERED = _("(filtrado para _MAX_ entradas)");
    var MSG_DT_LENGTH_MENU = _("Mostrar _MENU_ entradas");
    var MSG_DT_LOADING_RECORDS = _("Em carregamento...");
    var MSG_DT_PROCESSING = _("A processar...");
    var MSG_DT_SEARCH = _("Pesquisar:");
    var MSG_DT_ZERO_RECORDS = _("Sem registos correspondentes");
    var MSG_DT_COPY_TO_CLIPBOARD = _("Copiar para a área de transferência");
    var MSG_DT_COPY_KEYS = _("Clique em <i>ctrl</i> or <i>⌘</i> + <i>C</i> para copiar os dados da tabela<br>para a área de transferência do sistema.<br><br>Para cancelar, clique nesta mensagem ou carregue em Esc.");
    var MSG_DT_COPIED_ROWS = _("%d linhas copiadas para a área de transferência");
    var MSG_DT_COPIED_ONE_ROW = _("Uma linha copiada para a área de transferência");
    var MSG_CLEAR_FILTER = _("Limpar filtro");
    var MSG_DT_ALL = _("Todos");
    var CONFIG_EXCLUDE_ARTICLES_FROM_SORT = _("e o");
</script>
[% Asset.js("js/datatables.js") | $raw %]
