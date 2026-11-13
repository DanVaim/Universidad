const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);

app.set('views', './views');
app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(express.urlencoded({ extended: true }));

const rooms = {};

// Ruta principal que muestra las salas existentes
app.get('/', (req, res) => {
  res.render('index', { rooms: rooms });
});

app.post('/room', (req, res) => {
  const roomName = req.body.room;
  if (rooms[roomName] != null) {
    return res.redirect('/');
  }

  const password = req.body.password || '';
  rooms[roomName] = { users: {}, password: password };
  res.redirect(`/${roomName}`);
  // Emitir el evento de la nueva sala creada
  io.emit('crearRoom', roomName);
});

app.get('/:room', (req, res) => {
  const roomName = req.params.room;

  if (rooms[roomName] == null) {
    return res.redirect('/');
  }

  // Si la sala tiene una contraseña, mostrar la vista de contraseña
  if (rooms[roomName].password) {
    return res.render('password', { roomName: roomName, error: null });
  }

  // Si no tiene contraseña, redirige directamente
  res.render('room', { roomName: roomName });
});

// Verificar contraseña para unirse a la sala
app.post('/:room', (req, res) => {
  const roomName = req.params.room;
  const password = req.body.password;

  if (rooms[roomName] && rooms[roomName].password !== password) {
    return res.render('password', { roomName: roomName, error: 'Contraseña incorrecta' });
  }

  res.render('room', { roomName: roomName });
});

// Ruta de la sala de chat, solo accesible si la contraseña es correcta
app.get('/:room', (req, res) => {
  const roomName = req.params.room;
  res.render('room', { roomName: roomName });
});

server.listen(3000, () => {
  console.log('Server activo en puerto 3000');
});

// para manejar los mensajes de chat
io.on('connection', socket => {
  socket.on('usuarioNuevo', (room, name) => {
    socket.join(room);
    rooms[room].users[socket.id] = name;
    socket.to(room).broadcast.emit('usuarioConectado', name);
  });

  socket.on('enviarMensaje', (room, message) => {
    socket.to(room).broadcast.emit('mensaje', { message: message, name: rooms[room].users[socket.id] });
  });

  socket.on('disconnect', () => {
    getUserRooms(socket).forEach(room => {
      socket.to(room).broadcast.emit('usuarioSale', rooms[room].users[socket.id]);
      delete rooms[room].users[socket.id];
    });
  });
});

function getUserRooms(socket) {
  return Object.entries(rooms).reduce((names, [name, room]) => {
    if (room.users[socket.id] != null) names.push(name);
    return names;
  }, []);
}
