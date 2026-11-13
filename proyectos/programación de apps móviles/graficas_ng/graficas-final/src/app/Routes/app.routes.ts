import { RouterModule, Routes } from '@angular/router';
import { LinealComponent } from '../Pages/lineal/lineal.component';
import { EComponent } from '../Pages/404/404.component';
import { LoginComponent } from '../login/login.component';
import { BarrasComponent } from '../Pages/barras/barras.component';
import { AnillosComponent } from '../Pages/anillos/anillos.component';
import { DispersionComponent } from '../Pages/dispersion/dispersion.component';
import { RadarComponent } from '../Pages/radar/radar.component';
import { PolarComponent } from '../Pages/polar/polar.component';
import { CircularComponent } from '../Pages/circular/circulares.component';

export const routes: Routes = [
    { path: '', redirectTo: 'login', pathMatch: 'full'},
    { path: 'login', component: LoginComponent},
    { path: 'lineal', component: LinealComponent,},
    { path: 'barras', component: BarrasComponent,},
    { path: 'circulares', component: CircularComponent,},
    { path: 'anillos', component: AnillosComponent,},
    { path: 'dispersion', component: DispersionComponent},
    { path: 'radar', component: RadarComponent,},
    { path: 'polar', component: PolarComponent,},
    { path: '**', component: EComponent},
];