function resp (){ 
    numero = Math.ceil(Math.random()*10);
        var respuesta = document.getElementById("respuesta").value;
        var sal =  document.getElementById("salida");
        if (respuesta == numero) {
        sal.innerHTML = "Has acertado.";
        }
        else {
         sal.innerHTML = "Lo siento, el número era " + numero;
        }
    }