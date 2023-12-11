[% SWITCH error %]
[% CASE 'no_item' %]
 <span>Não foi encontrado um exemplar correspondente</span>
[% CASE 'no_checkout' %]
 <span>Exemplar não emprestado</span>
[% CASE 'too_soon' %]
 <span>Ainda não pode ser renovado</span>
[% CASE 'too_many' %]
 <span>Já renovou este empréstimo o número máximo de vezes permitido</span>
[% CASE 'auto_too_soon' %]
 <span>Este exemplar foi agendado para renovação automática e ainda não pode ser renovado</span>
[% CASE 'auto_too_late' %]
 <span>Foi agendado para renovação automática e não pode ser renovado mais vezes</span>
[% CASE 'auto_account_expired' %]
 <span>Foi agendado para renovação automática e não pode ser renovado porque a conta do leitor está expirada</span>
[% CASE 'auto_renew' %]
 <span>Agendado para renovação automática</span>
[% CASE 'auto_too_much_oweing' %]
 <span>Foi agendado para renovação automática e não pode ser renovado porque o leitor tem demasiadas multas de atraso</span>
[% CASE 'on_reserve' %]
 <span>Reservado para outro leitor</span>
[% CASE 'patron_restricted' %]
 <span>O leitor está restrito</span>
[% CASE 'item_denied_renewal' %]
 <span>A renovação do exemplar não é permitida</span>
[% CASE 'onsite_checkout' %]
 <span>O exemplar é um empréstimo on-site</span>
[% CASE 'has_fine' %]
 <span>O exemplar tem multa pendente</span>
[% CASE 'item_issued_to_other_patron'%]
 <span>Este exemplar está emprestado para outro leitor</span>
[% CASE %]
 <span>Erro desconhecido</span>
[% END %]
