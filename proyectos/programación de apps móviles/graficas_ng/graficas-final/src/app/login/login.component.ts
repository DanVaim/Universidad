import { Component, inject } from '@angular/core';
import { CommonModule } from '@angular/common';
import Swal from 'sweetalert2';
import { FormsModule } from '@angular/forms';
import { Router } from '@angular/router';
import { AuthService } from '../services/auth.service';

@Component({
  selector: 'app-login',
  standalone: true,
  imports: [FormsModule, CommonModule],
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css'],
})
export class LoginComponent {
  isLoginView: boolean = true;

  userRegisterObj: any = {
    userName: '',
    password: '',
    emailId: '',
  };

  userLogin: any = {
    userName: '',
    password: '',
  };

  registerErrors: any = {
    userName: '',
    emailId: '',
    password: '',
  };

  loginErrors: any = {
    userName: '',
    password: '',
  };

  constructor(private router: Router, private authService: AuthService) {}

  validateRegister(): boolean {
    let isValid = true;
    this.registerErrors = { userName: '', emailId: '', password: '' };
  
    if (!this.userRegisterObj.userName) {
      this.registerErrors.userName = 'Ingrese un usuario';
      isValid = false;
    }
    if (
      !this.userRegisterObj.emailId ||
      !/^\S+@\S+\.\S+$/.test(this.userRegisterObj.emailId)
    ) {
      this.registerErrors.emailId = 'Ingrese un correo válido';
      isValid = false;
    }
  
    if (!this.userRegisterObj.password) {
      this.registerErrors.password = 'Ingrese una contraseña';
      isValid = false;
    } else if (!/(?=.*[a-z])(?=.*[A-Z])/.test(this.userRegisterObj.password)) {
      this.registerErrors.password = 'La contraseña debe incluir una mayúscula';
      isValid = false;
    }
  
    if (!isValid) {
      setTimeout(() => {
        this.registerErrors = { userName: '', emailId: '', password: '' };
      }, 3000);
    }
  
    return isValid;
  }

  validateLogin(): boolean {
    let isValid = true;
    this.loginErrors = { userName: '', password: '' };

    if (!this.userLogin.userName) {
      this.loginErrors.userName = 'Ingrese su usuario';
      isValid = false;
    }
    if (!this.userLogin.password) {
      this.loginErrors.password = 'Ingrese su contraseña';
      isValid = false;
    }

    if (!isValid) {
      setTimeout(() => {
        this.loginErrors = { userName: '', password: '' };
      }, 1500);
    }

    return isValid;
  }

  onRegister() {
    if (this.validateRegister()) {
      let users = localStorage.getItem('Guardado')
        ? JSON.parse(localStorage.getItem('Guardado')!)
        : [];
      const userExists = users.some(
        (user: { userName: any; emailId: any }) =>
          user.userName === this.userRegisterObj.userName ||
          user.emailId === this.userRegisterObj.emailId
      );
      if (userExists) {
        Swal.fire({
          icon: 'error',
          title: '<strong>ERROR</strong>',
          html: '<p> Correo inválido (repetido)<p>',
        });
        return;
      }
      users.push(this.userRegisterObj);
      localStorage.setItem('Guardado', JSON.stringify(users));
      Swal.fire({
        title: 'Registro',
        html: 'Usuario registrado con éxito</strong>',
        icon: 'success'
    });
      this.isLoginView = true;
    }
  }

  onLogin() {
    if (this.validateLogin()) {
      const loggedIn = this.authService.login(
        this.userLogin.userName,
        this.userLogin.password
      );

      if (loggedIn) {
        this.router.navigateByUrl('lineal');
      } else {
        Swal.fire({
          title: "Olvidaste tu contraseña?",
          text: "Error al ingresar",
          icon: "question"
        });
      }
    }
    /* if (loggedIn) {
      this.router.navigateByUrl('dashboard');
    } else {
      <p> Preuba de fallos </p>
      swal.fire(
      "Alerta"
      "error de autenticación"
      "Enviar un Email de recuperación?")
      });
    } */
  }
}
