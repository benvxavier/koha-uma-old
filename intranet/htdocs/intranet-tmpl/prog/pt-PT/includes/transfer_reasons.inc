[%- BLOCK transfer_reason -%]
 [%- SWITCH transfer.reason -%]
 [%- CASE 'Manual'                    -%]<span>Manual</span>
 [%- CASE 'StockrotationAdvance'      -%]<span>Avanço da rotação de stock</span>
 [%- CASE 'StockrotationRepatriation' -%]<span>Repatriação da rotação de stock</span>
 [%- CASE 'ReturnToHome'              -%]<span>Devolução automática à biblioteca de origem</span>
 [%- CASE 'ReturnToHolding'           -%]<span>Devolução automática à biblioteca de empréstimo</span>
 [%- CASE 'RotatingCollection'        -%]<span>Coleções rotativas</span>
 [%- CASE 'Reserve'                   -%]<span>Reserva</span>
 [%- CASE 'LostReserve'               -%]<span>Reserva perdida</span>
 [%- CASE 'CancelReserve'             -%]<span>Reserva cancelada</span>
 [%- CASE                             -%]<span>[% transfer.reason | html %]</span>
 [%- END -%]
[%- END -%]
