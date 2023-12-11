[%- BLOCK role -%]
 [%- SWITCH role.key -%]
 [%- CASE 'manager'               -%]<span>Gestor de lançamento</span>
 [%- CASE 'manager_assistant'     -%]<span>Gestor assistente de lançamento</span>
 [%- CASE 'manager_mentor'        -%]<span>Mentor do gestor de lançamento</span>
 [%- CASE 'qa_manager'            -%]<span>Gestor da qualidade</span>
 [%- CASE 'qa'                    -%]<span>Equipa da qualidade</span>
 [%- CASE 'documentation'         -%]<span>Gestor da documentação</span>
 [%- CASE 'documentation_team'    -%]<span>Equipa de documentação</span>
 [%- CASE 'translation'           -%]<span>Gestor das traduções</span>
 [%- CASE 'translations'          -%]<span>Gestores das traduções</span>
 [%- CASE 'translation_assistant' -%]<span>Assistente de gestão de traduções</span>
 [%- CASE 'te'                    -%]<span>Especialista no assunto</span>
 [%- CASE 'bugwrangler'           -%]<span>Bug wrangler</span>
 [%- CASE 'maintainer'            -%]<span>Curador de lançamento</span>
 [%- CASE 'maintainer_assistant'  -%]<span>Curador assistente de lançamento</span>
 [%- CASE 'maintainer_mentor'     -%]<span>Mentor do curador de lançamento</span>
 [%- CASE 'wiki'                  -%]<span>Curador da Wiki</span>
 [%- CASE 'ci'                    -%]<span>Gestor da integração contínua</span>
 [%- CASE 'packaging'             -%]<span>Gestor de pacotes</span>
 [%- CASE 'packaging_assistant'   -%]<span>Assistente de gestão de pacotes</span>
 [%- CASE 'chairperson'           -%]<span>Presidente de reuniões</span>
 [%- CASE 'newsletter'            -%]<span>Editor do boletim de notícias</span>
 [%- CASE 'mm'                    -%]<span>Curador do módulo</span>
 [%- CASE 'vm'                    -%]<span>Gestor da máquina virtual</span>
 [%- CASE 'database'              -%]<span>Especialista de documentação</span>
 [%- CASE 'live_cd'               -%]<span>Manutenção do Live CD</span>
 [%- CASE 'accessibility_advocate'-%]<span>Promotor da acessibilidade</span>
 [%- CASE 'meeting_facilitator'   -%]<span>Facilitador de reuniões</span>
 [%- END -%]
[%- END -%]

[%- BLOCK person -%]
[% IF p.openhub %]<a href="[% p.openhub | url %]">[% p.name | html %]</a>[% ELSE %][% p.name | html %][% END %]
[%- END -%]

[%- BLOCK contributions -%]
[%- IF p.roles || p.notes -%]
<ul>
 [% FOREACH r IN p.roles %]<li>[% INCLUDE role role=r %] ([% r.value.join(', ') | html %])</li>[% END %]
 [% IF p.notes %]<li>[% p.notes | html %]</li>[% END %]
</ul>
[%- END -%]
[%- END -%]

