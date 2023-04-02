import React from 'react';
import styles from "./global.module.css"

function Images() {
  return (
    <div>
    <h1 className={styles.h1}>Imagens</h1>
    <img className={styles.img} src="https://www.marol.com.br/blog/wp-content/uploads/2020/04/piscina-de-fibra-1030x687.jpg" alt="Piscina de Fibra"/>
    <p className={styles.p}>Uma piscina de fibra de vidro.</p>
    <img className={styles.img} src="https://www.piscinafiber.com.br/img/xmanutencao-concreto-rede-fiber.jpg.pagespeed.ic.du2-wLQfly.webp" alt="Piscina de Concreto" width="400" height="300"/>
    <p className={styles.p}>Uma piscina de concreto.</p>
    <img className={styles.img} src="http://3.bp.blogspot.com/-hcEt9_Jfp5E/UAIemQhwJ3I/AAAAAAAAAdQ/50lJZTfPvYE/s1600/piscina2.jpg" alt="Piscina Natural"/>
    <p className={styles.p}>Uma piscina natural em um jardim.</p>
    </div>
  );
}

export default Images;