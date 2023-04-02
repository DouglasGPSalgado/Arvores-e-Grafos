import React from "react";
import { NavLink, useNavigate } from "react-router-dom";
import styled from "styled-components";
import styles from "./global.module.css"

const Nav = styled.nav`
  display: flex;
  justify-content: center;
  margin: 20px 0;
`;

const List = styled.ul`
  display: flex;
  list-style: none;
`;

const Item = styled.li`
  list-style: none;
  margin: 0 10px;
  padding: 0;
  margin-bottom: 1em;
`;

const Menu = () => {
  const navigate = useNavigate();
  return (
    <div>
      <Nav>
        <List>
          <Item>
            <NavLink to="/text" exact activeClassName="active">
              Elementos de Texto
            </NavLink>
          </Item>
          <Item>
            <NavLink to="/form" activeClassName="active">
              Formulário de Contato
            </NavLink>
          </Item>
          <Item>
            <NavLink to="/table" activeClassName="active">
              Tabelas
            </NavLink>
          </Item>
          <Item>
            <NavLink to="/image" activeClassName="active">
              Imagens
            </NavLink>
          </Item>
        </List>
      </Nav>
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
      <img
        src="http://3.bp.blogspot.com/-hcEt9_Jfp5E/UAIemQhwJ3I/AAAAAAAAAdQ/50lJZTfPvYE/s1600/piscina2.jpg"
        alt="Piscina de Azulejo"
        className={styles.img}
      />
      <p className={styles.p}>Uma piscina de azulejo.</p>
      <form>
        <label className={styles.label} for="pesquisa">Pesquisar:</label>
        <input className={styles.input} type="text" id="pesquisa" name="pesquisa" />
        <input className={styles.input} type="submit" value="Buscar"></input>
      </form>
      <h2 className={styles.h2}>Entre em Contato</h2>
      <form action="enviar_email.php" method="POST">
        <label className={styles.label} for="nome">Nome:</label>
        <input className={styles.input} type="text" id="nome" name="nome" required />
        <label className={styles.label} for="email">Email:</label>
        <input className={styles.input} type="email" id="email" name="email" required />
        <label className={styles.label} for="telefone">Telefone:</label>
        <input className={styles.input} type="tel" id="telefone" name="telefone" required />
        <label className={styles.label} for="mensagem">Mensagem:</label>
        <textarea className={styles.textarea} id="mensagem" name="mensagem" rows="5" cols="40"></textarea>
        <input className={styles.input} type="submit" value="Enviar" />
      </form>
    </div>
  );
};

export default Menu;
