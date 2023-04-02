import React from 'react';
import { Route, Routes, createBrowserRouter, RouterProvider } from 'react-router-dom';
import styled from 'styled-components';
import Menu from './components/Menu';
import TextElements from './components/TextElements';
import ContactForm from './components/ContactForm';
import Tables from './components/Tables';
import Images from './components/Images';

const Container = styled.div`
  display: flex;
  flex-direction: column;
  align-items: center;
  padding: 20px;
`;

const App = () => {
  return (
    <React.Fragment>
      <Menu />
      <Container>
        <Routes>
          <Route path="/text" component={TextElements} />
          <Route path="/form" component={ContactForm} />
          <Route path="/table" component={Tables} />
          <Route path="/image" component={Images} />
        </Routes>
      </Container>
    </React.Fragment>
  );
};

export default App;
