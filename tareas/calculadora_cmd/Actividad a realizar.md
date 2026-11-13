Tarea #2, Escribir este codigo en  C(printf() y scanf())

int main()
{
           int elecion;
        int a, b,suma=0,resta=0,mult=1,div;
        float divR;
        cout<<" ingrese  uno de los casos: caso 1 suma ";
        cout<<" \ningrese  uno de los casos: caso 2 resta ";
        cout<<" \ningrese  uno de los casos: caso 3 multiplicacion ";
        cout<<" \ningrese  uno de los casos: caso 4 divicion  \n";
       
        cin>>elecion;//aca se guerda la elecion que hizo el usuario
       
        switch(elecion){
        case 1:{ //suma
                cout<<"Usted ha ingresdo en el modulo de suma \n";
                cout<<"ingrese el valor de a: "; cin>>a;
                cout<<"ingrese el valor de b: "; cin>>b;
                suma=a+b;
                cout<<"\nla suma es: " <<suma;
                break;
        }
        case 2: { //resta
                cout<<"Usted ha ingresado en el modulo de la resta\n";
                cout<<"ingrese el valor de a: "; cin>>a;
                cout<<"ingrese el valor de b: "; cin>>b;
                resta=a-b;
                cout<<"\nla resta es: " <<resta;
               
                break;
        }
        case 3:{ //multiplicacion
                cout<<"Usted ha ingresado en el modulo de la multiplicacion\n";
                cout<<"ingrese el valor de a: "; cin>>a;
                cout<<"ingrese el valor de b: "; cin>>b;
                mult=a*b;
                cout<<"\nla multiplicacion es: " <<mult;
               
               
                break;
        }
        case 4:{        //division
                cout<<"Usted ha ingresado en el modulo de la divicion\n";
                cout<<"ingrese el valor de a: "; cin>>a;
                cout<<"ingrese el valor de b: "; cin>>b;
                div=a/b;
                cout<<"\nla division entera es: " <<div;
               
                divR=float(a)/float(b);
               
                printf("\n La division decimal es: %.2f",divR);

                break;
        }
        default: cout<<"\nLa opcion es invalida";
        }
       
        return 0;
}