[%- BLOCK team -%]
 <ul>

 [% IF v == 'release' %]
 <p>Esta é a equipa que foi responsável pelo lançamento inicial da versão do Koha instalada.</p>

 <li><strong>Gestor de lançamento:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li><strong>Assistentes de gestão de lançamento:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li><strong>Curador assistente de lançamento:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]

 [% ELSE %]
 <p>Esta é a equipa responsável pelo próximo lançamento do Koha e pela manutenção corrente da versão do Koha instalada. Vão estar nestas posições até <strong>[% t.release_date | $KohaDates %]</strong>, quando a próxima equipa será eleita.</p>

 [% FOREACH m IN t.maintainer %]
 [% IF m.version == ( v ) %]
 <li><strong>Curador de lançamento:</strong>
 [% INCLUDE person p=m %]
 </li>
 [% END %]
 [% END %]
 
 [% IF t.maintainer_assistants %]
 [% FOREACH m IN t.maintainer_assistants %]
 [% IF m.version == ( v ) %]
 <ul><li><strong>Auxiliar:</strong> [% INCLUDE person p=m %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 
 [% IF t.maintainer_mentors %]
 [% FOREACH m IN t.maintainer_mentors %]
 [% IF m.version == ( v ) %]
 <ul><li><strong>Mentor:</strong> [% INCLUDE person p=m %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF t.qa_manager %]
 <li><strong>Gestor da qualidade:</strong>
 [% INCLUDE person p=t.qa_manager %]
 </li>
 [% END %]

 [% IF t.qa %]
 <li><strong>Equipa da qualidade:</strong>
 <ul>
 [% FOREACH qa IN t.qa %]
 <li>[% INCLUDE person p=qa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.documentation %]
 [%- IF t.documentation.list.size == 1 %]
 <li><strong>Gestor da documentação:</strong>
 [% INCLUDE person p=t.documentation %]
 </li>
 [% ELSE %]
 <li><strong>Gestores da documentação:</strong>
 <ul>
 [% FOREACH doc_manager IN t.documentation %]
 <li>[% INCLUDE person p=doc_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.documentation_team %]
 <li><strong>Equipa de documentação:</strong>
 <ul>
 [% FOREACH doc_member IN t.documentation_team %]
 <li>[% INCLUDE person p=doc_member %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.newsletter %]
 <li><strong>Editor do boletim de notícias:</strong>
 [% INCLUDE person p=t.newsletter %]
 </li>
 [% END %]

 [% IF t.translation %]
 <li><strong>Gestor das traduções:</strong>
 [% INCLUDE person p=t.translation %]
 </li>
 [% END %]

 [% IF t.translations %]
 <li><strong>Gestores das traduções:</strong>
 <ul>
 [% FOREACH translation_manager IN t.translations %]
 <li>[% INCLUDE person p=translation_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.packaging %]
 [% IF t.packaging.size / 2 == 1 %]
 <li><strong>Gestor de pacotes:</strong>
 [% INCLUDE person p=t.packaging %]
 </li>
 [% ELSE %]
 <li><strong>Equipa de empacotamento:</strong>
 <ul>
 [% FOREACH pa IN t.packaging %]
 <li>[% INCLUDE person p = pa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.ci %]
 [% IF t.ci.size == 1 %]
 <li><strong>Manutenção do Jenkins:</strong>
 [% INCLUDE person p=t.ci.0 %]
 </li>
 [% ELSE %]
 <li><strong>Manutenção do Jenkins:</strong>
 <ul>
 [% FOREACH j IN t.ci %]
 <li>[% INCLUDE person p=j %]
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.bugwrangler %]
 <li><strong>Bug wranglers:</strong>
 <ul>
 [% FOREACH bugwrangler IN t.bugwrangler %]
 <li>[% INCLUDE person p=bugwrangler %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.accessibility_advocates %]
 <li><strong>Promotores da acessibilidade:</strong>
 <ul>
 [% FOREACH a IN t.accessibility_advocates %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.accessibility_advocate %]
 <li><strong>Promotor da acessibilidade:</strong>
 [% INCLUDE person p=t.accessibility_advocate %]
 </li>
 [% END %]

 [% IF v != 'release' %]

 <li><strong>Gestor de lançamento:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li><strong>Assistentes de gestão de lançamento:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li><strong>Curador assistente de lançamento:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]

 [% ELSE %]
 <li><strong>Registo:</strong>
 <ul>
 [% FOREACH m IN t.maintainer %]
 <li>[% m.version | html %] - [% INCLUDE person p=m %]</li>
 [% IF t.maintainer_assistants %]
 [% FOREACH ma IN t.maintainer_assistants %]
 [% IF ma.version == ( m.version ) %]
 <ul><li><strong>Auxiliar:</strong> [% INCLUDE person p=ma %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 
 [% IF t.maintainer_mentors %]
 [% FOREACH mm IN t.maintainer_mentors %]
 [% IF m.version == ( mm.version ) %]
 <ul><li><strong>Mentor:</strong> [% INCLUDE person p=mm %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </ul>
 </li>
 [% END %]
 </ul>
[%- END -%]
