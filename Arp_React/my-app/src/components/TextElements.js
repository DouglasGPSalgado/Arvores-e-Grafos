import React from 'react';
import styles from "./global.module.css"

const TextElements = () => {
  return (
    <>
      <h2 className={styles.h2}>Título Secundário</h2>
      <p className={styles.p}>Este é um parágrafo de exemplo.</p>
      <ul className={styles.ul}>
        <li className={styles.li}>Item 1</li>
        <li className={styles.li}>Item 2</li>
        <li className={styles.li}>Item 3</li>
      </ul>
      <a href="https://gfycat.com/anchoredvengefulgull" target="_blank" className={styles.a}>Surpressaaaaa!!</a>
    </>
  );
}

export default TextElements;