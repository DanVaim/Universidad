>Las expresiones regulares son patrones de cadenas de caracteres.

>Una expresión regular *r* es completamente definida mediante el conjunto de cadenas de caracteres con las que concuerdan.

El conjunto de cadenas de caracteres dentro de una expresión regular se denomina **lenguaje generado por la expresión regular**, se denota como: 

$$
L(r) 
$$

Aquí lenguaje hace referencia a " conjunto de cadenas de caracteres" y no a un lenguaje de programación. Este lenguaje depende del conjunto de caracteres que se encuentren disponibles definidos por un **alfabeto**, denominado **sigma**, ejemplo:


$$\sum = [a,b,c,d,...,z]$$ 
Una expresión regular contendrá caracteres del alfabeto , pero esos caracteres tienen un significado diferente: en una expresión regular todos los símbolos indican patrones. Además, las expresiones regulares contienen **metacaracteres o metasimbolos,** que no pueden ser caracteres legales en el alfabeto, ya que no se seria posible distinguir su uso de su participación en el alfabeto. Esto puede evitarse con el símbolo de slash invertido. 

### Expresiones basicas

#### Único simbolo

$$
L(a)=[a]
$$

#### Cadena vacia

$$
L(\epsilon) = [\epsilon]
$$
### Conjunto vacio

$$
L(\phi) = [\phi]
$$
### Operaciones de expresiones regulares 

#### Seleccion entre alternativas
$$
L(a | b)=L(a) \cup L(b)  =[a]\cup[b]=[a,b]
$$
#### Concatenacion

$$
L(ab)=L(a)L(b)=[a][b]=[ab]
$$
#### Repeticion (zero o mas), cerradura de Kleene

$$
L(a*)=L(a)*=[\epsilon, a, aa, aa, ...]
$$
### Extensiones de expresiones regulares
#### Repeticion (uno o mas)

$$
L(a+)=L(a)*-L(\epsilon)=[\epsilon, a, aa, aa, ...]-[\epsilon]=[a,aa,aaa, ...]
$$

#### Cualquier caracter

$$
L(.a)=[aa, ba, ca, ...]
$$

#### Intervalo de caracteres

$$
L([abc])=L(a|b|c)=[a,b,c]
$$
$$
L([a-z])=L(a|...|z)=[a,...,z]
$$
$$
L([a-zA-Z])=L(a|...|z|A|..|Z)=[a,...,z,A,...,Z]
$$
#### Negar expresiones

$$
L([ ▲ a]bc+)=L(a|...|z)=[bbc,cbcc,dbccc, ...]
$$

#### Subexpresiones opcionales

$$
L([ab]?c)=L(c)\cup L([ac]) \cup L([bc])=[c,ac,bc]
$$

### Nombres para expresiones regulares

Se pueden definir nombres para expresiones regulares de tal manera que una expresión compleja puede ser etiqueta o usada bajo un nombre

$$
digito=[0-9]
$$

$$
digito+ 2 = [0-9]+ 2 = [02,12,22,32,42 ...]
$$