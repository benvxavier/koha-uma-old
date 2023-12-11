<!-- validator-strings.inc -->
<script>
    $(document).ready(function(){
        jQuery.extend(jQuery.validator.messages, {
            required: _("Este campo é obrigatório."),
            remote: _("Por favor corrija este campo."),
            email: _("Por favor introduza um endereço de e-mail válido."),
            url: _("Por favor introduza um URL válido."),
            date: _("Por favor insira uma data válida."),
            dateISO: _("Por favor insira uma data válida (ISO)."),
            number: _("Por favor introduza um número válido."),
            digits: _("Por favor insira apenas números."),
            equalTo: _("Por favor introduza o mesmo valor de novo."),
            maxlength: $.validator.format(_("Por favor não introduza mais que {0} caracteres.")),
            minlength: $.validator.format(_("A palavra-passe deve ter pelo menos {0} caracteres.")),
            rangelength: $.validator.format(_("Por favor introduza um valor entre {0} e {1} caracteres.")),
            range: $.validator.format(_("Por favor introduza um valor entre {0} e {1}.")),
            max: $.validator.format(_("Tem que pagar um valor menor ou igual a {0}.")),
            min: $.validator.format(_("Tem que pagar um valor maior ou igual a {0}.")),
            phone: $.validator.format(_("Por favor introduza um número de telefone válido."))
        });
    });
</script>
<!-- / validator-strings.inc -->
