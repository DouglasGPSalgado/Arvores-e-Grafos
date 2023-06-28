const express = require('express');
const router = express.Router();
const UserController = require('./controllers/UserController');
const bodyParser = require('body-parser');
const app = express();

// Configuração do body-parser
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

router.post('/login', UserController.login);
router.post('/register', UserController.register);
router.get('/', UserController.teste);

app.use('/', router);
const mongoose = require('mongoose');
// Conecte-se ao MongoDB
mongoose.connect('mongodb://localhost/nome-do-banco-de-dados', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
  .then(() => {
    app.listen(3000, () => {
        console.log('Conexão com o MongoDB estabelecida com sucesso!');
      });
  })
  .catch((error) => {
    console.error('Erro ao conectar-se ao MongoDB:', error);
  });
module.exports = router;
