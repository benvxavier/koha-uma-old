[%- BLOCK account_type_description -%]
 [%- IF account.credit_type_code -%]
 [%- PROCESS credit_type_description credit_type = account.credit_type -%]
 [%- ELSIF account.debit_type_code -%]
 [%- PROCESS debit_type_description debit_type = account.debit_type -%]
 [%- END -%]
 [%- PROCESS account_status_description account=account -%]
[%- END -%]

[%- BLOCK debit_type_description -%]
 [%- SWITCH debit_type.code -%]
 [%- CASE 'ACCOUNT'          -%]<span>Taxa de criação de conta</span>
 [%- CASE 'ACCOUNT_RENEW'    -%]<span>Taxa de renovação de conta</span>
 [%- CASE 'ARTICLE_REQUEST'  -%]<span>Taxa de pedido de artigo</span>
 [%- CASE 'LOST'             -%]<span>Exemplar perdido</span>
 [%- CASE 'MANUAL'           -%]<span>Multa manual</span>
 [%- CASE 'NEW_CARD'         -%]<span>Novo cartão</span>
 [%- CASE 'OVERDUE'          -%]<span>Multa</span>
 [%- CASE 'PROCESSING'       -%]<span>Taxa de processamento de exemplar perdido</span>
 [%- CASE 'RENT'             -%]<span>Taxa de empréstimo</span>
 [%- CASE 'RENT_DAILY'       -%]<span>Taxa de aluguer diária</span>
 [%- CASE 'RENT_RENEW'       -%]<span>Renovação de empréstimo</span>
 [%- CASE 'RENT_DAILY_RENEW' -%]<span>Renovação de exemplar de empréstimo diário</span>
 [%- CASE 'RESERVE'          -%]<span>Taxa de reserva</span>
 [%- CASE 'RESERVE_EXPIRED'  -%]<span>Reserva a aguardar há demasiado tempo</span>
 [%- CASE 'PAYOUT'           -%]<span>Pagamento da biblioteca ao leitor</span>
 [%- CASE 'VOID'             -%]<span>O crédito foi anulado</span>
 [%- CASE                    -%]<span>[% debit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK credit_type_description -%]
 [%- SWITCH credit_type.code -%]
 [%- CASE 'CANCELLATION' -%]<span>Cobrança cancelada</span>
 [%- CASE 'CREDIT'       -%]<span>Crédito</span>
 [%- CASE 'DISCOUNT'     -%]<span>Desconto</span>
 [%- CASE 'FORGIVEN'     -%]<span>Perdoado</span>
 [%- CASE 'LOST_FOUND'   -%]<span>Reembolso da taxa de exemplar perdido</span>
 [%- CASE 'OVERPAYMENT'  -%]<span>Reembolso de pagamento em excesso</span>
 [%- CASE 'PAYMENT'      -%]<span>Pagamento</span>
 [%- CASE 'PROCESSING_FOUND' -%]<span>Taxa de processamento de exemplar perdido</span>
 [%- CASE 'PURCHASE'     -%]<span>Compra</span>
 [%- CASE 'REFUND'       -%]<span>Reembolso</span>
 [%- CASE 'WRITEOFF'     -%]<span>Amortizar</span>
 [%- CASE                -%]<span>[% credit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK account_status_description -%]
 [%- SWITCH account.status -%]
 [%- CASE 'UNRETURNED' -%]<span> (Creditado)</span>
 [%- CASE 'RETURNED'   -%]<span> (Devolvido)</span>
 [%- CASE 'REPLACED'   -%]<span> (Substituído)</span>
 [%- CASE 'REFUNDED'   -%]<span> (Reembolsado)</span>
 [%- CASE 'FORGIVEN'   -%]<span> (Perdoada)</span>
 [%- CASE 'VOID'       -%]<span> (Anulado)</span>
 [%- CASE 'LOST'       -%]<span> (Perdido)</span>
 [%- CASE 'CANCELLED'  -%]<span> (Cancelado)</span>
 [%- CASE              -%]
 [%- END -%]
[%- END -%]
