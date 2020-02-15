package pruebas;

import excepciones.JugadorExisteException;
import grafica.Fachada;

public class PruebaFachada {

	public static void main(String[] args)
	{
		Fachada f = new Fachada();
		
		try 
		{
			f.listarPartidasJuagador("juan");
		}
		catch (JugadorExisteException e)
		{
			e.darMensaje();
		}
	}

}