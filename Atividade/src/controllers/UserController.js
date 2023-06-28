const UserModel = require('../models/UserModel');

class UserController {
  static login(req, res) {
    const { email, password } = req.body;

    const user = UserModel.findOne(email);

    if (!user || user.password !== password) {
      return res.json({ success: false, message: 'Credenciais inválidas' });
    }

    return res.json({ success: true, message: 'Login bem-sucedido' });
  }

  static register(req, res) {
    const { name, email, password } = req.body;

    const existingUser = UserModel.findUserByEmail(email);

    if (existingUser) {
      return res.json({ success: false, message: 'E-mail já cadastrado' });
    }

    const newUser = { id: Date.now(), name, email, password };

    UserModel.addUser(newUser);

    return res.json({ success: true, message: 'Cadastro realizado com sucesso' });
  }
  static teste(req, res) {
    return res.json({ success: true, message: 'Teste bem-sucedido' });
  }
}

module.exports = UserController;
