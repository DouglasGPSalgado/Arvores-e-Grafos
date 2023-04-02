import React from 'react';
import styles from "./global.module.css"

function ContactForm() {
  return (
    <div>
         <h1>Fale Conosco</h1>
    <form action="processar_formulario.php" method="POST">
      <label className={styles.label} for="nome">Nome:</label>
      <input className={styles.input} type="text" id="nome" name="nome"/>
      <label className={styles.label} for="email">E-mail:</label>
      <input className={styles.input} type="email" id="email" name="email"/>
      <label className={styles.label} for="motivo_contato">Motivo do Contato:</label>
      <select className={styles.select} id="motivo_contato" name="motivo_contato"/>
        <option value="suporte">Suporte</option>
        <option value="vendas">Vendas</option>
        <option value="outro">Outro</option>
      <label className={styles.label} for="mensagem">Mensagem:</label>
      <textarea className={styles.textarea} id="mensagem" name="mensagem"></textarea>
      <input className={styles.input} type="submit" value="Enviar"/>
    </form>
    </div>
  );
}

export default ContactForm;