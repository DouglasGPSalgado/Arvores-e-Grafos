import React from 'react';
import styles from "./global.module.css"

function Tables() {
  return (
    <div>
      <h1 className={styles.h1}>Tabela de Preços</h1>
    <table className={styles.table}>
      <tr className={styles.tr}>
        <th className={styles.th}>Produto</th>
        <th className={styles.th}>Preço</th>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Piscina de Fibra</td>
        <td className={styles.td}>R$ 10.000,00</td>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Piscina de Concreto</td>
        <td className={styles.td}>R$ 15.000,00</td>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Piscina Natural</td>
        <td className={styles.td}>R$ 20.000,00</td>
      </tr>
    </table>
    
    <h1 className={styles.h1}>Tabela de Cores</h1>
    <table className={styles.table}>
      <tr className={styles.tr}>
        <th className={styles.th}>Cor</th>
        <th className={styles.th}>Código</th>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Vermelho</td>
        <td className={styles.td}>#FF0000</td>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Verde</td>
        <td className={styles.td}>#00FF00</td>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Azul</td>
        <td className={styles.td}>#0000FF</td>
      </tr>
    </table>
    
    <h1 className={styles.h1}>Tabela de Contatos</h1>
    <table className={styles.table}>
      <tr className={styles.tr}>
        <th className={styles.th}>Nome</th>
        <th className={styles.th}>Telefone</th>
        <th className={styles.th}>Email</th>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>João da Silva</td>
        <td className={styles.td}>(11) 99999-9999</td>
        <td className={styles.td}>joao.silva@email.com</td>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Maria Oliveira</td>
        <td className={styles.td}>(21) 88888-8888</td>
        <td className={styles.td}>maria.oliveira@email.com</td>
      </tr>
      <tr className={styles.tr}>
        <td className={styles.td}>Pedro Santos</td>
        <td className={styles.td}>(51) 77777-7777</td>
        <td className={styles.td}>pedro.santos@email.com</td>
      </tr>
    </table>
    </div>
  );
}

export default Tables;