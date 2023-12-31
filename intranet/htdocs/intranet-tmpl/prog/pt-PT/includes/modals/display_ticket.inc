<!-- Display updates concern modal -->
<div class="modal" id="ticketDetailsModal" tabindex="-1" role="dialog" aria-labelledby="ticketDetailsLabel">
 <div class="modal-dialog modal-lg" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="Fechar" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 class="modal-title" id="displayUpdateLabel">Detalhes do pedido</h4>
 </div>
 <div class="modal-body">
 <div id="concern-details"></div>
 <fieldset>
 <ol>
 <li class="form-group">
 <label for="message">Atualizar: </label>
 <textarea id="update_message" class="form-control" name="message"></textarea>
 </li>
 <li class="rows">
 <label for="public">Notificar: </label>
 <input type="checkbox" name="public" id="public">
 </li>
 </ol>
 </fieldset>
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <input type="hidden" name="ticket_id" id="ticket_id">
 <button type="button" class="btn btn-default" id="resolveTicket">Resolver <i id="resolve-spinner" class="fa fa-spinner fa-pulse fa-fw" style="display:none"></i></button>
 <button type="submit" class="btn btn-primary" id="updateTicket">Comentário <i id="comment-spinner" class="fa fa-spinner fa-pulse fa-fw" style="display:none"></i></button>
 </div> <!-- /.modal-footer -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#displayUpdateModal -->
