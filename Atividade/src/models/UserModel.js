const mongoose = require('mongoose');

// Defina o schema do usuário
const userSchema = new mongoose.Schema({
  name: String,
  email: String,
  password: String,
});

// Crie o modelo do usuário com base no schema
const UserModel = mongoose.model('User', userSchema);

module.exports = UserModel;
