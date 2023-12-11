[% USE raw %]
[% USE scalar %]
[% USE Koha %]
[% USE Categories %]
<!-- str/members-menu.inc -->
[% IF ( Koha.Preference('patronimages') ) %]
 [% Asset.js("js/patron-webcam.js") | $raw %]
[% END %]
<script>
    var advsearch = "[% advsearch | html %]";
    var destination = "[% destination | html %]";

    var CAN_user_borrowers_edit_borrowers = "[% CAN_user_borrowers_edit_borrowers | html %]";
    var CAN_user_borrowers_delete_borrowers = "[% CAN_user_borrowers_delete_borrowers | html %]";

    var dateformat = "[% Koha.Preference('dateformat') | html %]";

    var borrowernumber;
    var number_of_adult_categories = 0;
    [% IF patron %]
        borrowernumber = "[% patron.borrowernumber | html %]";
        [% IF patron.is_child %]
            [% SET adult_categories = Categories.scalar.all(category_type => 'A') %]
            [% SET number_of_adult_categories = adult_categories.count %]
            number_of_adult_categories = [% number_of_adult_categories | html %]
        [% END %]
    [% END %]

    [% IF ( patron.image ) %]
        $("body").on("click", "#delpicture", function(){
             return confirm(_("Tem a certeza que pretende eliminar esta imagem de leitor? Esta ação não pode ser desfeita."));
        });
        $('#upload-patron-image').find("input[value*=Upload]").click(function(){
            if($("#uploadfile").val() == ""){
                alert(_("Por favor, escolha um arquivo para carregar"));
                return false;
            }
            return confirm(_("Tem a certeza que pretende substituir a imagem do leitor? Esta ação não pode ser desfeita."));
        });
    [% END %]
</script>
<!-- / str/members-menu.inc -->
